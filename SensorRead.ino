int volts;
int miliVolts;
const int ANALOG_READ_PIN = 36; // or A0
const int RESOLUTION = 12; // 0-4096

void setup() {
  Serial.begin(115200);
    analogReadResolution(RESOLUTION);
}

void loop() {
  volts = analogRead(ANALOG_READ_PIN);
  miliVolts = analogReadMilliVolts(ANALOG_READ_PIN);
  Serial.printf("ADC analog value = %d\n",volts);
  Serial.printf("ADC millivolts value = %d\n",miliVolts);
  delay(1000);  // wait 1 second
}
