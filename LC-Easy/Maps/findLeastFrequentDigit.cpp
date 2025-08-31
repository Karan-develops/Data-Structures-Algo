// LC - 3663 - Easy - Find The Least Frequent Digit
#include<iostream>
#include<vector>
using namespace std;
int getLeastFrequentDigit(int n){
    string str=to_string(n);
    vector<int>vec(10,0);
    
    for(char &ch:str) vec[ch-'0']++;

    int ans=-1,minFreq=INT_MAX;
    
    for(int i=0;i<=9;i++){
        if(vec[i]>0){
            if(vec[i]<minFreq || (vec[i]==minFreq && i<ans)){
                minFreq=vec[i];
                ans=i;
            }
        }
    }
    return ans;
}
int main(){
    // Output: 1
    int n=1553322;
    // Output: 2
    int n2=723344511;
    cout<<getLeastFrequentDigit(n)<<endl;
    cout<<getLeastFrequentDigit(n2);
    return 0;
}