global contar_valor_en_array

		section .text
;RDI,RSI,RDX,RCX
;int contar_valor_en_array(int valor,int *array,unsigned int longitud,int *resultado);

contar_valor_en_array:
			mov rax,0
			test RSI,RSI
			jz final
			cmp RDX,0
			jz final
			mov dword[rcx],0;IMPORTANTE
			xor r10,r10;para ver cuanto falta para el final
			
bucle:
	
			
			mov r9d,[rsi+r10*4];r9d
			inc r10
			cmp r9,rdi
			jnz comp
			inc dword[rcx];IMPORTANTE
comp:			
			cmp r10,rdx
			jnz bucle
			
			 mov rax,1
			
final:
			ret
