#include<iostream>
#include<vector>
using namespace std;
bool isPossibleSolution(vector<int>ranks,int prata,int cooks,int mid){
    int prataCount=0;
    for(int i=0;i<ranks.size();i++){
       int rank=ranks[i];
       int j=1;
       int timeTaken=0;
       while(true){
        if(timeTaken+j*rank <= mid){
            prataCount++;
            timeTaken+=j*rank;
            j++;
        }
        else{
            break;
        }
       }
       if(prataCount>=prata){
        return true;
       }
    }
    return false;
}
int makePratas(vector<int>ranks,int prata,int cooks,int endCase){
    int start=0;
    int end=endCase;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSolution(ranks,prata,cooks,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int maxTime(int lastCookRank,int prata){
    int time=0;
    for(int i=1;i<=prata;i++){
        time+=lastCookRank*i;
    }
    return time;
}
int main(){
    vector<int>ranks{1,2,3,4};
    int prata;
    int cooks=ranks.size();
    cout<<"Enter number of pratas to make:";
    cin>>prata;
    int endCase=maxTime(ranks[ranks.size()-1],prata);
    int ans=makePratas(ranks,prata,cooks,endCase);
    cout<<"Minimum time to make pratas is: "<<ans<<" minutes";
    return 0;
}