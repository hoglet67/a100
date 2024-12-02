A collection of notes and experiment concerning the BridgeCo/Microchip
CX870 WiFi module that's used in various audio poducts (AV receivers,
Streaming Amplifiers, Internet Radios).

The CX870 module uses the DM850A chipset.

My goal was to be able to replace a failed board in a Monitor Audio
Airstream A100 Amplifier.

I've obtained three working CX870-3IB boards from AliExpress, but
containing difference firmware to what's expeced by the A100.


Some useful links:

Monitor Audio User Manual:
https://www.monitoraudio.com/site/assets/files/20020/a100-manual-en.pdf

Monitor Audio v632 Firmware:
https://web.archive.org/web/20150425004308/http://www.monitoraudiousa.com/assets/files/firmware/a100_6.3.2.zip

Monitor Audio v639 Firmware:
https://web.archive.org/web/20160505231108if_/http://ca2.monitoraudiocdn.com/downloads/firmware/A100-Firmware-v639.zip?mtime=20150529123549

AVForums thread that contains a copy of the v639 firmware:
https://www.avforums.com/threads/monitor-audio-a100-owner-experience.1910441/page-3#post-27048179

FCC Documentation:
https://fcc.report/FCC-ID/PPQ-CX8703MB/2117592.pdf

Microchip Jukeblox 2.1 Product Brief
https://ww1.microchip.com/downloads/jp/DeviceDoc/jukeblox2_1fs.pdf

Another reverse engineering effort:
https://github.com/loop333/pioneer-x-smc55/tree/master

A tool that parses the BCD firmware image file format:
https://github.com/benburkhart1/wml11b-firmware-tool

Some C++ code that uses ICSP to program a PIC24F from a Pi:
https://github.com/andyHa/OpenCobra
