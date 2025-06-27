// LC - 12 - Medium - Integer to Roman
#include<iostream>
#include<vector>
using namespace std;
vector<int>val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string>symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
string intToRoman(int num){
    string ans;
    
    for(int i=0;i<13;i++){
        if(num==0) break;

        int times=num/val[i];
        while(times--){
            ans+=symbol[i];
        }
        num%=val[i];
    }
    return ans;
}
int main(){
    // Output: "MMMDCCXLIX"
    int num=3749;
    // Output: "LVIII"
    int num2=58;
    // Output: "MCMXCIV"
    int num3=1994;
    cout<<intToRoman(num)<<endl;
    cout<<intToRoman(num2)<<endl;
    cout<<intToRoman(num3);
    return 0;
}