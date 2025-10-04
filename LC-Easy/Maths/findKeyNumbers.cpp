// LC - 3270 - Easy - Find the Key of the Numbers
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int generateKey(int num1,int num2,int num3){
    int ans=0;
    int i=0;

    while(num1 || num2 || num3){
        int a=num1%10;
        int b=num2%10;
        int c=num3%10;

        ans+=min({a,b,c})*pow(10,i++);
        
        num1/=10;
        num2/=10;
        num3/=10;
    }
    return ans;
}
int main(){
    // Output: 0
    int num1=1,num2=10,num3=1000;
    // Output: 777
    int num4=987,num5=879,num6=798;
    // Output: 1
    int num7=1,num8=2,num9=3;
    cout<<generateKey(num1,num2,num3)<<endl;
    cout<<generateKey(num4,num5,num6)<<endl;
    cout<<generateKey(num7,num8,num9);
    return 0;
}