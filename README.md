# AVRgo Boards and Programmers
AVRgo is a family of boards designed for on-the-go and in-the-field applications. Their bluetooth capability allows sketches to be uploaded and debugged via a multitude of devices without using wires, eg computer, smartphone, tablet, etc. The AVRgo-SerialBTx is a bluetooth programmer/debugger designed to give these capabilities to virtually all Arduino compatible AVRs that use a serial bootloader.

## AVRgo Boards
#### AVRgo-Infinity
The AVRgo-Infinity is the flagship board of the AVRgo family. It can be powered by its internal LiPo Battery or through the 5V USB port. A short listing of features and specifications are as follows...
- Dual Bootloader allows for uploading sketches via Bluetooth or Micro-SD card.
- Dual mode Bluetooth broadcasts both SPP and BLE, which can be connected to different devices simultaneuosly.
- Built in Micro-SD card slot with BinStacking capabilities (flashing sketches via Serial Command Line or from within another sketch)
- Integrated RGB LED allows for a customized look, as well as displaying information visually
- More on-board features, along with an extensive library allows for much greater capabilies than other developement boards, while requiring much less effort and/or experience.
- The internal 1800mAh LiPo battery with built-in charger provides more than enough power for most projects, wherever you need it.
- Triple Battery Protection Circuit allows for safe and optimal use of the LiPo battery by even the most inexperienced users.
  - Redundant Low Voltage Cutoff ensures the battery never drops to an unsafe voltage.
  - 900/1800mA Polyfuse disconnects the battery if current is exessively high (such as a short to ground) and can be reset by turning the board off for a few seconds.
  - Safe Storage Zener diode prevents the battery from being maintained above the Safe Storage Window (3.3-3.8V) for more than 48 hours, by slowly draining current when voltage is above 3.8V (±2%).
- Self-Discharge rate of 1% per month when within the Safe Storage Window
- 3.3V regulated operating voltage.
- Up to 200mA output current by default, with an additional 500mA available on-board by soldering the Boost jumper pads closed.
- Sleep current as low as 0.2uA
- 8mHz internal clock with convenient external clock capabilities
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
