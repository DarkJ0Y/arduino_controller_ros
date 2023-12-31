#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  // read the incoming data until newline character
    Serial.print("Received command: ");
    Serial.println(command);

    // Check the command and control the servo accordingly
    if (command.startsWith("clock ")) {
      int degrees = command.substring(6).toInt();  // Extract the numeric value after "clock "
      rotateClockwise(degrees);
    } else if (command.startsWith("anti ")) {
      int degrees = command.substring(5).toInt();  // Extract the numeric value after "anti "
      rotateAntiClockwise(degrees);
    } else {
      Serial.println("Unknown command");
    }
  }
}

void rotateClockwise(int degrees) {
  myservo.write(myservo.read() + degrees);
}

void rotateAntiClockwise(int degrees) {
  myservo.write(myservo.read() - degrees);
}
