[org 0x7C00]

start:
	mov ah, 0x0E
	mov bx, message


print_loop:
	mov al, [bx]
	cmp al, 0
	je done
	int 0x10
	inc bx
	jmp print_loop

done:
	hlt

message:
	db "Hello, World!", 0

times 510-($-$$) db 0
dw 0xAA55
