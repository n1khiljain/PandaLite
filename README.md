# PandaLite

Robotics project: ROS2 Jazzy + MuJoCo + LibTorch.

## Build the environment

```bash
docker build --platform linux/amd64 -t panda-dev .
```

## Run the container

```bash
docker run --platform linux/amd64 -it --rm -v "$(pwd):/workspace" panda-dev bash
```

Inside the container:
```bash
source /opt/ros/jazzy/setup.bash
source /workspace/install/setup.bash     # Your packages
```

## Sanity check

Builds a tiny C++ program that links ROS2 + MuJoCo + LibTorch.

```bash
cd /workspace/sanity_check
mkdir -p build && cd build
cmake .. && make
./sanity_check
```

