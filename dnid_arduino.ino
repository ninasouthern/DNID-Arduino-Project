#include <Servo.h>

Servo myservo;

int pos = 0; // servo position variable
int pushButton1 = 12; // green push button
int pushButton2 = 11; // red push button
int LED1 = 3; // green LED
int LED2 = 4; // red LED
bool isLED1On = false; // track LED1 light state
bool isLED2On = false; // track LED2 light state

// the setup routine runs once when you press reset:
void setup() {

  // making servo object:
  myservo.attach(9);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // make the pushbuttons' pin an input:
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);

  // make the LEDs' pin an output:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  myservo.write(90);
}

// the loop routine runs over and over again forever:
void loop() {

  for(pos = 0; pos <= 180; pos += 1){
    myservo.write(pos);
    delay(15);
  }

  for(pos = 180; pos >= 0; pos -= 1){
    myservo.write(pos);
    delay(15);
  }

  // read the input pin:
  int buttonState1 = digitalRead(pushButton1);
  int buttonState2 = digitalRead(pushButton2);

  // control LED1 & servo when pushButton1 is pressed:
  if (buttonState1 == HIGH) { 
    digitalWrite(LED1, HIGH);
    Serial.println("Pushbutto1 pressed & LED 1 turned on");
    Serial.println(buttonState1);
  } else {
    digitalWrite(LED1, LOW);
  }

  // control LED1 & servo when pushButton1 is pressed:
  if (buttonState2 == HIGH) { 
    digitalWrite(LED2, HIGH);
    Serial.println("Pushbutton2 pressed & LED 2 turned on");
    Serial.println(buttonState2);
  } else {
    digitalWrite(LED2, LOW);
  }

  // print button state
  Serial.print("Button 1 state: ");
  Serial.println(buttonState1);
  Serial.print("Button 2 state: ");
  Serial.println(buttonState2);
  
  delay(1000);  // delay in between reads for stability
}
