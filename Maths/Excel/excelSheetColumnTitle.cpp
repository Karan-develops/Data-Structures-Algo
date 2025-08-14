// LC - 168 - Easy - Excel Sheet Column Title
#include<iostream>
#include<algorithm>
using namespace std;
string convertToTitle(int columnNumber){
    string ans;

    while(columnNumber){
        // To handle 'Z'
        columnNumber--;

        int remainder=columnNumber%26;
        ans.push_back('A'+remainder);

        columnNumber/=26;
    }

    reverse(begin(ans),end(ans));
    return ans;
}
int main(){
    // Output: "A"
    int columnNumber=1;
    // Output: "AB"
    int columnNumber2=28;
    // Output: "ZY"
    int columnNumber3=701;
    cout<<convertToTitle(columnNumber)<<endl;
    cout<<convertToTitle(columnNumber2)<<endl;
    cout<<convertToTitle(columnNumber3);
    return 0;
}