;Steven Salvador
;CPSC 240-07 & CPSC240-08
;Complier: VS2019 Enterprise
;Date assigned: 10/07/2019
;Due Date: 10/23/19
;This program will loop and swap indirect addressing elements in an array of type WORD
INCLUDE Irvine32.inc


.DATA       
warray WORD 4,9,13,7,5,12,17,2,15,8

.CODE
main PROC

	;clearing eax and edx of anything that is already stored on the registers
	xor eax,eax
	xor edx,edx

	;moving the array into an offset memory location
	mov esi, OFFSET warray
	mov edi, OFFSET warray + 2
	
	;setting ecx to the size of the array and ebx to the type 
	mov ecx, (LENGTHOF warray)/2
	mov ebx, TYPE warray

L1:
	;First moving the values of the array from memory to registers
	mov ax, [esi]
	mov dx, [edi]
	
	;Now swapping them into the opposite memory locations
	mov [esi], dx
	mov [edi], ax
	

	;Had to get crafty here by moving in the already swapped values in the array in the 1st position of the block
	; back into ax for writedec to print out the value in Decimal without the junk from the other offset memory address
	; block locations.
	mov ax, [esi]
	call WriteDec
	call Crlf


	;this is other part to overwrites ax with the 2nd position of the block for WriteDec to work
	mov ax, [edi] 
	call WriteDec
	call Crlf

	;incrementing the ESI & EDI registers by TYPE ebx.
	add esi, TYPE ebx
	add edi, TYPE ebx
	
	;calling the loop back to the beginning
	loop L1

	
	call WaitMsg
	exit

main ENDP
END main