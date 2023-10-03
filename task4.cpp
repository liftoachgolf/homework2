#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>
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
void USA(){
	char one[] = "_________________________________________________\n";
	char two[] = "********_________________________________________\n";
	std::cout << one;
	for (int i = 0; i < 6;++i) {
		std::cout << two;
	}
	for (int i = 0; i < 6; ++i) {
		std::cout << one;
	}
}

void clear() {
	for(int i = 0; i<5; ++i){
		std::cout << std::endl << std::endl;
	}
}

int getSin(double x, int d_y = 25) {
	return  (int)((sin(x) * 100) + d_y / 2);
}

void gotoxy(int x, int y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void Sinusoid() {
	for (double x = -100; x < 100; x += 0.01) {
		int y = getSin(x);
		if (y <= 1) {
			continue;
		}
		gotoxy((int)(x * 10), y);
		std::cout << '*';
	}
	for (int i = 0; i < 120; i++) {
		gotoxy(i, 0);
		std::cout << ' ';
	}
	gotoxy(0, 26);

}


int main() {
	First firsty;
	File* filee = &firsty;
	std::cout << "enter number separated by spaces:  ";
	std::string line;
	getline(std::cin, line);
	std::cout << line << std::endl;
	std::string lineout = filee->open(line);

	double result = filee->read();
	std::cout << result << std::endl;

	std::cout << "enter x for second task: ";
	double x;
	std::cin >> x;
	std::cout << "the sign of xis: " << sign(x) << std::endl;
	USA();

	Sinusoid();


}
