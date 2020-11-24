#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>

const float pickup_x_position = 4.0;
const float pickup_y_position = 0.0;
const float dropoff_x_position = 1.0;
const float dropoff_y_position = -5.0;


ros::Publisher marker_pub;
ros::Subscriber odom_sub;
visualization_msgs::Marker marker;

void checkPositionCallback(const nav_msgs::Odometry::ConstPtr& msg){


    if(abs(msg->pose.pose.position.x - pickup_x_position) < .1 && abs(msg->pose.pose.position.y - pickup_y_position) < .2){
		marker.color.a = 0.0;
		ROS_INFO("Picking up marker.");

    } else if(abs(msg->pose.pose.position.x - dropoff_x_position) < .1 && abs(msg->pose.pose.position.y - dropoff_y_position) < .1){
		marker.pose.position.x = dropoff_x_position;
    		marker.pose.position.y = dropoff_y_position;
		marker.color.a = 1.0;
		ROS_INFO("Dropped off marker.");
    }
    


};



int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(.25);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  odom_sub = n.subscribe("odom", 1, checkPositionCallback);
  
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickup_x_position;
    marker.pose.position.y = pickup_y_position;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    marker_pub.publish(marker); //display marker in pickup zone first location
    ROS_INFO("Displaying pickup marker.");

    while(ros::ok){
	ros::spinOnce();
	marker_pub.publish(marker);
	r.sleep();
    }


    
 
}
