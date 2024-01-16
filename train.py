import pandas as pd
import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split
from tensorflow.keras import layers, models
import cv2
import base64
import ast
import matplotlib.pyplot as plt


# Load recorded data from CSV
data = pd.read_csv("data.csv")

# Extract features (X) and labels (y)
images_str = data['Image']
steering = data['Steering']
throattle = data['Throttle']

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

# # Assume all images are of the same shape as the first image
X = np.array(converted_images).reshape(-1, *first_image_shape)
# plt.imshow(X[5])
# plt.title('test x[5] Image')
# plt.axis('off')  # Turn off axis labels
# plt.show()
y = np.array(steering)
z = np.array(throattle)
with tf.device('/cpu:0'): 
    # Update the model with the correct input shape
    input_shape = X.shape[1:]  # Shape of a single image in the dataset
    model = models.Sequential()
    model.add(layers.Conv2D(24, (5, 5), activation='relu', input_shape=input_shape))
    model.add(layers.MaxPooling2D((2, 2)))
    model.add(layers.Conv2D(36, (5, 5), activation='relu'))
    model.add(layers.MaxPooling2D((2, 2)))
    model.add(layers.Flatten())
    model.add(layers.Dense(128, activation='relu'))
    model.add(layers.Dense(1))  # Output layer: one neuron for steering angle

    model.compile(optimizer='adam', loss='mean_squared_error')




    # Split the data into training and testing sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # Normalize pixel values to be between 0 and 1
    X_train, X_test = X_train / 255.0, X_test / 255.0
    # Reduce the batch size
    batch_size = 1  # Try smaller values like 16 or 8 if you still encounter OOM errors
    model.fit(X_train, y_train, epochs=10, batch_size=batch_size, validation_data=(X_test, y_test))
    # Save the model in HDF5 format
    model.save('my_model_3.h5')  # Replace with your desired file name