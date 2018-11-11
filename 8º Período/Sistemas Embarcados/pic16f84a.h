/*
 *  Declaração de Acesso para o PIC 16F84A
 *  
 *  Este arquivo é parte da GNU PIC library for SDCC, originalmente
 *  criada por Molnar Karoly <molnarkaroly@users.sf.net> 2012;
 * 
 *  SDCC está sob a licença GPLv2.
 * 
 *  Adaptado por: 
 *      Vitor Barth <vbob@vbob.com.br>
 *      Gabriela Santos <gabi.gsantos@hotmail.com>
 *
 *  Veja http://sdcc.sourceforge.net/ para mais informações sobre o SDCC.
 */

#ifndef P16F84A_H
#define P16F84A_H

/* TIPOS */
#define BYTE unsigned char

/* CONFIGURAÇÃO DE REGISTRADORES */

// Banco de Registradores 0
#define INDF_addr       0x0000   // Ponteiro para o endereço indicado em FSR
#define TMR0_addr       0x0001   // Contador do Timer0
#define PCL_addr        0x0002   // Bits<0:7> do Contador de Progama (Leitura e Escrita)
#define STATUS_addr     0x0003
#define FSR_addr        0x0004   // Endereço de Memória para Acesso Indireto
#define PORTA_addr      0x0005
#define PORTB_addr      0x0006
#define EEDATA_addr     0x0008   // Buffer de Dados para Escrita/Leitura na EEPROM
#define EEADR_addr      0x0009   // Buffer de Endereço para Escrita/Leitura na EEPROM
#define PCLATH_addr     0x000A   // Bits<8:12> do Contador de Programa (Somente Leitura)
#define INTCON_addr     0x000B

extern __sfr __at (INDF_addr)        INDF; 
extern __sfr __at (TMR0_addr)        TMR0;
extern __sfr __at (PCL_addr)         PCL;
extern __sfr __at (STATUS_addr)      STATUS;
extern __sfr __at (FSR_addr)         FSR;
extern __sfr __at (PORTA_addr)       PORTA;
extern __sfr __at (PORTB_addr)       PORTB;
extern __sfr __at (EEDATA_addr)      EEDATA;
extern __sfr __at (EEADR_addr)       EEADR;
extern __sfr __at (PCLATH_addr)      PCLATH;
extern __sfr __at (INTCON_addr)      INTCON;
 
// Banco de Registradores 1
#define OPTION_REG_addr 0x0081
#define TRISA_addr      0x0085
#define TRISB_addr      0x0086
#define EECON1_addr     0x0088
#define EECON2_addr     0x0089

extern __sfr __at (OPTION_REG_addr)  OPTION_REG;
extern __sfr __at (TRISA_addr)       TRISA;
extern __sfr __at (TRISB_addr)       TRISB;
extern __sfr __at (EECON1_addr)      EECON1;
extern __sfr __at (EECON2_addr)      EECON2;        // Não Implementado em Hardware

/* Registrador de Status */

typedef union {
    struct {
        BYTE    :1; 
        BYTE    :1;
        BYTE RP0:1; // Indicador de Seletor de Banco (0 se selecionado Banco 0, 1 se selecionado Banco 1)
        BYTE  TO:1; // Bit de Timeout (se ocorreu timeout com watchdog, define como 0) 
        BYTE  PD:1; // Bit de Desligamento (instrução SLEEP define como 0)
        BYTE   Z:1; // Bit de Zero (definido em 1 se o resultado da última operação lógico-aritmética for zero)
        BYTE  DC:1; // Vai-Um Digital (definido em 1 se houver Vai-Um no 4º Bit)
        BYTE   C:1; // Vai-Um/Overflow (definido em 1 se houver overflow)

    };
} __STATUS_bits_t;

extern volatile __STATUS_bits_t __at(STATUS_addr) STATUS_bits;

/* Registrador de Opções */

typedef union {
    struct {
        BYTE   RBPU:1; // Resistor de Pull-Up na Porta B (1 desabilita Pull-Ups da porta B, 0 permite ativá-los individualmente)
        BYTE INTEDG:1; // Interrupção de Borda de Subida na porta RB0/INT (1 habilita interrupção em borda de subida, 0 habilita interrupção em borda de descida)
        BYTE   T0CS:1; // Indica a fonte do Clock (1 usa a porta RA4/T0CKL para comandar o clock, 0 usa o clock interno)
        BYTE   T0SE:1; // Define a borda do Clock na porta RA4/T0CKL (1 incrementa o clock de alto->baixo, 0 incrementa em baixo->alto)
        BYTE    PSA:1; // Define o uso do divisor de frequência do clock (1 para uso do divisor no WatchDogTimer, e 0 para o Timer0)
        BYTE    PS2:1; // Bit 2 do Divisor de Frequência do Clock (vide datasheet para possibilidades)
        BYTE    PS1:1; // Bit 1 do Divisor de Frequência do Clock
        BYTE    PS0:1; // Bit 0 do Divisor de Frequência do Clock
    };
} __OPTION_REG_bits_t;

extern volatile __OPTION_REG_bits_t __at(OPTION_REG_addr) OPTION_REG_bits;

/* Registrador de Fonte de Interrupções */

typedef union {
    struct {
        // (1 ativa a interrupção, 0 desativa)

        BYTE  GIE:1; // Interrupção Global (deve ser ativada para as interrupções abaixo funcionarem)
        BYTE EEIE:1; // Interrupção de Fim de Escrita na Memória EEPROM
        BYTE T0IE:1; // Interrupção de Overflow no Timer 0
        BYTE INTE:1; // Interrupção Externa em RB0/INT
        BYTE RBIE:1; // Interrupção de Borda nos pinos RB4:RB7 
        BYTE T0IF:1; // Indica se houve interrupção de Overflow no Timer0 (deve ser limpa em software)
        BYTE INTF:1; // Indica se houve interrupção externa em RB0/INT (deve ser limpa em software)
        BYTE RBIF:1; // Indica se houve interrupção de borda em algum dos pinos RB4:RB7 (deve ser limpa em software)
    };
} __INTCON_bits_t;

extern volatile __INTCON_bits_t __at(INTCON_addr) INTCON_bits;

/* Registrador de Memória de Dados EEPROM */

typedef union {
    struct {
        BYTE      :1;
        BYTE      :1;
        BYTE      :1;
        BYTE  EEIF:1; // Flag de interrupção de operação de escrita (1 indica que a operação foi completada. Deve ser limpa em software)
        BYTE WRERR:1; // Flag de erro na operação de escrita (1 indica que houve interrupção prematura no processo de escrita)
        BYTE  WREN:1; // Ativa Escrita na EEPROM (0 desabilita escrita na EEPROM)
        BYTE    WR:1; // Controle de Escrita (1 inicializa o ciclo de escrita. Só pode ser definido, mas não limpo em software)
        BYTE    RD:1; // Controle de Leitura (1 inicializa o ciclo de leitura. Só pode ser definido, mas não limpo em software)
    };
} __EECON1_bits_t;

extern volatile __EECON1_bits_t __at(EECON1_addr) EECON1_bits;

/* Registrador PORTA */

typedef union {
    struct {
        // 1 como Alto, 0 como Baixo. Depende de TRISA
        BYTE    :1;
        BYTE    :1;
        BYTE    :1;
        BYTE RA4:1; // Pode ser usado para Timer0
        BYTE RA3:1;
        BYTE RA2:1;
        BYTE RA1:1;
        BYTE RA0:1;
    };
} __PORTA_bits_t;

extern volatile __PORTA_bits_t __at(PORTA_addr) PORTA_bits;

/* Registrador TRISA */

typedef union {
    struct {
        // 1 como Entrada, 0 como Saída
        BYTE       :1;
        BYTE       :1;
        BYTE       :1;
        BYTE TRISA4:1; 
        BYTE TRIRA3:1;
        BYTE TRISA2:1;
        BYTE TRISA1:1;
        BYTE TRISA0:1;
    };
} __TRISA_bits_t;

extern volatile __TRISA_bits_t __at(TRISA_addr) TRISA_bits;

/* Registrador PORTB */

typedef union {
    struct {
        // 1 como Alto, 0 como Baixo. Depende de TRISB
        BYTE RB7:1; // Dados da porta Serial
        BYTE RB6:1; // Clock da porta Serial
        BYTE RB5:1;
        BYTE RB4:1; 
        BYTE RB3:1;
        BYTE RB2:1;
        BYTE RB1:1;
        BYTE RB0:1;
    };
} __PORTB_bits_t;

extern volatile __PORTB_bits_t __at(PORTB_addr) PORTB_bits;

/* Registrador TRISB */

typedef union {
    struct {
        // 1 como Entrada, 0 como Saída.
        BYTE TRISB7:1; 
        BYTE TRISB6:1; 
        BYTE TRISB5:1;
        BYTE TRISB4:1; 
        BYTE TRISB3:1;
        BYTE TRISB2:1;
        BYTE TRISB1:1;
        BYTE TRISB0:1;
    };
} __TRISB_bits_t;

extern volatile __TRISB_bits_t __at(TRISB_addr) TRISB_bits;

// Definição de Pinos

#define PORTA    PORTA_bits
#define PORTB    PORTB_bits

#define PIN_RA0  PORTA_bits.RA0
#define PIN_RA1  PORTA_bits.RA1
#define PIN_RA2  PORTA_bits.RA2
#define PIN_RA3  PORTA_bits.RA3
#define PIN_RA4  PORTA_bits.RA4

#define PIN_RB0  PORTB_bits.RB0
#define PIN_RB1  PORTB_bits.RB1
#define PIN_RB2  PORTB_bits.RB2
#define PIN_RB3  PORTB_bits.RB3
#define PIN_RB4  PORTB_bits.RB4
#define PIN_RB5  PORTB_bits.RB5
#define PIN_RB6  PORTB_bits.RB6
#define PIN_RB7  PORTB_bits.RB7

// Definição de TRIS
#define TRISA    TRISA_bits
#define TRISB    TRISB_bits

#define TRIS_A0  TRISA_bits.TRISA0
#define TRIS_A1  TRISA_bits.TRISA1
#define TRIS_A2  TRISA_bits.TRISA2
#define TRIS_A3  TRISA_bits.TRISA3
#define TRIS_A4  TRISA_bits.TRISA4

#define TRIS_B0  TRISB_bits.TRISB0
#define TRIS_B1  TRISB_bits.TRISB1
#define TRIS_B2  TRISB_bits.TRISB2
#define TRIS_B3  TRISB_bits.TRISB3
#define TRIS_B4  TRISB_bits.TRISB4
#define TRIS_B5  TRISB_bits.TRISB5
#define TRIS_B6  TRISB_bits.TRISB6
#define TRIS_B7  TRISB_bits.TRISB7

#define PSA_TMR0_2    0x00 
#define PSA_TMR0_4    0x01
#define PSA_TMR0_8    0x02
#define PSA_TMR0_16   0x03
#define PSA_TMR0_32   0x04
#define PSA_TMR0_64   0x05
#define PSA_TMR0_128  0x06
#define PSA_TMR0_256  0x07

#define PSA_WDT_1    0x00
#define PSA_WDT_2    0x01
#define PSA_WDT_4    0x02
#define PSA_WDT_8    0x03
#define PSA_WDT_16   0x04
#define PSA_WDT_32   0x05
#define PSA_WDT_64   0x06
#define PSA_WDT_128  0x07


/* Métodos de Escrita e Leitura */

extern void set_tris(int tris, int value) {
    tris = value;
}

extern int read_tris(int tris) {
    return tris;
}

extern void write_port_tris(int tris, int port_bits) {
    tris = port_bits;
}

extern int read_port_tris(int tris) {
    return tris;
}

extern void set_pin(int pin, int value) {
    pin = value;
}

extern int read_pin(int pin) {
    return pin;
}

extern void enable_global_int() {
    INTCON_bits.GIE = 0x1;
}

extern void disable_global_int() {
    INTCON_bits.GIE = 0x0;
}

extern void enable_ext_int() {
    INTCON_bits.INTE = 0x1;
}

extern void disable_ext_int() {
    INTCON_bits.INTE = 0x0;
}

extern void clear_ext_int() {
    INTCON_bits.INTF = 0x0;
}

extern void enable_rb_int() {
    INTCON_bits.RBIE = 0x1;
}

extern void disable_rb_int() {
    INTCON_bits.RBIE = 0x0;
}

extern void clear_rb_int() {
    INTCON_bits.RBIF = 0x0;
}

extern void enable_tmr0_int() {
    INTCON_bits.T0IE = 0x1;
}

extern void disable_tmr0_int() {
    INTCON_bits.T0IE = 0x0;
}

extern void clear_tmr0_int() {
    INTCON_bits.T0IF = 0x0;
}

extern void set_prescaler(int scale) {
    OPTION_REG_bits.PS2 = scale >> 2 && 0x1;
    OPTION_REG_bits.PS1 = scale >> 1 && 0x1;
    OPTION_REG_bits.PS0 = scale && 0x1;
}

#endif