#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

ll grid[1000][19000];
vector<pair<int,int>> mat[1000][19000];

vector<string> getChildren(string &s){
	vector<string> children;
	int sz = s.size();
	int i=1;
	string child;
	while(i<sz){
		if(s[i]!='+'){
			child+=s[i];
		}
		else{
			children.push_back(child);
			child = "";
		}
		i++;
	}
	children.push_back(child);
	return children;
}
vector<pair<int,int>> decodeChildren(vector<string> &children){
	int sz = children.size();
	vector<pair<int,int>> decoded;
	for(int i=0;i<sz;i++){
		string child = children[i];
		int ind = 0;
		for(int j=0;j<child.size();j++){
			if(isdigit(child[j])){
				ind = j;
				break;
			}
		}
		string part1 = child.substr(0,ind);
		string part2 = child.substr(ind);
		int col = 0;
		for(int j=0;j<part1.size();j++)col = col * 26 + (part1[j]-'A' + 1);
		int row = stoi(part2);
		decoded.push_back({row,col});
	}
	return decoded;
}

ll getValue(int row, int col){
	ll value = grid[row][col];
	while(!mat[row][col].empty()){
		pair<int,int> curChild = mat[row][col].back();
		mat[row][col].pop_back();
		value += getValue(curChild.first, curChild.second);
	}
	grid[row][col] = value;
	return value;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int c;
	cin>>c;
	while(c--){
		int x,y;
		cin>>x>>y;
		swap(x,y);
		for(int i=1;i<=x;i++)for(int j=1;j<=y;j++){
			string s;
			cin>>s;
			if(s[0]=='='){
				vector<string> children = getChildren(s);
				mat[i][j] = decodeChildren(children);
				grid[i][j]=0;
			}
			else {
				grid[i][j] = stoll(s);
			}
		}
		for(int i=1;i<=x;i++)for(int j=1;j<=y;j++){
			getValue(i, j);
		}
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				cout<<grid[i][j];
				if(j!=y)cout<<" ";
			}
			cout<<'\n';
		}
	}
    


}