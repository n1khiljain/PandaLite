FROM osrf/ros:jazzy-desktop-full

RUN apt-get update && apt-get install -y \
    wget \
    unzip \
    ros-jazzy-ros2-control \
    ros-jazzy-controller-manager \
    libglfw3-dev \
    && rm -rf /var/lib/apt/lists/*

# Mujoco 3.8.1
RUN cd /tmp \
    && wget -q https://github.com/google-deepmind/mujoco/releases/download/3.8.1/mujoco-3.8.1-linux-x86_64.tar.gz \
    && tar -xzf mujoco-3.8.1-linux-x86_64.tar.gz -C /opt \
    && mv /opt/mujoco-3.8.1 /opt/mujoco \
    && rm mujoco-3.8.1-linux-x86_64.tar.gz

ENV MUJOCO_DIR=/opt/mujoco

# LibTorch 2.12.0 (CPU, cxx11 ABI)
RUN cd /tmp \
    && wget -q https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.12.0%2Bcpu.zip \
    && unzip -q libtorch-shared-with-deps-2.12.0+cpu.zip -d /opt \
    && rm libtorch-shared-with-deps-2.12.0+cpu.zip

ENV Torch_DIR=/opt/libtorch/share/cmake/Torch

WORKDIR /workspace
