// LC - 984 - Medium - String Without AAA or BBB
#include<iostream>
using namespace std;
string strWithout3a3b(int a,int b){
    string ans;

    while(a>0 || b>0){
        if(ans.size()>=2 && ans.back()==ans[ans.size()-2]){
            if(ans.back()=='a'){
                ans+='b';
                b--;
            } else{
                ans+='a';
                a--;
            }
        } else{
            if(a>=b){
                ans+='a';
                a--;
            } else{
                ans+='b';
                b--;
            }
        }
    }
    return ans;
}
int main(){
    // Output: "abb"
    int a=1,b=2;
    // Output: "aabaa"
    int a2=4,b2=1;
    cout<<strWithout3a3b(a,b)<<endl;
    cout<<strWithout3a3b(a2,b2);
    return 0;
}