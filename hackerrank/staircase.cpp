#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)cout<<" ";
        for(int j=0;j<i+1;j++)cout<<"#";
        cout<<"\n";
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
