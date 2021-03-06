#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define lp(n) for(int i=0;i<n;i++)
#define lpi(j,n) for(int i=j;i<n;i++)
#define all(v) (v.begin()), (v.end())
#define f first
#define s second


int main(){
    int f=0,s=0;
    vector<int> a(3), b(3);
    lp(3)cin>>a[i];
    lp(3)cin>>b[i];
    lp(3){
        f += (a[i]>b[i]);
        s += (a[i]<b[i]);
    } 
    cout<<f<<" "<<s;

}