# STM32F4xx_DevEBox description

[Board schematic](hardware/STM32F4xx_DevEBox_Schematics.pdf)

![Board exterior](doc/STM32F4xx_DevEBox.jpg)

> **ATENTION!** Native 8 MHz XTAL is replaced with the 25 MHz XTAL.

## Project structure

- [firmware](firmware) - firmware sources and building settings
- [hardware](hardware) - board documentation

The project is using STM32CubeMX for MCU peripheral configuration:
- [iot-threadx.ioc](firmware/iot-threadx.ioc)


# Pinout

|  Pin |    Signal   |
|:----:|:-----------:|
|  PA1 | ETH_REF_CLK |
|  PA2 |   ETH_MDIO  |
|  PC1 |   ETH_MDC   |
|  PA7 |  ETH_CRS_DV |
|  PC4 |   ETH_RXD0  |
|  PC5 |   ETH_RXD1  |
| PB11 |  ETH_TX_EN  |
| PB12 |   ETH_TXD0  |
| PB13 |   ETH_TXD1  |

# MCU perupherals

## SPI

|  SPI num  |    nCS pin   |    SPI slave    |
|:---------:|:------------:|:---------------:|
|   SPI 1   |     PA15     |      FLASH      |
|   SPI 1   |      PB6     |    RESERVED     |


## SDIO

|    Net    |  Pin | Description            |
|:---------:|:----:|:-----------------------|
|  SDIO_CMD |  PD2 | SDIO command line      |
|   SDIO_D0 |  PC8 | data signal            |
|   SDIO_D1 |  PC9 | data signal            |
|   SDIO_D2 | PC10 | data signal            |
|   SDIO_D3 | PC11 | data signal            |
|  SDIO_SCK | PC12 | SDIO interface clock   |
 

## Ethernet

|    Net   |  Pin | Description            |
|:--------:|:----:|:-----------------------|
|  TX_EN   |  PD2 | SDIO command line      |
|  REF_CLK |  PD2 | SDIO command line      |
|    MDIO  |  PC8 | data signal            |
|     MDC  |  PC8 | data signal            |
|   RXD0   |  PC9 | data signal            |
|   RXD1   |  PC9 | data signal            |
|   TXD0   |  PC9 | data signal            |
|   TXD1   |  PC9 | data signal            |


## Таймеры

| Таймер | Описание                                                           |
|:------:|:-------------------------------------------------------------------|
|  TIM1  | Светодиодная индикация                                             |
|  TIM2  | Поиск полуторного бита преамбулы                                   |
|  TIM3  | Тактовый символьный сигнал модема (режим прерываний)               |
|  TIM4  |                                                                    |
|  TIM5  |                                                                    |
|  TIM6  | Тактовый сигнал обновления мониторинговой информации               |
|  TIM7  | Секундная метка DHCP-клиента                                       |
|  TIM8  |                                                                    |
|  TIM9  |                                                                    |
| TIM10  |                                                                    |
| TIM11  |                                                                    |
| TIM12  |                                                                    |
| TIM13  |                                                                    |
| TIM14  |                                                                    |
| TIM15  |                                                                    |
| TIM16  |                                                                    |


## DMA-контроллер

*Таблица - Потоки контроллера DMA1*

|  Ch |  Str0  |  Str1  |  Str2  |  Str3  |  Str4  |  Str5  |  Str6  |  Str7  |
|:---:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|  0  |        |        |        |        |        |        |        |        |
|  1  |        |        |        |        |        |        |        |        |
|  2  |        |        |        |        |        |        |        |        |
|  3  |        |        |        |        |        |        |        |        |
|  4  |        |        |        |        |        |        |        |        |
|  5  |        |        |        |        |        |        |        |        |
|  6  |        |        |        |        |        |        |        |        |
|  7  |        |        |        |        |        |        |        |        |

*Таблица - Потоки контроллера DMA2*

|  Ch |  Str0  |  Str1  |  Str2  |  Str3  |  Str4  |  Str5  |  Str6  |  Str7  |
|:---:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|  0  |        |        |        |        |        |        |        |        |
|  1  |        |        |        |        |        |        |        |        |
|  2  |        |        |        |        |        |        |        |        |
|  3  |        |        |        |        |        |        |        |        |
|  4  |        |        |        |        |        |        |        |        |
|  5  |        |        |        |        |        |        |        |        |
|  6  |        |        |        |        |        |        |        |        |
|  7  |        |        |        |        |        |        |        |        |
