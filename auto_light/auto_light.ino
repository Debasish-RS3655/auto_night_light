#include <Ultrasonic.h>

#define SENSOR_PIN 2
#define RELAY_PIN LED_BUILTIN

const int Trig = 6;
const int Echo = 7;

Ultrasonic ultrasonic(Trig, Echo); //Trigger and Echo respectively

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.Ranging(CM); // (Use CM for centimeter and INC for inches)
  delay(40);    // delay added to make things stable
  int sensorValue = digitalRead(SENSOR_PIN);
  deMlay(40);

  if (sensorValue == HIGH || distance < 40) {
    digitalWrite(RELAY_PIN, HIGH); // LOW to switch on the light
    digitalWrite(LED_BUILTIN, HIGH);
    if (sensorValue == HIGH)Serial.println("motion detected");
    Serial.println("Light ON");
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
    
  //  if (distance < 40) digitalWrite(LED_BUILTIN, HIGH);
  //  else digitalWrite(LED_BUILTIN, LOW);
  //  delay (50);// check for objects
  
  Serial.println(distance);
}
