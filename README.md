# AVR-C-Demos

Projects on Microchip (Atmel) AVR micros, free to use

Most of this code has been written between 2016 and 2018, when I was starting my
joutney with AVR MCUs. Some of it may be broken. Some may be written in a bad way.
Some lacks description. I was just learning. So if you are learning too, looking for bugs or anything,
maybe my code can help you somehow.

Default ATMega8A. Sometimes ATMega328P.

Projects:

- ADC_PWM_joystick_servo - manipulating two servos (pan tilt) with a joystick module on ATMega8A
- ADC_PWM_pot_led_brightness: Control LED brightness with analog input voltage (potentiometer)
- ADC_PWM_pot_servo - potentiometer and servo
- ADC_UART_BT_demo - Send ADC measurements over HC-05 Bluetooth UART module
- ADC_ULN2003_clap_detection_light_switch - Microphone+ADC+Stepper
- ADC_first_example - ADC test?
- ADC_led_on - LED is ON when ADC input voltage greater than half AVCC/2 (ATMega8A)
- ADC_SPI_8led_vu: Control 8 LEDs with 47HC595 shift register, quasi VU Meter
- ASM_led_on: Nothing, just enable a LED wth Assembly
- ASM_led_timer: Toggling a LED with timer, Assembly (ATMega8/A)
- _I2C_ADC_OLED_Pong_: Potentiometer-as-a-joystick retro pong game on 128x64! pvp or vs bot
- MSGEQ7: (NOT TESTED) Attempts to read data from MSGEQ7 graphic equalizer and send them to UART (m8a)
- PWM_servo_right_left - cha cha real smooth
- _PWM_software_pwm_rgb_fade_ - Use timers as software PWM (not delays!)
- SPI_W28QB32V_external_memory - Write one byte, or clear a SPI Memory. Problems with block writing. Unstable.
- TIMER_rca_video: attempt to display something on a TV With RCA plug (ATMega328p)
- UART_ADC_BT_Oscilloscope - Bluetooth oscilloscope! Use safe voltages!
- UART_PWM_BT_servo: Controlling a servo through bluetooth (UART) module (values 0-255)
- ULN2003_test_rotate - I/O rotate ULN2003 stepper motor
- lib_pin_definitions: Pin definitions for ATMega8a
- TIMER_ISR_check: Interrupt demo (m8a)
