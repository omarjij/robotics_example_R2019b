#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <ros/time.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include "rasberrypi_publish_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(ros::Time* msgPtr, SL_Bus_rasberrypi_publish_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_rasberrypi_publish_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sensor_msgs::Image* msgPtr, SL_Bus_rasberrypi_publish_sensor_msgs_Image const* busPtr);
void convertToBus(SL_Bus_rasberrypi_publish_sensor_msgs_Image* busPtr, sensor_msgs::Image const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_rasberrypi_publish_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_rasberrypi_publish_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);

void convertFromBus(std_msgs::UInt8* msgPtr, SL_Bus_rasberrypi_publish_std_msgs_UInt8 const* busPtr);
void convertToBus(SL_Bus_rasberrypi_publish_std_msgs_UInt8* busPtr, std_msgs::UInt8 const* msgPtr);


#endif
