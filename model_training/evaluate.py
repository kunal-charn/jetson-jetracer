import os
os.environ['CUDA_VISIBLE_DEVICES'] = '-1'  # Forces TensorFlow to use CPU

import tensorflow as tf
import numpy as np
import cv2
import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
csv_path = 'data.csv'  # Replace with the path to your CSV file
data = pd.read_csv(csv_path)
images_str = data['Image']

def preprocess_image(image):
    # Convert image to RGB (if it's not already in that format)
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Define range of red color in RGB
    lower_red = np.array([100, 0, 0])
    upper_red = np.array([255, 100, 100])

    # Threshold the RGB image to get only red colors
    mask = cv2.inRange(image_rgb, lower_red, upper_red)

    # Bitwise-AND mask and original image
    result = cv2.bitwise_and(image_rgb, image_rgb, mask=mask)

    return result
# Initialize variable to store the shape of the first image
first_image_shape = None

converted_images = []
for img_str in images_str:
    # Remove the leading '[' and trailing ']'
    formatted_str = img_str.strip('[]')

    # Split the string on spaces and convert each element to an integer
    byte_list = [int(item) for item in formatted_str.split()]
    
    # Convert the list to a NumPy array
    byte_array = np.array(byte_list, dtype=np.uint8)

    # Decode the byte array to an image
    image = cv2.imdecode(byte_array, cv2.IMREAD_COLOR)

    # Check if 'image' is empty or not loaded correctly
    if image is None or image.size == 0:
        print("Image not loaded correctly.")
        continue
    
    # Capture the shape of the first image
    if first_image_shape is None:
        first_image_shape = image.shape
        print("First image shape:", first_image_shape)
        
    # Preprocess image
    preprocessed_image = preprocess_image(image)
    converted_images.append(preprocessed_image.flatten())


# Function to predict steering angles
def predict_steering_angles(model, images):
    return model.predict(images)

# Placeholder function for redrawing the course
def redraw_course(steering_angles):
    # Basic trajectory logic
    x, y = 0, 0
    coordinates = [(x, y)]
    for angle in steering_angles:
        x += np.cos(angle)
        y += np.sin(angle)
        coordinates.append((x, y))
    return coordinates

# Load the model
model = tf.keras.models.load_model('my_model_1.h5')

# Check if there are valid images
if len(converted_images) > 0:
    images = np.array(converted_images).reshape(-1, *first_image_shape)
    predicted_angles = predict_steering_angles(model, images)
    course_coordinates = redraw_course(predicted_angles.flatten())

    # Plotting the trajectory
    x_coords, y_coords = zip(*course_coordinates)
    plt.plot(x_coords, y_coords)
    plt.title('Predicted Course Trajectory')
    plt.xlabel('X Coordinate')
    plt.ylabel('Y Coordinate')
    plt.axis('equal')
    plt.show()
else:
    print("No valid images were processed.")