#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

string mor[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(vector<string>& words) {
    map<string,int> mp;
    for(int i=0;i<words.size();i++){
        string mors = "";
        for(int j=0;j<words[i].size();j++){
            mors+= mor[words[i][j]-'a'];
        }
        mp[mors]++;
    }        
    return mp.size();
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int n;
    cin>>n;

    vector<string> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<uniqueMorseRepresentations(arr)<<'\n'; 



}