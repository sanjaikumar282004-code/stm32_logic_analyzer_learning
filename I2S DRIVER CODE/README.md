# STM32 I2S Protocol Analysis

## Hardware

- STM32F401RE Nucleo Board
- MAX98357A I2S Audio Amplifier
- 8Ω Speaker
- 24 MHz 8-Channel USB Logic Analyzer

## Project Included

### I2S_ANALYSIS

Implemented I2S communication on STM32F401RE completely using register-level programming.

The project configures PLLI2S, initializes SPI2 in I2S mode and continuously transmits audio sample data.

A Logic Analyzer was used to verify generated I2S signals and measure the sampling frequency.

## Peripherals Used

- SPI2 (I2S Mode)
- GPIOB
- PLLI2S
- Logic Analyzer

## Concepts Learned

- I2S Protocol
- Philips I2S Standard
- Audio Sampling Frequency
- PLLI2S Configuration
- I2S Prescaler Configuration
- Bit Clock (BCLK)
- Word Select (LRC / WS)
- Serial Data (DIN)
- Protocol Verification Using Logic Analyzer

## Flow Diagram

```text
System Start
      │
      ▼
Configure GPIO Pins
(PB12, PB13, PB15)
      │
      ▼
Configure PLLI2S
      │
      ▼
Enable SPI2 Clock
      │
      ▼
Configure SPI2 in I2S Mode
      │
      ▼
Configure Prescaler
      │
      ▼
Enable I2S
      │
      ▼
Transmit Audio Samples
      │
      ▼
Logic Analyzer Captures Signals
      │
      ▼
Verify BCLK, LRC and DIN
```

## Pin Configuration

| STM32 Pin | I2S Signal |
|-----------|------------|
| PB12 | LRC / WS |
| PB13 | BCLK |
| PB15 | DIN |

## Clock Configuration

```text
PLLI2SN = 192
PLLI2SR = 3

I2SDIV = 62
ODD = 1
```

Target Sampling Frequency:

```text
16 kHz
```

## Output

Output screenshot is available in:

```text
I2S_ANALYSIS/OUTPUTS/I2S_ANALYSIS_OUTPUT.png
```

Measured:

```text
WS Period = 62 µs

Fs = 1 / 62 µs

Fs ≈ 16.1 kHz
```

Verified Signals:

- BCLK
- LRC / WS
- DIN

## Result

Successfully generated and verified I2S communication using STM32F401RE and PulseView.

The Logic Analyzer confirmed correct generation of BCLK, LRC/WS and DIN signals along with a sampling frequency of approximately 16.1 kHz.
