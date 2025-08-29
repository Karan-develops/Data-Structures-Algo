// Matrix Exponentiation - Log(n)
#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<long long>>Matrix;
class MatrixExponentiation{
    const int MOD=1e9+7;
    public:
    Matrix matrixMultiplication(Matrix &a,Matrix &b){
        Matrix ans(2,vector<long long>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
                }
            }
        }
        return ans;
    }
    // Function to raise matrix base to the power exponent (Just like Binary exponentiation)
    Matrix matrixExponentiation(Matrix& base,int exponent){
        if(exponent==0){
            // Matrix identity{};
            Matrix identity(2,vector<long long>(2,0));
            for(int i=0;i<2;i++){
                identity[i][i]=1;
            }
            return identity;
        }
        
        Matrix half=matrixExponentiation(base,exponent/2);
        Matrix ans=matrixMultiplication(half,half);

        if(exponent%2==1){
            ans=matrixMultiplication(ans,base);
        }
        return ans;
    }
};
int main(){
    // Output: 55
    int n=10;
    MatrixExponentiation m;
    Matrix T={{1,1},{1,0}};
    // Base case matrix: F(1) = 1, F(0) = 0
    Matrix mat={{1},{0}};

    Matrix Tn=m.matrixExponentiation(T,n-1);
    Matrix ans=m.matrixMultiplication(Tn,mat);

    cout<<"Fibonacci(" << n << ") = "<<ans[0][0]<<endl;
    return 0;
}

// Question - GFG
class Solution{
    const int MOD=1e9+7;
    typedef vector<vector<long long int>>Matrix;
    public:
    Matrix matrixMultiplication(Matrix &A,Matrix &B){
        Matrix ans(2,vector<long long int>(2,0));
        
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ans[i][j]=(ans[i][j]+A[i][k]*B[k][j])%MOD;
                }
            }
        }
        return ans;
    }
    Matrix matrixExponentiation(Matrix &base,long long int exponent){
        if(exponent==0){
            Matrix identity(2,vector<long long int>(2,0));
            
            for(int i=0;i<2;i++){
                identity[i][i]=1;
            }
            return identity;
        }
        
        Matrix half=matrixExponentiation(base,exponent/2);
        Matrix ans=matrixMultiplication(half,half);
        
        if(exponent&1) ans=matrixMultiplication(ans,base);
        
        return ans;
    }
    int FindNthTerm(long long int n){
        if(n==0) return 0;
        
        Matrix T={{1,1},{1,0}};
        
        Matrix Tn=matrixExponentiation(T,n);
        
        return Tn[0][0];
    }
};