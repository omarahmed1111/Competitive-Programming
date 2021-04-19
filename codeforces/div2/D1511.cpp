#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int n,k;
	cin>>n>>k;
	vector<char> c(k);
	for(int i=0;i<k;i++)c[i] = (char)'a'+i;
	string s(n, 'a');
	if(k==1){
		cout<<s<<'\n';
		return 0;
	}
	int sz = k*(k-1) + k;
	vector<char> temp2(sz);
	int i=0;
	map<char,bool> mp;
	while(i<sz){
		for(int j=0;j<k;j++){
			for(int z=j+1;z<k;z++){
				temp2[i] = c[j];
				i++;
				if(!mp[c[j]]){
					temp2[i] = c[j];
					i++;
					mp[c[j]] = true;
				}
				temp2[i] = c[z];
				i++;
				if(!mp[c[z]]){
					temp2[i] = c[z];
					i++;
					mp[c[z]] = true;
				}
			}
		}
	}

	int ind = 0;
	int ind2 = 0;
	while(ind<n){
		s[ind] = temp2[ind2];
		ind++;
		ind2++;
		ind2 = ind2%sz;
	}
	cout<<s<<'\n';
}