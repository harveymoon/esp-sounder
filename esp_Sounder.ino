/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
*/
#define NOOFCHIRPS        6   // The number of 'beeps' in a chirp
#define SPEAKERPIN        D7 // Pin with the piezo speaker attached
#define CHIRPFREQ        2600  // The frequency of the chirp

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(SPEAKERPIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  tickSound();
  delay(1000);              // wait for a second
  churpSound();
  delay(1000);
  churpSound2();
  delay(1000);
    churpSound3();
  delay(1000);

}

void tickSound() {
  digitalWrite(SPEAKERPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
  digitalWrite(SPEAKERPIN, LOW);    // turn the LED off by making the voltage LOW
}


void churpSound() {

  for (int i = 0; i < NOOFCHIRPS; i++)
  {
    tone(SPEAKERPIN, CHIRPFREQ, 30);
    delay(60);
  }
  noTone(SPEAKERPIN);
}

void churpSound2() {
  int crickets = 600;
  int chirp = 50;
  analogWrite(SPEAKERPIN, crickets);
  delayMicroseconds(chirp);
  analogWrite(SPEAKERPIN, 0);
  delayMicroseconds(chirp);
}

void churpSound3() {
for(int i = 0; i < 20; i += 2)
    {
      delay(i);
      digitalWrite(SPEAKERPIN, LOW);
      delay(20 - i);
      digitalWrite(SPEAKERPIN, HIGH);
    }
}
