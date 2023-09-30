#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include "untitled1_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(std_msgs::Float32* msgPtr, SL_Bus_untitled1_std_msgs_Float32 const* busPtr);
void convertToBus(SL_Bus_untitled1_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr);


#endif
