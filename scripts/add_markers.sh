#!/bin/sh

xterm  -e  " source /opt/ros/kinetic/setup.bash" & 
sleep 1
xterm  -e " source /home/robond/projectFive/devel/setup.bash" &
sleep 1
xterm  -e  " roslaunch my_project4 turtlebot_world.launch " &
sleep 15
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo2.launch " &
sleep 15
xterm  -e  " roslaunch turtlebot_rviz_launchers view_pickup_markers.launch " &
sleep 15
xterm -e " rosrun add_markers add_markersOrig"
