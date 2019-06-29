global det

		section .text

det:	push ebp
		mov ebp, esp
		mov eax, [ebp+8]
		imul eax, [ebp+20]
		mov ecx, [ebp+16]
		imul ecx,[ebp+12]
		sub eax,ecx

		pop ebp
		ret

