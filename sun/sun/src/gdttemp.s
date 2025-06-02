bits 64

global gdt_pointer

section .data
gdt_pointer:
   dw gdt_end - gdt_start - 1               ;limit 16bit
   dq gdt_start                             ;base 64bit

section .text
gdt_start:
;offset 0
.null_entry:
dq 0x0000000000000000                      ;null
;offset 0x8 
dq 0x00AF9A000000FFFF                     ;kernel code
;offset 0x10 
dq 0x00CF92000000FFFF                  ;data is actually ignored so this will be 32bit cuz we dont use segmentation

gdt_end:
