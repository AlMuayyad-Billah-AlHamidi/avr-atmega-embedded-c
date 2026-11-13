# AVR ATmega Embedded C

Drivers and lab tasks I wrote while learning Embedded C on AVR (ATmega32 / ATmega16).

The code follows a layered layout:

- `COTS/03_LIB` — common types and bit macros  
- `COTS/01_MCAL` — MCU drivers (DIO, PORT, EXTI, ADC)  
- `COTS/02_HAL` — hardware drivers (LED, SSD, BCD, 74HC595, Switch, CLCD, Keypad)  
- `Tasks_atmega32/` — applications on ATmega32  
- `Task_atmega16/` — applications on ATmega16  
- `proteus_simulation/` — Proteus circuits used for testing  
- `docs/` — short notes (e.g. avrdude)

## What is covered

| Area | Examples |
|------|----------|
| GPIO / LEDs | shift, ping-pong, snake, converge/diverge patterns |
| 7-segment / BCD | display digits, 0–99 counter, pin control |
| Switches | polling and LED effect control |
| Interrupts | INT0 / INT1 / INT2 with callbacks |
| LCD | string display |
| Keypad + LCD | read keys and show on CLCD |
| ADC | digital/analog value on LCD |

## Toolchain

- Atmel Studio / Microchip Studio  
- AVR-GCC  
- Proteus for simulation  
- Programmer: Arduino as ISP / avrdude (see `docs/avrdude_notes.txt`)

Typical fuse/clock settings depend on the board. Many demos use `F_CPU = 1000000UL`.

## How to open a task

1. Open the `.atsln` / `.cproj` inside the task folder in Microchip Studio.  
2. Or add the needed `COTS` sources + the task `main.c` to your own project.  
3. Match the pinout to the Proteus file under `proteus_simulation/` when available.

## Author

Almuayyad Billah Al-Hamidi — Mechatronics Engineer
