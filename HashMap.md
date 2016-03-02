
 |   Topic               |   function                       |   Type    | 
 | --------------------- | -------------------------------- | --------- |
 | ```/motor_0/send```   | ```mav(0, msg)```                | Publish   |
 | ```/motor_1/send```   | ```mav(1, msg)```                | Publish   |
 | ```/motor_2/send```   | ```mav(2, msg)```                | Publish   | 
 | ```/motor_3/send```   | ```mav(3, msg)```                | Publish   |
 | ```/analog_0/recv```  | ```analog(0)```                  | Subscribe |
 | ```/analog_1/recv```  | ```analog(1)```                  | Subscribe |
 | ```/analog_2/recv```  | ```analog(2)```                  | Subscribe |
 | ```/analog_3/recv```  | ```analog(3)```                  | Subscribe |
 | ```/analog_4/recv```  | ```analog(4)```                  | Subscribe |
 | ```/analog_5/recv```  | ```analog(5)```                  | Subscribe |
 | ```/analog_6/recv```  | ```analog(6)```                  | Subscribe |
 | ```/analog_7/recv```  | ```analog(7)```                  | Subscribe |
 | ```/digital_0/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_1/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_2/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_3/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_4/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_5/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_6/recv``` | ```digital10(0)```               | Subscribe |
 | ```/digital_7/recv``` | ```digital10(0)```               | Subscribe |
 | ```/servo_0/send```   | ```set_servo_position(0, msg)``` | Publish   |
 | ```/servo_0/recv```   | ```get_servo_position(0)```      | Subscribe |
 
 
 
 =====
 
*lab5 requires:*
 - analog(0)    //sonar sensor RECV
 - servo(0)     //servo        SEND
 - mav(0, VEL)  //left motor   SEND
 - mav(3, VEL)  //right motor  SEND
 
have a subscriber filling a 5-index array.
In the callback:
- move servo
- drive
- sleep subscriber thread.  (when the thread wakes up, it will read from the sonar
