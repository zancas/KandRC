	.file	"fastbitcount.c"
	.section	.rodata
.LC0:
	.string	"NO!"
.LC1:
	.string	"fast"
.LC2:
	.string	"classic"
.LC3:
	.string	"bitcount of %d is %d.\n"
.LC4:
	.string	"fbitcount of %d is %d.\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$21474830, -4(%rbp)
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L2
	movl	$.LC0, %edi
	call	puts
	movl	$15, %eax
	jmp	.L3
.L2:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L4
	jmp	.L5
.L6:
	movl	$2147483647, %edi
	call	fbitcount
	subl	$1, -4(%rbp)
.L5:
	cmpl	$0, -4(%rbp)
	jg	.L6
	jmp	.L7
.L4:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L7
	jmp	.L8
.L9:
	movl	$2147483647, %edi
	call	bitcount
	subl	$1, -4(%rbp)
.L8:
	cmpl	$0, -4(%rbp)
	jg	.L9
.L7:
	movl	$2147483647, %edi
	call	bitcount
	movl	%eax, %edx
	movl	$.LC3, %eax
	movl	$2147483647, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$2147483647, %edi
	call	fbitcount
	movl	%eax, %edx
	movl	$.LC4, %eax
	movl	$2147483647, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
.L3:
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.globl fbitcount
	.type	fbitcount, @function
fbitcount:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L12
	movl	$0, %eax
	jmp	.L13
.L12:
	movl	$1, -4(%rbp)
	jmp	.L14
.L15:
	addl	$1, -4(%rbp)
.L14:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	andl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L15
	movl	-4(%rbp), %eax
.L13:
	leave
	ret
	.cfi_endproc
.LFE1:
	.size	fbitcount, .-fbitcount
.globl bitcount
	.type	bitcount, @function
bitcount:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L18
.L20:
	movl	-20(%rbp), %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L19
	addl	$1, -4(%rbp)
.L19:
	shrl	-20(%rbp)
.L18:
	cmpl	$0, -20(%rbp)
	jne	.L20
	movl	-4(%rbp), %eax
	leave
	ret
	.cfi_endproc
.LFE2:
	.size	bitcount, .-bitcount
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
