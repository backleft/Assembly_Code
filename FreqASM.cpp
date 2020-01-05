#include <iostream>
using namespace std;

const int MAX_CHAR_INPUT = 127;

class BaseClass
{
private:

	char InputBuffer[MAX_CHAR_INPUT];

public:

	void setBuffer(char buffer[MAX_CHAR_INPUT]);
	char* getBuffer();

	void InputData();
	void CountData(char buffer[MAX_CHAR_INPUT]);

};

void BaseClass::setBuffer(char buffer[])
{
	strcpy_s(InputBuffer, buffer);
}

char* BaseClass::getBuffer()
{
	return InputBuffer;
}

void BaseClass::InputData()
{
	char buffer[MAX_CHAR_INPUT];
	bool input = true;
	do
	{

		cout << "Enter in the characters to be counted. Maximum input length is 127 characters and can only be alphabets or integers." << endl << endl;
		cin.getline(buffer, MAX_CHAR_INPUT);
		if (strlen(buffer) > (MAX_CHAR_INPUT))
		{
			cout << "ERROR: The input size is over 128 characters." << endl << endl;
		}
		else
		{
			setBuffer(buffer);
			input = false;
		}

	} while (input == true);
}

void BaseClass::CountData(char buffer[])
{
	char ch;
	int a = 0;
	int b = 0;
	int c = 0;
	int size = strlen(buffer);

	for (int i = 0; i < size; i++)
	{
		ch = buffer[i];
		if (int(ch) == 97)
		{
			a++;
		}
		else if (int(ch) == 98)
		{
			b++;
		}
		else if (int(ch) == 99)
		{
			c++;
		}
	}
	cout << "a - " << a << " times" << endl;
	cout << "b - " << b << " times" << endl;
	cout << "c - " << c << " times" << endl;
}

int main()
{
	BaseClass program;
	program.InputData();
	program.CountData(program.getBuffer());

	system("PAUSE");
}