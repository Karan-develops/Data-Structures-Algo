// LC - 1925 - Easy - Count Square Sum Triples
#include<iostream>
using namespace std;
int countTriples(int n){
    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if((i*i+j*j)==k*k) ans++;
            }
        }
    }

    return ans;
}
int main(){
    // Output: 2
    int n=5;
    // Output: 4
    int n2=10;
    cout<<countTriples(n)<<endl;
    cout<<countTriples(n2);
    return 0;
}