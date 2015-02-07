# %edi -> index of the list
# %ebx -> store the largest item
# %eax -> store the current item of the list

 .section .data

data_items:
 .long 3,67,24,13,56,87,6,44,33,22,11,66,0

 .section .text

 .global _start
_start:
 movl $0, %edi									# set 0 to index of the list
 movl data_items(,%edi,4), %eax # load the first byte of data
 movl %eax, %ebx 								# this is the largest item

start_loop:
 cmpl $0, %eax
 je loop_exit
 incl %edi
 movl data_items(,%edi,4), %eax
 cmpl %ebx, %eax
 jle start_loop
 movl %eax, %ebx
 jmp start_loop

loop_exit:
 movl $1, %eax
 int $0x80
