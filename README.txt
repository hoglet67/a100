A collection of notes and experiment concerning the BridgeCo/Microchip
CX870 WiFi module that's used in various audio poducts (AV receivers,
Streaming Amplifiers, Internet Radios).

The CX870 module uses the DM850A chipset.

My goal was to be able to replace a failed board in a Monitor Audio
Airstream A100 Amplifier.

I've obtained three working CX870-3IB boards from AliExpress, but
containing difference firmware to what's expeced by the A100.


Some useful links:

FCC Documentation:
https://fcc.report/FCC-ID/PPQ-CX8703MB/2117592.pdf

Microchip Jukeblox 2.1 Product Brief
https://ww1.microchip.com/downloads/jp/DeviceDoc/jukeblox2_1fs.pdf

Another reverse engineering effort:
https://github.com/loop333/pioneer-x-smc55/tree/master

A tool that parses the BCD firmware image file format:
https://github.com/benburkhart1/wml11b-firmware-tool
