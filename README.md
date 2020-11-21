# AVRgo Boards and Programmers
AVRgo is a family of boards designed for on-the-go and in-the-field applications. Their bluetooth capability allows sketches to be uploaded and debugged via a multitude of devices without using wires, eg computer, smartphone, tablet, etc. The AVRgo-SerialBTx is a bluetooth programmer/debugger designed to give these capabilities to virtually all Arduino compatible AVRs that use a serial bootloader.

## AVRgo Boards
#### AVRgo-Infinity
*Anticipated Launch Date: February 12th, 2021*

The AVRgo-Infinity originated with two primary goals. To be completely cordless and to be a board built with EVERYBODY in mind. It's not a design for beginners or for advanced users. It's a design that grows with you, from beginner to advanced user and can be picked up anywhere in between. Whether your're designing the next wearable device, an AVR-based handheld gaming system, or just learning how to turn on LEDs; The AVRgo-Infinity is designed for you. The library we developed to accompany this board is extensive, and it makes complicated tasks incredibly easy.
- Dual Bootloader allows for uploading sketches via Micro-SD Card, or directly from the Arduino IDE over Bluetooth.
- The Bluetooth Electronics App allows you to control your AVRgo-Infinity and select sketches via any android device (examples provided).
- The ArduinoDroid App allows you to compile and upload sketches directly from any Android device (under development)
- Dual mode Bluetooth broadcasts both SPP and BLE signals, which can be connected to different devices simultaneuosly.
- Built in Micro-SD card slot with BinStacking capabilities (flashing sketches via Serial Command Line or from within another sketch)
- Integrated RGB LED allows for a customized look, as well as displaying information visually
- More on-board features, along with an extensive library allows for much greater capabilies than other developement boards, while requiring much less effort and/or experience.
- The internal 3000mAh LiPo battery with built-in charger provides all the power you need, wherever you need it.
- Triple Battery Protection Circuit allows for optimal use of the LiPo battery by even the most inexperienced users.
  - Redundant Low Voltage Cutoff ensures the battery never drops to a damaging voltage.
  - 900/1800mA Polyfuse disconnects the battery if current is exessively high (such as a short to ground) and can be reset by turning the board off for a few seconds.
  - Immediately following a complete charge, the charging circuit is disabled and battery will begin to drain to Optimal Maximum Voltage of 3.9V (if left plugged in)
- Unlike most LiPo-based pruducts, the AVRgo-Infinity can be left plugged in indefinitely without damage, due to its battery protection circuit.
- LiPo Self-Discharge rate is less than 1% per month when within the Safe Storage Window
- Integrated charging LEDs let you know when the battery is fully charged
- 3.3V regulated operating voltage.
- Up to 200mA output current on-board, with an additional 500mA available by connecting the Current-Expansion board (included standard).
- Sleep current as low as 1uA
- JTAG funtionality (fuse set to disable by default)
- 8mHz internal clock with convenient external clock capabilities
- 120kB Flash Memory
- 16kB Ram
- 4kB EEPROM

#### AVRgo-Beyond
Anticipated Release Date: February 2022
- All the same features of the AVRgo-Infinity, but 4X faster and double the flash

## AVRgo Expansion Modules
#### AVRgo-SerialBTx
*Anticipated Launch Date: February 12th, 2021*

The AVRgo-SerialBTx is the Bluetooth portion of the AVRgo-Infinity, but in it's own high-performance module. Not only can it wirelessly upload sketches to virtually any Arduino with a serial bootloader, but it can do just about anything you could ever want from a Bluetooth module. We worked very dilligently to be able to say with confidence that this is the best all-around Bluetooth module on the market. A short listing of features and specifications are as follows...
- Reset pin automatically resets the target board upon connecting/uploading
- Simple to setup and operate
- Communication Interface: UART (serial)
- Operating Mode: Dual-Mode (SPP/BLE)
- Role: Master/Slave
- Working Voltage: 3.3V-5V
- Maximum Range: 40 meters
- Operating Current: 15mA
- Sleep Current: 25nA

# Installing AVRgo in the Arduino IDE
- Open the Arduino IDE
- Click the File tab
- Scroll down and click Preferences
- In the Additional Board Manager URLs textbox paste "https://raw.githubusercontent.com/DefianceDigital/AVRgo/master/package_avrgo_index.json" and press ok
- Click the Tools tab and scroll down to Board and over to and select Boards Manager
- In the drop-down box, select Contributed
- Scroll down to AVRgo and select Install
- Click Close when installation is finished
