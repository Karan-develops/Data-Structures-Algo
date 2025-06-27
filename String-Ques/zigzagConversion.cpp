// LC - 6 - Medium - Zigzag Conversion
#include<iostream>
#include<vector>
using namespace std;
string convert(string s,int numRows){
    if(numRows==1) return s;

    int n=s.length();

    vector<string>zigzag(numRows);
    int i=0,rows=0;
    bool direction=true;

    while(true){
        if(direction){
            while(i<n && rows<numRows){
                zigzag[rows++].push_back(s[i++]);
            }
            rows-=2;
        }
        else{
            while(i<n && rows>=0){
                zigzag[rows--].push_back(s[i++]);
            }
            rows=1;
        }
        if(i>=n) break;
        direction=!direction;
    }
    
    string ans="";
    for(string &str:zigzag){
        ans+=str;
    }
    return ans;
}
int main(){
    // Output: "PAHNAPLSIIGYIR"
    string s="PAYPALISHIRING";
    int numRows=3;
    // Output: "PINALSIGYAHRPI"
    string s2="PAYPALISHIRING";
    int numRows2=4;
    // Output: "A"
    string s3="A";
    int numRows3=1;
    cout<<convert(s,numRows)<<endl;
    cout<<convert(s2,numRows2)<<endl;
    cout<<convert(s3,numRows3);
    return 0;
}