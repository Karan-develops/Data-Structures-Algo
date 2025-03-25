// LC - 948 - Medium - Bag of Tokens
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bagOfTokensScore(vector<int>&tokens,int power){
    int n=tokens.size();
    sort(begin(tokens),end(tokens));

    int l=0,r=n-1;
    int score=0,currScore=0;

    while(l<=r){
        // power gwake score increase krlo
        if(power>=tokens[l]){
            currScore++;
            score=max(score,currScore);
            power-=tokens[l];
            l++;
        }
        // score gwake power increase krlo
        else if(currScore>=1){
            currScore--;
            power+=tokens[r];
            r--;
        }
        // When nothing is possible then return 
        else{
            return score;
        }
    }
    return score;
}
int main(){
    // Output: 0
    vector<int>tokens={100};
    int power=50;
    // Output: 1
    vector<int>tokens2={200,100};
    int power2=150;
    // Output: 2
    vector<int>tokens3={100,200,300,400};
    int power3=200;
    cout<<bagOfTokensScore(tokens,power)<<endl;
    cout<<bagOfTokensScore(tokens2,power2)<<endl;
    cout<<bagOfTokensScore(tokens3,power3);
    return 0;
}