// LC - 2129 - Easy - Capitalize the Title
#include<iostream>
#include<sstream>
using namespace std;
string capitalizeTitle(string title) {
    stringstream ss(title);
    string token,ans;
    while(getline(ss,token,' ')){
        for(char &ch:token) ch=tolower(ch);

        if(token.length()>2){
            token[0]=toupper(token[0]);
        }
        if(!ans.empty()) ans+=' ';
        ans+=token;
    }
    return ans;
}
int main(){
    // Output: "Capitalize The Title"
    string title="capiTalIze tHe titLe";
    // Output: "First Letter of Each Word"
    string title2="First leTTeR of EACH Word";
    // Output: "i Love Leetcode"
    string title3="i lOve leetcode";
    cout<<capitalizeTitle(title)<<endl;
    cout<<capitalizeTitle(title2)<<endl;
    cout<<capitalizeTitle(title3);
    return 0;
}