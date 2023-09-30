#!/usr/bin/env python

import rospy
import nanocamera as nano
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np
from std_msgs.msg import Float32

def process_frame(frame):
	pub_steering = rospy.Publisher('steering', Float32, queue_size=8)
	lower_black = np.uint8([0,0,0])
	upper_black = np.uint8([80,80,80])
	black_mask = cv2.inRange(frame, lower_black, upper_black)
	cv2.imshow("mask", black_mask)
	cv2.imshow("frame", frame)
	contours, _ = cv2.findContours(black_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
	steering_angle = 0 
	if contours:
		largest_countour = max(contours, key=cv2.contourArea)
		M = cv2.moments(largest_countour)
		if M['m00'] != 0:
			cx = int(M['m10'] / M['m00'])
			cy = int(M['m01'] / M['m00'])

			# Calculate the error (distance from the center of the frame)
			image_center_x = frame.shape[1] / 2
			error = cx - image_center_x

			# Define a proportional control gain
			Kp = 0.1

			# Calculate the steering angle based on the error
			steering_angle = Kp * error
 

	cv2.drawContours(frame, contours, -1, (0,0,255),1)
	print(steering_angle)
	pub_steering.publish(steering_angle)
	return frame


def talker():
	bridge = CvBridge()
	camera = nano.Camera(flip=0, width=160, height=120, fps=10)
	pub = rospy.Publisher('/lane', Image, queue_size = 1)
	rospy.init_node('image', anonymous = False)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		frame = camera.read()
		#if not ret:
		#	break
		new_frame = process_frame(frame)
		msg = bridge.cv2_to_imgmsg(new_frame, "bgr8")
		pub.publish(msg)

		if cv2.waitKey(1) & 0xFF == ord('q'):
			break

		if rospy.is_shutdown():
			camera.release()
			del camera

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
