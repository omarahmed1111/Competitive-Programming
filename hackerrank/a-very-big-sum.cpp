#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define lp(n) for(int i=0;i<n;i++)
#define lpi(j,n) for(int i=j;i<n;i++)
#define all(v) (v.begin()), (v.end())
#define f first
#define s second


int main(){
    int n;
    cin>>n;
    ll sum=0;
    lp(n){
        ll temp;
        cin>>temp;
        sum +=temp;
    }
    cout<<sum;

}