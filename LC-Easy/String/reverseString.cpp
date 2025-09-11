// LC - 344 - Easy - Reverse String
#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>&s){
    int n=s.size();

    int i=0,j=n-1;
    
    while(i<=j){
        swap(s[i++],s[j--]);
    }
}
int main(){
    // Output: ['o','l','l','e','h']
    string s={'h','e','l','l','o'};
    // Output: ['h','a','n','n','a','H']
    string s2={'H','a','n','n','a','h'};
    return 0;
}