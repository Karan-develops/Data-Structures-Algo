// LC - 3577 - Medium - Count the Number of Computer Unlocking Permutations
#include<iostream>
#include<vector>
using namespace std;
class Maths{
    const int M=1e9+7;
    public:
    int countPermutations(vector<int>&complexity){
        int n=complexity.size();

        long long ans=1;

        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
            
            ans=(ans*i)%M;
        }
        
        return ans;
    }
};
int main(){
    // Output: 2
    vector<int>complexity={1,2,3};
    // Output: 0
    vector<int>complexity2={3,3,3,4,4,4};

    Maths sol;
    cout<<sol.countPermutations(complexity)<<endl;
    cout<<sol.countPermutations(complexity2);
    return 0;
}