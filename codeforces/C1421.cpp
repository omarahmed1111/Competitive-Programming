#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    string s;
    cin>>s;
    cout<<4<<'\n';
    int size = s.size();
    cout<<"L "<<size-1<<'\n';
    size = size + (size -2);
    cout<<"R "<<size-1<<'\n';
    size++;
    cout<<"L "<<size-1<<'\n';
    size = size + (size-2);
    cout<<"L "<<2<<'\n';

}