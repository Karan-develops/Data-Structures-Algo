// LC - 179 - Medium - Largest Number
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class String{
public:
    static bool myComp(string &a,string &b){
        string x=a+b;
        string y=b+a;

        return x>y;
    }
    string largestNumber(vector<int>&nums){
        vector<string>temp;

        for(auto &i:nums){
            temp.push_back(to_string(i));
        }

        sort(temp.begin(),temp.end(),myComp);
        
        if(temp[0]=="0") return "0";
        
        string ans="";
        for(auto &i:temp) ans+=i;

        return ans;
    }
};
int main(){
    // Output: "210"
    vector<int>nums={10,2};
    // Output: "9534330"
    vector<int>nums2={3,30,34,5,9};

    String sol;
    cout<<sol.largestNumber(nums)<<endl;
    cout<<sol.largestNumber(nums2);
    return 0;
}