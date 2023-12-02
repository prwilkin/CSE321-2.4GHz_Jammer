#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE on Pin 7, CSN on Pin 8
const byte address[6] = "00001"; //meaningless but required
char payload[] = "Hello World"; //experiment with packet size
bool running = false;

void setup() {
  // debug with println
  Serial.begin(9600);
  Serial.println("Hello World");

  // Lights
  pinMode(4, OUTPUT); // Pin 4 green led
  pinMode(5, OUTPUT); // Pin 5 red led
  digitalWrite(5, HIGH); //red on
  Serial.println("Set Light: @");

  /* Button
  Button acts as a hardware interrupt. When pressed interruptHanlder is called to process function.
  The interrupt is set to trggier on FALLING (FALLING for when the pin goes from high to low.) since
  the pin is high on idle a press down triggers it. Other options:
  LOW to trigger the interrupt whenever the pin is low,
  CHANGE to trigger the interrupt whenever the pin changes value,
  RISING to trigger when the pin goes from low to high
  */
  pinMode(3, INPUT_PULLUP);  // Pin 3 button    High = 1 (True) Low = 0 (False)
  attachInterrupt(digitalPinToInterrupt(3), interruptHanlder, FALLING); // Interrupt
  Serial.println("Set Button: @");

  // NRF24L01
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  radio.setAutoAck(false); // for debug only
  Serial.println("Set Radio: @");

  Serial.println("Set up complete");
}

void loop() {
  if(running == true) {
    // www.everythingrf.com/community/2-4-ghz-wi-fi-802-11b-g-n-channels-and-frequency-band
    // Center Freq - 2400 to get channel on NRF mod
    jam(12);  //WiFi channel 1    Bluetooth channel 4
    //jam(17);  //WiFi channel 2    Bluetooth channel 6-7
    jam(22);  //WiFi channel 3    Bluetooth channel 9
    //jam(27);  //WiFi channel 4    Bluetooth channel 11
    jam(32);  //WiFi channel 5    Bluetooth channel 13
    //jam(37);  //WiFi channel 6    Bluetooth channel 15-16
    jam(42);  //WiFi channel 7    Bluetooth channel 18
    //jam(47);  //WiFi channel 8    Bluetooth channel 20-21
    jam(52);  //WiFi channel 9    Bluetooth channel 23
    //jam(57);  //WiFi channel 10   Bluetooth channel 25-26
    jam(62);  //WiFi channel 11   Bluetooth channel 28
    //jam(67);  //WiFi channel 12   Bluetooth channel 30-31
    jam(72);  //WiFi channel 13   Bluetooth channel 33
    //jam(77);  //WiFi channel 14   Bluetooth channel 35-36
  }
}

void on() {
  digitalWrite(5, LOW); //red off
  digitalWrite(4, HIGH); // green on
}

void off() {
  digitalWrite(4, LOW); // green off
  digitalWrite(5, HIGH); //red on
}

void jam(int channel) {
  radio.setChannel(channel);
    const bool result = radio.write(&payload, sizeof(payload));
    // debug(result);
    if (!result) {
        error();
    }
}

void error() {
  Serial.println("Data sending failed");
  // flash red light twice
  off();
  delay(100);
  digitalWrite(3, LOW); //red off
  delay(100);
  digitalWrite(3, HIGH); //red on
  delay(100);
  on();
  delay(50);
}

void interruptHanlder() {
  if (running == false) {
    on();
    running = true;
    Serial.println("begin");
  }
  else if (running == true) {
    Serial.println("halted");
    off();
    running = false;
  }
  delay(300);
}

void debug(int result) {
  if (result) {
        Serial.println("Data sent successfully");
    } else {
        error();
    }
}