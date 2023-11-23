#include <iostream>
#include "cmath"
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
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
void tusk12(int a, int b){
    if(a!=0 && b!=0){
        if(a>b){
            a=a%b;
            tusk12(a,b);
        }
        else{
            b=b%a;
            tusk12(a,b);
        }
    }
    else{
        cout<<a+b;
    }
}

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
    int a=0,e=0,i=0,o=0,u=0, y=0;
public:
    string Readfile();
    void FindSogl();
};

void diff(){
    cout<<"Enter number: "<<endl;
    int mas[10]= {0};
    int n, counter = 0;
    cin >> n;
    while(n)
    {
        mas[n%10]++;
        n/=10;
    }
    for(int i=0; i<10; i++)
        if(mas[i])
            counter++;
    cout <<"it has:"<< counter<<"diff nums,";

}


string FileReader::Readfile() {
    std::string readline;

    std::ifstream iff("file.txt");
    if (fopen("file.txt", "r") == NULL) {
        std::ofstream oFile("file.txt");
    }
    std::ifstream flow("file.txt");
    if (!flow.is_open()) {
        abort();
    } else {
        while (std::getline(flow, readline)) {
            return readline;
        }
    }
}
bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second < b.second;
}


void Sort(map<string, int>& M)
{


    vector<pair<string, int> > A;

    for (auto& it : M) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);
    cout<<A.at(size(A)-1).first<<" "<<A.at(size(A)-1).second<<endl;
    for(auto &mini: A){
        if(mini.second!=0){
            cout<<"MIN:"<<mini.first<<" "<<mini.second<<endl;
            break;
        }
    }

}

void summi(){
    int n;
    int sum=0;

    cout << "please, enter n = ";
    cin >> n;

    while (n!=0)
    {
        sum += n%10;
        n /= 10;
    }
    cout << "sum = " << sum << endl;

}

void FileReader::FindSogl() {
    string startLen = this->Readfile();
    for(char w : startLen){
        switch(w) {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            case 'y':
                y++;
                break;
            default:
                nullptr;
        }
    }
    map<string, int> m={
            {"a", a},
            {"e", e},
            {"i", i},
            {"o", o},
            {"u", u},
            {"y", y},
    };
  Sort(m);

}

void countSpace(){
    int maxi=0;
    vector<int> arr;
    string str;
    getline(cin, str);
    int j = str.length();
    int spaces = 0;
    for (int i = 0; i < j; ++i) {
        if (str[i] == ' ') {
            spaces++;
            arr.push_back(spaces);
        }
        else{
            spaces=0;
            arr.push_back(spaces);
        }

    }
    sort(arr.begin(), arr.end());
    cout<<arr.at(size(arr)-1);
}

int main() {
    Second s;
    tusk12(3,12);
//    tusk1(3,12);
//    s.tusk2(100);
//    FileReader a;
//    a.FindSogl();
//    summi();
    diff();
countSpace();
}
