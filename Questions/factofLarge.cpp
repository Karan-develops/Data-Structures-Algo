#include<iostream>
#include<vector>
using namespace std;
void findFact(int n){
    vector<int>ans;
    ans.push_back(1);
    int carry=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<ans.size();j++){
            int sum=ans[j]*i+carry;
            ans[j]=sum%10;
            carry=sum/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
        carry=0;
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
}
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    findFact(n);
    return 0;
}