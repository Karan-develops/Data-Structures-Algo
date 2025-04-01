// LC - 605 - Easy - Can Place Flowers
#include<iostream>
#include<vector>
using namespace std;
bool canPlaceFlowers(vector<int>&flowerbed,int n){
    if(n==0) return true;
    int N=flowerbed.size();
    for(int i=0;i<N;i++){
        if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==N-1 || flowerbed[i+1]==0)){
            flowerbed[i]=1;
            n--;
            if(n==0) return true;
        }
    }
    return false;
}
int main(){
    // Output: true
    vector<int>flowerbed={1,0,0,0,1};
    int n=1;
    // Output: false
    vector<int>flowerbed2={1,0,0,0,1};
    int n2=2;
    cout<<canPlaceFlowers(flowerbed,n)<<endl;
    cout<<canPlaceFlowers(flowerbed2,n2);
    return 0;
}