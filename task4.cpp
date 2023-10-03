#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#pragma warning(disable:4996)

class File {
public:
	virtual std::string open() = 0;
	virtual double read() = 0;

};

class First : public File {
private:
	std::vector<std::string>GetField;
	std::vector<char> TField;
public:
	std::string open() override;
	double read() override;

};

std::string First::open()
{
	if (fopen("file.txt", "r") == NULL) {
		std::ofstream oFile("file.txt");
		oFile.close();
	}
	 
		std::ofstream out;
		out.open("file.txt");
		if (out.is_open())
		{
			out << "123";	
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
		flow.close();
	}
	return summ;

}



int main() {
	First firsty;
	File* filee = &firsty;
	//std::string lineout = filee->open();
	double result = filee->read();
	std::cout << result << std::endl;

}
