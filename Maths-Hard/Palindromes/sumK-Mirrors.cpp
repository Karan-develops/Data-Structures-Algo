// LC - 2081 - HARD - Sum of k-Mirror Numbers
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
class Maths{
    bool isPalindrome(string &baseK){
        int i=0,j=baseK.length()-1;

        while(i<j){
            if(baseK[i++]!=baseK[j--]) return false;
        }
        return true;
    }
    string convertToBaseK(long long pal_num,int k){
        if(pal_num==0) return "0";

        string ans="";
        while(pal_num){
            ans+=to_string(pal_num%k);
            pal_num/=k;
        }
        return ans;
    }
    public:
    long long kMirror(int k,int n){
        long long sum=0;
        // Create L length Palindromes
        int L=1;

        while(n>0){
            int half_length=(L+1)/2;

            long long min_num=pow(10,half_length-1);
            long long max_num=pow(10,half_length)-1;

            for(int num=min_num;num<=max_num;num++){
                // Generating Palindrome numbers
                string first_half=to_string(num);
                string second_half=first_half;
                reverse(begin(second_half),end(second_half));

                string pal="";
                if(L&1){
                    pal=first_half+second_half.substr(1);
                } else{
                    pal=first_half+second_half;
                }

                long long pal_num=stoll(pal);
                string baseK=convertToBaseK(pal_num,k);

                if(isPalindrome(baseK)){
                    sum+=pal_num; // Found K-mirror number
                    n--;

                    if(n==0) break;
                }
            }
            L++;
        }
        return sum;
    }
};
int main(){
    // Output: 25
    int k=2,n=5;
    // Output: 499
    int k2=3,n2=7;
    // Output: 20379000
    int k3=7,n3=17;

    Maths sol;
    cout<<sol.kMirror(k,n)<<endl;
    cout<<sol.kMirror(k2,n2)<<endl;
    cout<<sol.kMirror(k3,n3);
    return 0;
}