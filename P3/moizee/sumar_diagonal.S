global sumar_diagonal

	section .text

sumar_diagonal:
;RDI,RSI,RDX,RCX,R8,R9,RAX,R10,R11
;RAX para el retorno
;int sumar_diagonal(long *matriz,unsigned int num_filas_columnas,long *resultado);

				xor r10,r10
				xor r11,r11
				xor r9,r9
				xor r8,r8
				mov dword[rdx],0


sumar:
			mov r9,[rdi+r10*8]
			add qword[rdx],r9

			inc r8
			add r11,rsi
			inc r11
			mov r10,r11

			cmp r8,rsi
			jnz sumar

fin:
ret
