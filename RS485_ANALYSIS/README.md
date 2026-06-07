# STM32 RS485 Protocol Analysis

## Hardware

- STM32F401RE Nucleo Board
- MAX485 RS485 Module
- 24 MHz 8-Channel USB Logic Analyzer
- PulseView

## Project Included

### RS485_ANALYSIS

Implemented RS485 communication using STM32F401RE.

The project uses USART1 for serial communication and controls the MAX485 transceiver direction pin through GPIO.

A Logic Analyzer was used to verify UART data transmission and RS485 direction control.

## Peripherals Used

- USART1
- GPIOA
- GPIOB
- MAX485
- Logic Analyzer

## Concepts Learned

- RS485 Communication
- Half-Duplex Communication
- Driver Enable (DE)
- Receiver Enable (RE)
- UART over RS485
- Direction Control
- Logic Analyzer Verification
- PulseView UART Decoding

## Flow Diagram

```text
System Start
      │
      ▼
Initialize USART1
      │
      ▼
Initialize RS485 Module
      │
      ▼
Enable Transmit Mode
      │
      ▼
Transmit Data
      │
      ▼
Wait for Transmission Complete
      │
      ▼
Enable Receive Mode
      │
      ▼
Repeat
```

## Pin Configuration

| STM32 Pin | Function |
|-----------|-----------|
| PA9 | USART1_TX |
| PB0 | RS485 DE/RE Control |

## RS485 Direction Control

Transmit Mode:

```text
PB0 = HIGH
```

Receive Mode:

```text
PB0 = LOW
```

## Experiment

Transmitted:

```c
printf("Hello\r\n");
```

Logic Analyzer successfully captured the transmitted UART frame through the MAX485 module.

## Output

Output screenshot available in:

```text
RS485_ANALYSIS/OUTPUTS/RS485_ANALYSIS_OUTPUT.png
```

## Result

Successfully implemented RS485 communication using STM32F401RE and MAX485 transceiver.

Verified UART data transmission and RS485 direction control using a Logic Analyzer and PulseView.
