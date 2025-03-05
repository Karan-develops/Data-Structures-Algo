#include<iostream>
using namespace std;
int main(){
    int divident,divisor;
    cout<<"Enter divident:";
    cin>>divident;
    cout<<"Enter divisor:";
    cin>>divisor;
    int start=0;
    int end=abs(divident);
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(abs(mid*divisor)==abs(divident)){
            ans=mid;
            break;
        }
        else if(abs(mid*divisor)>abs(divident)){
            end=mid-1;
        }
        else{
            ans=mid;
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    if((divident<0 && divisor<0) || (divident>0 && divisor>0)){
        cout<<"The quotient is:"<<ans;
    }
    else{
        cout<<"The quotient is:"<<-ans;
    }
    return 0;
}