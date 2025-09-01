// LC - 2194 - Easy - Cells in a Range on an Excel Sheet
#include<iostream>
#include<vector>
using namespace std;
vector<string> cellsInRange(string s){
    vector<string>ans;

    for(char i=s[0];i<=s[3];i++){
        for(char j=s[1];j<=s[4];j++){
            ans.push_back({i,j});
        }
    }
    return ans;
}
int main(){
    // Output: ["K1","K2","L1","L2"]
    string s="K1:L2";
    // Output: ["A1","B1","C1","D1","E1","F1"]
    string s2="A1:F1";
    return 0;
}