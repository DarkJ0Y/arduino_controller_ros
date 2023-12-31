#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def rotate_servo_motor(command):
    # Publish the command to the 'servo_command' topic
    rospy.loginfo("Sending command: %s", command)
    pub.publish(command)

if __name__ == '__main__':
    try:
        rospy.init_node('servo_motor_gurai', anonymous=True)
        pub = rospy.Publisher('servo_command', String, queue_size=10)

        rate = rospy.Rate(1)  # 1 Hz, adjust as needed

        while not rospy.is_shutdown():
            # Get user input to send commands
            user_input = input("Enter command ('clock 20' or 'anti 20'): ")
            rotate_servo_motor(user_input)

            rate.sleep()

    except rospy.ROSInterruptException:
        pass
