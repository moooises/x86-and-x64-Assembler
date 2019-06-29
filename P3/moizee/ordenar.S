global ordenar

	section .text


ordenar:
;int ordenar(int *array, unsigned int longitud);
;RDI,RSI,RDX,RCX,R8,R9,RAX,R10,R11
;RAX para el retorno


bucle_1:
		xor r8,r8
		xor r9,r9
		inc r9
		dec rsi
bucle_2:
		mov r10d,[rdi+r8*4]
		inc r8
		mov r11d,[rdi+r8*4]
		cmp r10d,r11d
		jl continuar

		dec r8
		mov dword[rdi+r8*4],r11d
		inc r8
		mov dword[rdi+r8*4],r10d


continuar:
		cmp rsi,0
		jz fin
		cmp r8,rsi
		jz bucle_1

		jmp bucle_2


fin:
ret
