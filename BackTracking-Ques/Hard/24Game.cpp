// LC - 679 - HARD - 24 Game
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    // To check if value is close to 24
    const double epsilon=0.1;
    bool solve(vector<double>&cards){
        if(cards.size()==1){
            return abs(24-cards[0])<=epsilon;
        }

        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j) continue;

                vector<double>temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(cards[k]);
                    }
                }

                double a=cards[i];
                double b=cards[j];
                vector<double>possibleVal={a+b,a-b,b-a,a*b};

                if(abs(b)>0.0) possibleVal.push_back(a/b);
                if(abs(a)>0.0) possibleVal.push_back(b/a);

                for(double &val:possibleVal){
                    // Do
                    temp.push_back(val);
                    // Explore
                    if(solve(temp)==true) return true;
                    // Undo
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    public:
    bool judgePoint24(vector<int>&cards){
        vector<double>nums;

        for(int &i:cards) nums.push_back(1.0*i);

        return solve(nums);
    }
};
int main(){
    // Output: true
    vector<int>cards={4,1,8,7};
    // Output: false
    vector<int>cards2={1,2,1,2};

    BackTracking sol;
    cout<<sol.judgePoint24(cards)<<endl;
    cout<<sol.judgePoint24(cards2);
    return 0;
}