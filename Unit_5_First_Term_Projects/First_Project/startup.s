	.cpu cortex-m3
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"startup.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	1
	.global	Default_Handler
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	Default_Handler, %function
Default_Handler:
.LFB0:
	.file 1 "startup.c"
	.loc 1 9 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
.LCFI0:
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
.LCFI1:
	.cfi_def_cfa_register 7
	.loc 1 11 0
	bl	reset_Handler
	.loc 1 12 0
	nop
	pop	{r7, pc}
	.cfi_endproc
.LFE0:
	.size	Default_Handler, .-Default_Handler
	.weak	Usage_fault_Handler
	.thumb_set Usage_fault_Handler,Default_Handler
	.weak	Bus_fault
	.thumb_set Bus_fault,Default_Handler
	.weak	NM_fault_Handler
	.thumb_set NM_fault_Handler,Default_Handler
	.weak	H_fault_Handler
	.thumb_set H_fault_Handler,Default_Handler
	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler
	.global	vectors
	.section	.vectors,"aw",%progbits
	.align	2
	.type	vectors, %object
	.size	vectors, 28
vectors:
	.word	_stack_top
	.word	reset_Handler
	.word	NMI_Handler
	.word	H_fault_Handler
	.word	NM_fault_Handler
	.word	Bus_fault
	.word	Usage_fault_Handler
	.text
	.align	1
	.global	reset_Handler
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	reset_Handler, %function
reset_Handler:
.LFB1:
	.loc 1 40 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
.LCFI2:
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #24
.LCFI3:
	.cfi_def_cfa_offset 32
	add	r7, sp, #0
.LCFI4:
	.cfi_def_cfa_register 7
	.loc 1 43 0
	ldr	r2, .L7
	ldr	r3, .L7+4
	subs	r3, r2, r3
	str	r3, [r7, #4]
	.loc 1 44 0
	ldr	r3, .L7+8
	str	r3, [r7, #20]
	.loc 1 45 0
	ldr	r3, .L7+4
	str	r3, [r7, #16]
.LBB2:
	.loc 1 46 0
	movs	r3, #0
	str	r3, [r7, #12]
	b	.L3
.L4:
	.loc 1 47 0 discriminator 3
	ldr	r2, [r7, #20]
	adds	r3, r2, #1
	str	r3, [r7, #20]
	ldr	r3, [r7, #16]
	adds	r1, r3, #1
	str	r1, [r7, #16]
	ldrb	r2, [r2]	@ zero_extendqisi2
	strb	r2, [r3]
	.loc 1 46 0 discriminator 3
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L3:
	.loc 1 46 0 is_stmt 0 discriminator 1
	ldr	r3, [r7, #12]
	ldr	r2, [r7, #4]
	cmp	r2, r3
	bhi	.L4
.LBE2:
	.loc 1 51 0 is_stmt 1
	ldr	r2, .L7+12
	ldr	r3, .L7+16
	subs	r3, r2, r3
	str	r3, [r7]
	.loc 1 52 0
	ldr	r3, .L7+16
	str	r3, [r7, #16]
.LBB3:
	.loc 1 53 0
	movs	r3, #0
	str	r3, [r7, #8]
	b	.L5
.L6:
	.loc 1 54 0 discriminator 3
	ldr	r3, [r7, #16]
	adds	r2, r3, #1
	str	r2, [r7, #16]
	movs	r2, #0
	strb	r2, [r3]
	.loc 1 53 0 discriminator 3
	ldr	r3, [r7, #8]
	adds	r3, r3, #1
	str	r3, [r7, #8]
.L5:
	.loc 1 53 0 is_stmt 0 discriminator 1
	ldr	r3, [r7, #8]
	ldr	r2, [r7]
	cmp	r2, r3
	bhi	.L6
.LBE3:
	.loc 1 58 0 is_stmt 1
	bl	main
	.loc 1 59 0
	nop
	adds	r7, r7, #24
.LCFI5:
	.cfi_def_cfa_offset 8
	mov	sp, r7
.LCFI6:
	.cfi_def_cfa_register 13
	@ sp needed
	pop	{r7, pc}
.L8:
	.align	2
.L7:
	.word	_E_data
	.word	_S_data
	.word	_E_text
	.word	_E_bss
	.word	_S_bss
	.cfi_endproc
.LFE1:
	.size	reset_Handler, .-reset_Handler
.Letext0:
	.file 2 "c:\\program files (x86)\\gnu tools arm embedded\\7 2017-q4-major\\arm-none-eabi\\include\\machine\\_default_types.h"
	.file 3 "c:\\program files (x86)\\gnu tools arm embedded\\7 2017-q4-major\\arm-none-eabi\\include\\sys\\_stdint.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x18c
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF22
	.byte	0xc
	.4byte	.LASF23
	.4byte	.LASF24
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x3
	.4byte	.LASF9
	.byte	0x2
	.byte	0x4f
	.4byte	0x53
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x3
	.4byte	.LASF10
	.byte	0x3
	.byte	0x30
	.4byte	0x48
	.uleb128 0x5
	.4byte	.LASF11
	.byte	0x1
	.byte	0x15
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x6
	.4byte	0x76
	.4byte	0x9e
	.uleb128 0x7
	.4byte	0x6f
	.byte	0x6
	.byte	0
	.uleb128 0x8
	.4byte	.LASF12
	.byte	0x1
	.byte	0x16
	.4byte	0x8e
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	vectors
	.uleb128 0x5
	.4byte	.LASF13
	.byte	0x1
	.byte	0x22
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.4byte	.LASF14
	.byte	0x1
	.byte	0x23
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.4byte	.LASF15
	.byte	0x1
	.byte	0x24
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.4byte	.LASF16
	.byte	0x1
	.byte	0x25
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x5
	.4byte	.LASF17
	.byte	0x1
	.byte	0x26
	.4byte	0x6f
	.byte	0x1
	.byte	0x1
	.uleb128 0x9
	.byte	0x1
	.4byte	.LASF25
	.byte	0x1
	.byte	0x28
	.byte	0x1
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LLST1
	.byte	0x1
	.4byte	0x174
	.uleb128 0xa
	.4byte	.LASF18
	.byte	0x1
	.byte	0x2b
	.4byte	0x6f
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xa
	.4byte	.LASF19
	.byte	0x1
	.byte	0x2c
	.4byte	0x174
	.byte	0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xa
	.4byte	.LASF20
	.byte	0x1
	.byte	0x2d
	.4byte	0x174
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0xa
	.4byte	.LASF21
	.byte	0x1
	.byte	0x33
	.4byte	0x6f
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xb
	.4byte	.LBB2
	.4byte	.LBE2
	.4byte	0x15d
	.uleb128 0xc
	.ascii	"i\000"
	.byte	0x1
	.byte	0x2e
	.4byte	0x68
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xd
	.4byte	.LBB3
	.4byte	.LBE3
	.uleb128 0xc
	.ascii	"i\000"
	.byte	0x1
	.byte	0x35
	.4byte	0x68
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0xe
	.byte	0x4
	.4byte	0x2c
	.uleb128 0xf
	.byte	0x1
	.4byte	.LASF26
	.byte	0x1
	.byte	0x9
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LLST0
	.byte	0x1
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST1:
	.4byte	.LFB1-.Ltext0
	.4byte	.LCFI2-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 0
	.4byte	.LCFI2-.Ltext0
	.4byte	.LCFI3-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 8
	.4byte	.LCFI3-.Ltext0
	.4byte	.LCFI4-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 32
	.4byte	.LCFI4-.Ltext0
	.4byte	.LCFI5-.Ltext0
	.2byte	0x2
	.byte	0x77
	.sleb128 32
	.4byte	.LCFI5-.Ltext0
	.4byte	.LCFI6-.Ltext0
	.2byte	0x2
	.byte	0x77
	.sleb128 8
	.4byte	.LCFI6-.Ltext0
	.4byte	.LFE1-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 8
	.4byte	0
	.4byte	0
.LLST0:
	.4byte	.LFB0-.Ltext0
	.4byte	.LCFI0-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 0
	.4byte	.LCFI0-.Ltext0
	.4byte	.LCFI1-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 8
	.4byte	.LCFI1-.Ltext0
	.4byte	.LFE0-.Ltext0
	.2byte	0x2
	.byte	0x77
	.sleb128 8
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF23:
	.ascii	"startup.c\000"
.LASF16:
	.ascii	"_S_bss\000"
.LASF18:
	.ascii	"size_data\000"
.LASF19:
	.ascii	"src_data\000"
.LASF24:
	.ascii	"E:\\Final_Project_1\000"
.LASF25:
	.ascii	"reset_Handler\000"
.LASF1:
	.ascii	"unsigned char\000"
.LASF5:
	.ascii	"long unsigned int\000"
.LASF22:
	.ascii	"GNU C11 7.2.1 20170904 (release) [ARM/embedded-7-br"
	.ascii	"anch revision 255204] -mcpu=cortex-m3 -mthumb -gdwa"
	.ascii	"rf-2\000"
.LASF3:
	.ascii	"short unsigned int\000"
.LASF20:
	.ascii	"dst_data\000"
.LASF12:
	.ascii	"vectors\000"
.LASF15:
	.ascii	"_E_data\000"
.LASF9:
	.ascii	"__uint32_t\000"
.LASF13:
	.ascii	"_E_text\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF11:
	.ascii	"_stack_top\000"
.LASF17:
	.ascii	"_E_bss\000"
.LASF6:
	.ascii	"long long int\000"
.LASF26:
	.ascii	"Default_Handler\000"
.LASF2:
	.ascii	"short int\000"
.LASF14:
	.ascii	"_S_data\000"
.LASF10:
	.ascii	"uint32_t\000"
.LASF4:
	.ascii	"long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF21:
	.ascii	"size_bss\000"
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2017-q4-major) 7.2.1 20170904 (release) [ARM/embedded-7-branch revision 255204]"
