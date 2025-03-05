#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    vector<int>v1{1,5,10,20,40,80};
    vector<int>v2{6,7,20,80,100};
    vector<int>v3{3,4,15,20,30,70,80,120};
    set<int>st;
    int s1=v1.size(),s2=v2.size(),s3=v3.size();
    int i=0,j=0,k=0;
    int rep=0;
    while(i<s1 && j<s2 && k<s3){
        if(v1[i]==v2[j] && v2[j]==v3[k]){
            st.insert(v1[i]);
            i++,j++,k++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
        else if(v2[j]<v3[k]){
            j++;
        }
        else k++;
    }
    for(auto i:st){
        cout<<i<<" ";
    }
    return 0;
}