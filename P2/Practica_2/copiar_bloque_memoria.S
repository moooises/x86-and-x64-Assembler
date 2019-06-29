global copiar_bloque_memoria

	section .text

copiar_bloque_memoria:

						push ebp
						mov ebp,esp
						mov esi,[ebp+16]
						mov edi,[ebp+8]
						mov eax,[ebp+20]

;esto comprueba si de longitud 64 bits(quad word)
comprobacion:
						cmp eax,0
						jz fin

						mov edx,64
						cdq
						div edx

						cmp edx,0

						jz comprobar_doubleword

						mov ecx,eax
						mov eax,2
						mul eax
						rep
						movsd

						jmp fin

comprobar_doubleword:
						mov edx,32
						cdq
						div edx

						cmp edx,0

						jz comprobar_word

						mov ecx,eax
						rep
						movsd

						jmp fin
comprobar_word:
						mov edx,16
						cdq
						div edx

						cmp edx,0

						jz comprobar_byte

						mov ecx,eax
						rep
						movsw

						jmp fin

comprobar_byte:
						mov edx,8
						cdq
						div edx

						cmp edx,0

					;	jz comprobar_half_byte
						mov ecx,eax

						rep
						movsb

						add edi,8
						add esi,8
						sub eax,1

						jmp comprobacion

fin:
						pop ebp
						ret
