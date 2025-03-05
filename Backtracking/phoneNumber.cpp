#include<iostream>
#include<vector>
using namespace std;
void solve(vector<string>&ans,int index,string input,string output,vector<string>&mapping){
    // Base Case
    if(index>=input.length()){
        ans.push_back(output);
        return;
    }
    // Solve 1 Case
    int digit=input[index]-'0';
    string value=mapping[digit];
    for(int i=0;i<value.length();i++){
        char ch=value[i];
        // include
        output.push_back(ch);
        // Recursive call
        solve(ans,index+1,input,output,mapping);
        // Backtrack
        output.pop_back();
    }
}
int main(){
    string input="23";
    vector<string>ans;
    vector<string>mapping(10);
    if(input.length()==0){
        cout<<"No solution!";
        return 0;
    }
    mapping[2]="abc";
    mapping[3]="def";
    mapping[4]="ghi";
    mapping[5]="jkl";
    mapping[6]="mno";
    mapping[7]="pqrs";
    mapping[8]="tuv";
    mapping[9]="wxyz";
    string output="";
    solve(ans,0,input,output,mapping);
    for(auto i:ans){
        cout<<"[";
        cout<<i;
        cout<<"]";
    }
    return 0;
}