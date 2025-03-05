#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>a{9,5,4,9};
    vector<int>b{2,1,4};
    vector<int>ans;
    int i=a.size()-1;
    int j=b.size()-1;
    int carry=0;
    while(i>=0 && j>=0){
        int sum=a[i]+b[j]+carry;
        int digit=sum%10;
        ans.push_back(digit);
        carry=sum/10;
        i--,j--;
    }
    while(i>=0){
        int sum=a[i]+carry;
        int digit=sum%10;
        ans.push_back(digit);
        carry=sum/10;
        i--;
    }
    while(j>=0){
        int sum=b[j]+carry;
        int digit=sum%10;
        ans.push_back(digit);
        carry=sum/10;
        j--;
    }
    if(carry){
        ans.push_back(carry);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}