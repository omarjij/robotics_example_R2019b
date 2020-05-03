#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "rasberrypi_publish";

// For Block rasberrypi_publish/Publish
SimulinkPublisher<sensor_msgs::Image, SL_Bus_rasberrypi_publish_sensor_msgs_Image> Pub_rasberrypi_publish_1;

// For Block rasberrypi_publish/Publish1
SimulinkPublisher<std_msgs::UInt8, SL_Bus_rasberrypi_publish_std_msgs_UInt8> Pub_rasberrypi_publish_103;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

