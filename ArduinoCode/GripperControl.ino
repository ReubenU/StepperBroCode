#include <Servo.h>

Servo gripper;

// 
int gripper_speed = 90;

void setup()
{
	Serial.begin(115200);
	Serial.setTimeout(5);

	gripper.attach(9);
}


void loop()
{
	// Force loop to wait for Serial string input.
	while (!Serial.available());
	
	// Initialize servo speed to 0 (90 ms is the command pulse).
	gripper_speed = 90;
	// Read the serial string input and parse it to integer.
	gripper_speed = Serial.readString().toInt();

	// Map the input integer to a range between 0 and 180.
	// The integer input originally ranges from -100 to 100.
	gripper_speed = map(gripper_speed, -100, 100, 0, 180);

	// Millisecond delay to prevent timeout
	delay(5);
	Serial.print(gripper_speed);

	gripper.write(gripper_speed);
}
