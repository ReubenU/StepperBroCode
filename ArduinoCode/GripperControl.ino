#include <Servo.h>

Servo gripper;

int x = 90;

void setup()
{
	Serial.begin(115200);
	Serial.setTimeout(5);

	gripper.attach(9);
}

void loop()
{
	while (!Serial.available());
	x = 90;
	x = Serial.readString().toInt();

	x = map(x, -100, 100, 0, 180);

	delay(5);
	Serial.print(x);

	gripper.write(x);
}
