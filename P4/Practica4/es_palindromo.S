global es_palindromo
	section .text

es_palindromo:
;int es_palindromo(const char *cadena);
;RDI,RSI,RDX

		xor r10,r10

		xor r12,r12

		xor r8,r8
		xor r9,r9

		mov rax,-1
		test rdi,rdi
		jz final
		mov rax,0

longitud:
	inc r8
	mov r9b,byte[rdi+r8]
	cmp r9b,0
	jnz longitud


	xor r9,r9
	dec r8
bucle:


	mov r10b,byte[rdi+r8];esto da 0, tiene que ser r8-1
	mov r9b,byte[rdi+r12]

	cmp r9b,r10b
	jnz final

	inc r12
	cmp r12, r8
	jz es_pal

	dec r8
	cmp r12,r8
	jz es_pal

	jmp bucle

es_pal:
		mov rax,1

final:

ret
