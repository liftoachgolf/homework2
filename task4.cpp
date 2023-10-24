#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
#include <typeinfo>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>

#pragma warning(disable:4996)

class File {
public:
	virtual std::string open(std::string sringline) = 0;
	virtual double read() = 0;
};

class First : public File {
private:
	std::vector<std::string>GetField;
	std::vector<char> TField;
public:
	std::string open(std::string sringline) override;
	double read() override;

};

std::string First::open(std::string stringline)
{
	if (fopen("file.txt", "r") == NULL) {
		std::ofstream oFile("file.txt");
		oFile.close();
	}

	std::ofstream out;
	out.open("file.txt");
	if (out.is_open())
	{
		out << stringline;
	}

	return "ss";
}
double First::read() {
	double temp;
	double summ = 0;
	std::ifstream flow("file.txt");
	if (flow) {
		while (flow >> temp) {
			summ += temp;
		}
	}
	return summ;

}


int sign(double x) {
	if (x > 0) {
		return 1;
	}
	else if (x == 0) {
		return 0;
	}
	else if (x < 0) {
		return -1;
	}
}
void USA() {
	char one[] = "_________________________________________________\n";
	char two[] = "********_________________________________________\n";
	std::cout << one;
	for (int i = 0; i < 6; ++i) {
		std::cout << two;
	}
	for (int i = 0; i < 6; ++i) {
		std::cout << one;
	}
}

void clear() {
	for (int i = 0; i < 5; ++i) {
		std::cout << std::endl << std::endl;
	}
}


void Sinusoid() {
	{
		double width = 200;
		double height = 41;

		std::vector<std::string> sing(height, std::string(width, ' '));
		sing[height / 4] = std::string(width, '-');


		for (double i = 0; i < width; i += 0.1) {
			sing[(10 * sin(i / 4.5) + 10)][i] = 'X';
		}

		for (int s = 0; s < sing.size(); s++) {
			std::cout << sing[s] << '\n';
		}

	}
}
std::list<int> numlist;

void fakeRandom(int count, int option)
{
	int temp = 0;
	numlist.push_back(temp);
	if (option == 1)
	{
		for (int i = 0; i < count - 1; ++i)
		{
			temp = (37 * temp + i + 3) % 64;
			numlist.push_back(temp);
		}
	}
	else if (option == 2)
	{
		for (int i = 0; i < count - 1; ++i)
		{
			temp = (25173 * temp + i + 13849) % 65537;
			numlist.push_back(temp);
		}
	}
}

enum class RomanNums { I, V, X, L, C, D, M };

std::string  RomanNumsStr = "IVXLCDM";

std::list<int> romanNumsList;

bool CheckRomanNumIsCorrect(std::string romanNumStr)
{
	for (char _char : romanNumStr)
	{
		if (RomanNumsStr.find(_char) == std::string::npos)
			return false;
	}
	if (romanNumStr.find("IIII") != std::string::npos)
		return false;
	if (romanNumStr.find("VX") != std::string::npos)
		return false;
	if (romanNumStr.find("VL") != std::string::npos)
		return false;
	if (romanNumStr.find("VC") != std::string::npos)
		return false;
	if (romanNumStr.find("VD") != std::string::npos)
		return false;
	if (romanNumStr.find("VM") != std::string::npos)
		return false;
	if (romanNumStr.find("VV") != std::string::npos)
		return false;

	return true;
}

int GetArabicNum(RomanNums romanNum)
{
	switch (romanNum)
	{
	case RomanNums::I:
		return 1;
	case RomanNums::V:
		return 5;
	case RomanNums::X:
		return 10;
	case RomanNums::L:
		return 50;
	case RomanNums::C:
		return 100;
	case RomanNums::D:
		return 500;
	case RomanNums::M:
		return 1000;
	}
}

void ConvertToArabic(std::string romanNumStr)
{
	for (auto _char : romanNumStr)
	{
		if (_char == 'I')
			romanNumsList.push_back(GetArabicNum(RomanNums::I));
		else if (_char == 'V')
			romanNumsList.push_back(GetArabicNum(RomanNums::V));
		else if (_char == 'X')
			romanNumsList.push_back(GetArabicNum(RomanNums::X));
		else if (_char == 'L')
			romanNumsList.push_back(GetArabicNum(RomanNums::L));
		else if (_char == 'C')
			romanNumsList.push_back(GetArabicNum(RomanNums::C));
		else if (_char == 'D')
			romanNumsList.push_back(GetArabicNum(RomanNums::D));
		else if (_char == 'M')
			romanNumsList.push_back(GetArabicNum(RomanNums::M));
	}
}

int GetArabicNum()
{
	int prev = 0, result = 0, temp = 0;

	for (int num : romanNumsList)
	{
		if (num >= prev && num > 5)
		{
			result += num - temp;
			temp = 0;
		}
		else if (num == prev && num < 5)
		{
			temp += num;
		}
		else if (num < prev)
		{
			temp += num;
		}
		prev = num;
	}

	if (temp != 0)
		result += temp;

	return result;
}

void Task6()
{
	std::cout << "Enter roman number: " << std::endl;
	std::string romanNum;
	std::cin >> romanNum;
	if (CheckRomanNumIsCorrect(romanNum))
	{
		ConvertToArabic(romanNum);
		std::cout << GetArabicNum() << std::endl;
	}
	else
	{
		std::cout << "incorrect number!!1";
	}
}


void task7()
{
	int count, option;
	std::cout << "enter skolko random chisel and type(1/2)" << std::endl;
	std::cin >> count >> option;
	fakeRandom(count, option);

	for (int num : numlist)
	{
		std::cout << num << std::endl;
	}
}

void task8() {
	
		double matrix1[3][4]
		{
			{5, 2, 0, 10},
			{3, 5, 2, 5},
			{20, 0, 0, 0}
		},
			matrix2[4][2]
		{
			{1.20, 0.50},
			{2.80, 0.40},
			{5.00, 1.00},
			{2.00, 1.50}
		},
			matrix3[3][2],
			result = 0,
			maxIncome = 0,
			minIncome = 100000000,
			totalIncome = 0,
			maxComission = 0,
			minComission = 100000000,
			totalComission = 0,
			totalMoney = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					result += matrix1[i][k] * matrix2[k][j];
				}
				matrix3[i][j] = result;
				if (j == 0)
				{
					if (result > maxIncome)
					{
						maxIncome = result;
					}
					if (result < minIncome)
					{
						minIncome = result;
					}
					totalIncome += result;
				}
				if (j == 1)
				{
					if (result > maxComission)
					{
						maxComission = result;
					}
					if (result < minComission)
					{
						minComission = result;
					}
					totalComission += result;
				}
				totalMoney += result;
				result = 0;
				std::cout << std::setw(5) << matrix3[i][j] << " ";
			}
			std::cout << std::endl;
		}
		
			std::cout << std::endl;
			std::cout << "max dohod: " << maxIncome << std::endl;
			std::cout << "min dohod: " << minIncome << std::endl;
			std::cout << "max comssia: " << maxComission << std::endl;
			std::cout << "min comissia: " << minComission << std::endl;
			std::cout << "polny dohod: " << totalIncome << std::endl;
			std::cout << "full comissia: " << totalComission << std::endl;
			std::cout << "vsego deneg: " << totalMoney << std::endl;
		
}
std::list<int> numsSys;
std::string nums = "1234567890ABCDEF";

template <typename T>
std::string ToString(T val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}


void parseString(std::string _str)
{
	for (auto _char : _str)
	{
		if (nums.find(_char) == std::string::npos)
		{
			std::cout << "uncorrect number!!1" << std::endl;
			return;
		}
		switch (_char)
		{
		case '0':
			numsSys.push_front(0);
			break;
		case '1':
			numsSys.push_front(1);
			break;
		case '2':
			numsSys.push_front(2);
			break;
		case '3':
			numsSys.push_front(3);
			break;
		case '4':
			numsSys.push_front(4);
			break;
		case '5':
			numsSys.push_front(5);
			break;
		case '6':
			numsSys.push_front(6);
			break;
		case '7':
			numsSys.push_front(7);
			break;
		case '8':
			numsSys.push_front(8);
			break;
		case '9':
			numsSys.push_front(9);
			break;
		case 'A':
			numsSys.push_front(10);
			break;
		case 'B':
			numsSys.push_front(11);
			break;
		case 'C':
			numsSys.push_front(12);
			break;
		case 'D':
			numsSys.push_front(13);
			break;
		case 'E':
			numsSys.push_front(14);
			break;
		case 'F':
			numsSys.push_front(15);
			break;
		}
	}
}

int ConvertToDecimal(std::string num, int currNumSys)
{
	int result = 0, _pow = 0;
	parseString(ToString(num));
	for (int num : numsSys)
	{
		result += num * pow(currNumSys, _pow);
		_pow++;
	}
	return result;
}

std::string ConvertToOther(int num, int requiredSys)
{
	std::string result = "";
	do
	{
		switch (num % requiredSys)
		{
		case 0:
			result.insert(0, "0");
			break;
		case 1:
			result.insert(0, "1");
			break;
		case 2:
			result.insert(0, "2");
			break;
		case 3:
			result.insert(0, "3");
			break;
		case 4:
			result.insert(0, "4");
			break;
		case 5:
			result.insert(0, "5");
			break;
		case 6:
			result.insert(0, "6");
			break;
		case 7:
			result.insert(0, "7");
			break;
		case 8:
			result.insert(0, "8");
			break;
		case 9:
			result.insert(0, "9");
			break;
		case 10:
			result.insert(0, "A");
			break;
		case 11:
			result.insert(0, "B");
			break;
		case 12:
			result.insert(0, "C");
			break;
		case 13:
			result.insert(0, "D");
			break;
		case 14:
			result.insert(0, "E");
			break;
		case 15:
			result.insert(0, "F");
			break;
		}
		num = num / requiredSys;
	} while (num / requiredSys != 0);
	if (num % requiredSys != 0)
	{
		switch (num % requiredSys)
		{
		case 0:
			result.insert(0, "0");
			break;
		case 1:
			result.insert(0, "1");
			break;
		case 2:
			result.insert(0, "2");
			break;
		case 3:
			result.insert(0, "3");
			break;
		case 4:
			result.insert(0, "4");
			break;
		case 5:
			result.insert(0, "5");
			break;
		case 6:
			result.insert(0, "6");
			break;
		case 7:
			result.insert(0, "7");
			break;
		case 8:
			result.insert(0, "8");
			break;
		case 9:
			result.insert(0, "9");
			break;
		case 10:
			result.insert(0, "A");
			break;
		case 11:
			result.insert(0, "B");
			break;
		case 12:
			result.insert(0, "C");
			break;
		case 13:
			result.insert(0, "D");
			break;
		case 14:
			result.insert(0, "E");
			break;
		case 15:
			result.insert(0, "F");
			break;
		}
	}
	return result;
}

void task9()
{
	std::cout << "enter number, input num sys and required num sys" << std::endl;
	int inp, req;
	std::string  num;

	std::cin >> num >> inp >> req;

	bool isNegative = false;
	if (num[0] == '-')
	{
		num.erase(0, 1);
		isNegative = true;
	}
	std::string minus = "";
	if (isNegative)
	{
		minus = "-";
	}

	std::cout << minus + ConvertToOther(ConvertToDecimal(num, inp), req) << std::endl;
}



int main() {
	//First firsty;
	//File* filee = &firsty;
	//std::cout << "enter number separated by spaces:  ";
	//std::string line;
	//getline(std::cin, line);
	//std::cout << line << std::endl;
	//std::string lineout = filee->open(line);

	//double result = filee->read();
	//std::cout << result << std::endl;

	//std::cout << "enter x for second task: ";
	//double x;
	//std::cin >> x;
	//std::cout << "the sign of xis: " << sign(x) << std::endl;
	///*USA();*/

	/*Sinusoid();
	std::cin.get();*/
	//Task6();
	//task7();
	//task8();
	task9();

}
