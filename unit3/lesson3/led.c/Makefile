#learn in depth Eng. Mohamed Gamal
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3
Deg=-gdwarf-2 #-g
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
File=led_init

all:$(File).bin

%.o: %.s
	$(CC)as.exe $(Deg) $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(Deg) $(INCS) $(CFLAGS) $< -o $@ 

$(File).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(AsOBJ) -o $@  

$(File).hex: $(File).elf
	$(CC)objcopy -O ihex $< $@

$(File).bin:$(File).hex	
	$(CC)objcopy -I ihex $(File).hex -O binary $(File).bin
	@echo "============Bulid_Done============"


debug: $(File).elf
	$(CC)strip.exe -g -S -d $<
	@echo "============rm_degig_Done============"

clean_all:
	rm *.o *.elf *.bin *.hex *.map
	@echo "============rm_all============"	

clean:
	rm *.elf *.bin *.hex *.map
	@echo "============rm============"	
