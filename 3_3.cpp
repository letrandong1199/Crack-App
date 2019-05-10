#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE 
using namespace std;

#define MAX_INT_128 "170141183460469231731687303715884105727"
#define MIN_INT_128 "-170141183460469231731687303715884105728"

class CQInt
{
private:
	int qint[4] = { 0 };

public:
	/*
	Turn on/off bit at position i of sequence of 128 bits (0: turn off, otherwise: turn on)
	Input:
	bitIdx: index of bit in the sequence
	state: turn on or off
	*/
	void turnBit(int bitIdx, int state);

	/*
	Get bit at position i of a 128-bit sequence
	Input:
	bitIdx: index of bit in the sequence
	Output: the required bit
	*/
	int getBit(int bitIdx);


	/**/
	int getUsedBits();

	//Set all bits in QInt to zero
	void reset();

	/*
	Append a digit into the units of the QInt's value
	Input:
	decDigit: a digit appended
	*/
	void pushDecimal(int decDigit);

	//Perform two's complement convertion  
	void convertTwoComplement();

	/*
	Set a string of digits into QInt
	Input:
	decStr: a string of digits
	*/
	void setDecStr(string decStr);

	/*
	Set a string of bits into QInt
	Input:
	binStr: a bit string
	*/
	void setBinStr(string binStr);

	/*
	Set a string of hexes into QInt
	Input:
	hexStr: a string of hexes
	*/
	void setHexStr(string hexStr);

	/*
	Convert QInt into a decimal string
	Output:
	a string of ditgits
	*/
	string convertToDec();

	/*
	Convert QInt into a binary string
	Output:
	a string of bits
	*/
	string convertToBin();

	/*
	Convert QInt number to hexadecimal string
	Output:
	a string of hexes
	*/
	string convertToHex();


	/*
	Assign a QInt to another QInt
	Input:
	srcQInt: a QInt to assign from
	Output:
	former QInt with the bit sequence of srcQInt
	*/
	CQInt operator=(const CQInt & srcQInt);


	//ARITHMETIC OPERATOR

	/*
	Perform addition between two QInt(s)
	Input:
	aQInt to add
	Output:
	result from an addition between *this and aQInt
	*/
	CQInt operator+(CQInt aQInt);

	/*
	Perform substraction between two QInt(s)
	Input:
	aQInt to substract
	Output:
	result from an substract between *this and aQInt
	*/
	CQInt operator-(CQInt aQInt);

	/*
	Perform multiplication between two QInt(s)
	Input:
	aQInt to multiply
	Output:
	result from an multiply between *this and aQInt
	*/
	CQInt operator*(CQInt aQInt);

	/*
	Perform division between two QInt(s)
	Input:
	aQInt to divide
	Output:
	result from an division between *this and aQInt
	*/
	CQInt operator/(CQInt aQInt);


	//RELATIONAL OPERATOR

	/*
	Greater comparison between *this and another QInt aQInt
	Input:
	a number QInt type to compare with *this
	Output:
	true if *this is greater than B and false otherwise
	*/
	bool operator>(CQInt aQInt);

	/*
	Greater or equal comparison between *this and another QInt aQInt
	Input:
	a number in QInt type
	Output:
	true if *this >= aQInt and false otherwise
	*/
	bool operator>=(CQInt aQInt);

	/*
	Less than comparison
	Input:
	a number in QInt type
	Output:
	true if *this < aQInt and false otherwise
	*/
	bool operator<(CQInt aQInt);

	/*
	Les than or equal comparison
	Input:
	a number QInt type
	Output:
	true if *this <= aQInt and false otherwise
	*/
	bool operator<=(CQInt aQInt);

	/*
	Equal to comparison
	Input:
	a number in QInt type
	Output:
	true if *this == aQInt and false otherwise
	*/
	bool operator==(CQInt aQInt);

	/*
	Not equal comparison
	Input:
	a number in QInt type
	Output:
	true if *this != aQInt and false otherwise
	*/
	bool operator!=(CQInt aQInt);


	//BITWISE OPERATOR

	/*
	AND operator
	Input:
	a QInt type number to perform AND
	Output:
	CQInt type result
	*/
	CQInt operator&(CQInt aQInt);

	/*
	OR operator
	Input:
	a QInt type number to perform OR
	Output:
	CQInt type result
	*/
	CQInt operator|(CQInt aQInt);

	/*
	XOR operator
	Input:
	a QInt type number to perform XOR
	Output:
	CQInt type result
	*/
	CQInt operator^(CQInt aQInt);

	/*
	NOT operator
	Input:
	a QInt type number to perform NOT
	Output:
	CQInt type result
	*/
	CQInt operator~();

	/*
	Logical shift right
	Input:
	number: the number of bits to shift
	Output:
	right shifted QInt
	*/
	CQInt operator >> (int number);

	/*
	Shift left
	Input :
	number: the number of bits to shift
	Output :
	left shifted QInt
	*/
	CQInt operator << (int number);

	/*
	Right rotate
	Input:
	number: the number of bits to rotate
	Output:
	rotated QInt
	*/
	CQInt ror(int number);

	/*
	Left circular rotate
	Input:
	number: the number of bits to rotate
	Output:
	rotated QInt
	*/
	CQInt rol(int number);


	/*
	Get input into QInt
	Input:
	str: sequence of bits/digits/hexes
	base: base 2/10/16
	Output:

	*/
	void scanQInt(string str, int base);

	/*
	Print output to screen in base 2/10/16
	Input:
	base: base 2/10/16
	Output:
	output in the desired base
	*/
	void printQInt(int base);

	CQInt();

	~CQInt();
};

void fillZero(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = 0;
	}
}

string add2Dec(string &A, string &B)
{
	string res;
	res.resize(50);
	fillZero(res);

	int remain = 0;

	res[0] = A[0] > B[0] ? A[0] : B[0];

	for (int i = 1; i <= res[0]; i++)
	{
		remain = remain + A[i] + B[i];
		res[i] = remain % 10;
		remain /= 10;
	}

	if (remain != 0)
	{
		res[0]++;
		res[res[0]] = remain;
	}
	return res;
}

string multiply2Dec(string &A, string &B)
{
	string res;
	res.resize(50);
	fillZero(res);

	for (int i = 1; i <= A[0]; i++)
	{
		int remain = 0;
		for (int j = 1; j <= B[0]; j++)
		{
			remain = A[i] * B[j] + remain + res[i + j - 1];
			res[i + j - 1] = remain % 10;
			remain /= 10;
		}

		int j = i + B[0] - 1;

		while (remain != 0)
		{
			j++;
			remain = remain + res[j];
			res[j] = remain % 10;
			remain /= 10;
		}
	}
	res[0] = A[0] + B[0] + 2;
	while ((res[res[0]] == 0) && (res[0] > 1)) res[0]--;
	return res;
}

void reverseStr(string &str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		char temp = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = temp;
	}
}

void uppercaseStr(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}
void CQInt::turnBit(int bitIdx, int state)
{
	if (bitIdx <= 127)
	{
		div_t arrIdx = div(bitIdx, 32); // Tra ve arrIdx.quot la phan nguyen, arrIdx.rem la phan du
		int number = qint[arrIdx.quot];

		if (state != 0)
		{
			number = number | (1 << arrIdx.rem);	//turn bit on
		}
		else
		{
			number = number & (~(1 << arrIdx.rem));	//turn bit off
		}

		qint[arrIdx.quot] = number;
	}
}

int CQInt::getBit(int bitIdx)
{
	div_t arrIdx = div(bitIdx, 32);
	int shiftRight = qint[arrIdx.quot] >> arrIdx.rem;
	int andOne = shiftRight & 1;
	return andOne;
}

int CQInt::getUsedBits()
{
	int usedBits = 0;
	int i = 3;	//start from the last element of array qint[], run back to the first one
	while ((this->qint[i] == 0) && (i >= 0)) i--;	//ignore element equals 0 (32 bits is 0)
	if (i >= 0)	//stop at element unequals 0
	{
		int bitIdx = (i + 1) * 32 - 1;	//start from the last bit of element unequals 0, run back to the first one
		while ((this->getBit(bitIdx) == 0) && (bitIdx >= 0)) bitIdx--;	//ignore bit equals 0
		usedBits = bitIdx + 1;	//update used bits
	}
	else
	{
		usedBits = 0;
	}
	return usedBits;
}

void CQInt::reset()
{
	for (int i = 0; i < 4; i++)
	{
		this->qint[i] = 0;
	}
}

void CQInt::pushDecimal(int decDigit)
{
	//Varible val10 = 10
	CQInt val10;
	val10.qint[0] = 10;

	//Varible digit = decDigit
	CQInt digit;
	digit.qint[0] = decDigit;

	*this = (*this)*val10 + digit;
}

void CQInt::convertTwoComplement()
{
	*this = ~(*this);

	CQInt temp;
	temp.qint[0] = 1;

	*this = (*this) + temp;
}

void CQInt::setDecStr(string decStr)
{
	this->reset();	//reset to 0

	int start = 0;
	if (decStr[0] == '-')
	{
		start = 1;
	}

	for (int i = start; i < decStr.length(); i++)
	{
		this->pushDecimal(decStr[i] - 48);
	}

	if (decStr[0] == '-')
	{
		this->convertTwoComplement();
	}
}

void CQInt::setBinStr(string binStr)
{
	reverseStr(binStr);

	for (int i = 0; i < binStr.length(); i++)
	{
		turnBit(i, binStr[i] - 48);
	}
}

void CQInt::setHexStr(string hexStr)
{
	reverseStr(hexStr);

	for (int i = 0; i < hexStr.length(); i++)
	{
		CQInt temp;
		temp.qint[0] = (hexStr[i] >= '0' && hexStr[i] <= '9') ? hexStr[i] - 48 : hexStr[i] - 55;

		for (int j = 0; j < 4; j++)
		{
			turnBit(i * 4 + j, temp.getBit(j));
		}
	}
}

string CQInt::convertToDec()
{
	string str;

	//Init P = 1 (in calculated format string)
	string P;
	P.resize(50);
	fillZero(P);
	P[0] = P[1] = 1;

	//Init S = 0 (in calculated format string)
	string S;
	fillZero(S);
	S.resize(50);
	S[0] = 1;

	if (this->getBit(127) == 1)	//is positive number
	{
		str.push_back('-');

		CQInt temp = *this;
		temp.convertTwoComplement();

		if (temp == *this)	//minimum value
		{
			string minimumVal = MIN_INT_128;
			return minimumVal;
		}

		str += temp.convertToDec();
		return str;
	}
	else
	{
		//If 0th bit is zero then init S = 1 (in calculated format string)
		if (this->getBit(0) == 1)
		{
			S[1] = 1;
		}

		//two = 2 (in calculated format string)
		string two;
		fillZero(two);
		two.resize(50);
		two[0] = 1;
		two[1] = 2;

		for (int i = 1; i < this->getUsedBits(); i++)
		{
			//Calculate 2^i
			P = multiply2Dec(P, two);

			//If bit i equals 1 then add 2^i to S
			if (this->getBit(i) == 1)
			{
				S = add2Dec(S, P);
			}
		}

		//Convert 'calculated format string' to string for displaying
		for (int i = S[0]; i >= 1; i--)
		{
			str.push_back(S[i] + 48);
		}
		return str;
	}
}

string CQInt::convertToBin()
{
	string str;
	for (int i = this->getUsedBits() - 1; i >= 0; i--)
	{
		str.push_back(this->getBit(i) + 48);
	}
	if (str.length() == 0)
		str.push_back('0');
	return str;
}

string CQInt::convertToHex()
{
	string str;
	CQInt temp;
	int lastBit = this->getUsedBits();
	while (lastBit < 128 && lastBit % 4 != 0) lastBit++;

	for (int i = 0; i < lastBit; i++)
	{
		temp.turnBit(i % 4, this->getBit(i));
		if ((i + 1) % 4 == 0)
		{
			string temp2 = temp.convertToDec();
			if (temp2.length() == 2)
			{
				str.push_back(temp2[1] + 17);
			}
			else
				str.push_back(temp2[0]);
		}
	}
	reverseStr(str);
	if (str.length() == 0)
		str.push_back('0');
	return str;
}

CQInt CQInt::operator=(const CQInt & srcQInt)
{
	for (int i = 0; i < 4; i++)
	{
		this->qint[i] = srcQInt.qint[i];
	}
	return *this;
}

CQInt CQInt::operator+(CQInt B)
{
	CQInt A = *this;
	CQInt res;

	int remain = 0;
	int max = A.getUsedBits() > B.getUsedBits() ? A.getUsedBits() : B.getUsedBits();
	for (int i = 0; i < max; i++)
	{
		remain = remain + A.getBit(i) + B.getBit(i);
		res.turnBit(i, remain % 2);
		remain /= 2;
	}
	if (remain != 0)
	{
		res.turnBit(max, 1);
		remain = 0;
	}
	return res;
}

CQInt CQInt::operator-(CQInt aQInt)
{
	aQInt.convertTwoComplement();
	CQInt res = *this + aQInt;
	return res;
}

CQInt CQInt::operator*(CQInt aQInt)
{
	CQInt A = *this;
	CQInt res;

	for (int i = 0; i < A.getUsedBits(); i++)
	{
		int bitA = A.getBit(i);
		int remain = 0;

		for (int j = 0; j < aQInt.getUsedBits(); j++)
		{
			int bitB = aQInt.getBit(j);

			remain = bitA * bitB + remain + res.getBit(i + j);
			res.turnBit(i + j, remain % 2);
			remain /= 2;
		}

		int j = aQInt.getUsedBits() + i - 1;

		while (remain != 0)
		{
			j++;
			remain += res.getBit(j);
			res.turnBit(j, remain % 2);
			remain /= 2;
		}
	}
	return res;
}

CQInt CQInt::operator/(CQInt aQInt)
{
	CQInt A = *this;
	CQInt res;
	string str;
	CQInt zero;

	bool isNegative = false;
	if (A < zero)
	{
		isNegative = !isNegative;
		A.convertTwoComplement();
	}
	if (aQInt < zero)
	{
		isNegative = !isNegative;
		aQInt.convertTwoComplement();
	}

	CQInt temp;
	int pos = A.getUsedBits() - aQInt.getUsedBits();

	while (pos >= 0)
	{
		temp = aQInt << pos;
		if (A >= temp)
		{
			str.push_back('1');
			A = A - temp;
		}
		else
		{
			str.push_back('0');
		}
		pos--;
	}
	res.setBinStr(str);
	if (isNegative)
		res.convertTwoComplement();
	return res;
}

bool CQInt::operator>(CQInt aQInt)
{
	CQInt A = *this;
	if ((A.getBit(127) == 0) && (aQInt.getBit(127) == 1))
	{
		return true;
	}
	else
		if ((A.getBit(127) == 1) && (aQInt.getBit(127) == 0))
		{
			return false;
		}
		else
			if ((A.getBit(127) == 0) && (aQInt.getBit(127) == 0))
			{
				if (A.getUsedBits() != aQInt.getUsedBits())
				{
					return (A.getUsedBits() > aQInt.getUsedBits());
				}
				else
				{
					int i = A.getUsedBits() - 1;
					while ((i >= 0) && (A.getBit(i) == aQInt.getBit(i))) i--;
					return (A.getBit(i) > aQInt.getBit(i));
				}
			}
			else
			{
				A.convertTwoComplement();
				aQInt.convertTwoComplement();
				return aQInt > A;
			}
}

bool CQInt::operator>=(CQInt aQInt)
{
	return (*this > aQInt) || (*this == aQInt);
}

bool CQInt::operator<(CQInt aQInt)
{
	return !(*this >= aQInt);
}

bool CQInt::operator<=(CQInt aQInt)
{
	return !(*this > aQInt);
}

bool CQInt::operator==(CQInt aQInt)
{
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) != aQInt.getBit(i))
		{
			return false;
		}
	}
	return true;
}

bool CQInt::operator!=(CQInt aQInt)
{
	return !(*this == aQInt);
}

CQInt CQInt::operator&(CQInt aQInt)
{
	CQInt A = *this;
	CQInt res;

	for (int i = 0; i < 128; i++)
	{
		res.turnBit(i, A.getBit(i) && aQInt.getBit(i));
	}
	return res;
}

CQInt CQInt::operator|(CQInt aQInt)
{
	CQInt A = *this;
	CQInt res;

	for (int i = 0; i < 128; i++)
	{
		res.turnBit(i, A.getBit(i) || aQInt.getBit(i));
	}
	return res;
}

CQInt CQInt::operator^(CQInt aQInt)
{
	CQInt A = *this;
	CQInt res;

	for (int i = 0; i < 128; i++)
	{
		res.turnBit(i, A.getBit(i) - aQInt.getBit(i));
	}
	return res;
}

CQInt CQInt::operator~()
{
	CQInt A = *this;
	CQInt res;

	for (int i = 0; i < 128; i++)
	{
		res.turnBit(i, A.getBit(i) - 1);
	}
	return res;
}

CQInt CQInt::operator >> (int number)
{
	CQInt res;
	if (number >= 128)
	{
		return res;
	}
	else
	{
		for (int i = 0; i <= 127; i++)
		{
			if (i + number <= 127)
			{
				res.turnBit(i, this->getBit(i + number));
			}
			else
			{
				res.turnBit(i, 0);
			}
		}
	}
	return res;
}

CQInt CQInt::operator << (int number)
{
	CQInt res;
	if (number >= 128)
	{
		return res;
	}
	else
	{
		for (int i = 127; i >= 0; i--)
		{
			if (i - number >= 0)
			{
				res.turnBit(i, this->getBit(i - number));
			}
			else
			{
				res.turnBit(i, 0);
			}
		}
	}
	return res;
}

CQInt CQInt::rol(int number)
{
	return ((*this << number) | (*this >> (128 - number)));
}

CQInt CQInt::ror(int number)
{
	return this->rol(128 - number);
}

void CQInt::scanQInt(string str, int base)
{
	switch (base)
	{
	case 2:
		this->setBinStr(str);
		break;
	case 10:
		this->setDecStr(str);
		break;
	case 16:
		this->setHexStr(str);
		break;
	default:
		break;
	}
}

void CQInt::printQInt(int base)
{
	switch (base)
	{
	case 2:
		cout << this->convertToBin() << endl;
		break;
	case 10:
		cout << this->convertToDec() << endl;
		break;
	case 16:
		cout << this->convertToHex() << endl;
		break;
	default:
		break;
	}
}

CQInt::CQInt()
{
}

CQInt::~CQInt()
{
}


int main()
{
	while (true)
	{
		char name[100];
		cout << "UserName: ";
		cin >> name;
		if (strlen(name) > 4)
		{
			int length = 6;
			if (length > strlen(name))
			{
				length = strlen(name);

			}
			string str = "23E";
			CQInt a;
			a.scanQInt(str, 16);
			string str1 = "5";
			CQInt b;
			b.scanQInt(str1, 16);
			for (int i = 0; i < length; i++)
			{
				int t = toascii(name[i]);
				char temp[100];
				_itoa(t, temp, 10);
				string str2 = temp;
				CQInt c;
				c.scanQInt(str2, 10);
				c.convertToHex();
				a = a*(c / b) + c;
			}
			str = a.convertToHex();
			if (str.length() > 8)
			{
				string str1 = str.substr(str.length() - 8, 8);
				CQInt a;
				a.scanQInt(str1, 16);
				CQInt res;
				res = a >> 31;
				string str2 = "0";
				b.scanQInt(str2, 16);
				if (res == b)
				{
					cout << "Serial: ";
					a.printQInt(10);
				}
				else
				{
					string str3 = "FFFFFFFFFFFFFFFFFFFFFFFF";
					str3 = str3 + str1;
					a.scanQInt(str3, 16);
					cout << "Serial: ";
					a.printQInt(10);
				}
			}
			else
			{
				CQInt res;
				res = a >> 31;
				string str2 = "0";
				b.scanQInt(str2, 16);
				if (res == b)
				{
					cout << "Serial: ";
					a.printQInt(10);
				}
				else
				{
					string str3 = "FFFFFFFFFFFFFFFFFFFFFFFF";
					str3 = str3 + str;
					a.scanQInt(str3, 16);
					cout << "Serial: ";
					a.printQInt(10);
				}
			}
		}
		else
		{
			cout << "Name too short";
			cout << endl;
		}
	}

	system("pause");
	return 0;
}