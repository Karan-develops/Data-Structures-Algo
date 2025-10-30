// LC - 2125 - Medium - Number of Laser Beams in a Bank
#include<iostream>
#include<vector>
using namespace std;
int numberOfBeams(vector<string>&bank){
    int m=bank.size();
    int n=bank[0].size();
    
    int ans=0;
    int prev=0;

    for(int i=0;i<m;i++){
        int curr=0;
        
        for(char &ch:bank[i]){
            if(ch=='1') curr++;
        }

        if(i==0){
            prev=curr;
            continue;
        }

        ans+=(curr*prev);

        if(curr) prev=curr;
    }

    return ans;
}
int main(){
    // Output: 8
    vector<string>bank={"011001","000000","010100","001000"};
    // Output: 0
    vector<string>bank2={"000","111","000"};
    cout<<numberOfBeams(bank)<<endl;
    cout<<numberOfBeams(bank2);
    return 0;
}