// LC - 2483 - Medium - Minimum Penalty for a Shop
// 4 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Brute Force - TLE
int bestClosingTimeBF(string customers){
    int n=customers.length();
    int minPenalty=INT_MAX;
    int minHour=INT_MAX;
    
    for(int i=0;i<n;i++){
        int j=i-1;
        int penalty=0;
        
        // Find penalty when shop was open & we had 'N'
        while(j>=0){
            if(customers[j]=='N'){
                penalty++;
            }
            j--;
        }
        
        j=i;

        // Find penalty when shop was closed & we had 'Y'
        while(j<n){
            if(customers[j]=='Y'){
                penalty++;
            }
            j++;
        }
        
        if(penalty<minPenalty){
            minPenalty=penalty; 
            minHour=i;
        }
    }
    
    // Trying closing at nth Hour
    int nthHourPenalty=count(begin(customers),end(customers),'N');
    if(nthHourPenalty<minPenalty){
        minPenalty=nthHourPenalty; 
        minHour=n;
    }
    
    return minHour;
}
// Approach 2 - ACCEPTED
int bestClosingTimeVec(string customers){
    int n=customers.length();
    
    vector<int>prefixN(n+1,0);
    prefixN[0]=0;
        
    vector<int>suffixY(n+1,0);
    suffixY[n]=0;
    
    for(int i=1;i<=n;i++){
        if(customers[i-1]=='N'){
            prefixN[i]=prefixN[i-1]+1;
        } else{
            prefixN[i]=prefixN[i-1];
        }
    }
    
    for(int i=n-1;i>=0;i--){
        if(customers[i]=='Y'){
            suffixY[i]=suffixY[i+1]+1;
        } else{
            suffixY[i]=suffixY[i+1];   
        }
    }
    
    int minPenalty=INT_MAX;
    int minHour=INT_MAX;
    
    for(int i=0;i<n+1;i++){
        int currPenalty=prefixN[i]+suffixY[i];
        
        if(currPenalty<minPenalty){
            minPenalty=currPenalty;
            minHour=i;
        }
    }
    
    return minHour;
}
// Approach 3 - Two Pass
int bestClosingTimeOP(string customers){
    int n=customers.length();
    
    int minHour=0;
    int penalty=count(begin(customers),end(customers),'Y');
    
    int minPenalty=penalty;

    for(int i=0;i<n;i++){
        if(customers[i]=='Y'){
            penalty--;
        } else{
            penalty++;
        }
        
        if(penalty<minPenalty){
            minHour=i+1;
            minPenalty=penalty;
        }
    }
    
    return minHour;
}
// Approach 4 - One Pass
int bestClosingTime(string customers){
    int bestTime=0;
    int minPenalty=0;
    int prefix=0;
    
    for (int i=0;i<customers.length();i++){
        prefix+=customers[i]=='Y'?-1:1;
        
        if(prefix<minPenalty){
            bestTime=i+1;
            minPenalty=prefix;
        }
    }
    
    return bestTime;
}
int main(){
    // Output: 2
    string customers="YYNY";
    // Output: 0
    string customers2="NNNNN";
    // Output: 4
    string customers3="YYYY";
    cout<<bestClosingTime(customers)<<endl;
    cout<<bestClosingTime(customers2)<<endl;
    cout<<bestClosingTime(customers3);
    return 0;
}