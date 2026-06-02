#ifndef PANDALITE_MUJOCO_HW__MUJOCO_SYSTEM_HPP_
#define PANDALITE_MUJOCO_HW__MUJOCO_SYSTEM_HPP_

#include <vector>                                                  // for std::vector
#include <string>                                                  // for std::string
#include "hardware_interface/system_interface.hpp"                 // base class
#include "hardware_interface/handle.hpp"                           // StateInterface, CommandInterface
#include "hardware_interface/hardware_info.hpp"                    // HardwareInfo struct
#include "hardware_interface/types/hardware_interface_return_values.hpp"  // return_type
#include "rclcpp/rclcpp.hpp"                                       // rclcpp::Time, Duration
#include "rclcpp_lifecycle/state.hpp"                              // lifecycle::State

namespace pandalite_mujoco_hw 
{
    class PandaliteMujocoSystem : public hardware_interface::SystemInterface
{
    public:
        // constructor
        PandaliteMujocoSystem() = default;

        // Called once on load. Parse URDF info, allocate memory.
        hardware_interface::CallbackReturn on_init(
            const hardware_interface::HardwareInfo & info) override;

        // Tell the framework about your read-only interfaces (joint state).
        std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

        // Tell the framework about your writable interfaces (commands in).
        std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

        // Called when activated. Start the simulation, get ready to run.
        hardware_interface::CallbackReturn on_activate(
            const rclcpp_lifecycle::State & previous_state) override;

        // Called when deactivated. Stop accepting commands.
        hardware_interface::CallbackReturn on_deactivate(
            const rclcpp_lifecycle::State & previous_state) override;

        // Called every tick. Read joint state from "hardware" (MuJoCo, later).
        hardware_interface::return_type read(
            const rclcpp::Time & time, const rclcpp::Duration & period) override;

        // Called every tick. Apply commands to "hardware".
        hardware_interface::return_type write(
            const rclcpp::Time & time, const rclcpp::Duration & period) override;
    private:
        std::vector<double> joint_positions_;       // 6 doubles, state
        std::vector<double> joint_velocities_;      // 6 doubles, state  
        std::vector<double> joint_efforts_;         // 6 doubles, state
        std::vector<double> joint_position_commands_; // 6 doubles, command
};
} // namespace pandalite_mujoco_hw


#endif  // PANDALITE_MUJOCO_HW__MUJOCO_SYSTEM_HPP_
