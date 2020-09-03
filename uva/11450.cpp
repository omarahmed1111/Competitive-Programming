#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int c;
	cin>>c;
	while(c--){
		int m,g;
		cin>>m>>g;
		int price[25][25];
		for(int i=0;i<g;i++){
			cin>>price[i][0];
			for(int j=1; j<=price[i][0];j++){
				cin>>price[i][j];
			}
		}
		bool reachable[2][250];
		memset(reachable,0, sizeof reachable);
		int prev = 1,cur=0;
		for(int i=1;i<=price[0][0];i++){
			if(m-price[0][i]>=0){
				reachable[cur][m-price[0][i]]=true;
			}
		}
		
		for(int i=1;i<g;i++){
			swap(cur,prev);
			memset(reachable[cur],0,sizeof reachable[cur]);
			for(int mon=0;mon<205;mon++){
				if(reachable[prev][mon]){
					for(int j=1;j<=price[i][0];j++){
						if(mon-price[i][j]>=0){
							reachable[cur][mon-price[i][j]] = true;
						}
					}
				}
			}
		}
		int ans = -1;
		for(int i = 0;i<205;i++){
			if(reachable[cur][i]){
				ans = i;
				break;
			}
		}
		if(ans==-1){
			cout<<"no solution\n";
		}
		else{
			cout<<m-ans<<'\n';
		}


	}
    


}