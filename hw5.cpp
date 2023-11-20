#include <iostream>
#include "cmath"
#include <vector>
#include <string>
#include "fstream"

using namespace std;

static const string abc = "aeiouy";

class Second{
private:
    vector<int>arr;

public:

    bool isSimple(int a);
    void AddToArr(int n);
    void tusk2(int n);
};
class Third{
private:
public:

};

void tusk1(double a,double b){
    double max, min;
    if (a==b){
        cout<<"NOD: "<<a;
    }
    else if(a>b){
        max = a;
        min = b;
        tusk1(max-min, min);
    }
    else{
        max = b;
        min = a;
        tusk1(max-min, min);
    }
}
void activateTusk1(){
    double a,b;
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    tusk1(a,b);
}

bool Second::isSimple(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

void Second::AddToArr(int n) {
    for(int i = n-1; i>2; --i){
        if(this->isSimple(i)){
            arr.push_back(i);
        }

    }
}
void Second::tusk2(int n){
    this->AddToArr(n);
    for(int i : arr){
        cout<<i<<endl;
    }
}

class FileReader{
private:
    string line;
    int a=0,e=0,i=0,o=0,u=0, y= 0;
public:
    string Readfile();
    void FindSogl();
};

string FileReader::Readfile()
{
    std::string readline;

    std::ifstream  iff("file.txt");
    if(fopen("file.txt", "r") == NULL){
        std::ofstream oFile("file.txt");
    }
    std::ifstream  flow("file.txt");
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
void FileReader::FindSogl() {
    string startLen = this->Readfile();
    for(int i = 0; i< startLen.size(); ++i){
        switch (startLen[i]) {
            case 'a':
                a++;
            case 'e':
                e++;
            case 'i':
                i++;
            case 'o':
                o++;
            case 'u':
                u++;
            case 'y':
                y++;
        }
    }
    cout<<a;
}

int main() {
    Second s;
//    s.tusk2(13);
    FileReader a;
    a.FindSogl();
}

