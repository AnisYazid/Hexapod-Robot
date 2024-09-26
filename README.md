# Hexapod Robot with ESP32 and Jetson Nano

![Hexapod Robot](https://github.com/AnisYazid/Hexapod-Robot/blob/main/image0.jpeg)   
![Hexapod Robot](https://github.com/AnisYazid/Hexapod-Robot/blob/main/image2.jpeg)   

## Overview
This project involves the design and development of a hexapod robot equipped with 18 HS-475HB servo motors for movement, controlled by an ESP32 microcontroller. The robot utilizes two PCA9685 servo drivers to manage the 18 servos—dividing them between the left and right sides for better control and coordination. An accelerometer is integrated for real-time calibration and stabilization. For movement, the robot employs Bézier curves for smooth trajectory planning and PID (Proportional-Integral-Derivative) control for precise servo positioning. For autonomous navigation, the robot leverages a Jetson Nano paired with an Xbox Kinect V2 for environmental mapping and obstacle avoidance. Additionally, the robot features a buzzer and LEDs for debugging and status indication. The robot can also be controlled remotely using a Radiolink AT10 transmitter and RD12DS receiver.

## Components
- **Microcontroller:** ESP32
- **Servo Drivers:** 2 x PCA9685 (one for the left side, one for the right side)
  - **Right PCA9685 Address Modification: 0x41 ** A0 pin soldered to change the I2C address ( E-D-F )
  - **Left PCA9685 Address Modification: 0x42 ** A1 pin soldered to change the I2C address ( A-B-C )
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
 
- **Software:**

   ```bash
   git clone https://github.com/yourusername/hexapod-robot.git
   cd hexapod-robot
   
### Install ESP32 Libraries
1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for and install:
   - Adafruit PWM Servo Driver Library
   - MPU6050 library
   - PID library (if necessary for your implementation)

### Install Jetson Nano Libraries
1. Open a terminal and install OpenCV:
   ```bash
   sudo apt-get install python3-opencv
   
2. Install ROS (Robot Operating System) following: [official ROS installation instructions](http://wiki.ros.org/ROS/Installation).
   
## Pinout

### ESP32 Connections
- **PCA9685 Servo Driver 1:**
  - SDA: GPIO 21
  - SCL: GPIO 22

- **PCA9685 Servo Driver 2:**
  - SDA: GPIO 21
  - SCL: GPIO 22
  - (Note: Both drivers share the same SDA and SCL pins)

- **MPU6050:**
  - SDA: GPIO 21
  - SCL: GPIO 22
  - (Note: The MPU6050 also shares the same I2C pins)

- **LEDs:**
  - Red LED: GPIO 25
  - Blue LED: GPIO 4
  - Green LED: GPIO 2

- **Buzzer:**
  - Buzzer: GPIO 23
 
## Troubleshooting
### Common Issues

#### Servo Not Responding:
- Check the power supply to ensure the servos are receiving adequate voltage.
- Verify the wiring connections to the PCA9685 and ESP32.
- Ensure the correct I2C address is being used in the code.
- Inspect the servo motors for physical damage or mechanical binding.
- Test individual servos to confirm they are operational by connecting them directly to a power source.

#### Inconsistent Movement:
- Make sure the PID parameters are properly tuned for the specific movement requirements.
- Check the calibration of the MPU6050 to ensure accurate orientation readings.
- Monitor the servo feedback to ensure they are reaching the desired positions.
- Adjust the movement commands to ensure they are not exceeding the servo's capabilities.

#### LEDs Not Lighting Up:
- Confirm that the LEDs are wired correctly and that the appropriate pins are defined in the code.
- Check for any potential shorts or incorrect resistor values.
- Verify that the code includes logic to turn on the LEDs in the correct conditions.
- Test the LEDs individually to ensure they are functional.

#### Battery Issues:
- Monitor battery levels to ensure adequate power for all components.
- Check the battery connections for any loose or corroded terminals.
- Consider using a battery management system to prevent over-discharge and optimize performance.

## Future Work
  - **Advanced Sensor Integration:** Explore additional algorithms for obstacle avoidance and pathfinding
  
  - **Machine Learning:** Implement machine learning techniques for better decision-making and adaptive behaviors based on the robot's experiences.
    
  - **Battery Management System:** Develop a battery management system to monitor battery levels and optimize power consumption during operation.

## References
- **PCA9685 Library:** [Adafruit PWM Servo Driver Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)
  
- **MPU6050 Library:** [MPU6050 Library for Arduino](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)
  
- **PID Control:** [PID Controller Basics](https://en.wikipedia.org/wiki/PID_controller)
  
- **Bézier Curves:** [Understanding Bézier Curves](https://en.wikipedia.org/wiki/B%C3%A9zier_curve)

- **NVIDIA Jetson Nano Installation:** [Jetson Nano Setup Guide](https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-devkit)
