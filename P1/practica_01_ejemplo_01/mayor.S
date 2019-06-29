;===============================================================================
; Fichero: mayor.S
;-------------------------------------------------------------------------------
; Fichero con la función mayor en ensamblador que devuelve el mayor de dos
; números enteros pasados como parámetros.
;
; Versión para Linux.
;===============================================================================

		global mayor

		section .text

mayor: 	push ebp
		mov ebp, esp
		mov eax, [ebp + 8]
		cmp eax, [ebp + 12]
		jge short el_primero_es_mayor
		mov eax, [ebp + 12]

el_primero_es_mayor:
	pop ebp
	ret
