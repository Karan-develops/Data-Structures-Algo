// Leet Code ProbNo.287 (medium)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// Method 1 -> complexity (nlogn)
int method1(vector<int>a){
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            return a[i];
        }
    }
    return -1;
}
// Method 2
int method2(vector<int>a){
    int ans=-1;
    for(int i=0;i<a.size();i++){
        int index = abs(a[i]);
        if(a[index]<0){
            ans=index;
            break;
        }
        a[index]*=-1;
    }
    return ans;
}
// Method 3
int method3(vector<int>a){
    while(a[0]!=a[a[0]]){
        swap(a[0],a[a[0]]);
    }
    return a[0];
}
int main(){
    vector<int>a{1,3,4,2,4};
    int ans=method1(a);
    cout<<ans<<endl;
    int ans2=method2(a);
    cout<<ans2<<endl;
    int ans3=method3(a);
    cout<<ans3;
    return 0;
}