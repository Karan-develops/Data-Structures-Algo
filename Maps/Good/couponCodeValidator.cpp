// LC - 3606 - Easy - Coupon Code Validator
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Maps{
    bool checkValidCode(string &code){
        if(code.empty()) return false;

        for(char &ch:code){
            if(!isalnum(ch) && ch!='_'){
                return false;
            }
        }
        return true;
    }
    public:
    vector<string> validateCoupons(vector<string>&code,vector<string>&businessLine,vector<bool>&isActive){
        unordered_map<string,int>mp={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };

        // {businessLineIntegerValue, code}
        vector<pair<int,string>>temp;

        for(int i=0;i<code.size();i++){
            if(isActive[i] && mp.count(businessLine[i]) && checkValidCode(code[i])){
                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp),end(temp));
        vector<string>ans;

        for(auto &it:temp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
int main(){
    // Output: ["PHARMA5","SAVE20"]
    vector<string>code={"SAVE20","","PHARMA5","SAVE@20"},businessLine={"restaurant","grocery","pharmacy","restaurant"};
    vector<bool>isActive={true,true,true,true};
    // Output: ["ELECTRONICS_50"]
    vector<string>code2={"GROCERY15","ELECTRONICS_50","DISCOUNT10"},businessLine2={"grocery","electronics","invalid"};
    vector<bool>isActive2={false,true,true};
    return 0;
}