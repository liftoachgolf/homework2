#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

static const std::string file_name = "file.txt";

class Homework {
private:
    std::vector<char> abc;
    std::vector<int> vec;
    std::vector<char> result;
    int b;
    double S,p,n,m,r;
public:
    Homework(double S, double n, double p){
        this->S = S;
        this->n = n;
        this->p=p;
    };
    Homework();
    void ReadInt();
    void Base();
    void Swap(int* a, int* b);
    void bubbleSort(std::vector<int>& array);
    std::string WorkWithFile();
    std::pair<double,std::string> fuSuda();
};


int main() {
    setlocale(LC_ALL, "Russian");

    double S, p, n, m;
    std::cout<<"print S, p,n"<<std::endl;
    std::cin >> S >> p >> n;
    Homework a(S, p, n);
    m = a.fuSuda().first;
    std::string comment = a.fuSuda().second;
    if (m == 0) {
        std::cout << comment << std::endl;
    } else {
        std::cout << comment << m<<std::endl;
    }
    a.WorkWithFile();
    std::cout << "only numbers: ";
    a.ReadInt();
    std::cout << std::endl << "task 5" << "sorted: ";
    a.Base();

}

std::pair<double, std::string> Homework::fuSuda(){
    r= p/100;
    if ((n <= 0) ||( S <= 0)||(p<=0)){
        return std::make_pair(NULL, "the numbers cant be less than: 0 ");
    }
    else if (p == 0) {
        m = S / (12 * n);
    }

    else {
        r = p / 100;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
    }
    if (12 * (pow(1 + r, n) - 1) < 0) {
        return std::make_pair(NULL, "u cant deletb on ");
    }
    return std::make_pair(m,"the result is: ");
}

void Homework::ReadInt() {
    std::ifstream file(file_name);
    do
    {
        if(file >> b)
        {
            std::cout << b;
        }
        else
        {
            file.clear();
            file.ignore(1, ' ');
        }
    }
    while(!file.eof());
    file.close();
}

void Homework::Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Homework::bubbleSort(std::vector<int>& array)
{

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size() - 1; j++)
        {
            if (array[j] > array[j + 1])
                Swap(&array[j], &array[j + 1]);
        }
    }
}

std::string Homework::WorkWithFile()
{
    std::string readline;

    std::ifstream  iff("file.txt");
    if(fopen("file.txt", "r") == NULL){
        std::ofstream oFile("file.txt");
    }
    std::ifstream  flow(file_name);
    if (!flow.is_open()){
        abort();
    }
    else{
        while (std::getline(flow, readline))
        {
            return readline;
        }
    }
}
void Homework::Base() {
    std::string start = this->WorkWithFile();
    for (char i: start) {
        abc.push_back(i);
    }
    for (char &i: abc) {
        vec.push_back((int) i);
    }
    this->bubbleSort(vec);

    for (int &i: vec) {
        result.push_back((char) (tolower(i)));
    }

    for (char i: result) {
        std::cout << i;
    }
}

/*
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double S,n,mevery,m,r;

    double rTemp = 0.000001;
    cout << "----------------------- "<<endl;
    cout << "summ = ";
    cin >> S;
    cout << "amont of years = ";
    cin >> n;
    cout << "everymothpay = ";
    cin >> mevery;


    if ((n <= 0) ||( S <= 0)||(mevery<=0)) {
        cout << "Incorrect data"<<std::endl;
    }
    else{

    while (m < mevery) {
        r = rTemp;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
        rTemp = rTemp + 0.000001;
    }

    cout << "p = " << r * 100 << "%" << endl;
}
}
*/
