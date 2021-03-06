#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define lp(i, n) for(int i=0;i<n;i++)
#define lpi(j,n) for(int i=j;i<n;i++)
#define all(v) (v.begin()), (v.end())
#define f first
#define s second


int main(){
    int n;
    cin>>n;
    
    int sum1=0,sum2=0;
    lp(i,n){
        lp(j,n){
            int temp;
            cin>>temp;
            if(i==j)sum1+=temp;
            if(i+j==n-1)sum2+=temp;
        }
    }
    cout<<abs(sum1-sum2);

}