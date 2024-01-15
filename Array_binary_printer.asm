dseg segment
d db 54h, 0b7h, 9fh, 46h, 11h
dseg ends
cseg segment
assume cs:cseg, ds:dseg

Start: mov ax, dseg
mov ds, ax
mov si, 0
mov ah, 2

Shoov: mov cl, d[si]
mov dh, 8
sh: cmp dh, 0
jz ender
shl cl, 1
jnc c
mov dl, 31h  ; 1
jmp print
c: mov dl, 30h  ; 0
print: int 21h
dec dh
jnz sh
ender: mov dl, ' '
int 21h
inc si
cmp si, 5
jc Shoov
Sof: int 3h
cseg ends
end Start
