INCLUDE Irvine32.inc

.data
msg BYTE 80 DUP(0) ; buffer to store user input
ecxbkp DWORD ? ;save ecx if necessary

.code
main PROC
    ; prompt user to enter string
    mov edx, OFFSET msg
    mov ecx, SIZEOF msg
    call ReadString

    ; find length of string
    mov eax, OFFSET msg
    mov esi, eax
    mov ecx, 0

    L1:
        inc ecx
        cmp BYTE PTR [eax+ecx], 0
        je L2
        jmp L1

    L2:
        inc ecx
        add eax, ecx               
        mov edi, eax               
        dec edi
        dec edi                               
        shr ecx,1                             

    L3:
        mov al, [esi]                        
        mov bl, [edi]
        mov [esi], bl                         
        mov [edi], al
        inc esi                               
        dec edi                               
        loop L3

    ; print reversed string
    mov edx, OFFSET msg
    call WriteString
    call Crlf

    exit
main ENDP

END main
