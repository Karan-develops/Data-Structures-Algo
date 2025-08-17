// LC - 837 - Medium - New 21 Game
// 2 Approaches
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
// Approach 1 - Brute Force
double new21GameBruteForce(int n,int k,int maxPts){
    // P[i] = probability of getting score = i
    vector<double>P(n+1);
    
    // Since already initally she has score = 0, hence probability for scoring 0 is 1
    P[0]=1;
    
    for(int i=1;i<=n;i++){
        for(int card=1;card<=maxPts;card++){
            if(i-card>=0 && i-card<k){
                // Probability of score card = 1/maxPts
                // Remaining points = (i-card);
                // So,  P[i] = Probability of card * Probability of remaining
                // i.e. P[i] = 1/maxPts * P[i-card]
                // Or, P[i] = P[i-card]/maxPts;

                P[i]+=P[i-card]/maxPts;
            }
        }
    }
    return accumulate(begin(P)+k,end(P),0.0);
}
double new21Game(int n,int k,int maxPts){
    // P[i] = probability of getting score = i
    vector<double>P(n+1,0.0);
    
    // Since already initally she has score = 0, hence probability for scoring 0 is 1
    P[0]=1;
    
    double currProbabSum=k>0?1:0;
    
    for(int i=1;i<=n;i++){
        P[i]=currProbabSum/maxPts;
        
        if(i<k){
            currProbabSum+=P[i];
        }
        
        if(i-maxPts>=0 && i-maxPts<k){
            currProbabSum-=P[i-maxPts];
        }
        
    }
    return accumulate(begin(P)+k,end(P),0.0);
}
int main(){
    // Output: 1.00000
    int n=10,k=1,maxPts=10;
    // Output: 0.60000
    int n2=6,k2=1,maxPts2=10;
    // Output: 0.73278
    int n3=21,k3=17,maxPts3=10;
    cout<<new21Game(n,k,maxPts)<<endl;
    cout<<new21Game(n2,k2,maxPts2)<<endl;
    cout<<new21Game(n3,k3,maxPts3);
    return 0;
}