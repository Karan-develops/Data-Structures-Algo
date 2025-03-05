// Fancy Pattern-1
#include<iostream>
using namespace std;
int main(){
    short n;
    cout<<"Enter rows(Rows should be-[0-9]):";
    cin>>n;
    for(int i=0;i<n;i++){
        int start_num_index=8-i;
        int num=i+1;
        int count_num=num;
        for(int j=0;j<17;j++){
            if(j==start_num_index && count_num){
                cout<<num;
                start_num_index+=2;
                count_num--;
            }
            else cout<<"*";
        }
        cout<<endl;
    }
}