global convertir_celcius_fahrenheit

	section .text

convertir_celcius_fahrenheit:
								push ebp
								mov ebp,esp
								mov eax,[ebp+8]
								mov ecx,[ebp+12]
								push eax
								mov eax,[ebp+24]
								cmp ecx,0

								jnz celsius

								sub eax,32
								imul eax,5
								mov ecx,9
								cdq
								idiv ecx

								jmp redondeo



celsius:
								imul eax,9
								mov ecx,5
								cdq
								idiv ecx
								add eax,32


redondeo:
								;push eax
								;push edx
								;mov ecx,2
								;mov eax,edx
								;cdq
								;div ecx



								mov edx,[ebp+16]
								mov [edx],eax
								pop ebp
								ret
