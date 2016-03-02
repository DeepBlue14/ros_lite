/**
 * File: cbc.hpp
 * Authors: James Kuczynski James_Kuczynski@student.uml.edu and Justin Wood Justin_Wood@student.uml.edu
 * File Description: 
 *
 * Created: 2/10/2016
 * Last Modified: 2/12/2016
 */
 
 namespace cbc
 {
	 extern enum Sensor
	 {
		 ANALOG,
		 DIGINAL
	 };
	 
	 extern const int MOTOR_LEFT = 0; /** The motor port the left motor is plugging into. */
	 extern const int MOTOR_RIGHT = 3; /**  */
	 extern const int BUMP_SENSOR_LEFT = 8;
	 extern const int BUMP_SENSOR_RIGHT = 10;
	 extern const int LIGHT_SENSOR_LEFT = 0;
	 extern const int LIGHT_SENSOR_RIGHT = 2;
	 extern const int IR_SENSOR_LEFT = 3;
	 extern const int IR_SENSOR_RIGHT = 5;
	 
	 extern const int DEFAULT_VELOCITY = 200;
	 
	 /**
	  *
	  *
	  * @param VELOCITY
	  */
	 extern void forward(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 /**
	  *
	  *
	  * @param VELOCITY
	  */
	 extern void backward(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 /**
	  *
	  *
	  * @param VELOCITY
	  */
	 extern void rotateRight(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 /**
	  *
	  *
	  * @param VELOCITY
	  */
	 extern void rotateLeft(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 
	 /**
	  *
	  *
	  * @param ticks
	  * @param VELOCITY
	  */
	 extern void rotateLeft(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 /**
	  *
	  *
	  * @param ticks
	  * @param VELOCITY
	  */
	 extern void rotateRight(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY);
	 
	 /**
	  * 
	  *
	  * @param ticks
	  * @param VELOCITY_LEFT
	  * @param VELOCITY_RIGHT
	  */
	 extern void turn(int ticks = 1, const int VELOCITY_LEFT = DEFAULT_VELOCITY, const int VELOCITY_RIGHT = DEFAULT_VELOCITY);
	 
	 
	 /**
	  * 
	  *
	  */
	 extern int* servo_left(const int SERVO_POINT = 0, const int MIN_VALUE = 5, const int MAX_VALUE = 2045, const int NUM_OF_VALUES = 408, const Sensor SENSOR = ANALOG, const int SENSOR_PORT = 0);
	 
	 
	 /**
	  *
	  *
	  */
	 extern int* servo_right(const int SERVO_POINT = 0, const int MIN_VALUE = 5, const int MAX_VALUE = 2045, const int NUM_OF_VALUES = 408, const Sensor SENSOR = ANALOG, const int SENSOR_PORT = 0);
	 

	 
	 
 }
