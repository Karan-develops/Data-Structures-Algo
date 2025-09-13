// LC - 3227 - Medium - Vowels Game in a String
#include<iostream>
using namespace std;
bool doesAliceWin(string s){
    for(char &ch:s){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
    }
    return false;
}
int main(){
    // Output: true
    string s="leetcoder";
    // Output: false
    string s2="bbcd";
    cout<<doesAliceWin(s)<<endl;
    cout<<doesAliceWin(s2);
    return 0;
}