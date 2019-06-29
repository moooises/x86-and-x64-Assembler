
; int sse_imagen_a_blanco_y_negro(unsigned char *ptr_imagen,
;                                 int ancho,
;                                 int alto,
;                                 unsigned char umbral);

;rdi,rsi,rdx,rcx
        global      sse_imagen_a_blanco_y_negro

        section    .text

sse_imagen_a_blanco_y_negro:

		mov rax,0
		test rdi,rdi
		jz fin
		mov rax,1

		xor r8,r8

		mov r9,255
		pxor xmm1,xmm1
		pxor xmm2,xmm2
		movd xmm0,ecx

		movd xmm3,r9d
		pshufb xmm3,xmm1;ahora todos los bytes de xmm3 son 255
		pshufb xmm0,xmm1;ahora todos los bytes de xmm0 son umbral

		imul rdx,rsi;el numero de bloques
		mov r10,rdi

bucle_1:

		cmp rdx,r8
		jz fin

		cmp rdx,r8
		jl menos_de_16_pixeles

		movdqa xmm2,[r10];lo sacamos de memoria

		pminub xmm2,xmm0;los que estan por encima de 100, valen 100
		pcmpeqb xmm2,xmm0;todos los que valian 100 ahora valen 255

		pand xmm2,xmm3;todos los que no valieran 255 vale 0

		movdqa [r10],xmm2;lo devolvemos a memoria

		mov r11,r8
		add r8,16
		add r10,16


		jmp bucle_1

menos_de_16_pixeles:

		cmp rdx,r11
		jz fin

		;mov r12d,[r10]

		cmp [r10],ecx
		jg mayor

		mov byte[r10],0
		add r11,1
		add r10,1
		jmp menos_de_16_pixeles

mayor:
		mov byte[r10],255
		add r11,1
		add r10,1
		jmp menos_de_16_pixeles




fin:
		ret
