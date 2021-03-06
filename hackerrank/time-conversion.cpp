#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    char ap = s[8];
    if(ap=='A'){
        string h = s.substr(0,2);
        if(h=="12"){
            s = "00" + s.substr(2);
        }
    }
    else{
        string h = s.substr(0,2);
        if(h<"12"){
            int tmp = stoi(h);
            tmp = tmp + 12;
            s = to_string(tmp) + s.substr(2);
        }
    }
    s.pop_back();
    s.pop_back();
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
