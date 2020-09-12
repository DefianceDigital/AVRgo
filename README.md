# AVRgo Boards and Programmers
AVRgo is a family of boards designed for on-the-go and in-the-field applications. Their bluetooth capability allows sketches to be uploaded and debugged via a multitude of devices without using wires, eg computer, smartphone, tablet, etc. The AVRgo-SerialBTx is a bluetooth programmer/debugger designed to give these capabilities to virtually all Arduino compatible AVRs that use a serial bootloader.

## AVRgo Boards
#### AVRgo-Infinity
The AVRgo-Infinity is the flagship board of the AVRgo family. It can be powered by its internal LiPo Battery or through the 5V USB port. A short listing of features and specifications are as follows...
- Internal 1800mAh LiPo battery with built-in charger
- Dual low-voltage cutoff circuits prevent battery damage due to over-discharge
- 3.3V regulated operating voltage.
- Up to 200mA output current when powered by battery and 700mA when plugged in
- Built in Micro-SD card slot 
- Dual Bootloader allows for uploading/debugging sketches via on-board bluetooth or Micro-SD card.
- Uses ATMEGA1284P AVR
- 8mHz Clock
- 120kB Flash Memory
- 16kB Ram
- 4kB EEPROM
#### AVRgo-Switch
The AVRgo-Switch is a powerful developement board with a selectable operating voltage. It can be run at either 3.3V or 5V with the flip of a switch, making it one of the most versatile development board in existence. A short listing of features and specifications are as follows...
- Breadboard-friendly design makes projects a breeze
- Selectable 3.3V or 5V regulated operating voltage virtually eliminates any need for level-shifters to communicate with other boards or sensors
- Up to 800mA output current at either operating voltage
- Built in Micro-SD card slot 
- Dual Bootloader allows for uploading/debugging sketches via on-board bluetooth or Micro-SD card.
- Uses ATMEGA1284P AVR
- 8mHz Clock
- 120kB Flash Memory
- 16kB Ram
- 4kB EEPROM
#### AVRgo-Vitality
The AVRgo-Vitality is designed for non-rechargeable battery powered applications with a long service life (up to 10+ years). As most 3.3V sensors and modules have an operating voltage of 1.8-3.6V, no regulator is required. A short listing of features and specifications are as follows...
- Comes in Stand-alone(female headers) or Breadboard(XL male pins) packages
- Uses 2 AAA batteries
- Operating Voltage: 1.8-3.2V(direct battery voltage)
- Battery Capacity: 1000mAh(typical)
- Maximum recommended output current: 500mA
- Power consumption down to nanoAmp scale
- Low-battery indicator light consumes ultra-low current when enabled(default) and no current when disabled
- Bootloader allows sketches to be uploaded/debugged via on-board bluetooth
- Uses ATMEGA328PB AVR
- 8mHz Clock
- 30kB Flash Memory
- 2kB Ram
- 1kB EEPROM

## AVRgo Programmers
#### AVRgo-SerialBTx
The AVRgo-SerialBTx is a bluetooth programmer/debugger that allows virtually any Arduino Compatible Development Board to essentially become an AVRgo. A short listing of features and specifications are as follows...
- Ability to upload sketches via bluetooth to virtually any AVR based development board with a serial bootloader, using a computer, phone or tablet
- Ability to run Serial Monitor wirelessly, makes debugging a breeze
- 3.3V operating voltage with 5V tolerant TX/RX pins
- Simple to setup and operate

# Installing AVRgo Boards and Programmers in the Arduino IDE
- Open the Arduino IDE
- Click the File tab
- Scroll down and click Preferences
- In the Additional Board Manager URLs textbox paste "https://raw.githubusercontent.com/DefianceDigital/AVRgo/master/package_avrgo_index.json" and press ok
- Click the Tools tab and scroll down to Board and over to and select Boards Manager
- In the drop-down box, select Contributed
- Scroll down to AVRgo-Boards-and-Programmers and select Install
- Click Close when installation is finished
