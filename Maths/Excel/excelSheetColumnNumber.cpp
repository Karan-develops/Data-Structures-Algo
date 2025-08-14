// LC - 171 - Easy - Excel Sheet Column Number
#include<iostream>
#include<math.h>
using namespace std;
int titleToNumber(string columnTitle){
    int n=columnTitle.size();
    int ans=0;

    for(int i=n-1;i>=0;i--){
        ans+=(columnTitle[i]-'A'+1)*pow(26,n-i-1);
    }
    return ans;
}
int main(){
    // Output: 1
    string columnTitle="A";
    // Output: 28
    string columnTitle2="AB";
    // Output: 701
    string columnTitle3="ZY";
    cout<<titleToNumber(columnTitle)<<endl;
    cout<<titleToNumber(columnTitle2)<<endl;
    cout<<titleToNumber(columnTitle3);
    return 0;
}