#include<bits/stdc++.h>
using namespace std;
#define lli long long int
using matrix = vector<vector<lli>>;


matrix matmul(matrix a, matrix b){


    matrix ans;
    ans.resize(2, vector<lli>(2));


    for(lli i=0;i<2;i++){
        for(lli j=0;j<2;j++){


            ans[i][j]=0;
            
for(lli k=0;k<2;k++){
           ans[i][j]+=(a[i][k]*b[k][j]);
            }    
        }
    }
    return ans;
}


matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
	// Binary exponentiation
    while (n>0) {
        if(n&1)
            ans = matmul(ans,base);
        base = matmul(base,base);
        n >>= 1;
    }
    return ans;
}


int main() {
   
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    lli n;
    cin>>n;


    cout<<matpow(base, n)[0][1]<<endl;
}
