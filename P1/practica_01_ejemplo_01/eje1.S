global eje1

		section .text

eje1: 	push ebp
		mov ebp, esp
		mov eax, [ebp + 8]
		cmp eax, [ebp + 12]
		cmovle eax, [ebp +12]
		pop ebp
		ret


