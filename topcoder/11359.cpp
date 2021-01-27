#include <bits/stdc++.h>
using namespace std;

class TheLotteryBothDivs{
public:

    bool issuff(string a, string b){
        int sz = a.size();
        for(int i=sz-1, j = b.size()-1;i>=0;i--, j--){
            if(a[i]!=b[j])return false;
        }
        return true;
    }
    static bool cmp(string a, string b){
        return a.size() < b.size();
    }
    double find(vector<string> goodSuffixes){
        sort(goodSuffixes.begin(), goodSuffixes.end(), cmp);
        vector<int> ans(10);
        vector<bool> add(goodSuffixes.size());
        for(int i=0;i<goodSuffixes.size();i++){
            string cur = goodSuffixes[i];
            if(!add[i]){
                for(int j=i+1;j<goodSuffixes.size();j++){
                    if(issuff(cur, goodSuffixes[j])){
                        add[j]=true;
                    }
                }
                ans[cur.size()]++;
            }
        }
        double a = 0;
        for(int i=1;i<10;i++){
            a+= (double)ans[i] / pow(10,i);
        }
        return a;
    }
};

