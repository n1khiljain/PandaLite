#include <iostream>

// ros2 - rclcpp is the c++ client library for ros2
#include <rclcpp/rclcpp.hpp>

// Mujoco
#include <mujoco/mujoco.h>

// LibTorch
#include <torch/torch.h>

int main(int argc, char *argv[]) {
    std::cout << "=== Sanity Check: ROS2 + MuJoCo + LibTorch ===" << std::endl;

    // Ros2 initialization
    rclcpp::init(argc, argv);
    std::cout << "ROS2: rclcpp initialized successfully" << std::endl;
    rclcpp::shutdown();

    // Mujoco initialization
    std::cout << "MuJoCo version: " << mj_versionString() << std::endl;

    // LibTorch initialization
    torch::Tensor t = torch::rand({2, 3});
    std::cout << "LibTorch version: " << TORCH_VERSION << std::endl;
    std::cout << "Random 2x3 tensor:\n" << t << std::endl;

    std::cout << "=== All three libraries working ===" << std::endl;
    return 0;

}
