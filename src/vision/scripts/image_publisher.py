#!/usr/bin/env python

import rospy
import nanocamera as nano
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2



def talker():
	bridge = CvBridge()
	camera = nano.Camera(flip=0, width=640, height=480, fps=10)
	pub = rospy.Publisher('/webcam', Image, queue_size = 1)
	rospy.init_node('image', anonymous = False)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		frame = camera.read()
		#if not ret:
		#	break
		
		msg = bridge.cv2_to_imgmsg(frame, "rgb8")
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
