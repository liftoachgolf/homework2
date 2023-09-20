#include <iostream>
#include <string>
#include <vector>
#include <fstream>

static const std::string file_name = "file.txt";

class Homework {
private:
    std::vector<char> abc;
    std::vector<int> vec;
    std::vector<char> result;
public:
    Homework(){
        std::string start = this->WorkWithFile();
        for (char i : start) {
            abc.push_back(i);
        }
        for (char & i : abc) {
            vec.push_back((int)i);
        }
        this->bubbleSort(vec);

        for(int & i : vec){
            result.push_back((char)(i));
        }

        for(char i : result){
            std::cout<<i;
        }

    }
    void Swap(int* a, int* b);
    void bubbleSort(std::vector<int>& array);
    std::string WorkWithFile();
};


int main(){
    Homework();
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

    std::ifstream  iff(file_name);
    if(iff.bad()){
        std::ofstream oFile(file_name);
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
