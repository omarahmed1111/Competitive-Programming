#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
       
    
       int n,q;
       cin>>n>>q;
       vector<int> a(n);
       vector<int> ind(60,-1);
       for(int i=0;i<n;i++){
           cin>>a[i];
           if(ind[a[i]]==-1)ind[a[i]] = i;
       }
       for(int i=0;i<q;i++){
           int x;
           cin>>x;
           int tmpi = ind[x];
           cout<<ind[x]+1<<" ";
           for(int j=1;j<51;j++){
               if(ind[j]<tmpi)ind[j]++;
           }
           ind[x]=0;
       } 
    
}