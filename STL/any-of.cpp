// C++ - any_of, all_of, none_of
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v={1,2,3,4};

    auto lambda=[&](int x){
        return x%2==0;
    };

    bool ans1=any_of(begin(v),end(v),lambda);
    cout<<ans1<<endl;

    bool ans2=all_of(begin(v),end(v),lambda);
    cout<<ans2<<endl;

    bool ans3=none_of(begin(v),end(v),lambda);
    cout<<ans3;
    return 0;
}