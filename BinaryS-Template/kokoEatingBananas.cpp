// LC - 875 - Medium - Koko Eating Bananas
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    bool canEatAll(vector<int>&piles,int h,int givenHours){
        int actualHours=0;

        for(int &x:piles){
            actualHours+=(x/givenHours);

            if(x%givenHours!=0) actualHours++;
        }
        return actualHours<=h;
    }
    public:
    int minEatingSpeed(vector<int>&piles,int h){
        int l=1,r=*max_element(begin(piles),end(piles));

        while(l<r){
            int mid=l+(r-l)/2;

            if(canEatAll(piles,h,mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        return l;
    }
};
int main(){
    // Output: 4
    vector<int>piles={3,6,7,11};
    int h=8;
    // Output: 30
    vector<int>piles2={30,11,23,4,20};
    int h2=5;
    // Output: 23
    vector<int>piles3={30,11,23,4,20};
    int h3=6;

    BinarySearch sol;
    cout<<sol.minEatingSpeed(piles,h)<<endl;
    cout<<sol.minEatingSpeed(piles2,h2)<<endl;
    cout<<sol.minEatingSpeed(piles3,h3);
    return 0;
}