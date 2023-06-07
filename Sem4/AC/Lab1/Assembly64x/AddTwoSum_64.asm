INCLUDE Irvine64.inc	

section .data
    message db 'Hello, world!',0

section .code
main PROC
    ; print message to console
    mov rdx, message
    call WriteString
    
    ; exit program
    call Crlf
    call WaitMsg
    xor eax, eax
    ret
main ENDP
