	.file	"pomoc.c"
	.text
	.section	.rodata
.LC0:
	.string	"%llu %llu"
.LC1:
	.string	"%i"
.LC4:
	.string	"%llu"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	cmpq	%rax, %rdx
	jne	.L2
	movl	$0, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp	.L10
.L2:
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L4
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	%xmm1, %rax
	jmp	.L5
.L4:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movq	%xmm0, %rax
.L5:
	movq	%rax, %xmm0
	call	sqrt@PLT
	movsd	%xmm0, -64(%rbp)
	fldl	-64(%rbp)
	leaq	-16(%rsp), %rsp
	fstpt	(%rsp)
	call	roundl@PLT
	addq	$16, %rsp
	fstpt	-64(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L6
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rax, %xmm2
	movq	%xmm2, %rax
	jmp	.L7
.L6:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	movq	%xmm0, %rax
.L7:
	movq	%rax, %xmm0
	call	sqrt@PLT
	movsd	%xmm0, -48(%rbp)
	fldl	-48(%rbp)
	leaq	-16(%rsp), %rsp
	fstpt	(%rsp)
	call	ceill@PLT
	addq	$16, %rsp
	fldt	-64(%rbp)
	faddp	%st, %st(1)
	fld1
	fsubrp	%st, %st(1)
	fldt	.LC3(%rip)
	fxch	%st(1)
	fcomi	%st(1), %st
	fstp	%st(1)
	jnb	.L8
	fnstcw	-34(%rbp)
	movzwl	-34(%rbp), %eax
	orb	$12, %ah
	movw	%ax, -36(%rbp)
	fldcw	-36(%rbp)
	fistpq	-64(%rbp)
	fldcw	-34(%rbp)
	movq	-64(%rbp), %rax
	jmp	.L9
.L8:
	fldt	.LC3(%rip)
	fsubrp	%st, %st(1)
	fnstcw	-34(%rbp)
	movzwl	-34(%rbp), %eax
	orb	$12, %ah
	movw	%ax, -36(%rbp)
	fldcw	-36(%rbp)
	fistpq	-64(%rbp)
	fldcw	-34(%rbp)
	movq	-64(%rbp), %rax
	movabsq	$-9223372036854775808, %rdx
	xorq	%rdx, %rax
.L9:
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
.L10:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 16
.LC3:
	.long	0
	.long	-2147483648
	.long	16446
	.long	0
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
