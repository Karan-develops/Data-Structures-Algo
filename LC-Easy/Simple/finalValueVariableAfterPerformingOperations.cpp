// LC - 2011 - Easy - Final Value of Variable After Performing Operations
#include<iostream>
#include<vector>
using namespace std;
int finalValueAfterOperations(vector<string>&operations){
    int ans=0;

    for(const string &s:operations){
        if(s[1]=='+') ans++;
        else ans--;
    }

    return ans;
}
int main(){
    // Output: 1
    vector<string>operations={"--X","X++","X++"};
    // Output: 3
    vector<string>operations2={"++X","++X","X++"};
    // Output: 0
    vector<string>operations3={"X++","++X","--X","X--"};
    cout<<finalValueAfterOperations(operations)<<endl;
    cout<<finalValueAfterOperations(operations2)<<endl;
    cout<<finalValueAfterOperations(operations3);
    return 0;
}