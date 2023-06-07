.model small
.stack 100h
.data
.code
start:
    mov ax, @data
    mov ds, ax

    mov ah, 00h ; set video mode
    mov al, 12h ; with resolution 640 columns x 480 lines
    int 10h ; call BIOS service

    ; wait for user input
    mov ah, 1
    int 21h
    cmp al, '1'
    je draw_netherlands_flag
    cmp al, '2'
    je draw_estonia_flag

    ; if user input is not 1 or 2, exit program
    mov ax, 4c00h
    int 21h

draw_netherlands_flag:
    mov ah, 0ch ; function - draw a pixel on the screen
    mov bh, 0 ; video page (0 base)
    mov cx, 0 ; column
    mov dx, 0 ; line

m2_netherlands:
    mov al, 4h ; red
    int 10h
    inc cx
    cmp cx, 410
    jne m2_netherlands
    inc dx
    xor cx, cx
    cmp dx, 100
    jne m2_netherlands

m3_netherlands:
    mov al, 0Fh ; white
    int 10h
    inc cx
    cmp cx, 410
    jne m3_netherlands
    inc dx
    xor cx, cx
    cmp dx, 200
    jne m3_netherlands

m4_netherlands:
    mov al, 1h ; blue
    int 10h
    inc cx
    cmp cx, 410
    jne m4_netherlands
    inc dx
    xor cx, cx
    cmp dx, 300
    jne m4_netherlands

    ; wait for user input
    mov ah, 1
    int 21h
    jmp end_program

draw_estonia_flag:
    mov ah, 0ch ; function - draw a pixel on the screen
    mov bh, 0 ; video page (0 base)
    mov cx, 0 ; column
    mov dx, 0 ; line

m2_estonia:
    mov al, 01h ; blue
    int 10h
    inc cx
    cmp cx, 600 ; change this value
    jne m2_estonia
    inc dx
    xor cx, cx
    cmp dx, 160
    jne m2_estonia

m3_estonia:
    mov al, 00h ; black
    int 10h
    inc cx
    cmp cx, 600 ; change this value
    jne m3_estonia
    inc dx
    xor cx, cx
    cmp dx, 160*2
    jne m3_estonia

m4_estonia:
    mov al, 0Fh ; white
    int 10h
    inc cx
    cmp cx, 600 ; change this value
    jne m4_estonia
    inc dx
    xor cx, cx
    cmp dx, 160*3
    jne m4_estonia

    ; wait for user input
    mov ah, 1
    int 21h

end_program:
    mov ax, 4c00h ; exit program
    int 21h
end start
