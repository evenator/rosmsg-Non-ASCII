// Publishes a test message with roscpp, which works
// Based on the roscpp talker tutorial
#include "ros/ros.h"
#include "non_ascii_msgs/Test.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<non_ascii_msgs::Test>("test", 1000);

  ros::Rate loop_rate(1);
  int count = 0;
  while (ros::ok())
  {
    non_ascii_msgs::Test msg;
    msg.number = 1;

    ROS_INFO("Published a message with number=%d", msg.number);
    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
