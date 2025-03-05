#include<iostream>
#include<string.h>
using namespace std;
void convertToUpperCase(char ch[]){
    for(int i=0;i<strlen(ch);i++){
        // ch[i]-=32;
        ch[i]=ch[i]-'a'+'A';
    }
}
int main(){
    // char ch[20];
    // ch[0]='K';
    // ch[1]='a';
    // ch[2]='r';
    // ch[3]='a';
    // ch[4]='n';
    // cout<<ch<<endl;
    // int val= (int)ch[10];
    // cout<<"ASCII->"<<val<<endl;
    // cout<<sizeof(ch)<<endl;

    char ch[100]="karan";
    cout<<"Before upper-case:"<<ch<<endl;
    convertToUpperCase(ch);
    cout<<"After upper-case:"<<ch<<endl;
    return 0;
}