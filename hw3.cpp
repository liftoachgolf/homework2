#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main(){
    string start = "asjdkadajdkajdklsjslajd";
    vector <char> abc;

    for (int i = 0; i < start.size(); ++i) {
        abc.push_back(start[i]);
    }
    vector<int> vec;
    for (int i = 0; i < abc.size(); ++i) {
        vec.push_back((int)(abc[i]));
    }
}
