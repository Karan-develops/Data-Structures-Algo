#include<iostream>
#include<vector>
using namespace std;
string convert(string s, int numRows) {
    if(numRows==1) return s;
    int n=s.length();
    vector<string>zigzag(numRows);
    int i=0,rows=0;
    bool direction=1;
    while(true){
        if(direction){
            while(i<n && rows<numRows){
                zigzag[rows++].push_back(s[i++]);
            }
            rows=rows-2;
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
    for(int i=0;i<zigzag.size();i++){
        ans+=zigzag[i];
    }
    return ans;
}
int main(){
    string s1="PAYPALISHIRING";
    int numRows=3;
    cout<<convert(s1,numRows);
    return 0;
}