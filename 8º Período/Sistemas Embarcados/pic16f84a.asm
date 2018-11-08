;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.7.0 #10231 (Linux)
;--------------------------------------------------------
	.module pic16f84a
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _set_pin_PARM_2
	.globl _write_port_tris_PARM_2
	.globl _set_tris_PARM_2
	.globl _set_prescaler
	.globl _clear_tmr0_int
	.globl _disable_tmr0_int
	.globl _enable_tmr0_int
	.globl _clear_rb_int
	.globl _disable_rb_int
	.globl _enable_rb_int
	.globl _clear_ext_int
	.globl _disable_ext_int
	.globl _enable_ext_int
	.globl _disable_global_int
	.globl _enable_global_int
	.globl _read_pin
	.globl _set_pin
	.globl _read_port_tris
	.globl _write_port_tris
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
_write_port_tris_PARM_2:
	.ds 2
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_set_pin_PARM_2:
	.ds 2
	.area	OSEG    (OVR,DATA)
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
_set_prescaler_sloc0_1_0:
	.ds 1
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
;	pic16f84a.h:265: extern void set_tris(int tris, int value) {
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
;	pic16f84a.h:266: tris = value;
;	pic16f84a.h:267: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_tris'
;------------------------------------------------------------
;tris                      Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:269: extern int read_tris(int tris) {
;	-----------------------------------------
;	 function read_tris
;	-----------------------------------------
_read_tris:
;	pic16f84a.h:270: return tris;
;	pic16f84a.h:271: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_port_tris'
;------------------------------------------------------------
;port_bits                 Allocated with name '_write_port_tris_PARM_2'
;tris                      Allocated to registers 
;------------------------------------------------------------
;	pic16f84a.h:273: extern void write_port_tris(int tris, int port_bits) {
;	-----------------------------------------
;	 function write_port_tris
;	-----------------------------------------
_write_port_tris:
;	pic16f84a.h:274: tris = port_bits;
;	pic16f84a.h:275: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_port_tris'
;------------------------------------------------------------
;tris                      Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:277: extern int read_port_tris(int tris) {
;	-----------------------------------------
;	 function read_port_tris
;	-----------------------------------------
_read_port_tris:
;	pic16f84a.h:278: return tris;
;	pic16f84a.h:279: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_pin'
;------------------------------------------------------------
;value                     Allocated with name '_set_pin_PARM_2'
;pin                       Allocated to registers 
;------------------------------------------------------------
;	pic16f84a.h:281: extern void set_pin(int pin, int value) {
;	-----------------------------------------
;	 function set_pin
;	-----------------------------------------
_set_pin:
;	pic16f84a.h:282: pin = value;
;	pic16f84a.h:283: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_pin'
;------------------------------------------------------------
;pin                       Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:285: extern int read_pin(int pin) {
;	-----------------------------------------
;	 function read_pin
;	-----------------------------------------
_read_pin:
;	pic16f84a.h:286: return pin;
;	pic16f84a.h:287: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'enable_global_int'
;------------------------------------------------------------
;	pic16f84a.h:289: extern void enable_global_int() {
;	-----------------------------------------
;	 function enable_global_int
;	-----------------------------------------
_enable_global_int:
;	pic16f84a.h:290: INTCON_bits.GIE = 0x1;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	orl	a,#0x01
	mov	@r0,a
;	pic16f84a.h:291: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disable_global_int'
;------------------------------------------------------------
;	pic16f84a.h:293: extern void disable_global_int() {
;	-----------------------------------------
;	 function disable_global_int
;	-----------------------------------------
_disable_global_int:
;	pic16f84a.h:294: INTCON_bits.GIE = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xfe
	mov	@r0,a
;	pic16f84a.h:295: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'enable_ext_int'
;------------------------------------------------------------
;	pic16f84a.h:297: extern void enable_ext_int() {
;	-----------------------------------------
;	 function enable_ext_int
;	-----------------------------------------
_enable_ext_int:
;	pic16f84a.h:298: INTCON_bits.INTE = 0x1;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	orl	a,#0x08
	mov	@r0,a
;	pic16f84a.h:299: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disable_ext_int'
;------------------------------------------------------------
;	pic16f84a.h:301: extern void disable_ext_int() {
;	-----------------------------------------
;	 function disable_ext_int
;	-----------------------------------------
_disable_ext_int:
;	pic16f84a.h:302: INTCON_bits.INTE = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xf7
	mov	@r0,a
;	pic16f84a.h:303: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'clear_ext_int'
;------------------------------------------------------------
;	pic16f84a.h:305: extern void clear_ext_int() {
;	-----------------------------------------
;	 function clear_ext_int
;	-----------------------------------------
_clear_ext_int:
;	pic16f84a.h:306: INTCON_bits.INTF = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xbf
	mov	@r0,a
;	pic16f84a.h:307: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'enable_rb_int'
;------------------------------------------------------------
;	pic16f84a.h:309: extern void enable_rb_int() {
;	-----------------------------------------
;	 function enable_rb_int
;	-----------------------------------------
_enable_rb_int:
;	pic16f84a.h:310: INTCON_bits.RBIE = 0x1;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	orl	a,#0x10
	mov	@r0,a
;	pic16f84a.h:311: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disable_rb_int'
;------------------------------------------------------------
;	pic16f84a.h:313: extern void disable_rb_int() {
;	-----------------------------------------
;	 function disable_rb_int
;	-----------------------------------------
_disable_rb_int:
;	pic16f84a.h:314: INTCON_bits.RBIE = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xef
	mov	@r0,a
;	pic16f84a.h:315: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'clear_rb_int'
;------------------------------------------------------------
;	pic16f84a.h:317: extern void clear_rb_int() {
;	-----------------------------------------
;	 function clear_rb_int
;	-----------------------------------------
_clear_rb_int:
;	pic16f84a.h:318: INTCON_bits.RBIF = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0x7f
	mov	@r0,a
;	pic16f84a.h:319: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'enable_tmr0_int'
;------------------------------------------------------------
;	pic16f84a.h:321: extern void enable_tmr0_int() {
;	-----------------------------------------
;	 function enable_tmr0_int
;	-----------------------------------------
_enable_tmr0_int:
;	pic16f84a.h:322: INTCON_bits.T0IE = 0x1;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	orl	a,#0x04
	mov	@r0,a
;	pic16f84a.h:323: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disable_tmr0_int'
;------------------------------------------------------------
;	pic16f84a.h:325: extern void disable_tmr0_int() {
;	-----------------------------------------
;	 function disable_tmr0_int
;	-----------------------------------------
_disable_tmr0_int:
;	pic16f84a.h:326: INTCON_bits.T0IE = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xfb
	mov	@r0,a
;	pic16f84a.h:327: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'clear_tmr0_int'
;------------------------------------------------------------
;	pic16f84a.h:329: extern void clear_tmr0_int() {
;	-----------------------------------------
;	 function clear_tmr0_int
;	-----------------------------------------
_clear_tmr0_int:
;	pic16f84a.h:330: INTCON_bits.T0IF = 0x0;
	mov	r0,#_INTCON_bits
	mov	a,@r0
	anl	a,#0xdf
	mov	@r0,a
;	pic16f84a.h:331: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_prescaler'
;------------------------------------------------------------
;scale                     Allocated to registers r6 r7 
;------------------------------------------------------------
;	pic16f84a.h:333: extern void set_prescaler(int scale) {
;	-----------------------------------------
;	 function set_prescaler
;	-----------------------------------------
_set_prescaler:
	mov	r6,dpl
	mov	r7,dph
;	pic16f84a.h:334: OPTION_REG_bits.PS2 = scale >> 2 && 0x1;
	mov	ar4,r6
	mov	a,r7
	mov	c,acc.7
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	mov	c,acc.7
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	mov	r5,a
	orl	a,r4
	jnz	00104$
;	assignBit
	clr	_set_prescaler_sloc0_1_0
	sjmp	00105$
00104$:
;	assignBit
	setb	_set_prescaler_sloc0_1_0
00105$:
	mov	c,_set_prescaler_sloc0_1_0
	clr	a
	rlc	a
	mov	r0,#_OPTION_REG_bits
	rrc	a
	mov	a,@r0
	mov	acc.5,c
	mov	@r0,a
;	pic16f84a.h:335: OPTION_REG_bits.PS1 = scale >> 1 && 0x1;
	mov	ar4,r6
	mov	a,r7
	mov	c,acc.7
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	mov	r5,a
	orl	a,r4
	jnz	00107$
;	assignBit
	clr	_set_prescaler_sloc0_1_0
	sjmp	00108$
00107$:
;	assignBit
	setb	_set_prescaler_sloc0_1_0
00108$:
	mov	c,_set_prescaler_sloc0_1_0
	clr	a
	rlc	a
	mov	r5,a
	mov	r0,#_OPTION_REG_bits
	rrc	a
	mov	a,@r0
	mov	acc.6,c
	mov	@r0,a
;	pic16f84a.h:336: OPTION_REG_bits.PS0 = scale && 0x1;
	mov	a,r6
	orl	a,r7
	jnz	00110$
;	assignBit
	clr	_set_prescaler_sloc0_1_0
	sjmp	00111$
00110$:
;	assignBit
	setb	_set_prescaler_sloc0_1_0
00111$:
	mov	c,_set_prescaler_sloc0_1_0
	clr	a
	rlc	a
	mov	r0,#_OPTION_REG_bits
	rrc	a
	mov	a,@r0
	mov	acc.7,c
	mov	@r0,a
;	pic16f84a.h:337: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
