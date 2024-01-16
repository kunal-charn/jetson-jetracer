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
  :slots (_compressed_image _steering_angle _throttle_value ))

(defmethod custom_msg_python::custom
  (:init
   (&key
    ((:compressed_image __compressed_image) (instance sensor_msgs::CompressedImage :init))
    ((:steering_angle __steering_angle) (instance std_msgs::Float32 :init))
    ((:throttle_value __throttle_value) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _compressed_image __compressed_image)
   (setq _steering_angle __steering_angle)
   (setq _throttle_value __throttle_value)
   self)
  (:compressed_image
   (&rest __compressed_image)
   (if (keywordp (car __compressed_image))
       (send* _compressed_image __compressed_image)
     (progn
       (if __compressed_image (setq _compressed_image (car __compressed_image)))
       _compressed_image)))
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
    ;; sensor_msgs/CompressedImage _compressed_image
    (send _compressed_image :serialization-length)
    ;; std_msgs/Float32 _steering_angle
    (send _steering_angle :serialization-length)
    ;; std_msgs/Float32 _throttle_value
    (send _throttle_value :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/CompressedImage _compressed_image
       (send _compressed_image :serialize s)
     ;; std_msgs/Float32 _steering_angle
       (send _steering_angle :serialize s)
     ;; std_msgs/Float32 _throttle_value
       (send _throttle_value :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/CompressedImage _compressed_image
     (send _compressed_image :deserialize buf ptr-) (incf ptr- (send _compressed_image :serialization-length))
   ;; std_msgs/Float32 _steering_angle
     (send _steering_angle :deserialize buf ptr-) (incf ptr- (send _steering_angle :serialization-length))
   ;; std_msgs/Float32 _throttle_value
     (send _throttle_value :deserialize buf ptr-) (incf ptr- (send _throttle_value :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg_python::custom :md5sum-) "3a65ddb3433fdf5ed9029c363843bd15")
(setf (get custom_msg_python::custom :datatype-) "custom_msg_python/custom")
(setf (get custom_msg_python::custom :definition-)
      "sensor_msgs/CompressedImage compressed_image
std_msgs/Float32 steering_angle
std_msgs/Float32 throttle_value

================================================================================
MSG: sensor_msgs/CompressedImage
# This message contains a compressed image

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image

string format        # Specifies the format of the data
                     #   Acceptable values:
                     #     jpeg, png
uint8[] data         # Compressed image buffer

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



(provide :custom_msg_python/custom "3a65ddb3433fdf5ed9029c363843bd15")


