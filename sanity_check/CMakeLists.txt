cmake_minimum_required(VERSION 3.16)
project(sanity_check)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- ROS2 ---
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# --- MuJoCo ---
# MuJoCo doesn't ship a CMake config file, so we point at it manually
# using the MUJOCO_DIR environment variable set in the Dockerfile.
set(MUJOCO_DIR $ENV{MUJOCO_DIR})
if(NOT MUJOCO_DIR)
    message(FATAL_ERROR "MUJOCO_DIR environment variable not set")
endif()

# --- LibTorch ---
# Torch_DIR env var points at the dir with TorchConfig.cmake
find_package(Torch REQUIRED)

# --- The executable ---
add_executable(sanity_check main.cpp)

target_include_directories(sanity_check PRIVATE
    ${MUJOCO_DIR}/include
)

target_link_libraries(sanity_check
    rclcpp::rclcpp
    ${MUJOCO_DIR}/lib/libmujoco.so
    ${TORCH_LIBRARIES}
)

# LibTorch requires this flag
set_property(TARGET sanity_check PROPERTY CXX_STANDARD 17)