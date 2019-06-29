global calcular_histograma

	section .text

calcular_histograma:
	;int calcular_histograma(const unsigned char* ptr_datos,unsigned int num_datos,unsigned int *ptr_histograma);
	;RDI,RSI,RDX
		xor rax,rax

		test rdi,rdi
		jz fin
		test rdx,rdx
		jz fin

		mov rax,1

		xor r9,r9
		xor r10,r10
poner_cero:

		cmp r10,123;la mitad porque es quadword,64 bits = 8 bytes
		jz bucle_1
		mov [rdx+r10*8],r9
		inc r10
		jmp poner_cero

bucle_1:
		xor r8,r8

		cmp r9,rsi
		jz fin

		mov r8b,byte[rdi+r9]

		inc dword[rdx+r8*4]
		inc r9

		jmp bucle_1

fin:

ret
