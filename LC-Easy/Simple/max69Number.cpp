// LC - 1323 - Easy - Maximum 69 Number
// 2 Approaches
#include<iostream>
#include<math.h>
using namespace std;
// Approach 1 - Converting into string
int maximum69Number(int num){
    string temp=to_string(num);
    for(char &ch:temp){
        if(ch=='6'){
            ch='9';
            break;
        }
    }
    return stoi(temp);
}
// Approach 2 - Without Converting into string
int maximum69Number2(int num){
    int place=0;
    int index=-1;
    int temp=num;

    while(temp){
        int remain=temp%10;
        if(remain==6) index=place;
        
        temp/=10;
        place++;
    }
    
    if(index==-1) return num;
    
    // Add 300... to that place
    return num+3*pow(10,index);   
}
int main(){
    // Output: 9969
    int num=9669;
    // Output: 9999
    int num2=9996;
    // Output: 9999
    int num3=9999;
    cout<<maximum69Number(num)<<endl;
    cout<<maximum69Number(num2)<<endl;
    cout<<maximum69Number(num3);
    return 0;
}