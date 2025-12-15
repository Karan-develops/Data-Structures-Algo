// LC - 2147 - HARD - Number of Ways to Divide a Long Corridor
// Topics -> Math, String, Dynamic Programming
#include<iostream>
#include<vector>
using namespace std;
class String{
    const int M=1e9+7;
    public:
    int numberOfWays(string corridor){
        vector<int>pos_seats;
        
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                pos_seats.push_back(i);
            }
        }
        
        if(pos_seats.size()%2 || pos_seats.size()==0){
            return 0;
        }
        
        long long ans=1;
        // End index of the starting subarray having 2 seats
        int prev=pos_seats[1];
        
        for(int i=2;i<pos_seats.size();i+=2){
            int length=pos_seats[i]-prev;
            ans=(ans*length)%M;
            
            prev=pos_seats[i+1];
        }
        
        return ans;
    }
};
int main(){
    // Output: 3
    string corridor="SSPPSPS";
    // Output: 1
    string corridor2="PPSPSP";
    // Output: 0
    string corridor3="S";

    String sol;
    cout<<sol.numberOfWays(corridor)<<endl;
    cout<<sol.numberOfWays(corridor2)<<endl;
    cout<<sol.numberOfWays(corridor3);
    return 0;
}