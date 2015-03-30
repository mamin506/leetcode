	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"Solution.cpp"
	.section	.rodata
	.align	2
	.type	_ZStL19piecewise_construct, %object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.space	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,4
	.section	.text._ZN8ListNodeC2Ei,"axG",%progbits,_ZN8ListNodeC5Ei,comdat
	.align	2
	.weak	_ZN8ListNodeC2Ei
	.type	_ZN8ListNodeC2Ei, %function
_ZN8ListNodeC2Ei:
	.fnstart
.LFB1551:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-12]
	str	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	mov	r2, #0
	str	r2, [r3, #4]
	ldr	r3, [fp, #-8]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.cantunwind
	.fnend
	.size	_ZN8ListNodeC2Ei, .-_ZN8ListNodeC2Ei
	.weak	_ZN8ListNodeC1Ei
_ZN8ListNodeC1Ei = _ZN8ListNodeC2Ei
	.section	.text._ZN8Solution8hasCycleEP8ListNode,"axG",%progbits,_ZN8Solution8hasCycleEP8ListNode,comdat
	.align	2
	.weak	_ZN8Solution8hasCycleEP8ListNode
	.type	_ZN8Solution8hasCycleEP8ListNode, %function
_ZN8Solution8hasCycleEP8ListNode:
	.fnstart
.LFB1553:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	ldr	r3, [fp, #-20]
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-20]
	str	r3, [fp, #-12]
	b	.L5
.L9:
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #4]
	ldr	r3, [r3, #4]
	str	r3, [fp, #-12]
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	bne	.L5
	mov	r3, #1
	b	.L6
.L5:
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	beq	.L7
	ldr	r3, [fp, #-12]
	ldr	r3, [r3, #4]
	cmp	r3, #0
	beq	.L7
	mov	r3, #1
	b	.L8
.L7:
	mov	r3, #0
.L8:
	cmp	r3, #0
	bne	.L9
	mov	r3, #0
.L6:
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.cantunwind
	.fnend
	.size	_ZN8Solution8hasCycleEP8ListNode, .-_ZN8Solution8hasCycleEP8ListNode
	.section	.rodata
	.align	2
.LC0:
	.ascii	"has cycle\000"
	.align	2
.LC1:
	.ascii	"no cycle\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
.LFB1554:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, fp, lr}
	.save {r4, fp, lr}
	.setfp fp, sp, #8
	add	fp, sp, #8
	.pad #36
	sub	sp, sp, #36
	str	r0, [fp, #-40]
	str	r1, [fp, #-44]
	mov	r0, #8
.LEHB0:
	bl	_Znwj
	mov	r3, r0
	mov	r4, r3
	mov	r0, r4
	mov	r1, #1
	bl	_ZN8ListNodeC1Ei
	str	r4, [fp, #-16]
	mov	r0, #8
	bl	_Znwj
	mov	r3, r0
	mov	r4, r3
	mov	r0, r4
	mov	r1, #3
	bl	_ZN8ListNodeC1Ei
	str	r4, [fp, #-20]
	mov	r0, #8
	bl	_Znwj
	mov	r3, r0
	mov	r4, r3
	mov	r0, r4
	mov	r1, #4
	bl	_ZN8ListNodeC1Ei
	str	r4, [fp, #-24]
	mov	r0, #8
	bl	_Znwj
	mov	r3, r0
	mov	r4, r3
	mov	r0, r4
	mov	r1, #5
	bl	_ZN8ListNodeC1Ei
	str	r4, [fp, #-28]
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-20]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-20]
	ldr	r2, [fp, #-24]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-24]
	ldr	r2, [fp, #-28]
	str	r2, [r3, #4]
	ldr	r3, [fp, #-28]
	ldr	r2, [fp, #-20]
	str	r2, [r3, #4]
	sub	r3, fp, #32
	mov	r0, r3
	ldr	r1, [fp, #-16]
	bl	_ZN8Solution8hasCycleEP8ListNode
	mov	r3, r0
	cmp	r3, #0
	beq	.L11
	ldr	r0, .L17
	ldr	r1, .L17+4
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	r3, r0
	mov	r0, r3
	ldr	r1, .L17+8
	bl	_ZNSolsEPFRSoS_E
	b	.L12
.L11:
	ldr	r0, .L17
	ldr	r1, .L17+12
	bl	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	r3, r0
	mov	r0, r3
	ldr	r1, .L17+8
	bl	_ZNSolsEPFRSoS_E
.LEHE0:
.L12:
	mov	r3, #0
	b	.L16
.L15:
.LEHB1:
	bl	__cxa_end_cleanup
.LEHE1:
.L16:
	mov	r0, r3
	sub	sp, fp, #8
	ldmfd	sp!, {r4, fp, pc}
.L18:
	.align	2
.L17:
	.word	_ZSt4cout
	.word	.LC0
	.word	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.word	.LC1
	.global	__gxx_personality_v0
	.personality	__gxx_personality_v0
	.handlerdata
.LLSDA1554:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1554-.LLSDACSB1554
.LLSDACSB1554:
	.uleb128 .LEHB0-.LFB1554
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L15-.LFB1554
	.uleb128 0
	.uleb128 .LEHB1-.LFB1554
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1554:
	.text
	.fnend
	.size	main, .-main
	.align	2
	.type	_Z41__static_initialization_and_destruction_0ii, %function
_Z41__static_initialization_and_destruction_0ii:
	.fnstart
.LFB1713:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-8]
	cmp	r3, #1
	bne	.L19
	ldr	r2, [fp, #-12]
	ldr	r3, .L21
	cmp	r2, r3
	bne	.L19
	ldr	r0, .L21+4
	bl	_ZNSt8ios_base4InitC1Ev
	ldr	r0, .L21+4
	ldr	r1, .L21+8
	ldr	r2, .L21+12
	bl	__aeabi_atexit
.L19:
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L22:
	.align	2
.L21:
	.word	65535
	.word	_ZStL8__ioinit
	.word	_ZNSt8ios_base4InitD1Ev
	.word	__dso_handle
	.cantunwind
	.fnend
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align	2
	.type	_GLOBAL__sub_I_main, %function
_GLOBAL__sub_I_main:
	.fnstart
.LFB1714:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	mov	r0, #1
	ldr	r1, .L24
	bl	_Z41__static_initialization_and_destruction_0ii
	ldmfd	sp!, {fp, pc}
.L25:
	.align	2
.L24:
	.word	65535
	.cantunwind
	.fnend
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align	2
	.word	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Debian 4.7.2-5+rpi1) 4.7.2"
	.section	.note.GNU-stack,"",%progbits
