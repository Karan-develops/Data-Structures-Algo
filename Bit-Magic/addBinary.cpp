// LC - 67 - Easy - Add Binary
#include<iostream>
#include<algorithm>
using namespace std;
string addBinary(string a,string b){
    int m=a.length(),n=b.length();

    int carry=0;
    int i=m-1,j=n-1;
    string ans;

    while(i>=0 || j>=0 || carry){
        if(i>=0) carry+=a[i--]-'0';
        if(j>=0) carry+=b[j--]-'0';
        
        ans+=carry%2+'0';
        carry/=2;
    }

    reverse(begin(ans),end(ans));
    return ans;
}
int main(){
    // Output: "100"
    string a="11",b="1";
    // Output: "10101"
    string a2="1010",b2="1011";
    cout<<addBinary(a,b)<<endl;
    cout<<addBinary(a2,b2);
    return 0;
}