;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_python::custom)
  (if (not (find-package "CUSTOM_MSG_PYTHON"))
    (make-package "CUSTOM_MSG_PYTHON"))
  (shadow 'custom (find-package "CUSTOM_MSG_PYTHON")))
(unless (find-package "CUSTOM_MSG_PYTHON::CUSTOM")
  (make-package "CUSTOM_MSG_PYTHON::CUSTOM"))

(in-package "ROS")
;;//! \htmlinclude custom.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msg_python::custom
  :super ros::object
  :slots (_image _steering_angle _throttle_value ))

(defmethod custom_msg_python::custom
  (:init
   (&key
    ((:image __image) (instance sensor_msgs::Image :init))
    ((:steering_angle __steering_angle) (instance std_msgs::Float32 :init))
    ((:throttle_value __throttle_value) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _image __image)
   (setq _steering_angle __steering_angle)
   (setq _throttle_value __throttle_value)
   self)
  (:image
   (&rest __image)
   (if (keywordp (car __image))
       (send* _image __image)
     (progn
       (if __image (setq _image (car __image)))
       _image)))
  (:steering_angle
   (&rest __steering_angle)
   (if (keywordp (car __steering_angle))
       (send* _steering_angle __steering_angle)
     (progn
       (if __steering_angle (setq _steering_angle (car __steering_angle)))
       _steering_angle)))
  (:throttle_value
   (&rest __throttle_value)
   (if (keywordp (car __throttle_value))
       (send* _throttle_value __throttle_value)
     (progn
       (if __throttle_value (setq _throttle_value (car __throttle_value)))
       _throttle_value)))
  (:serialization-length
   ()
   (+
    ;; sensor_msgs/Image _image
    (send _image :serialization-length)
    ;; std_msgs/Float32 _steering_angle
    (send _steering_angle :serialization-length)
    ;; std_msgs/Float32 _throttle_value
    (send _throttle_value :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/Image _image
       (send _image :serialize s)
     ;; std_msgs/Float32 _steering_angle
       (send _steering_angle :serialize s)
     ;; std_msgs/Float32 _throttle_value
       (send _throttle_value :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/Image _image
     (send _image :deserialize buf ptr-) (incf ptr- (send _image :serialization-length))
   ;; std_msgs/Float32 _steering_angle
     (send _steering_angle :deserialize buf ptr-) (incf ptr- (send _steering_angle :serialization-length))
   ;; std_msgs/Float32 _throttle_value
     (send _throttle_value :deserialize buf ptr-) (incf ptr- (send _throttle_value :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg_python::custom :md5sum-) "48c8011b63e2f995bac8b531cb24cad0")
(setf (get custom_msg_python::custom :datatype-) "custom_msg_python/custom")
(setf (get custom_msg_python::custom :definition-)
      "sensor_msgs/Image image
std_msgs/Float32 steering_angle
std_msgs/Float32 throttle_value

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: std_msgs/Float32
float32 data
")



(provide :custom_msg_python/custom "48c8011b63e2f995bac8b531cb24cad0")


