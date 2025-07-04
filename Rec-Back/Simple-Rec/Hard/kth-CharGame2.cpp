// LC - 3307 - HARD - Find the K-th Character in String Game II
#include<iostream>
#include<vector>
using namespace std;
class Recursion{
    public:
    char kthCharacter(long long k,vector<int>&operations){
        if(k==1) return 'a';

        int n=operations.size();
        long long len=1;
        long long newK=-1;
        int operationType=-1;

        for(int i=0;i<n;i++){
            len*=2;

            if(len>=k){
                newK=k-len/2;
                operationType=operations[i];
                break;
            }
        }

        char ch=kthCharacter(newK,operations);
        
        if(operationType==0) return ch;

        return ch=='z'?'a':ch+1;
    }
};
int main(){
    // Output: "a"
    int k=5;
    vector<int>operations={0,0,0};
    // Output: "b"
    int k2=10;
    vector<int>operations2={0,1,0,1};

    Recursion sol;
    cout<<sol.kthCharacter(k,operations)<<endl;
    cout<<sol.kthCharacter(k2,operations2);
    return 0;
}