#define MQ3pin A0

int sensorValue;  //variable to store sensor value

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	delay(200); // allow the MQ2 to warm up
}

void loop() {
	sensorValue = analogRead(MQ3pin); 
	float val =sensorValue*(5.0/1023.0);// read digital output pin
	Serial.print("Analog Voltage: ");
	Serial.print(val);
	
	// Determine the status
	if (val>3.5) {
		digitalWrite(2,HIGH);
	} else {
		digitalWrite(2,LOW);
	}
	
	delay(2000); // wait 2s for next reading
}