#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class File {
public:
	virtual std::string open() = 0;
};

class First:public File {
private:
	std::vector<std::string>GetField;
public:
	std::string open() override;
};

std::string First::open()
{
	if (fopen("file.txt", "r") == NULL) {
		std::ofstream oFile("file.txt");
	}
	else {
		std::ofstream out;
		out.open("file.txt");
		if (out.is_open())
		{
			out << "qq";
		}
	}
	return "ss";
}

int main() {
	First firsty;
	File* filee = &firsty;
	std::string lineout = filee->open();
	std::cout << lineout;

}
