# ArduinoAsm

# ATmega328P - Registres

## Registres généraux
- r0 à r31 : 32 registres de travail (8 bits chacun)
  - r0 : registre général (souvent utilisé comme temporaire, pas préservé par les fonctions)
  - r1 : registre zéro (toujours 0, utilisé implicitement par certaines instructions)
  - r2 – r17 : registres généraux disponibles pour l’usage
  - r18 – r25 : registres généraux souvent utilisés pour variables temporaires
  - r26 – r31 : registres utilisés comme pointeurs (X, Y, Z)

## Registres pointeurs
- **X** : formé par r26 (XL) et r27 (XH)  
- **Y** : formé par r28 (YL) et r29 (YH)  
- **Z** : formé par r30 (ZL) et r31 (ZH)  

Ces registres sont utilisés pour l’adressage indirect en mémoire SRAM ou Flash.

## Découpage spécial
- Chaque registre est 8 bits.  
- Les paires (r26:r27, r28:r29, r30:r31) forment des registres 16 bits pour les pointeurs.  
- Le registre r1 est réservé comme registre zéro (toujours 0).  
- Le registre r0 est utilisé comme registre temporaire dans certaines opérations internes du compilateur.

## Résumé
- 32 registres de travail : r0 – r31  
- 3 pointeurs 16 bits : X, Y, Z  
- Usage typique :
  - r0 : temporaire
  - r1 : zéro constant
  - r2–r25 : variables générales
  - r26–r31 : pointeurs (X, Y, Z)

# ATmega328P - Organisation de la mémoire de données

Le **ATmega328P** est un microcontrôleur complexe avec plus d’unités périphériques que ne peuvent être supportées dans les 64 emplacements réservés par l’opcode des instructions `IN` et `OUT`.

- L’espace **Extended I/O** (0x60 – 0xFF en SRAM) n’est accessible qu’avec les instructions `ST/STS/STD` (Store) et `LD/LDS/LDD` (Load).  
- Le bus de données `IN/OUT` a un accès direct aux 64 octets de la section I/O Memory (non-Extended) via les adresses `0x00 – 0x1F`.  
- Cette mémoire peut aussi être atteinte par le bus standard avec un décalage d’adresse `0x20`.

---

## Espace mémoire de données ATmega328P

La mémoire de données (2303 emplacements) est organisée comme suit :

- **Registers (32 × 8-bit)** : `0x0000 – 0x001F`  
  - 32 registres de travail généraux (`R0 – R31`)

- **I/O Memory (64 × 8-bit)** : `0x0020 – 0x005F`  
  - Registres de contrôle des périphériques et autres registres d’E/S

- **Extended I/O Memory (160 × 8-bit)** : `0x0060 – 0x00FF`  
  - Utilisé par certains AVR pour gérer des périphériques supplémentaires via la SRAM

- **Internal SRAM (2048 × 8-bit)** : `0x0100 – 0x08FF`  
  - Stockage temporaire des variables, résultats intermédiaires et pile logicielle

---

## Modes d’adressage du bus de données

1. **Direct**  
   - Atteint tout l’espace mémoire de données

2. **Indirect**  
   - Utilise les registres `R26 – R31` comme pointeurs (X, Y, Z)

3. **Indirect avec Déplacement**  
   - Permet d’atteindre 63 adresses à partir de la base donnée par `Y` ou `Z`

4. **Indirect avec Pré-décrément**  
   - Les registres pointeurs `X`, `Y`, `Z` sont décrémentés avant l’accès

---

## Résumé
- 32 registres généraux (`R0 – R31`)  
- 64 registres I/O standards  
- 160 registres I/O étendus  
- 2048 octets de SRAM interne  
- Modes d’adressage : Direct, Indirect, Indirect avec Déplacement, Indirect avec Pré-décrément

# ATmega328P - I/O Registers Table

| Address (I/O) | Name   | Bit 7   | Bit 6   | Bit 5   | Bit 4   | Bit 3   | Bit 2   | Bit 1   | Bit 0   | Page |
|---------------|--------|---------|---------|---------|---------|---------|---------|---------|---------|------|
| 0x1F (0x3F)   | EECR   | –       | –       | EEPM1   | EEPM0   | EERIE   | EEMPE   | EEPE    | EERE    | 21   |
| 0x1E (0x3E)   | GPIOR0 |         |         |         |         |         |         |         |         | 15   |
| 0x1D (0x3D)   | EIMSK  | –       | –       | –       | –       | –       | –       | INT1    | INT0    | 73   |
| 0x1C (0x3C)   | EIFR   | –       | –       | –       | –       | –       | –       | INTF1   | INTF0   | 73   |
| 0x1B (0x3B)   | PCIFR  | –       | –       | –       | –       | –       | PCIF2   | PCIF1   | PCIF0   |      |
| 0x17 (0x37)   | TIFR2  | –       | –       | –       | –       | –       | OCF2B   | OCF2A   | TOV2    | 160  |
| 0x16 (0x36)   | TIFR1  | –       | –       | ICF1    | –       | –       | OCF1B   | OCF1A   | TOV1    | 137  |
| 0x15 (0x35)   | TIFR0  | –       | –       | –       | –       | –       | OCF0B   | OCF0A   | TOV0    |      |
| 0x0B (0x2B)   | PORTD  | PORTD7  | PORTD6  | PORTD5  | PORTD4  | PORTD3  | PORTD2  | PORTD1  | PORTD0  | 93   |
| 0x0A (0x2A)   | DDRD   | DDD7    | DDD6    | DDD5    | DDD4    | DDD3    | DDD2    | DDD1    | DDD0    | 93   |
| 0x09 (0x29)   | PIND   | PIND7   | PIND6   | PIND5   | PIND4   | PIND3   | PIND2   | PIND1   | PIND0   | 93   |
| 0x08 (0x28)   | PORTC  | –       | PORTC6  | PORTC5  | PORTC4  | PORTC3  | PORTC2  | PORTC1  | PORTC0  | 92   |
| 0x07 (0x27)   | DDRC   | –       | DDC6    | DDC5    | DDC4    | DDC3    | DDC2    | DDC1    | DDC0    | 92   |
| 0x06 (0x26)   | PINC   | –       | PINC6   | PINC5   | PINC4   | PINC3   | PINC2   | PINC1   | PINC0   | 92   |
| 0x05 (0x25)   | PORTB  | PORTB7  | PORTB6  | PORTB5  | PORTB4  | PORTB3  | PORTB2  | PORTB1  | PORTB0  | 92   |
| 0x04 (0x24)   | DDRB   | DDB7    | DDB6    | DDB5    | DDB4    | DDB3    | DDB2    | DDB1    | DDB0    | 92   |
| 0x03 (0x23)   | PINB   | PINB7   | PINB6   | PINB5   | PINB4   | PINB3   | PINB2   | PINB1   | PINB0   | 92   |




# ATmega328P - Liste des instructions ASM (AVR)

## Instructions arithmétiques
- ADC – Add with Carry  
- ADD – Add without Carry  
- ADIW – Add Immediate to Word  
- SUB – Subtract without Carry  
- SUBI – Subtract Immediate  
- SBC – Subtract with Carry  
- SBCI – Subtract Immediate with Carry  
- SBIW – Subtract Immediate from Word  
- MUL – Multiply Unsigned  
- MULS – Multiply Signed  
- MULSU – Multiply Signed with Unsigned  
- FMUL – Fractional Multiply Unsigned  
- FMULS – Fractional Multiply Signed  
- FMULSU – Fractional Multiply Signed with Unsigned

## Instructions logiques et bit à bit
- AND – Logical AND  
- ANDI – Logical AND with Immediate  
- OR – Logical OR  
- ORI – Logical OR with Immediate  
- EOR – Exclusive OR  
- COM – One’s Complement  
- NEG – Two’s Complement  
- SBR – Set Bit(s) in Register  
- CBR – Clear Bit(s) in Register  
- SER – Set Register (all bits = 1)

## Instructions de transfert
- MOV – Copy Register  
- MOVW – Copy Register Word  
- LDI – Load Immediate  
- LDS – Load Direct from Data Space  
- STS – Store Direct to Data Space  
- LD – Load Indirect  
- ST – Store Indirect  
- LPM – Load Program Memory  
- SPM – Store Program Memory  
- IN – Input from I/O Location  
- OUT – Output to I/O Location  
- PUSH – Push Register on Stack  
- POP – Pop Register from Stack

## Instructions de contrôle
- RJMP – Relative Jump  
- IJMP – Indirect Jump  
- JMP – Jump  
- RCALL – Relative Call Subroutine  
- ICALL – Indirect Call Subroutine  
- CALL – Call Subroutine  
- RET – Return from Subroutine  
- RETI – Return from Interrupt  
- CP – Compare  
- CPI – Compare with Immediate  
- CPC – Compare with Carry  
- BRBS – Branch if Bit Set  
- BRBC – Branch if Bit Cleared  
- BREQ – Branch if Equal  
- BRNE – Branch if Not Equal  
- BRCS – Branch if Carry Set  
- BRCC – Branch if Carry Cleared  
- BRSH – Branch if Same or Higher  
- BRLO – Branch if Lower  
- BRMI – Branch if Minus  
- BRPL – Branch if Plus  
- BRGE – Branch if Greater or Equal  
- BRLT – Branch if Less Than  
- BRHS – Branch if Half Carry Set  
- BRHC – Branch if Half Carry Cleared  
- BRTS – Branch if T Flag Set  
- BRTC – Branch if T Flag Cleared  
- BRVS – Branch if Overflow Set  
- BRVC – Branch if Overflow Cleared  
- BRIE – Branch if Interrupt Enabled  
- BRID – Branch if Interrupt Disabled

## Instructions diverses
- NOP – No Operation  
- SLEEP – Enter Sleep Mode  
- WDR – Watchdog Reset  
- BREAK – Break (debug)  
- DES – DES Encryption Instruction (sur certains AVR)




# Ressources GCC / AVR

- [Basic Asm Statements](https://gcc.gnu.org/onlinedocs/gcc/Basic-Asm.html)
- [Extended Asm Statements](https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html)
- [Constraints](https://gcc.gnu.org/onlinedocs/gcc/Constraints.html)
- [Explicit Register Variables](https://gcc.gnu.org/onlinedocs/gcc/Explicit-Register-Variables.html)
- [Inline Assembler Cookbook](https://www.nongnu.org/avr-libc/user-manual/inline_asm.html)
- [What registers are used by the C compiler?](https://www.microchip.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_reg_usage.html)
- [AVR Function Attributes](https://gcc.gnu.org/onlinedocs/gcc/AVR-Function-Attributes.html)
- [ATmega328P Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
- [Atmel ATmega640/V-1280/V-1281/V-2560/V-2561/V Datasheet](https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf)
- [AVR Options](https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html)
- [Relocatable Expression Modifiers](https://sourceware.org/binutils/docs/as/AVR_002dModifiers.html)
- [AVR Assembler](https://www.microchip.com/webdoc/avrassembler/)
- [GCC Inline Assembly HOWTO](https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)
- [Common Function Attributes](https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html)
- [The GNU Assembler Labels](http://tigcc.ticalc.org/doc/gnuasm.html#SEC46)
- [Interrupts](https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html)
- [Special Function Registers](https://www.nongnu.org/avr-libc/user-manual/group__avr__sfr__notes.html)
- [AVR Instruction Set Manual](http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf)
- [Reasons you should NOT use inline asm](https://gcc.gnu.org/wiki/DontUseInlineAsm)

https://www-lisic.univ-littoral.fr/~hebert/microcontroleur/atmel/
