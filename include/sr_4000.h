#ifndef SR_4000_H
#define SR_4000_H

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/PointCloud.h>

class SrNode {

public:
  SrNode();

private:
  void pointCallback(const sensor_msgs::PointCloud::ConstPtr& point_msg);

  ros::NodeHandle nh;
  ros::Subscriber sub;
  ros::Publisher pub;

  double dist;
};

#endif // SR_4000_H
