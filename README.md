# IoST
The Internet of Stranger Things (IoST) is an IoT project using the Blynk service, the Arduino compatible Adafruit Feather WiFi board,  and WS2811 individually programmable LEDs. Other optional components are included in this particular build of the project that do not effect its overall functionality. Such items will be described within the source code.

You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino 101 or compatable board
      (Adafruit Feather M0 Board used)
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)
   - Individually Addressable LED string compatable
     with Adafruit_Neopixel library. 
      (WS2811 LEDs used)
   - 5V Wall Adapter
      (Used to power WS2811)
   - 1x 560 Ohm 5% 1/4W Resistor
      (Can be slightly lower of higher. Used for Data
       Line.)
   - Breadboard
   - Male to Male Jumper Wires
   - 1000 uF Capacitor
      (Power Supply Noise Reduction)

  Required Equipment for Adafruit Feather M0 Board
   - 1x USB Cable - A/Micro B
   - 1x 3.3v to 5v Logic Level Shifter
  
  Optional Hardware Used
   - 2x 10K 5% 1/4W Resistors
      (Used in Safety Circuit)
   - 1x Diffused 10mm Red LED
      (5V Power Indicator: OFF)
   - 1x Diffused 10mm Green LED
      (5V Power Indicator: ON)
   - 1x Breadboard-friendly SPDT Slide Switch
      (5V Power Switch)
   - 1x FeatherWing OLED - 128x32 OLED
