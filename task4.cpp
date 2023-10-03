#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

}
