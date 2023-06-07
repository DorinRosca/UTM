INCLUDE Irvine32.inc
;Sirul se inverseaza stiind lungimea acestuia
.data
msg    BYTE   "54321",0
ecxbkp DWORD  ?     ;save ecx if necessary 


.code
    main PROC
    mov ecx, SIZEOF msg                   ;initializare lungimea sirului
    mov eax, OFFSET msg                   ;adresa msg
    mov esi, eax                          ;muta esi in eax     
    add eax, ecx               
    mov edi, eax               
    dec edi
    dec edi                               ;edi points to end
    shr ecx,1                             ;shift loop counter 

L1: 
    mov al, [esi]                         ;incarcam caracterele
    mov bl, [edi]
    mov [esi], bl                         ;interschimb
    mov [edi], al
    inc esi                               ;increment +1
    dec edi                               ;decrement -1
loop L1

; afisare string

mov  edx,OFFSET msg
call WriteString				; afisare
call Crlf						; \n

exit
main ENDP

END main
