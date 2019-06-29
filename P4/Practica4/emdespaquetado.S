global empaquetar,desempaquetar

	section .text

;RDI,RSI
;int empaquetar(const struct estructura *origen,struct estructura_empaquetada *destino);
;int desempaquetar(const struct estructura_empaquetada *origen,struct estructura *destino);

desempaquetar:
	xor rax,rax

	test rdi,rdi
	jz fin
	test rsi,rsi
	jz fin

	mov rax,1
	xor r8,r8
	xor r9,r9
	xor r10,r10
d_short_2:
	mov r9w,word[rdi+r8],
	mov word[rsi+r8],r9w
	add r8,2;2
	xor r9,r9
d_byte_1x3:
	mov r9b,byte[rdi+r8]
	mov byte[rsi+r8],r9b
	inc r8
	cmp r8,5
	jnz d_byte_1x3;r8=5
	mov r10,r8;en r10 esta el incremento del empaquetado
	add r8,3;r8=8,r10=5
	xor r9,r9
d_int_4:
	mov r9d,dword[rdi+r10]
	mov dword[rsi+r8],r9d
	add r10,4;r10=9
	add r8,8;r8=16
	xor r9,r9
d_long_8:
	mov r9,qword[rdi+r10]
	mov qword[rsi+r8],r9

jmp fin


empaquetar:
	xor rax,rax

	test rdi,rdi
	jz fin
	test rsi,rsi
	jz fin

	mov rax,1
	xor r8,r8
	xor r9,r9
	xor r10,r10
short_2:
	mov r9w,word[rdi+r8],
	mov word[rsi+r8],r9w
	add r8,2;2
	xor r9,r9
byte_1x3:
	mov r9b,byte[rdi+r8]
	mov byte[rsi+r8],r9b
	inc r8
	cmp r8,5
	jnz byte_1x3;r8=5
	mov r10,r8;en r10 esta el incremento del empaquetado
	add r8,3;r8=8,r10=5
	xor r9,r9
int_4:
	mov r9d,dword[rdi+r8]
	mov dword[rsi+r10],r9d
	add r10,4;r10=9
	add r8,8;r8=16
	xor r9,r9
long_8:
	mov r9,qword[rdi+r8]
	mov qword[rsi+r10],r9
ret

fin:

ret
