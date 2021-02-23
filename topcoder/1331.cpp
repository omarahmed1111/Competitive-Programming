#include <bits/stdc++.h>
using namespace std;

class MessageMess{
public:
    map<string,bool> h;
    string msg;
    int sz;
    map<pair<string,int>, bool> dp;
    int solve(int i, string cur){
        if(i==sz){
            return cur.size() == 0;
        }
        
        if(dp.find({cur,i}) != dp.end()){
            return dp[{cur, i}];
        }
        int ret = 0;
        if(h[cur+msg[i]]){
            ret += solve(i+1, "");
        }
        ret += solve(i+1, cur+msg[i]);
        dp[{cur,i}] = ret;
        return ret;
    }
    string build(int i, string cur){
        if(i==sz){
            return "";
        }
        int best = solve(i, cur);
        int b1 = -1;

        if(h[cur+msg[i]]){
            b1 = solve(i+1, "");
        }
        if(b1 == best){
            if(i+1 == msg.size()) return cur + msg[i] + build(i+1, "");
            else return cur + msg[i] + " " + build(i+1, "");
        }
        return build(i+1, cur+msg[i]);

    }
    
    
    string restore(vector<string> dictionary, string message){
        map<string,bool> mp;
        for(int i=0;i<dictionary.size();i++)mp[dictionary[i]] = true;
        h = mp;
        msg = message;
        sz = msg.size();
        int ans = solve(0, "");
        if(ans==0)return "IMPOSSIBLE!";
        else if(ans>1)return "AMBIGUOUS!";
        else return build(0, "");
    }
};

int main(){
    MessageMess m;
    vector<string> inputArr = {"AC", "AB", "ABC", "ABCD", "BCDE", "CDE"};
    string msg = "ABCDE";
    cout<<m.restore(inputArr, msg)<<'\n';
}