cmake_minimum_required(VERSION 3.5)
project(robot_planner)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O3")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")
set(CMAKE_BUILD_TYPE Release)

find_package(
        catkin REQUIRED COMPONENTS
        geometry_msgs
        nav_msgs
        sensor_msgs
        roscpp
        rospy
        std_msgs
        tf
)

find_package(Eigen3 REQUIRED)
find_package(ompl REQUIRED)
find_package(LAPACK REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${OMPL_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
)

add_message_files(
  FILES
  path_result.msg
  data_result.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
        CATKIN_DEPENDS
        roscpp
        geometry_msgs
        message_runtime
        nav_msgs
        rospy
        std_msgs
        tf
        DEPENDS
        EIGEN3
        LAPACK
)

set(
        sources
        src/main.cpp
        src/RobotDynamicModel.cpp
        src/RobotKinematicModel.cpp
)

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(
        ${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${OMPL_LIBRARIES}
)