global uint_a_cadena_binario

	section .text

uint_a_cadena_binario:

				push ebp
				mov ebp,esp
				mov eax,[ebp+12]
				mov ecx,[ebp+8]
				mov edx,0
desplazar:
				shl ecx,1
				;cmovc [eax+edx],'1'
				;cmovnc [eax+edx],'0'

				jc uno

cero:
				mov byte[eax+edx],'0'
				jmp fin

uno:
				mov byte[eax+edx],'1'

fin:
				add edx,1
				cmp edx,32
				jc desplazar

				mov byte[eax+edx],0;Caracter terminador, no se imprime
				pop ebp
				ret
