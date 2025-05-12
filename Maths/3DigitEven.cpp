// LC - 2094 - Easy - Finding 3-Digit Even Numbers
#include<iostream>
#include<vector>
using namespace std;
vector<int> findEvenNumbers(vector<int>&digits){
    int n=digits.size();
    vector<int>ans;
    vector<int>mp;

    for(int &digit:digits) mp[digit]++;

    for(int i=1;i<=9;i++){
        if(mp[i]==0) continue;
        mp[i]--;
        for(int j=0;j<=9;j++){
            if(mp[j]==0) continue;
            mp[j]--;
            for(int k=0;k<=8;k+=2){
                if(mp[k]==0) continue;
                mp[k]--;

                int num=i*100+j*10+k;
                ans.push_back(num);
                mp[k]++;
            }
            mp[j]++;
        }
        mp[i]++;
    }
    return ans;
}
int main(){
    // Output: [102,120,130,132,210,230,302,310,312,320]
    vector<int>digits={2,1,3,0};
    // Output: [222,228,282,288,822,828,882]
    vector<int>digits={2,2,8,8,2};
    // Output: []
    vector<int>digits={3,7,5};
    return 0;
}