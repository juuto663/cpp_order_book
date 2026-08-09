	.file	"hello_world.cpp"
# GNU C++20 (GCC) version 15.3.0 (x86_64-unknown-linux-gnu)
#	compiled by GNU C version 15.3.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.4.1, isl version isl-0.20-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -U _FORTIFY_SOURCE -U _FORTIFY_SOURCE -D _FORTIFY_SOURCE=3 -mno-omit-leaf-frame-pointer -mtls-dialect=gnu2 -mtune=generic -march=x86-64 -O2 -O0 -std=c++20 -fPIC -fstack-clash-protection -fzero-call-used-regs=used-gpr -fstrict-flex-arrays=1 -fstack-protector-strong -fno-strict-overflow -fno-omit-frame-pointer -frandom-seed=lkrifry61i --param=ssp-buffer-size=4
	.text
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
.LC0:
	.string	"Hello, World!"
#NO_APP
	.text
	.globl	main
	.type	main, @function
main:
.LFB2358:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# src/hello_world.cpp:5:   std::cout << "Hello, World!" << std::endl;
	leaq	.LC0(%rip), %rax	#, tmp101
	movq	_ZSt4cout@GOTPCREL(%rip), %rdx	#, tmp103
	movq	%rax, %rsi	# tmp101,
	movq	%rdx, %rdi	# tmp102,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
# src/hello_world.cpp:5:   std::cout << "Hello, World!" << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp105
	movq	%rdx, %rsi	# tmp104,
	movq	%rax, %rdi	# _1,
	call	_ZNSolsEPFRSoS_E@PLT	#
# src/hello_world.cpp:6:   return 0;
	movl	$0, %eax	#, _6
# src/hello_world.cpp:7: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2358:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.3.0"
	.section	.note.GNU-stack,"",@progbits
