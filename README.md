# line_follower_robot
The software used to program the robot uses the two IR sensors to determine how the robot
should move based on its readings from the floor. In addition, the LCD display presents the
current movement state of the robot. In the beginning of the program, all of the components
are initialized, including the LCD screen and the location of the pins for each component as
well as their respective pin modes. A description of each line of code is
presented in .ino file to better understand this process.

In the loop function, the movement of the robot is dependent on the readings given by both IR
sensors. The LCD screen is used to display the current movement state of the robot based on
the IR sensors. In the beginning of the loop function, the digital readings of the IR sensors
are assigned to their respective variables. The series of if-else will cause the robot to
either move forward, right, left, or come to a full stop. The LCD screen is updated in each
if-else statement by displaying the current movement state as "RIGHT", "LEFT", or "STOP".

Three sources were referenced to assist in creating the program:
https://create.arduino.cc/projecthub/Raushancpr/arduino-with-ir-sensor-1579b6
This leads to a page which shows how to use IR sensors as well as sample code to accompany it.

https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5
This link shows how to use the 1298N Motor Driver for the Arduino as well as sample code to
accompany it.

https://create.arduino.cc/projecthub/saher-iqbal/line-follower-robot-36516b
This shows a robot which uses IR sensors to create a line follower robot. Sample code is shown
to demonstrate how it works.
