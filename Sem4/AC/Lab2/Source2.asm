INCLUDE Irvine32.inc
		; sa se calculeze expresia aritmetica: z=((a*c-b*d)/f +(a+b)*c/d)/h
		; se considera a, b, c, d, f, h cuvinte de 16 biti (word)
		; ne vor interesa doar caturile impartirilor, rezultatul va fi de tip octet

.data
    a DWORD 4
    b DWORD -1
    cd DWORD 2
    d DWORD 1
    f DWORD 6
    h DWORD 2
    interm1 DWORD ?
    zInt DWORD ?
    zRest DWORD ?
    Conditie BYTE "z = ((a*c-b*d)/f +(a+b)*c/d)/h-Varianta 14", 0
    zInt_msg BYTE "z = ", 0
    zRest_msg BYTE ".", 0

.code
main proc
	; Calculate ((a*c - b*d)/f + (a+b)*c/d)/h and store the result in z
	mov eax, a		; eax = a
	mul cd			; eax = a * c
	mov ebx, b		; ebx = b
	mul d			; ebx = b * d
	sub eax, ebx		; eax = a * c - b * d
	cwd				; Convert the word in eax to a doubleword in edx:eax
	idiv f			; eax = (a * c - b * d) / f
	mov interm1, eax	; interm1 = (a * c - b * d) / f
	mov eax, a		; eax = a
	add eax, b		; eax = a + b
	mul cd			; eax = (a + b) * c
	cwd				; Convert the word in eax to a doubleword in edx:eax
	idiv d			; eax = (a + b) * c / d
	add eax, interm1	; eax = (a*c - b*d)/f + (a+b)*c/d
	cwd				; Convert the word in eax to a doubleword in edx:eax
	idiv h			; eax = ((a*c - b*d)/f + (a+b)*c/d)/h

	;stocare in zInt eax si in zFloat edx
	mov zInt, eax
	mov zRest, edx
	
	;Afisare Conditii
	mov edx, offset Conditie
	call WriteString
	call Crlf ; din rand nou

	;Afisare zInt
	mov edx, offset zInt_msg
	call WriteString
	mov eax, zint
	call WriteDec

	;Afisare zRest
	mov edx, offset zRest_msg
	call WriteString
	mov eax, zRest
	call WriteDec

    invoke ExitProcess, 0
main endp
end main