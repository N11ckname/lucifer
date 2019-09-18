ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/display.cpp.o \
	project/encoder.cpp.o \
	project/lucifer.cpp.o \
	project/regulation.cpp.o \
	project/temperature.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/hooks.c.o \
	core/IPAddress.cpp.o \
	core/main.cpp.o \
	core/new.cpp.o \
	core/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/Stream.cpp.o \
	core/Tone.cpp.o \
	core/USBCore.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/wiring_shift.c.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/RotaryEncoder/RotaryEncoder.cpp.o \
	libraries/NeoNextion/INextionColourable.cpp.o \
	libraries/NeoNextion/INextionFontStyleable.cpp.o \
	libraries/NeoNextion/INextionTouchable.cpp.o \
	libraries/NeoNextion/INextionWidget.cpp.o \
	libraries/NeoNextion/Nextion.cpp.o \
	libraries/NeoNextion/NextionCrop.cpp.o \
	libraries/NeoNextion/NextionPage.cpp.o \
	libraries/NeoNextion/NextionPicture.cpp.o \
	libraries/NeoNextion/NextionSlidingText.cpp.o \
	libraries/NeoNextion/NextionTimer.cpp.o \
	libraries/NeoNextion/NextionWaveform.cpp.o \
	libraries/SPI/src/SPI.cpp.o \
	libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp.o \
	libraries/SoftwareSerial/src/SoftwareSerial.cpp.o \

TARGETS = \
	lucifer.hex \

all: $(TARGETS)

lucifer.hex: lucifer.elf
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./lucifer.elf" "./lucifer.hex"

lucifer.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./lucifer.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-size" -A "./lucifer.elf"

project/display.cpp.o: ../../display.cpp project/display.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/display.cpp.d: ;

-include project/display.cpp.d 

project/encoder.cpp.o: ../../encoder.cpp project/encoder.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/encoder.cpp.d: ;

-include project/encoder.cpp.d 

project/lucifer.cpp.o: ../../lucifer.cpp project/lucifer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/lucifer.cpp.d: ;

-include project/lucifer.cpp.d 

project/regulation.cpp.o: ../../regulation.cpp project/regulation.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/regulation.cpp.d: ;

-include project/regulation.cpp.d 

project/temperature.cpp.o: ../../temperature.cpp project/temperature.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

project/temperature.cpp.d: ;

-include project/temperature.cpp.d 


core/abi.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/RotaryEncoder/RotaryEncoder.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder/RotaryEncoder.cpp libraries/RotaryEncoder/RotaryEncoder.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/RotaryEncoder/RotaryEncoder.cpp.d: ;

-include libraries/RotaryEncoder/RotaryEncoder.cpp.d

libraries/NeoNextion/INextionColourable.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/INextionColourable.cpp libraries/NeoNextion/INextionColourable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/INextionColourable.cpp.d: ;

-include libraries/NeoNextion/INextionColourable.cpp.d

libraries/NeoNextion/INextionFontStyleable.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/INextionFontStyleable.cpp libraries/NeoNextion/INextionFontStyleable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/INextionFontStyleable.cpp.d: ;

-include libraries/NeoNextion/INextionFontStyleable.cpp.d

libraries/NeoNextion/INextionTouchable.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/INextionTouchable.cpp libraries/NeoNextion/INextionTouchable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/INextionTouchable.cpp.d: ;

-include libraries/NeoNextion/INextionTouchable.cpp.d

libraries/NeoNextion/INextionWidget.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/INextionWidget.cpp libraries/NeoNextion/INextionWidget.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/INextionWidget.cpp.d: ;

-include libraries/NeoNextion/INextionWidget.cpp.d

libraries/NeoNextion/Nextion.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/Nextion.cpp libraries/NeoNextion/Nextion.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/Nextion.cpp.d: ;

-include libraries/NeoNextion/Nextion.cpp.d

libraries/NeoNextion/NextionCrop.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionCrop.cpp libraries/NeoNextion/NextionCrop.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionCrop.cpp.d: ;

-include libraries/NeoNextion/NextionCrop.cpp.d

libraries/NeoNextion/NextionPage.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionPage.cpp libraries/NeoNextion/NextionPage.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionPage.cpp.d: ;

-include libraries/NeoNextion/NextionPage.cpp.d

libraries/NeoNextion/NextionPicture.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionPicture.cpp libraries/NeoNextion/NextionPicture.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionPicture.cpp.d: ;

-include libraries/NeoNextion/NextionPicture.cpp.d

libraries/NeoNextion/NextionSlidingText.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionSlidingText.cpp libraries/NeoNextion/NextionSlidingText.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionSlidingText.cpp.d: ;

-include libraries/NeoNextion/NextionSlidingText.cpp.d

libraries/NeoNextion/NextionTimer.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionTimer.cpp libraries/NeoNextion/NextionTimer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionTimer.cpp.d: ;

-include libraries/NeoNextion/NextionTimer.cpp.d

libraries/NeoNextion/NextionWaveform.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/NeoNextion/NextionWaveform.cpp libraries/NeoNextion/NextionWaveform.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/NeoNextion/NextionWaveform.cpp.d: ;

-include libraries/NeoNextion/NextionWaveform.cpp.d

libraries/SPI/src/SPI.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp.o: C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp.d: ;

-include libraries/Adafruit_MAX31856_library/1.0.3/Adafruit_MAX31856.cpp.d

libraries/SoftwareSerial/src/SoftwareSerial.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src/SoftwareSerial.cpp libraries/SoftwareSerial/src/SoftwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"C:/Users/Devialet/.arduinocdt/libraries/RotaryEncoder" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"C:/Users/Devialet/.arduinocdt/libraries/NeoNextion" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"C:/Users/Devialet/.arduinocdt/libraries/Adafruit_MAX31856_library/1.0.3" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.6.21/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SoftwareSerial/src/SoftwareSerial.cpp.d: ;

-include libraries/SoftwareSerial/src/SoftwareSerial.cpp.d

