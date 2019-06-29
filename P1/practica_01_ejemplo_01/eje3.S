global eje3

		section .text

eje3:
		push ebp
		mov ebp,esp
		mov eax,[ebp+8]
		mov ecx,[ebp+12]
		and eax,0xff000
		and ecx,0x00fff
		or eax,ecx

		pop ebp
		ret




