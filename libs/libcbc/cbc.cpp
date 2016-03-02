#include <iostream>

using namespace std;

namespace cbc
{
	enum Sensor
	{
		ANALOG,
		DIGITAL
	};
	 
	 const int MOTOR_LEFT = 0;
	 const int MOTOR_RIGHT = 3;
	 const int BUMP_SENSOR_LEFT = 8;
	 const int BUMP_SENSOR_RIGHT = 10;
	 const int LIGHT_SENSOR_LEFT = 0;
	 const int LIGHT_SENSOR_RIGHT = 2;
	 const int IR_SENSOR_LEFT = 3;
	 const int IR_SENSOR_RIGHT = 5;
	 
	 const int DEFAULT_VELOCITY = 200;
	 
	 
	 
	 void forward(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY)
	 {
		 while(ticks > 0)
		 {
			mav(MOTOR_LEFT, VELOCITY);
			mav(MOTOR_RIGHT, VELOCITY);
		 }
	 }
	 
	 
	 void backward(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY)
	 {
		 while(ticks > 0)
		 {
			mav(MOTOR_LEFT, -VELOCITY);
			mav(MOTOR_RIGHT, -VELOCITY);
		 }
	 }
	 
	 
	 void rotateRight(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY)
	 {
		 while(ticks > 0)
		 {
			mav(MOTOR_LEFT, VELOCITY);
			mav(MOTOR_RIGHT, -VELOCITY);
		 }
	 }
	 
	 
	 void rotateLeft(int ticks = 1, const int VELOCITY = DEFAULT_VELOCITY)
	 {
		 while(ticks > 0)
		 {
			mav(MOTOR_LEFT, -VELOCITY);
			mav(MOTOR_RIGHT, VELOCITY);
		 }
	 }
	 
	 
	 void turn(int ticks = 1, const int VELOCITY_LEFT = DEFAULT_VELOCITY, const int VELOCITY_RIGHT = DEFAULT_VELOCITY)
	 {
		 while(ticks > 0)
		 {
			 mav(MOTOR_LEFT, VELOCITY_LEFT);
			 mav(MOTOR_RIGHT, VELOCITY_RIGHT);
		 }
	 }
	 
	 
	 int* servo_left(const int SERVO_POINT = 0, const int MIN_VALUE = 5, const int MAX_VALUE = 2045, const int NUM_OF_VALUES = 408, const Sensor SENSOR = ANALOG, const int SENSOR_PORT = 0)
	 {
		 int array[NUM_OF_VALUES];
		 int count = MIN_VALUE;
		 int inc = (MAX_VALUE - MIN_VALUE) / NUM_OF_VALUES;
		 int index = 0;
		 
		 while(count < MAX_VALUE)
		 {
			 switch(SENSOR)
			 {
				 case ANALOG:
					 array[index] = analog(SENSOR_PORT);
				 case DIGITAL:
					 ;
				 default:
					 cerr << "INVALID sensor enumeration type @cbc::servo_left" << endl;
			 }
			 count += inc;
			 index++;
		 }
		 
		 return array;
	 }
	 
	 
	 int* servo_right(const int SERVO_POINT = 0, const int MIN_VALUE = 5, const int MAX_VALUE = 2045, const int NUM_OF_VALUES = 408, const Sensor SENSOR = ANALOG, const int SENSOR_PORT = 0)
	 {
		 ;
	 }
	 
	 
	 
	 
} // END of namespace cbc
 
 
 
 
 
 
//-----------------------------------testing----------------------------------------------
 int main()
 {
	 ;
	 
	 return 0;
 }
