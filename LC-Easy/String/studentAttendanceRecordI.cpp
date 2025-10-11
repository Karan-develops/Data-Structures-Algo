// LC - 551 - Easy - Student Attendance Record I
// 2 Approaches
#include<iostream>
using namespace std;
bool checkRecord(string s){
    int n=s.length();
    if(n==1) return true;

    int absent=0;
    if(s[0]=='A') absent++;
    if(s[1]=='A') absent++;

    for(int i=2;i<n;i++){
        if(s[i-2]=='L' && s[i-1]=='L' && s[i]=='L'){
            return false;
        }
        if(s[i]=='A') absent++;
    }
    return absent<2;
}
// Approach 2 - Use Counters
bool checkRecord2(string s){
    int absent=0;
    int late=0;

    for(char &ch:s){
        if(ch=='A') absent++;
        if(ch=='L') late++;
        if(ch!='L') late=0;

        if(absent==2 || late==3) return false;
    }
    return true;
}
int main(){
    // Output: true
    string s="PPALLP";
    // Output: false
    string s2="PPALLL";
    cout<<checkRecord(s)<<endl;
    cout<<checkRecord(s2);
    return 0;
}