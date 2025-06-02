// LC - 2810 - Easy - Faulty Keyboard
#include<iostream>
#include<algorithm>
using namespace std;
string finalString(string s) {
    string ans="";

    for(char &ch:s){
        if(ch!='i') ans+=ch;
        else{
            reverse(begin(ans),end(ans));
        }
    }
    return ans;
}
int main(){
    // Output: "rtsng"
    string s="string";
    // Output: "ponter"
    string s2="poiinter";
    cout<<finalString(s)<<endl;
    cout<<finalString(s2);
    return 0;
}