

This repository contains catkin packages used with standard ros packages as examples for SLAM implementations.

This repository should be exported into the src folder of a catkin workspace. Each package inside of this repository will be addressed below.

## Packages

add_marker - contains two cpp files that demonstrate the ability to manuever markers in the Rviz environment.

my_project4 - contains backups of the map and world files. Contains urdf file of personally created robot that can be used in future implementations.

pick_objects - sends goal positions to the move_base package.

slam_gmapping - primarily used for the gmapping_demo.launch file. This package takes in a laser scan and odometry topic and publishes an occupancy grid map. It does this by utilizing a particle filter. Each particle represents a potential robot pose and map. The subscribed measurements are used to calculate a probability of the particles being the true robot pose. Weights are calculated based on the probabilities and resampling of the particles are done based on those weights. New particles are also generated with position and measurement noise. A db file is also created during this process and can be used later for localization if desired.

turtlebot - primarily used for the turtlebot_teleop.launch file. This package is used to manually move the robot around in the environment. This package is great for troubleshooting rviz and gmapping functionality.

turtlebot_interactions - This package contains a preconfigured rviz environment setup for the turtlebot, map_server, move_base, and amcl packages.

turtlebot_simulator - This packages contains both the turtlebot_world.launch and amcl_demo2.launch files. The turtlebot_world.launch contains parameters for launching a world file with the turtlebot initialized inside of it. In this example, the turtlebot's laser scan is created from the depth image of the kinect. The amcl_demo2.launch file takes in a laser scan and occupancy grid map and publishes a robot pose and particle cloud of poses. This launch file also sets up all of the amcl parameters for the turtlebot. This package uses the move_base package to navigate the map given a goal position. The move_base package creates a global costmap from the map published by the map_server package. The map_server is publishing a map based on a pgm file of our gazebo world. With the costmap, the navigation stack in the move_base package utilizes the Dijkstra's algorithm to determine the path for the robot and its necessary velocities. During runtime, the costmaps can be seen in rviz as borders around obstacles and a cost cloud is also generated around the robot for navigation.

## Directories

scripts - contains several sh files that utilize xterm to execute several launch and cpp files. Executing the home_services.sh file is the best way to see the majority of the functionality of the above packages.

map - contains the gazebo world file and the pgm/yaml files used with the map_server package in ros.


## License

The content of this repository is licensed under a [Creative Commons Attribution License](https://creativecommons.org/licenses/by/3.0/us/)
