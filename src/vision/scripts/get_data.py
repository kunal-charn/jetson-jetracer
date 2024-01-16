#!/usr/bin/env python3

from io import StringIO
import rospy
from custom_msg_python.msg import custom
import csv
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
import base64
from PIL import Image
from io import BytesIO

data_list = []

def callback(data):
    # Save data to the list
    bridge = CvBridge()

    data_list.append((data.compressed_image.data, data.steering_angle.data, data.throttle_value.data))

    
    
# def callback_image(image_msg):
#     # Convert ROS Image message to OpenCV image
#     bridge = CvBridge()
#     cv_image = bridge.imgmsg_to_cv2(image_msg, desired_encoding="bgr8")

#     # Check if data_list is not empty
#     if data_list:
#         data_list[-1] = (cv_image,) + data_list[-1][1:]
#     else:
#         # If data_list is empty, append a new tuple
#         data_list.append((cv_image, None, None))  # Assuming None for steering and throttle values

def save_to_csv(data, filename):
    # Save the recorded data to a CSV file
    print(data)
    with open(filename, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['Image', 'Steering', 'Throttle'])  # Write header

        for item in data:
                    # Use item[0] directly as binary image data
                    image_array = np.frombuffer(item[0], dtype=np.uint8)

                
                    steering_angle = item[1]
                    throttle_value = item[2]
                    np.set_printoptions(threshold=np.inf)

                    csvwriter.writerow([image_array, steering_angle, throttle_value])


def listener():
    rospy.init_node('csv_saver', anonymous=True)
    rospy.Subscriber('/data', custom, callback)

    #Register a callback to write data to CSV when shutting down
    rospy.on_shutdown(lambda: save_to_csv(data_list, "data"))

    # Wait for ROS messages
    rospy.spin()

if __name__ == '__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass
