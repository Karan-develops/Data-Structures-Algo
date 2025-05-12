// LC - 925 - Easy - Long Pressed Name
// Low Acceptance Rate
#include<iostream>
using namespace std;
bool isLongPressedName(string name, string typed) {
    int m=name.length(),n=typed.length();

    int i=0,j=0;
    while(j<n){
        if(i<m && name[i]==typed[j]) i++,j++;
        else if(j>0 && typed[j]==typed[j-1]) j++;
        else return false;
    }
    return i==m;
}
int main(){
    // Output: true
    string name="alex",typed="aaleex";
    // Output: false
    string name2="saeed",typed2="ssaaedd";
    cout<<isLongPressedName(name,typed)<<endl;
    cout<<isLongPressedName(name2,typed2);
    return 0;
}