// LC - 3494 - Medium - Find the Minimum Amount of Time to Brew Potions
#include<iostream>
#include<vector>
using namespace std;
long long minTime(vector<int>&skill,vector<int>&mana){
    int n=skill.size();
    int m=mana.size();

    // finishTime[i] = when wizard i finishes current potion
    vector<long long>finishTime(n,0);

    for(int j=0;j<m;j++){
        finishTime[0]+=1LL*mana[j]*skill[0];

        for(int i=1;i<n;i++){
            finishTime[i]=max(finishTime[i],finishTime[i-1])+1LL*mana[j]*skill[i];
        }

        for(int i=n-1;i>0;i--){
            finishTime[i-1]=finishTime[i]-1LL*mana[j]*skill[i];
        }
    }

    return finishTime[n-1];
}
int main(){
    // Output: 110
    vector<int>skill={1,5,2,4},mana={5,1,4,2};
    // Output: 5
    vector<int>skill2={1,1,1},mana2={1,1,1};
    // Output: 21
    vector<int>skill3={1,2,3,4},mana3={1,2};
    cout<<minTime(skill,mana)<<endl;
    cout<<minTime(skill2,mana2)<<endl;
    cout<<minTime(skill3,mana3);
    return 0;
}