INCLUDE Irvine32.inc

.data 
mes1 byte "Valoarea X:",0
mes2 byte "Valoarea Y:",0
mes3 byte "Rezultatul este:",0
f1 byte "z = (y-2x)-y+123 | if x-y/2 > 0",0
f2 byte "z = 2x-153+y | if x-y/2 <= 0",0
vrx  dword ?
vry  dword ?
intDivisor dword 2
interm  dd 0
rez  dd 0

.code 
main proc
    ; Read X from keyboard
    mov edx,OFFSET mes1
    call WriteString ; afisarea mes1
    call ReadInt ; citirea valorii X
    mov vrx,eax ; salvarea valorii citite

    ; Read Y from keyboard
    mov edx,OFFSET mes2
    call WriteString ; afisarea mes2
    call ReadInt ; citirea valorii Y
    mov vry,eax ; salvarea valorii citite

    ;controlam conditiile
    xor eax,eax
    mov edx,0

    mov ebx, vry
    sub ebx, vrx
    mov eax, intDivisor
    cdq
    idiv eax, ebx
    cmp ebx, 0 ; x-y/2 > 0
    ja con1 ;salt la con1, daca x-y/2 > 0

    mov edx,OFFSET f2
    call WriteString
    call Crlf
    ;realizam expresia 2x-153+y
    mov eax,vrx
    shl eax,1 ;inmultim X cu 2
    add eax, vry
    sub eax, 153
    mov rez,eax
    jmp ex ;salt neconditionat la ex

    con1: 
    mov edx,OFFSET f1
    call WriteString
    call Crlf

    ;realizam expresia (y-2x)-y+123
    mov eax, vry
    sub eax, vrx
    shl eax, 1 ;inmultim (y-2x) cu 2
    sub eax, vry ; scadem y
    add eax, 123 ; adaugam 123
    mov rez,eax

    ex: mov edx,OFFSET mes3
    call WriteString ; afisarea mesajului mes3 
    call WriteInt ; afisarea rezultatului cu semn
    call Crlf ; din rand nou

    exit
main ENDP
END main
