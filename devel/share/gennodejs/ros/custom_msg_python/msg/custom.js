// Auto-generated. Do not edit!

// (in-package custom_msg_python.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');
let sensor_msgs = _finder('sensor_msgs');

//-----------------------------------------------------------

class custom {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.compressed_image = null;
      this.steering_angle = null;
      this.throttle_value = null;
    }
    else {
      if (initObj.hasOwnProperty('compressed_image')) {
        this.compressed_image = initObj.compressed_image
      }
      else {
        this.compressed_image = new sensor_msgs.msg.CompressedImage();
      }
      if (initObj.hasOwnProperty('steering_angle')) {
        this.steering_angle = initObj.steering_angle
      }
      else {
        this.steering_angle = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('throttle_value')) {
        this.throttle_value = initObj.throttle_value
      }
      else {
        this.throttle_value = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type custom
    // Serialize message field [compressed_image]
    bufferOffset = sensor_msgs.msg.CompressedImage.serialize(obj.compressed_image, buffer, bufferOffset);
    // Serialize message field [steering_angle]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.steering_angle, buffer, bufferOffset);
    // Serialize message field [throttle_value]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.throttle_value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type custom
    let len;
    let data = new custom(null);
    // Deserialize message field [compressed_image]
    data.compressed_image = sensor_msgs.msg.CompressedImage.deserialize(buffer, bufferOffset);
    // Deserialize message field [steering_angle]
    data.steering_angle = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [throttle_value]
    data.throttle_value = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += sensor_msgs.msg.CompressedImage.getMessageSize(object.compressed_image);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg_python/custom';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3a65ddb3433fdf5ed9029c363843bd15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    sensor_msgs/CompressedImage compressed_image
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new custom(null);
    if (msg.compressed_image !== undefined) {
      resolved.compressed_image = sensor_msgs.msg.CompressedImage.Resolve(msg.compressed_image)
    }
    else {
      resolved.compressed_image = new sensor_msgs.msg.CompressedImage()
    }

    if (msg.steering_angle !== undefined) {
      resolved.steering_angle = std_msgs.msg.Float32.Resolve(msg.steering_angle)
    }
    else {
      resolved.steering_angle = new std_msgs.msg.Float32()
    }

    if (msg.throttle_value !== undefined) {
      resolved.throttle_value = std_msgs.msg.Float32.Resolve(msg.throttle_value)
    }
    else {
      resolved.throttle_value = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = custom;
