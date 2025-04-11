// LC - 2843 - Easy - Count Symmetric Integers
#include<iostream>
using namespace std;
int countSymmetricIntegers(int low,int high){
    int ans=0;
    for(int i=low;i<=high;i++){
        // 2 Digit Numbers
        if(i>=11 && i<=99 && i%11==0) ans++;
        // 4 Digit Numbers
        else if(i>=1000 && i<=9999){
            int first=i/1000;
            int second=(i/100)%10;
            int third=(i/10)%10;
            int fourth=i%10;
            if(first+second==third+fourth) ans++;
        }
    }
    return ans;
}
int main(){
    // Output: 9
    int low=1,high=100;
    // Output: 4
    int low2=1200,high2=1230;
    cout<<countSymmetricIntegers(low,high)<<endl;
    cout<<countSymmetricIntegers(low2,high2);
    return 0;
}