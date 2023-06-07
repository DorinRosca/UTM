INCLUDE Irvine32.inc

.data 
mes1 byte "Valoarea X:",0
mes2 byte "Valoarea Y:",0
mes3 byte "Rezultatul este:",0
f1 byte "z = (y-2*x)-y+123 | if x-y/2 > 0",0
f2 byte "z = 2*x-153+y | if x-y/2 <= 0",0
vrx  dword 0
vry  dword 0
interm  dd 0
rez  dd 0


.code 
 main proc
    mov edx,OFFSET mes1
    call WriteString ; afisarea mes1
    
    call Random32
    mov  eax,10    ;get random 0 to 10
    call RandomRange ;
    mov  vrx,eax  ;save random number
    call WriteInt ; afisarea rezultatului cu semn
    call Crlf ; din rand nou

    mov edx,OFFSET mes2
    call WriteString ; afisarea mes2

    call Randomize
    mov  eax,10    ;get random 0 to 10
    call RandomRange ;
    mov  vry,eax  ;save random number
    call WriteInt ; afisarea rezultatului cu semn
    call Crlf ; din rand nou


    ;controlam conditiile
    xor eax,eax
    mov edx,0

    mov eax,vrx
    sub eax,vry ;calculam diferenta X-Y
    cmp eax,0 ;comparam cu 0
    jg con1 ;salt la con1, daca X-Y/2 > 0


    mov edx,OFFSET f2
    call WriteString
    call Crlf
    ;realizam expresia 2x-153+y
    mov eax,vrx
    shl eax,1 ;inmultim X cu 2
    sub eax,153
    add eax,vry
    mov rez,eax
    jmp ex ;salt neconditionat la ex

    con1: 
    mov edx,OFFSET f1
    call WriteString
    call Crlf

    ;realizam expresia (y-2x)-y+123
    mov eax,vry
    mov ebx,vrx
    shl ebx,1 ;inmultim X cu 2
    sub eax,ebx
    sub eax,vry
    add eax,123
    mov rez,eax

    ex: mov edx,OFFSET mes3
    call WriteString ; afisarea mesajului mes3 
    call WriteInt ; afisarea rezultatului cu semn
    call Crlf ; din rand nou



exit
main ENDP
END main
