INCLUDE Irvine32.inc

.data
sir1 BYTE "Sirul1", 0
sir2 BYTE "Sirul2", 0
sir3 BYTE "Sirul3", 0
sir4 BYTE SIZEOF sir1 + SIZEOF sir2 + SIZEOF sir3 - 3 DUP(0) ; sirul rezultat

.code
Alipirea PROC
     mov esi, [esp+4]
     mov edi, [esp+8]
     mov ecx, [esp+12]
     rep movsb
     mov BYTE PTR [edi], '_'
     ret
Alipirea ENDP

main PROC
     ;afisare sir1
     mov edx, OFFSET sir1
     call WriteString
     call Crlf ; trecem la rand nou

     ;afisare sir2
     mov edx, OFFSET sir2
     call WriteString
     call Crlf ; trecem la rand nou

     ;afisare sir3
     mov edx, OFFSET sir3
     call WriteString
     call Crlf ; trecem la rand nou

     ; copy sir1 in sir4
     push SIZEOF sir1 - 1 ; lungimea sirului sir1
     push OFFSET sir4 ; adresa sirului sir1
     push OFFSET sir1 ; adresa sirului sir4
     call Alipirea
   
     ; adaugam sirul sir2 la sirul sir4
     push SIZEOF sir2 - 1 ; lungimea sirului sir2
     push OFFSET sir4 + SIZEOF sir1  ; adresa sirului sir2
     push OFFSET sir2 ; adresa sirului sir4
     call Alipirea

     ; adaugam sirul sir3 la sirul sir4
     push SIZEOF sir3 - 1 ; lungimea sirului sir3
     push OFFSET sir4 + SIZEOF sir1 + SIZEOF sir2  ; adresa sirului sir3
     push OFFSET sir3 ; adresa sirului sir4
     call Alipirea

     ; afisam sirul actualizat
     mov edx, OFFSET sir4
     call WriteString
     call Crlf ; trecem la rand nou

    exit
main ENDP

END main
