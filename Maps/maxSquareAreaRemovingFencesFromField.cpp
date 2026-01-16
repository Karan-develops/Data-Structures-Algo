// LC - 2975 - Medium - Maximum Square Area by Removing Fences From a Field
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class HashSet{
    int M=1e9+7;
    public:
    int maximizeSquareArea(int m,int n,vector<int>&hFences,vector<int>&vFences){
        sort(begin(hFences),end(hFences));
        sort(begin(vFences),end(vFences));

        unordered_set<int>horDiff;
        unordered_set<int>verDiff;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                int diff=abs(hFences[i]-hFences[j]);
                horDiff.insert(diff);
            }
        }

        int side=0;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int diff=abs(vFences[i]-vFences[j]);

                if(horDiff.find(diff)!=horDiff.end()){
                    side=max(side,diff);
                }
            }
        }

        return side==0?-1:(1LL*side*side)%M;
    }
};
int main(){
    // Output: 4
    int m=4,n=3;
    vector<int>hFences={2,3},vFences={2};
    // Output: -1
    int m2=6,n2=7;
    vector<int>hFences2={2},vFences2={4};

    HashSet sol;
    cout<<sol.maximizeSquareArea(m,n,hFences,vFences)<<endl;
    cout<<sol.maximizeSquareArea(m2,n2,hFences2,vFences2);
    return 0;
}