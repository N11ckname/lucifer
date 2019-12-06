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
	project/src/NeoNextion/INextionColourable.cpp.o \
	project/src/NeoNextion/INextionFontStyleable.cpp.o \
	project/src/NeoNextion/INextionTouchable.cpp.o \
	project/src/NeoNextion/INextionWidget.cpp.o \
	project/src/NeoNextion/Nextion.cpp.o \
	project/src/NeoNextion/NextionCrop.cpp.o \
	project/src/NeoNextion/NextionPage.cpp.o \
	project/src/NeoNextion/NextionPicture.cpp.o \
	project/src/NeoNextion/NextionSlidingText.cpp.o \
	project/src/NeoNextion/NextionTimer.cpp.o \
	project/src/NeoNextion/NextionWaveform.cpp.o \
	project/src/hardware/Adafruit_MAX31856.cpp.o \
	project/src/hardware/RotaryEncoder.cpp.o \
	project/src/hardware/SPI.cpp.o \
	project/src/hardware/SoftwareSerial.cpp.o \
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

TARGETS = \
	lucifer.hex \

all: $(TARGETS)

lucifer.hex: lucifer.elf
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-objcopy" -O ihex -R .eeprom  "./lucifer.elf" "./lucifer.hex"

lucifer.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./lucifer.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-size" -A "./lucifer.elf"

project/display.cpp.o: ../../display.cpp project/display.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/display.cpp.d: ;

-include project/display.cpp.d 

project/encoder.cpp.o: ../../encoder.cpp project/encoder.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/encoder.cpp.d: ;

-include project/encoder.cpp.d 

project/lucifer.cpp.o: ../../lucifer.cpp project/lucifer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/lucifer.cpp.d: ;

-include project/lucifer.cpp.d 

project/regulation.cpp.o: ../../regulation.cpp project/regulation.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/regulation.cpp.d: ;

-include project/regulation.cpp.d 

project/src/NeoNextion/INextionColourable.cpp.o: ../../src/NeoNextion/INextionColourable.cpp project/src/NeoNextion/INextionColourable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/INextionColourable.cpp.d: ;

-include project/src/NeoNextion/INextionColourable.cpp.d 

project/src/NeoNextion/INextionFontStyleable.cpp.o: ../../src/NeoNextion/INextionFontStyleable.cpp project/src/NeoNextion/INextionFontStyleable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/INextionFontStyleable.cpp.d: ;

-include project/src/NeoNextion/INextionFontStyleable.cpp.d 

project/src/NeoNextion/INextionTouchable.cpp.o: ../../src/NeoNextion/INextionTouchable.cpp project/src/NeoNextion/INextionTouchable.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/INextionTouchable.cpp.d: ;

-include project/src/NeoNextion/INextionTouchable.cpp.d 

project/src/NeoNextion/INextionWidget.cpp.o: ../../src/NeoNextion/INextionWidget.cpp project/src/NeoNextion/INextionWidget.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/INextionWidget.cpp.d: ;

-include project/src/NeoNextion/INextionWidget.cpp.d 

project/src/NeoNextion/Nextion.cpp.o: ../../src/NeoNextion/Nextion.cpp project/src/NeoNextion/Nextion.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/Nextion.cpp.d: ;

-include project/src/NeoNextion/Nextion.cpp.d 

project/src/NeoNextion/NextionCrop.cpp.o: ../../src/NeoNextion/NextionCrop.cpp project/src/NeoNextion/NextionCrop.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionCrop.cpp.d: ;

-include project/src/NeoNextion/NextionCrop.cpp.d 

project/src/NeoNextion/NextionPage.cpp.o: ../../src/NeoNextion/NextionPage.cpp project/src/NeoNextion/NextionPage.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionPage.cpp.d: ;

-include project/src/NeoNextion/NextionPage.cpp.d 

project/src/NeoNextion/NextionPicture.cpp.o: ../../src/NeoNextion/NextionPicture.cpp project/src/NeoNextion/NextionPicture.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionPicture.cpp.d: ;

-include project/src/NeoNextion/NextionPicture.cpp.d 

project/src/NeoNextion/NextionSlidingText.cpp.o: ../../src/NeoNextion/NextionSlidingText.cpp project/src/NeoNextion/NextionSlidingText.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionSlidingText.cpp.d: ;

-include project/src/NeoNextion/NextionSlidingText.cpp.d 

project/src/NeoNextion/NextionTimer.cpp.o: ../../src/NeoNextion/NextionTimer.cpp project/src/NeoNextion/NextionTimer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionTimer.cpp.d: ;

-include project/src/NeoNextion/NextionTimer.cpp.d 

project/src/NeoNextion/NextionWaveform.cpp.o: ../../src/NeoNextion/NextionWaveform.cpp project/src/NeoNextion/NextionWaveform.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/NeoNextion/NextionWaveform.cpp.d: ;

-include project/src/NeoNextion/NextionWaveform.cpp.d 

project/src/hardware/Adafruit_MAX31856.cpp.o: ../../src/hardware/Adafruit_MAX31856.cpp project/src/hardware/Adafruit_MAX31856.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/hardware/Adafruit_MAX31856.cpp.d: ;

-include project/src/hardware/Adafruit_MAX31856.cpp.d 

project/src/hardware/RotaryEncoder.cpp.o: ../../src/hardware/RotaryEncoder.cpp project/src/hardware/RotaryEncoder.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/hardware/RotaryEncoder.cpp.d: ;

-include project/src/hardware/RotaryEncoder.cpp.d 

project/src/hardware/SPI.cpp.o: ../../src/hardware/SPI.cpp project/src/hardware/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/hardware/SPI.cpp.d: ;

-include project/src/hardware/SPI.cpp.d 

project/src/hardware/SoftwareSerial.cpp.o: ../../src/hardware/SoftwareSerial.cpp project/src/hardware/SoftwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/src/hardware/SoftwareSerial.cpp.d: ;

-include project/src/hardware/SoftwareSerial.cpp.d 

project/temperature.cpp.o: ../../temperature.cpp project/temperature.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"

project/temperature.cpp.d: ;

-include project/temperature.cpp.d 


core/abi.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/cores/arduino" -I"C:/Users/Devialet/.arduinocdt/packages/arduino/hardware/avr/1.8.1/variants/standard" "$<" -o "$@"
	"C:/Users/Devialet/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



