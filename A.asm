cseg segment
assume cs: cseg

    double: mov si, 4000h
            mov ax,23
            mov bx,17
            mov cx,bx
            mov ds, si
            mov si, 0
    bin1:   cmp ax, 2
            jz two
            jc bin2
            inc si
            shr ax,1
            jnc z
            mov ds: [si], 1
            jmp bin1
    z:      mov ds: [si], 0
            jmp bin1
    two:    shr ax,1
            inc si
    bin2:   cmp si,0
            jz e
            shl bx,1
            mov dl,ds:[si]
            dec si
            cmp dl,1
            jnz bin2
            add bx, cx
            jmp bin2
    e  :    int 3
            

cseg ends
end double 
