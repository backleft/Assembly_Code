/*
	Author: Steven Salvador
	Class: CPSC 240-07 MW 8am-9:50am
	Complier: VS2019 Enterprise
	Purpose: to Encode and Decode a user inputed message using VS2019 mixmode
	with C++ and embedded MASM programming language.

	Due Date: December 04, 2019
	Completion Date: November 28, 2019
*/

#include <iostream>
#include <fstream>

using namespace std;

const short SIZE = 127;

class DATA {
private: //All the private variable needed to run the program
	char InputBuffer[SIZE];
	char EncBuffer[SIZE];
	char CountBuffer[123];
	short count;
	char OutputBuffer[SIZE];
public:
	void InputData();
	void EncData();
	void DecrData();
	void OutputData();
};
void DATA::InputData() {
	cout << "Enter a line of text less than 127 characters: ";

	//Grabs from the console the user inputted line of text
	cin.getline(InputBuffer, sizeof(InputBuffer));
	//Grabs the amount of characters inputted
	count = cin.gcount();
	cout << endl;

	//Zeroes out all the countBuffers
	for (int i = 0; i < 123; i++)
		CountBuffer[i] = 0;
}
void DATA::EncData() {

	//Local Variables for the encoding in assembly
	char LocalInput[SIZE];
	char LocalCount[SIZE];
	short LCount = count;

	//copies all the data from the private variables 
	//to be used in embedded MASM
	for (int i = 0; i < LCount; i++)
		LocalInput[i] = InputBuffer[i];
	for (int i = 0; i < 123; i++)
		LocalCount[i] = CountBuffer[i];

	//Embedded ASM
	__asm {
		//Clearing out needed registers
		xor eax, eax
		xor ecx, ecx

		//Loading ECX with the count for the loop
		movzx ecx, LCount

		//Loading the copy input from memory into the ESI and EDI 
		//registers
		lea esi, LocalInput
		lea edi, LocalCount

		ENC ://Encode label

			mov al, [esi] // takes the lower byte at the ESI location into AL
			ror al, 4 //rotates right 4 bits to change the message
			xor al, 0ACh//causes an overflow to change the ASCII symbol

			mov[esi], al // moves the changed value back into the memory location

			inc esi // goes to the next location

			//checks if the last enter character is the Enter key.
			//Jumps back to the beginning if not equal to AC in hex
			cmp al, 0ACh
			jne ENC

	}

	//copies the encoded message to the EncBuffer
	for (int i = 0; i < LCount; i++)
		EncBuffer[i] = LocalInput[i];

	//prints out the Encoded message
	cout << "Here is your encoded message: ";
	for (int i = 0; i < LCount; i++)
		cout << EncBuffer[i] << " ";
	cout << endl;


}
void DATA::DecrData() {
	//local variables used for copying the buffer variables
	char LocalCount[123];
	char DecryptBuffer[SIZE];
	short LCount = count;

	//copies the Encoded message to the Decrypting buffer
	for (int i = 0; i < 127; i++)
		DecryptBuffer[i] = EncBuffer[i];
	for (int i = 0; i < 123; i++)
		LocalCount[i] = CountBuffer[i];

	//embedded ASM
	/*This works the same way as the EncData embedded MASM but instead
	works in the reverse order to decoded the message*/
	__asm {
		xor eax, eax
		xor ecx, ecx
		
		movzx ecx, LCount
		lea esi, DecryptBuffer
		lea edi, LocalCount
		
		DECR:
			movzx eax, [esi] // Zeroes out the unneccessary upper half of the register
			xor al, 0ACh
			cmp al, 00h //checks if the last inputted character is the Enter Key.
			JE END //Jumps out if Equal
			rol al, 4
			mov[esi], al
			inc esi
			cmp al, 00h //Double checks if the any of the other characters are the ENTER key.
			jne DECR

		END:
	}

	// For Testing purposes
	//for (int i = 0; i < (LCount-1); i++)
	//	cout << DecryptBuffer[i] << " ";

	//copies the decoded message to the OutputBuffer
	for (int i = 0; i < (LCount - 1); i++)
		OutputBuffer[i] = DecryptBuffer[i];
	cout << endl;
}
void DATA::OutputData() {
	short LCount = count;
	//outputs the decoded message.
	cout << "THE SECRET MESSAGE IS: ";
	for (int i = 0; i < (LCount - 1); i++)
		cout << OutputBuffer[i] << " ";
	cout << endl;
}
int main()
{
	DATA test; // calling the class 

	cout << "++++++++++++++++++++++++++++++++++++++ Welcome to the Enc/Decode program! ++++++++++++++++++++++++++++++++++++++++++++++ \n\n";
	test.InputData();
	test.EncData();
	test.DecrData();
	test.OutputData();
	system("pause");
	return 0;
}