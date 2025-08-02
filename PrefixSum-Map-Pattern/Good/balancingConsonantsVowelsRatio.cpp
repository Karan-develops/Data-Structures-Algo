// GFG - Balancing Consonants and Vowels Ratio
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countBalanced(vector<string>&arr){
    unordered_map<int,int>diffCount;
    diffCount[0]=1;
    
    int vowelCount=0,consonantCount=0;
    int ans=0;

    auto isVowel=[](const char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    };

    for(const string &s:arr){
        for(const char &ch:s){
            if(isVowel(ch)) vowelCount++;
            else consonantCount++;
        }
        
        int diff=vowelCount-consonantCount;

        if(diffCount.count(diff)){
            ans+=diffCount[diff];
        }
        
        diffCount[diff]++;
    }
    return ans;
}
int main(){
    // Output: 4
    vector<string>arr={"aeio","aa","bc","ot","cdbd"};
    // Output: 3
    vector<string>arr2={"ab","be"};
    // Output: 0
    vector<string>arr3={"tz","gfg","ae"};
    cout<<countBalanced(arr)<<endl;
    cout<<countBalanced(arr2)<<endl;
    cout<<countBalanced(arr3);
    return 0;
}