#Eng. Mohamed Gamal
#----------------------------------------------------------------------------------------#
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3
Deg=-gdwarf-2 #-g
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
File=main
#----------------------------------------------------------------------------------------#

all:$(File).bin

startup.s: startup.c
	$(CC)gcc.exe -S $(Deg) $(CFLAGS) $< -o $@ 

startup.o: startup.s
	$(CC)as.exe $(Deg) $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(Deg) $(INCS) $(CFLAGS) $< -o $@ 

$(File).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(AsOBJ) -o $@  
	cp $(File).elf  $(File).axf
	cp $(File).elf  $(File)_remove_debug.elf

$(File).hex: $(File).elf
	$(CC)objcopy -O ihex $< $@

$(File).bin:$(File).hex	
	$(CC)objcopy -I ihex $(File).hex -O binary $(File).bin
	@echo "============Bulid_Done============"

#----------------------------------------------------------------------------------------#

remove_debug: $(File)_remove_debug.elf
	$(CC)strip.exe -g -S -d $<
	@echo "============rm_degig_Done============"

#----------------------------------------------------------------------------------------#	

sections: $(File).elf 
	$(CC)objdump.exe -h $<
	@echo "============sections============"
	
#----------------------------------------------------------------------------------------#

sections_without_debug: $(File)_remove_debug.elf
	$(CC)objdump.exe -h $<
	@echo "============sections_without_debug============"

#----------------------------------------------------------------------------------------#

symbols: $(File).o
	$(CC)nm.exe $(File).o $(File).elf
	@echo "============symbols============"

#----------------------------------------------------------------------------------------#

readlf: $(File).o
	$(CC)readelf.exe -a $(File).o $(File).elf $(File)_remove_debug.elf
	@echo "============readlf_Done============"
	
#----------------------------------------------------------------------------------------#

misra: $(File).c
	F:\Cppcheck\cppcheck --dump $(File).c
	python F:\Cppcheck\addons/misra.py $(File).c.dump
	@echo "============Check_Misra_Done============"

#----------------------------------------------------------------------------------------#

clean_all:
	rm *.o *.elf *.bin *.hex *.map *.s *.c.dump *.axf
	@echo "============rm_all============"	

#----------------------------------------------------------------------------------------#

clean:
	rm *.elf *.bin *.hex *.map *.s *.c.dump *.axf
	@echo "============rm============"	

#----------------------------------------------------------------------------------------#
