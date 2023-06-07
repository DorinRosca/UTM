INCLUDE Irvine32.inc

.DATA
a DWORD 10
b DWORD 3
r DWORD 8
d DWORD 2
f DWORD 4
h DWORD 7
z DWORD ?
temp1 DWORD ?
temp2 DWORD ?

.CODE
main PROC
; z = ((a*r-b*d)/f +(a+b)*r/d)/h = ((5*4-7*6)/2 +(5+7)*4/6)/5 = -2
    ; move values into registers
    mov eax, a
    mov ebx, b
    mov ecx, r
    mov edx, d
    mov esi, f
    mov edi, h
    
    ; (a*r)-(b*d)
    imul eax, ecx
    imul ebx, edx
    sub eax, ebx
    
    ; Check if the divisor is zero before performing division
    cmp esi, 0
    je DivideByZeroError
    
    ; (a*r-b*d)/f
    cdq
    idiv esi
    mov temp1, eax
    
    ; ((a*r-b*d)/f+b)*r
    add eax, ebx
    imul eax, ecx
    cdq
    
    ; Check if the divisor is zero before performing division
    cmp edx, 0
    je DivideByZeroError
    
    ; compute the remainder from previous division
    idiv edx
    
    ; store the quotient in z
    mov z, eax
    
    ; calculate the decimal part of z
    mov eax, temp1
    mov ebx, h
    cdq
    idiv ebx
    mov edx, eax
    
    call DumpRegs
    
    ; Output z to the console
    mov eax, z
    call WriteDec
    call Crlf
    

    exit
    
DivideByZeroError:
    ; Handle divide by zero error here
    ; Display an error message or take appropriate action
    ; For example, you could set the quotient to zero or exit the program
    mov z, 0
    jmp ExitProgram
    
ExitProgram:
    ; Cleanup code goes here
    exit
    
main ENDP
END main
