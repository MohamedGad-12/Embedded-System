/* learn in depth 
Eng. Mohamed Gamal */



.section .vectors

.word 0x20001000  		/*stack pointer*/
.word _reset 			/*resrt*/
.word vector_handler	/*NMI*/
.word vector_handler	/*Hard Fault*/
.word vector_handler	/*Mem Manage*/
.word vector_handler	/*Bus Fault*/
.word vector_handler	/*Usage Fault*/
.word vector_handler	/*Reserved*/
.word vector_handler	/*Reserved*/
.word vector_handler	/*Reserved*/
.word vector_handler	/*Reserved*/
.word vector_handler	/*Sv Call*/
.word vector_handler	/*Debug mointor*/
.word vector_handler	/*Reserved*/
.word vector_handler	/*pend Sv*/
.word vector_handler	/*sys tick*/
.word vector_handler	/*IRQ 0*/
.word vector_handler	/*IRQ 1*/
.word vector_handler	/*IRQ 2*/	
.word vector_handler	/*.....*/
						/*On to IR7*/


.section .text
_reset:
	bl main
	b .

.thumb_func
vector_handler:
	b _reset
