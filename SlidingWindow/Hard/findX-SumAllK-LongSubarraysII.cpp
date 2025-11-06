// LC - 3321 - HARD - Find X-Sum of All K-Long Subarrays II
// Part 1 → https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Simulation/findX-SumAllK-LongSubarraysI.cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
class SlidingWindow{
    int X;
    long long sum=0;
    typedef pair<int,int>P;
    set<P>main; // main set containing top x elements
    set<P>sec; // secondary set containing rest of the elements
    void insertInSet(const P &p){
        if(main.size()<X || p>*main.begin()){
            sum+=1LL*p.first*p.second;
            main.insert(p);

            if(main.size()>X){
                auto smallest=*main.begin();

                sum-=1LL*smallest.first*smallest.second;

                sec.insert(smallest);
                main.erase(smallest);
            }
        } else{
            sec.insert(p);
        }
    }
    void removeFromSet(const P &p){
        if(main.find(p)!=main.end()){
            sum-=1LL*p.first*p.second;
            main.erase(p);

            if(!sec.empty()){
                auto largest=*sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum+=1LL*largest.first*largest.second;
            }
        } else{
            sec.erase(p);
        }
    }
    public:
    vector<long long> findXSum(vector<int>&nums,int k,int x){
        int n=nums.size();
        sum=0;
        X=x;

        unordered_map<int,int>mp;

        int i=0,j=0;
        vector<long long>ans;

        while(j<n){
            if(mp[nums[j]]>0){
                removeFromSet({mp[nums[j]],nums[j]});
            }

            mp[nums[j]]++;
            insertInSet({mp[nums[j]],nums[j]});

            if(j-i+1==k){
                ans.push_back(sum);

                removeFromSet({mp[nums[i]],nums[i]});
                
                mp[nums[i]]--;
                
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                } else{
                    insertInSet({mp[nums[i]],nums[i]});
                }

                i++;
            }
            j++;
        }

        return ans;
    }
};
int main(){
    // Output: [6,10,12]
    vector<int>nums={1,1,2,2,3,4,2,3};
    int k=6,x=2;
    // Output: [11,15,15,15,12]
    vector<int>nums2={3,8,7,8,7,5};
    int k2=2,x2=2;
    return 0;
}