#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block rasberrypi_publish/Publish
extern SimulinkPublisher<sensor_msgs::Image, SL_Bus_rasberrypi_publish_sensor_msgs_Image> Pub_rasberrypi_publish_1;

// For Block rasberrypi_publish/Publish1
extern SimulinkPublisher<std_msgs::UInt8, SL_Bus_rasberrypi_publish_std_msgs_UInt8> Pub_rasberrypi_publish_103;

void slros_node_init(int argc, char** argv);

#endif
