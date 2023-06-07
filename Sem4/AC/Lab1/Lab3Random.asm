INCLUDE Irvine32.inc

	
	.data 
	  	a db 5
		b dw 7
		cd db 4
		d db 6
		e db 3
		interm dw ?
		rez db ?

	.code 
	 main proc
		; z = ((a+b)/c + 2*d)/e = ((5+7)/4 + 2*6)/3 = 5
		mov eax,0
		mov al, a
		add ax, b			; ax=a+b
		cwd
		idiv cd			; ax=(a+b)/c
		mov interm, ax		; interm=(a+b)/c
		mov al, d			; ax=d
		add ax, ax		; ax=2*d
		add ax, interm		; ax=(a+b)/c + 2*d
		cwd
		idiv e			; ax=((a+b)/c + 2*d)/e
		mov rez, al		; rez=((a+b)/c + 2*d)/e


exit
main ENDP
END main
