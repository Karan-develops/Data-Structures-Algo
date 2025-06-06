// LC - 2434 - Medium - Using a Robot to Print the Lexicographically Smallest String
#include<iostream>
#include<vector>
using namespace std;
string robotWithString(string s) {
    int n=s.length();

    vector<char>minCharToRight(n);
    minCharToRight[n-1]=s[n-1];

    for(int i=n-2;i>=0;i--){
        minCharToRight[i]=min(s[i],minCharToRight[i+1]);
    }

    string paper,t;

    for(int i=0;i<n;i++){
        t.push_back(s[i]);

        char minChar=(i+1<n)?minCharToRight[i+1]:s[i];

        while(!t.empty() && t.back()<=minChar){
            paper+=t.back();
            t.pop_back();
        }
    }

    // Fill the remaining characters
    while(!t.empty()){
        paper+=t.back();
        t.pop_back();
    }
    return paper;
}
int main(){
    // Output: "azz"
    string s="zza";
    // Output: "abc"
    string s2="bac";
    // Output: "addb"
    string s3="bdda";
    cout<<robotWithString(s)<<endl;
    cout<<robotWithString(s2)<<endl;
    cout<<robotWithString(s3);
    return 0;
}