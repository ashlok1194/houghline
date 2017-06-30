#include "../include/sr_4000.h"

SrNode::SrNode() {
   nh = ros::NodeHandle("");
   sub = nh.subscribe("/swissranger/pointcloud_raw", 10, &SrNode::pointCallback, this);
   pub = nh.advertise<std_msgs::Bool>("point", 10);

   nh.param("range", dist);
}

void SrNode::pointCallback(const sensor_msgs::PointCloud::ConstPtr& point_msg) {
  for(int i=0; i < point_msg->points.size(); ++i) {
    if (sqrt(pow(point_msg->points[i].x, 2.0) + pow(point_msg->points[i].y, 2.0) + pow(point_msg->points[i].z, 2.0)) < dist) {
      ROS_INFO_STREAM("Point below range");
      std_msgs::Bool bool_msg;
      bool_msg.data = true;
      pub.publish(bool_msg);
      return;
    }
  }
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "sr_node");

  SrNode tn;

  ros::spin();

  return 0;
}


