// LC - 3723 - Medium - Maximize Sum of Squares of Digits
#include<iostream>
using namespace std;
string maxSumOfSquares(int num,int sum){
    if(sum>9*num) return "";

    string ans="";

    for(int i=0;i<num;i++){
        int digit=min(9,sum);
        
        ans+=(digit+'0');

        sum-=digit;
    }

    if(sum!=0) return "";

    return ans;
}
int main(){
    // Output: "30"
    int num=2,sum=3;
    // Output: "98"
    int num2=2,sum2=17;
    // Output: ""
    int num3=1,sum3=10;
    cout<<maxSumOfSquares(num,sum)<<endl;
    cout<<maxSumOfSquares(num2,sum2)<<endl;
    cout<<maxSumOfSquares(num3,sum3);
    return 0;
}