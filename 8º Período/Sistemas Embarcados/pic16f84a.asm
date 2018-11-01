;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.7.0 #10231 (Linux)
;--------------------------------------------------------
	.module pic16f84a
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _write_PARM_2
	.globl _set_tris_PARM_2
	.globl _read
	.globl _write
	.globl _read_tris
	.globl _set_tris
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_set_tris_PARM_2:
	.ds 2
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_write_PARM_2:
	.ds 2
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'set_tris'
;------------------------------------------------------------
;value                     Allocated with name '_set_tris_PARM_2'
;tris                      Allocated to registers 
;------------------------------------------------------------
;	pic16f84a.h:226: extern void set_tris(int tris, int value) {
;	-----------------------------------------
;	 function set_tris
;	-----------------------------------------
_set_tris:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	pic16f84a.h:227: tris = value;
;	pic16f84a.h:228: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_tris'
;------------------------------------------------------------
;tris                      Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:230: extern int read_tris(int tris) {
;	-----------------------------------------
;	 function read_tris
;	-----------------------------------------
_read_tris:
;	pic16f84a.h:231: return tris;
;	pic16f84a.h:232: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write'
;------------------------------------------------------------
;value                     Allocated with name '_write_PARM_2'
;pin                       Allocated to registers 
;------------------------------------------------------------
;	pic16f84a.h:234: extern void write(int pin, int value) {
;	-----------------------------------------
;	 function write
;	-----------------------------------------
_write:
;	pic16f84a.h:235: pin = value;
;	pic16f84a.h:236: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read'
;------------------------------------------------------------
;pin                       Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:238: extern int read(int pin) {
;	-----------------------------------------
;	 function read
;	-----------------------------------------
_read:
;	pic16f84a.h:239: return pin;
;	pic16f84a.h:240: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
