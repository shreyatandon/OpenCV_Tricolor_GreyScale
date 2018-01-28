cmake_minimum_required(VERSION 3.0)
find_package(OpenCV REQUIRED )
add_executable(DisplayImage trial.cpp )
target_link_libraries(DisplayImage ${OpenCV_LIBS} )