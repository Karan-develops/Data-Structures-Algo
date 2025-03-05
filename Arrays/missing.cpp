#include<iostream>
#include<vector>
using namespace std;
// Method 1
void method1(vector<int>a){
    for(int i=0;i<a.size();i++){
        int index=abs(a[i]);
        if(a[index-1]>0){
            a[index-1]*=-1;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]>0) cout<<i+1<<" ";
    }
    cout<<endl;
}
// Method 2
void method2(vector<int>a){
    int i=0;
    while(i<a.size()){
        int index=a[i]-1;
        if(a[index]!=a[i]){
            swap(a[index],a[i]);
        } else{
            i++;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=i+1) cout<<i+1<<" ";
    }
}
int main(){
    vector<int>a{1,3,5,3,4};
    method1(a);
    method2(a);
    return 0;
}