cmake_minimum_required(VERSION 2.8.3)
project(using_markers)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
  interactive_markers
  tf
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES using_markers
#  CATKIN_DEPENDS roscpp visualization_msgs
#  DEPENDS system_lib
)



## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_shapes src/basic_shapes.cpp)
target_link_libraries(basic_shapes ${catkin_LIBRARIES})

add_executable(interactive_marker src/interactive_marker.cpp)
target_link_libraries(interactive_marker ${catkin_LIBRARIES})

add_executable(my_interactive_marker src/my_interactive_marker.cpp)
target_link_libraries(my_interactive_marker ${catkin_LIBRARIES})

add_executable(menu src/menu.cpp)
target_link_libraries(menu ${catkin_LIBRARIES})


