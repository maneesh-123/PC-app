#ifdef Local
#include "C:\Users\manee\OneDrive\Desktop\codeforces\debug1.h"
#else 
#define dbg(...)
#endif

#include<bits/stdc++.h>
using namespace std;



#define lli long long int
#define float long double

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//Function to ask a query
lli query(lli x, lli y){
    cout<<"? "<<x<<" "<<y<<endl;
    cout.flush();
    lli res;
    cin>>res;

    return res;


}


int main() {
    lli t;
    cin >> t;
 
    while (t--) {
 
        lli n,m;
        cin>>n>>m;

        lli res1,res2,res3,res4,ansx,ansy;
        lli x1=1,y1=1,x2,y2,x3,y3,x4,y4;
       
        bool got=false;
        
        
        res1=query(x1,y1);

        if(res1==0){
            ansx=1;
            ansy=1;
            got=true;
        }

        // x2,y2 and x3,y3 are the coordinates of corners of the diagonal containing one of the mine
        if(res1<=n-1){
            x2=x1+res1;
            y2=y1;

        }else{
            x2=n;
            y2=y1+1+res1-x2;

        }

        if(res1<=m-1){
            x3=x1;
            y3=y1+res1;

        }else{
           y3=m;
           x3=x1+1+res1-y3;

        }
        
        res2=query(x2,y2);
        
        res3=query(x3,y3);

        x2-=(res2/2);
        y2+=(res2/2);
        x3+=(res3/2);
        y3-=(res3/2);

        res4=query(x2,y2);

        // dbg(res1);
        // dbg(res2);
        // dbg(res3);
        // dbg(res4);

        if(res4==0)
        cout<<"! "<<x2<<" "<<y2<<endl;
        else
        cout<<"! "<<x3<<" "<<y3<<endl; 
        
        
}
 
}
 
