// GFG - Largest number in one swap
#include<iostream>
using namespace std;
string largestSwap(string &s){
    int n=s.length();
    int maxIdx=n-1;
    int leftIdx=-1,rightIdx=-1;

    for(int i=n-2;i>=0;i--){
        if(s[i]>s[maxIdx]){
            maxIdx=i;
        } else if(s[i]<s[maxIdx]){
            leftIdx=i;
            rightIdx=maxIdx;
        }
    }

    if(leftIdx!=-1){
        swap(s[leftIdx],s[rightIdx]);
    }

    return s;
}
int main(){
    // Output: "867"
    string s="768";
    // Output: "333"
    string s2="333";
    cout<<largestSwap(s)<<endl;
    cout<<largestSwap(s2);
    return 0;
}