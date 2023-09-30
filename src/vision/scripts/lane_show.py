#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2


# from nanocamera.NanoCam import Camera
import nanocamera as nano

def callback_image(image):
	
	bridge = CvBridge()
	cv_image = bridge.imgmsg_to_cv2(image, "bgr8")
	cv2.imshow("image from ros", cv_image)
	cv2.waitKey(1)

if __name__ == '__main__':
	print("Running lane show")
	rospy.init_node('laneDetection',anonymous=True)
	rospy.Subscriber("/lane", Image, callback_image)
	rospy.spin()
