;Steven Salvador
;CPSC 240-07 & CPSC240-08
;Complier: VS2019 Enterprise
;Date assigned: 10/07/2019
;Due Date: 10/23/19
;This program will loop and swap indirect addressing elements
INCLUDE Irvine32.inc


.DATA       
warray WORD 4,9,13,7,5,12,17,2,15,8

.CODE
main PROC
	xor eax,eax
	xor edx,edx
	mov esi, OFFSET warray
	mov ecx, LENGTHOF warray
	mov ebx, TYPE warray
	
	;putting elements from warray[1] and warray[2] into lower 8bit registers
	mov al, [esi]
	mov dl, [esi+2]
	;swaping warray elements 1 and 2  
	mov [esi+2],al
	mov [esi],dl
	
	;putting elements from warray[3] and warray[4] into lower 8bit registers
	mov al,[esi+4]
	mov dl,[esi+6]
	;swapping 3 and 4
	mov [esi+6],al
	mov [esi+4],dl
	
	;putting elements from warray[5] and warray[6] into lower 8bit registers
	mov al,[esi+8]
	mov dl,[esi+10]
	;swapping 5 and 6
	mov [esi+10],al
	mov [esi+8],dl
	
	;putting elements from warray[7] and warray[8] into lower 8bit registers
	mov al,[esi+12]
	mov dl,[esi+14]
	;swapping 7 and 8
	mov [esi+14],al
	mov [esi+12],dl
	
	;putting elements from warray[9] and warray[10] into lower 8bit registers
	mov al,[esi+16]
	mov dl,[esi+18]
	;swapping 9 and 10
	mov [esi+18],al
	mov [esi+16],dl

	call DumpRegs
	call DumpMem
	call WaitMsg
	exit

main ENDP
END main
