#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of Elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array ->";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans ^= arr[i];
    }
    cout<<"Unique element is: "<<ans;
    return 0;
}