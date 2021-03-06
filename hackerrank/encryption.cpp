#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string t = "";
    for(int i=0;i<s.size();i++)if(s[i]!=' ')t+=s[i];
    int n = t.size();
    int r = sqrt(n);
    vector<vector<char>> m;
    if(r*r==n) m = vector<vector<char>>(r,vector<char>(r, ' '));
    else if(r*(r+1) >=n) m = vector<vector<char>>(r,vector<char>(r+1, ' '));
    else m = vector<vector<char>>(r+1,vector<char>(r+1, ' '));
    int ind = 0;
    int rows = m.size();
    int cols = m[0].size();
    for(int i=0;i<rows&&ind<n;i++){
        for(int j=0;j<cols&&ind<n;j++){
            m[i][j] = t[ind];
            ind++;
        }
    }
    string ans = "";
    for(int i=0;i<cols;i++){
        string tmp;
        for(int j=0;j<rows;j++){
            if(m[j][i]!=' ')tmp = tmp + m[j][i];
        }
        
        if(tmp.size()>0)ans = ans + tmp + " ";
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
