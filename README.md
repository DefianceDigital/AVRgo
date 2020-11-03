# AVRgo Boards and Programmers
AVRgo is a family of boards designed for on-the-go and in-the-field applications. Their bluetooth capability allows sketches to be uploaded and debugged via a multitude of devices without using wires, eg computer, smartphone, tablet, etc. The AVRgo-SerialBTx is a bluetooth programmer/debugger designed to give these capabilities to virtually all Arduino compatible AVRs that use a serial bootloader.

## AVRgo Boards
#### AVRgo-Infinity
The AVRgo-Infinity is the flagship board of the AVRgo family. It can be powered by its internal LiPo Battery or through the 5V USB port. A short listing of features and specifications are as follows...
- Internal 1800mAh LiPo battery with built-in charger
- Triple Battery Protection Circuit allows safe and optimal use of LiPo battery by even the most inexperienced users.
  - Redundant Low Voltage Cutoff ensures the battery never drops to an unsafe voltage.
  - 900/1800mA Polyfuse disconnects battery if current gets too high (such as a short to ground) and can be reset by turning the board off for a few seconds.
  - Safe Storage Zener diode ensures the battery cannot be stored at full charge for more than 2 weeks by slowly draining current if voltage is above 3.85V
- 3.3V regulated operating voltage.
- Up to 200mA output current when powered by battery and 700mA when plugged in
- Built in Micro-SD card slot 
- Dual Bootloader allows for uploading/debugging sketches via on-board bluetooth or Micro-SD card.
- Uses ATMEGA1284P AVR
- 8mHz Clock
- 120kB Flash Memory
- 16kB Ram
- 4kB EEPROM

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
