#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int numberLetter(string s, char letter) {
        int result{0};
        for(char str:s){
            if(str==letter)     result++;
        }
        return result;
    }
};

int main(){
    string s{};
    char letter{};
    cout<<"Please enter a string:\n";
    getline(cin,s);
    cout<<"Please enter the letter:\n";
    cin>>letter;
    Solution s1;
    cout<<"letter '"<<letter<<"' in '"<<s<<"' occupied "<<s1.numberLetter(s,letter);
}