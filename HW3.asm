;Steven Salvador
;CPSC 240-07 & CPSC240-08
;Complier: VS2019
;Date assigned: 9/18/19
;Due Date: 10/2/19
;This program adds 32-bit registers 
INCLUDE Irvine32.inc


.DATA       
finalVal DWORD ?

.CODE
main PROC
	mov eax, 0
	mov EBX, 20
	mov ECX, 40
	mov EDX, 10
	
	;storing temp values into unused registers
	mov EDI,EBX
	
	;doing the arithmetic operations
	add EBX,ECX
	add EAX,EBX

	sub ECX,EDX
	add EAX,ECX
	sub EAX,EDI
	mov finalVal,EAX

	;CALL procedures
	call WriteDec
	call DumpRegs
	call WaitMSG
	exit

main ENDP
END main
