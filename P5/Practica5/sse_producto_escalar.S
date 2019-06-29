global sse_producto_escalar

	section .text

;int sse_producto_escalar(const float *vector_1,
;						  const float *vector_2,
;						  unsigned int dimension,
;						  float *resultado);
;rdi,rsi,rdx,rcx

sse_producto_escalar:
		xor rax,rax

		test rdi,rdi
		jz fin
		test rsi,rsi
		jz fin
		test rcx,rcx
		jz fin

		mov rax,1
		xor r8,r8
		xor r9,r9
		pxor xmm0,xmm0
		pxor xmm1,xmm1
		pxor xmm2,xmm2


bucle:
		cmp rdx,4
		jl almacenar

		movaps xmm0,[rdi+r8]
		movaps xmm1,[rsi+r8]

		mulps xmm1,xmm0

		addps xmm2,xmm1

		sub rdx,4

		add r8,16
		jmp bucle

almacenar:

		haddps xmm2,xmm2
		haddps xmm2,xmm2
		movss [rcx],xmm2

menos_de_16_bytes:
		cmp rdx,0
		jz fin

		movss xmm0,[rdi+r8]
		movss xmm1,[rsi+r8]

		mulss xmm1,xmm0

		addss xmm1,[rcx]
		movss [rcx],xmm1

		add r8,4
		dec rdx
		jnz menos_de_16_bytes

fin:

ret
