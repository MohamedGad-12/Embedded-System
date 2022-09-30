
/*ENG.Mohamed Gamal*/

#include <stdint.h>

extern int main(void);

void reset_Handler(void);

void Default_Handler(){

	reset_Handler();
}

void NMI_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void NM_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Bus_fault(void)__attribute__((weak,alias ("Default_Handler")));;
void Usage_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_Handler(){

	// Copy Data From ROM to RAM;
	unsigned int size_data =  (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* src_data   =  (unsigned char*)&_E_text;
 	unsigned char*  dst_data   =  (unsigned char*)&_S_data;
	for(int i =0 ; i < size_data ; i++){
		*((unsigned char*)dst_data++) = *((unsigned char*)src_data++);
	}

	// initialize bss In RAM With Zero;
	unsigned int size_bss =  (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	dst_data =  (unsigned char*)&_S_bss;
	for(int i =0 ; i < size_bss ; i++){
		*((unsigned char*)dst_data++) = (unsigned char) 0;
	}
	// Jump To main
	main();
}

static unsigned long stack_top[256] ;  //(256*4) in bss//


void (* const stack []) () __attribute__((section(".vectors"))) = {

	(void (*) () ) (stack_top + sizeof(stack_top)),
	&reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&NM_fault_Handler,
	&Bus_fault,
	&Usage_fault_Handler

};






