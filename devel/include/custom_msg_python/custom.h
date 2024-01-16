// Generated by gencpp from file custom_msg_python/custom.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_PYTHON_MESSAGE_CUSTOM_H
#define CUSTOM_MSG_PYTHON_MESSAGE_CUSTOM_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/CompressedImage.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>

namespace custom_msg_python
{
template <class ContainerAllocator>
struct custom_
{
  typedef custom_<ContainerAllocator> Type;

  custom_()
    : compressed_image()
    , steering_angle()
    , throttle_value()  {
    }
  custom_(const ContainerAllocator& _alloc)
    : compressed_image(_alloc)
    , steering_angle(_alloc)
    , throttle_value(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sensor_msgs::CompressedImage_<ContainerAllocator>  _compressed_image_type;
  _compressed_image_type compressed_image;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _steering_angle_type;
  _steering_angle_type steering_angle;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _throttle_value_type;
  _throttle_value_type throttle_value;





  typedef boost::shared_ptr< ::custom_msg_python::custom_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg_python::custom_<ContainerAllocator> const> ConstPtr;

}; // struct custom_

typedef ::custom_msg_python::custom_<std::allocator<void> > custom;

typedef boost::shared_ptr< ::custom_msg_python::custom > customPtr;
typedef boost::shared_ptr< ::custom_msg_python::custom const> customConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg_python::custom_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg_python::custom_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::custom_msg_python::custom_<ContainerAllocator1> & lhs, const ::custom_msg_python::custom_<ContainerAllocator2> & rhs)
{
  return lhs.compressed_image == rhs.compressed_image &&
    lhs.steering_angle == rhs.steering_angle &&
    lhs.throttle_value == rhs.throttle_value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::custom_msg_python::custom_<ContainerAllocator1> & lhs, const ::custom_msg_python::custom_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace custom_msg_python

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_python::custom_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_python::custom_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_python::custom_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_python::custom_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_python::custom_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_python::custom_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg_python::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3a65ddb3433fdf5ed9029c363843bd15";
  }

  static const char* value(const ::custom_msg_python::custom_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3a65ddb3433fdf5eULL;
  static const uint64_t static_value2 = 0xd9029c363843bd15ULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg_python::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg_python/custom";
  }

  static const char* value(const ::custom_msg_python::custom_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg_python::custom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/CompressedImage compressed_image\n"
"std_msgs/Float32 steering_angle\n"
"std_msgs/Float32 throttle_value\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/CompressedImage\n"
"# This message contains a compressed image\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"\n"
"string format        # Specifies the format of the data\n"
"                     #   Acceptable values:\n"
"                     #     jpeg, png\n"
"uint8[] data         # Compressed image buffer\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Float32\n"
"float32 data\n"
;
  }

  static const char* value(const ::custom_msg_python::custom_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg_python::custom_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.compressed_image);
      stream.next(m.steering_angle);
      stream.next(m.throttle_value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct custom_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg_python::custom_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg_python::custom_<ContainerAllocator>& v)
  {
    s << indent << "compressed_image: ";
    s << std::endl;
    Printer< ::sensor_msgs::CompressedImage_<ContainerAllocator> >::stream(s, indent + "  ", v.compressed_image);
    s << indent << "steering_angle: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.steering_angle);
    s << indent << "throttle_value: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.throttle_value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_PYTHON_MESSAGE_CUSTOM_H
