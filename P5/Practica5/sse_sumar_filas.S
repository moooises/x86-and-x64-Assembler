 global      sse_sumar_filas

        section    .text

sse_sumar_filas:
;rdi,rsi,rdx,rcx
;int sse_sumar_filas(const float *ptr_matriz, float *ptr_suma);
	xor rax,rax

	test rdi,rdi
	jz fin
	test rsi,rsi
	jz fin

	mov rax,1

	xor r8,r8
	xor r9,r9

	pxor xmm0,xmm0
	pxor xmm1,xmm1

bucle:

	movaps xmm0,[rdi+r9]
	addps xmm1,xmm0

	inc r8
	add r9,16
	cmp r8,4
	jnz bucle

	movaps [rsi],xmm1

fin:

ret
