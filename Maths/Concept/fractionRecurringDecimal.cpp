// LC - 166 - Medium - Fraction to Recurring Decimal
#include<iostream>
#include<unordered_map>
using namespace std;
string fractionToDecimal(int numerator,int denominator){
    if(numerator==0) return "0";

    string ans;

    if((long long)numerator*(long long)denominator<0){
        ans+="-";
    }

    long long absNumerator=llabs(numerator);
    long long absDenominator=llabs(denominator);

    long long integerDiv=absNumerator/absDenominator;

    ans+=to_string(integerDiv);

    long long rem=absNumerator%absDenominator;
    if(rem==0) return ans;

    ans+='.';

    unordered_map<int,int>mp;

    while(rem){
        if(mp.count(rem)){
            ans.insert(mp[rem],"(");
            ans+=")";
            break;
        }

        mp[rem]=ans.length();
        rem*=10;
        int digit=rem/absDenominator;
        ans+=to_string(digit);

        rem%=absDenominator;
    }

    return ans;
}
int main(){
    // Output: "0.5"
    int numerator=1,denominator=2;
    // Output: "2"
    int numerator2=2,denominator2=1;
    // Output: "0.(012)"
    int numerator3=4,denominator3=333;
    cout<<fractionToDecimal(numerator,denominator)<<endl;
    cout<<fractionToDecimal(numerator2,denominator2)<<endl;
    cout<<fractionToDecimal(numerator3,denominator3);
    return 0;
}