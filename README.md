# Egyemb_AVR_kit_Drivers
- This folder include all kit driver for EGYEMB kit 
- This Kit is based on Atmega16 which included:
      - Portable LCD 2X16
      - keypad 3x3
      - 2 push button connected to external interrupt
      - 2 internal LEDs.
      - Relay with led. 
      - Buzzer connected to PWM.
      - 9 to 5 volt Regulator. 
      - 2 variable resistance connected to ADC0 and ADC1.
      - Internal burner.
      - 2 seven segment with 7447 decoder
      - External EEPROM.
- Open Driver file and install Khazam and extreme burner
- Use Test.hex to check all Kit Hardware

- This derivers is compatible with Atmega16/32

- feel free to contact me in our official FB Page: https://www.facebook.com/egyemb/
- The package include USB Cable + Kit + 2 jumber with total Cost: 400LE ~= 25$


- About Test.hex Code:
--- Press on  pushbutton 1 : test Push button PINB3 and PINB2
--- Press on  pushbutton 2 : test 7-segment "note: put jumber 1 and 2 above seven segment 1 and 2 (JP3,JP4)"
--- Press on  pushbutton 3 : Toggle leds, buzzer and relay every 0.5 msec "Put jumber on led1, led2, relay and buzzer (JP5, JP6, JP2, JP1)"
--- Press on  pushbutton 4 : Test ADC0 
--- Press on  pushbutton 5 : Test ADC1

