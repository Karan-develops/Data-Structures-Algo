// LC - 476 - Easy - Number Complement
// 2 Approaches
#include<iostream>
#include<math.h>
using namespace std;
class BitMagic{
    public:
    int findComplement(int num){
        int number_of_bits=(int)(log2(num))+1;
        
        for(int i=0;i<number_of_bits;i++){
            num=num^(1<<i); //Take Xor to flip
        }
        return num;
    }
    int findComplement2(int num){
        int i=0,ans=0;

        while(num){
            // If the current bit is 0, set the corresponding bit in ans to 1
            if(!(num & 1)) ans|=(1<<i);

            num>>=1;
            i++;
        }
        return ans;
    }
};
int main(){
    // Output: 2
    int num=5;
    // Output: 0
    int num2=1;

    BitMagic sol;
    cout<<sol.findComplement2(num)<<endl;
    cout<<sol.findComplement2(num2);
    return 0;
}