🔌 Wiring

This project uses an Arduino, an I2C LCD, and a Servo motor.

📟 I2C LCD Connection
LCD Pin        	Arduino Pin
VCC	            5V
GND	            GND
SDA	            A4
SCL	            A5

The LCD uses I2C communication. Make sure the address is 0x27.


⚙️ Servo Motor Connection
Servo Wire	            Arduino Pin
Red (VCC)	              VIN
Brown/Black (GND)	      GND
Yellow/Orange (Signal)	D6



🍞 Breadboard Setup

Use the breadboard power rails to share 5V and GND.

Connect Arduino 5V → Breadboard + rail.

Connect Arduino GND → Breadboard – rail.

Connect LCD and Servo power to the rails.

This allows both components to receive power from the Arduino safely.

⚠️ Notes

Make sure all grounds (GND) are connected together.

If the LCD only shows a blue screen, check the contrast potentiometer.

If the LCD is not detected, verify SDA and SCL connections.

Avoid powering large servos directly from Arduino if unstable.
