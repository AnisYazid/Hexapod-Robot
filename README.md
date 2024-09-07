# Hexapod Robot with ESP32 and Jetson Nano

## Overview
This project involves the design and development of a hexapod robot equipped with 18 HS-475HB servo motors for movement, controlled by an ESP32 microcontroller. The robot utilizes two PCA9685 servo drivers to manage the 18 servos—dividing them between the left and right sides for better control and coordination. An accelerometer is integrated for real-time calibration and stabilization. For movement, the robot employs Bézier curves for smooth trajectory planning and PID (Proportional-Integral-Derivative) control for precise servo positioning. For autonomous navigation, the robot leverages a Jetson Nano paired with an Xbox Kinect V2 for environmental mapping and obstacle avoidance. Additionally, the robot features a buzzer and LEDs for debugging and status indication. The robot can also be controlled remotely using a Radiolink AT10 transmitter and RD12DS receiver.

## Components
- **Microcontroller:** ESP32
- **Servo Drivers:** 2 x PCA9685 (one for the left side, one for the right side)
  - **Right PCA9685 Address Modification:** A0 pin soldered to change the I2C address
- **Servo Motors:** 18 x HS-475HB
- **Orientation Sensor:** MPU6050 
- **Processing Unit:** Jetson Nano (for advanced processing and AI capabilities)
- **Depth Sensor:** Xbox Kinect V2 (for 3D mapping and object detection amd mapping)
- **Buzzer:** For audio feedback and alerts
- **LEDs:**
  - **Red LED:** Main power indicator
  - **Blue LED:** Connection status indicator (searching for remote and Jetson)
  - **Green LED:** Setup ready indicator (all systems operational)
- **Power Supply:** 4S 14.8V LiPo battery (100C rating)
- **Remote Control:**
  - **Transmitter:** Radiolink AT10II
  - **Receiver:** Radiolink RD12DS (connected to ESP32 via TX2 pin)

## Servo Motor Specification: HS-475HB
- **Modulation:** Analog
- **Torque:**
  - 4.8V: 61.0 oz-in (4.39 kg-cm)
  - 6.0V: 76.0 oz-in (5.47 kg-cm)
- **Speed:**
  - 4.8V: 0.23 sec/60°
  - 6.0V: 0.18 sec/60°
- **Weight:** 1.41 oz (40.0 g)
- **Dimensions:**
  - Length: 1.52 in (38.6 mm)
  - Width: 0.77 in (19.6 mm)
  - Height: 1.41 in (35.8 mm)
- **Motor Type:** 3-pole
- **Gear Type:** Plastic
- **Rotation/Support:** Single Bearing
- **Rotational Range:** 200°
- **Pulse Cycle:** 20 ms
- **Pulse Width:** 900-2100 µs

## Features
- **Dual PCA9685 Control:** Two PCA9685 drivers allow for precise control of 18 HS-475HB servos, with separate management for the left and right sides of the hexapod.
- **Smooth Movement:** Utilizes Bézier curves to generate smooth trajectories for the hexapod's movements, enhancing agility and fluidity.
- **PID Control:** Implements PID control for precise servo positioning, allowing for accurate and stable movement adjustments.
- **Real-Time Calibration:** Uses MPU6050 for detecting orientation and adjusting the robot's posture on-the-fly.
- **Autonomous Navigation:** Implements SLAM (Simultaneous Localization and Mapping) algorithms for navigating complex environments.
- **Obstacle Detection:** Utilizes Kinect V2 for depth perception and real-time obstacle avoidance.
- **Debugging Tools:** Buzzer for alerts and LEDs for indicating status (e.g., errors, operational states).
- **Remote Control Mode:** Allows manual operation via Radiolink AT10 transmitter.

## Installation
### Prerequisites
- **Hardware:**
  - ESP32 development board
  - 2 x PCA9685 servo drivers
  - 18 x HS-475HB servo motors
  - MPU6050 sensor
  - Jetson Nano
  - Kinect V2 sensor
  - Buzzer
  - LEDs:
    - Red for power
    - Blue for connection status
    - Green for setup readiness
  - Resistors for LEDs (if needed)
  - 4S LiPo battery (100C rating)
  - Radiolink AT10 transmitter
  - Radiolink RD12DS receiver
  - Power supply
 
  ##Future Work
  - **Advanced Sensor Integration:** Explore additional algorithms for obstacle avoidance and pathfinding
  - **Machine Learning:** Implement machine learning techniques for better decision-making and adaptive behaviors based on the robot's experiences.
  - **Battery Management System:** Develop a battery management system to monitor battery levels and optimize power consumption during operation.
  
