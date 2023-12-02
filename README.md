# CSE321-2.4GHz_Jammer
Code, diagrams, and supporting documents for CSE 321: Real-time Embedded Systems.

# Usage of Codebase and Device
## Code base
In order to use the code base the RF24 Library must be installed. This library can be found on GitHub, link in 
references section, or on the Arduino Library. This library is maintained by THRh20 and should always use the latest 
version, however this code was made on version 1.4.8.
### Debugging
There is a function called debug which will hurt finally deployment functionality. However, it will be useful to use 
if you build your own. The function is commented out with the area of code it is relevant. You may also find it 
helpful to connect and enable a serial terminal with your Arduino as the code does give printouts that may prove 
helpful.

**Note:** The usage of serial terminal will give you updates that are hardcoded are should not lead to believe 
something is working. They are an indication, if they do not show up, that something is not working. This is purely 
to give you an idea of where code is being executed at what times not whether a section of code executed completely 
correct.
### Comments
Within the code there are comments explaining how things are done and why they are this way. Its highly recommend 
comments be reviewed before use.
### Note on hardware
Hardware will be addressed in the next section however certain code segments (all pins, especially the pin interrupt) 
are depended on the Arduino used. If a different Arduino is used then what the one used on this, please check with 
the Arduino documentation for new pins. Certain pins are also required to be used by the RF24 Library and have to be 
manually changed from their default.
## Hardware
This project uses an Arduino Uno R3 for its powersupply, microcontroller, and attachments. 2 LEDs and with 2 1k ohm 
resistors are also used for indicators. 1 tactile button is used for inputs. 1 NRF24L01 + PA/LNA is used as the 
transmitter. All connections are made to 1 mini breadboard with male to male and female to male wires. **Note:** 
Nothing is connected directly to the arduino without going through the breadboard.
### Limitation of NRF24L01 + PA/LNA
This device is powered by the 3.3v pin and is low in power. With a more powerful transmitter the range and strength 
would be very beneficial to performance. A more advanced transmitter may also be more effective in transmitting 
whether that be faster permanence in transmitting or chanel switching or the ability to transmit on more than channel 
at a time.

# Useage
When the Arduino is powered up the setup will begin and if connected to a serial interface several lines will print 
stating that certain phases of the setup have been completed. The red LED will light and stay light. Upon pressing 
the button down the main program will interrupt and execute a function that will allow the program to begin jamming. 
It will also turn on the green LED and the red LED off. Upon exiting the interrupt the main program will begin 
to transmit on a variety of channels. This will occur until an interrupt. Should there be an issue with transmitting,
ie a bad connection, the red LED will rapidly flash twice with the green light off and then return to the green 
light. The button can be pressed at any point to immediately halt the jamming at the end of the sequence. Angling 
the antenna can boost performance in certain circumstances.

# Schematics
![Architectural Block.drawio.png](..%2F..%2F..%2FDownloads%2FArchitectural%20Block.drawio.png)

# Citations
***
### Sources
1. Arduino Uno Rev3 Pinout Diagram: https://content.arduino.cc/assets/A000066-full-pinout.pdf
2. Mini Breadboard Diagram: https://static.javatpoint.com/blog/images/breadboard.png
3. NRF24L01 + PA/LNA Pinout Graphic: https://howtomechatronics.com/wp-content/uploads/2017/02/NRF24L01-Pinout-NRF24L01-PA-LNA-.png

### References
+ TMRh20,Avamander RF24: A NRF24L01+ Library [Software]. https://github.com/nRF24/RF24
+ Arduino Code Documentation: https://www.arduino.cc/reference/en/
+ Editorial Team - Everything RF. October 6, 2018. 2.4 GHz Wi-Fi 802.11b/g/n Channels and Frequency Band. 
  https://www.everythingrf.com/community/2-4-ghz-wi-fi-802-11b-g-n-channels-and-frequency-band

# Academic Integrity Violation Warning

This code repository is for educational and informational purposes only. Unauthorized copying, modification, distribution,
or any form of misuse of the code within this repository is strictly prohibited. Using any part of the code in this 
repository as your own in academic settings will be considered a violation of academic integrity policies.

By accessing this repository, you are agreeing to adhere to all applicable academic integrity guidelines set forth by
your educational institution or other governing bodies. The unauthorized use of this code, including copying, redistribution,
or modification, is not allowed. Any violation of this agreement could result in academic penalties, failure of the assignment,
course failure, or more severe academic sanctions.

By continuing to access this repository, you acknowledge that you have read and understood this disclaimer and agree to abide
by all the terms mentioned herein.
