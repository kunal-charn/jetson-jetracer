#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "untitled1";

// For Block untitled1/Steering Publish
SimulinkPublisher<std_msgs::Float32, SL_Bus_untitled1_std_msgs_Float32> Pub_untitled1_1;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

