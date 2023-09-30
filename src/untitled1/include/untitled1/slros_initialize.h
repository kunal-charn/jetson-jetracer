#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "untitled1_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block untitled1/Steering Publish
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_untitled1_std_msgs_Float32> Pub_untitled1_1;

void slros_node_init(int argc, char** argv);

#endif
