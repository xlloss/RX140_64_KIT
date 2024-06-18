PLEASE REFER TO THE APPLICATION NOTE FOR THIS MODULE FOR MORE INFORMATION

r_ctsu_qe
=================

Document Number 
---------------
r01an4469jj0210

Version
-------
v2.10

Overview
--------
A simple Application Program Interface (API) has been created to allow users of
RX100 and RX200 and RX600 Series devices with the CTSU peripheral to easily integrate 
capacitive touch capabilities into their applications. Requires Touch QE FIT driver
for full operation.

Features
--------
* Self capacitance measurement
* Mutual capacitance measurement
* Multiple configurations (methods) supported within a single application
* Uses initialization data from QE Tool for Capacitive Touch
* diagnosis function support.
* Temperature correcttion function support.
* MEC function support.
* Automatic correction support.
* Automatic judgement support.
 

Supported MCUs
--------------
* RX113 Group
* RX130 Group
* RX140 Group
* RX230 Group
* RX231 Group
* RX23W Group
* RX671 Group


Boards Tested On
----------------
* RX130 Capacitive Touch Kit
* RSKRX231
* RX140 Capacitive Touch Kit


Limitations
-----------
-


Peripherals Used Directly
-------------------------
* CTSU


Required Packages
-----------------
* r_bsp       v6.20
* r_touch_qe  v2.10


Toolchain(s) Used
-----------------
* Renesas CC-RX 3.03


File Structure
--------------
r_ctsu_qe (v2.10)
|   +-- readme.txt
|   +-- r_ctsu_qe_if.h (v2.10)

+---src
|   +-- r_ctsu_qe.h (v2.10)
|   +-- r_ctsu_qe_api.h (v2.10)
|
+---src
    +-- r_ctsu_qe.c (v2.10)

r_config
    r_ctsu_qe_config.h (v2.10)

