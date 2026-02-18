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


📟 RFID-RC522 Connection
RFID-RC522    	Arduino Pin
3.3V            3.3V
GND	            GND
SDA	           ~10
SCK	            13
MOSI           ~11
MISO            12
RST            ~9



⚠️ Notes

If the LCD only shows a blue screen, check the contrast potentiometer.

Avoid powering large servos directly from Arduino if unstable.
