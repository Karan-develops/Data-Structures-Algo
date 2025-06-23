// GFG - Minimum sum
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Maths{
    string addString(string &s1,string &s2){
        int i=s1.length()-1;
        int j=s2.length()-1;
        int c=0;
        string ans="";

        while(i>=0 || j>=0 || c>0){
            int sum=c;

            if(i>=0) sum+=(s1[i]-'0');
            if(j>=0) sum+=(s2[j]-'0');

            ans.push_back(sum%10+'0');
            c=sum/10;
            i--,j--;
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(begin(ans),end(ans));

        return ans;
    }
    public:
    string minSum(vector<int>&nums){
        sort(begin(nums),end(nums));

        string s1="";
        string s2="";

        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                s1.push_back(nums[i]+'0');
            } else{
                s2.push_back(nums[i]+'0');
            }
        }
        return addString(s1,s2);
    }
};
int main(){
    // Output: "604"
    vector<int>nums={6,8,4,5,2,3};
    // Output: "82"
    vector<int>nums2={5,3,0,7,4};
    // Output: "13"
    vector<int>nums3={9,4};

    Maths sol;
    cout<<sol.minSum(nums)<<endl;
    cout<<sol.minSum(nums2)<<endl;
    cout<<sol.minSum(nums3);
    return 0;
}