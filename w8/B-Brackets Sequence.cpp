#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<vector<int> > dp, trace;

void print(string& s, int beg, int tail) {
    if (beg > tail)
        return;
    
    if (beg == tail) {
        if (s[beg] == '(' || s[beg] == ')')
            cout << "()";
        else
            cout << "[]";
        return ;
    }

    if (trace[beg][tail] == -1) {
        cout << s[beg];
        print(s, beg+1, tail-1);
        cout << ((s[beg] == '(')?')':']');
    } else {
        print(s, beg, trace[beg][tail]);
        print(s, trace[beg][tail]+1, tail);
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    dp = trace = vector<vector<int> >(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

/*([(]  ()[()]*/
    for (int L = 2; L <= n; ++L) {
        for (int beg = 0, tail=beg+L-1; tail < n; ++beg, ++tail) {
            dp[beg][tail] = INF;
            if ((s[beg]=='(' && s[tail]==')') || (s[beg]=='[' && s[tail]==']'))
                dp[beg][tail] = min(dp[beg][tail], dp[beg+1][tail-1]);

            trace[beg][tail] = -1;

            for (int k = beg; k < tail; ++k) {
                if (dp[beg][k]+dp[k+1][tail] < dp[beg][tail]) {
                    dp[beg][tail] = dp[beg][k]+dp[k+1][tail];
                    trace[beg][tail] = k;
                }
            }
            //printf("beg=%d, tail=%d, dp=%d\n", beg, tail, dp[beg][tail]);
        }
    }
    //cout << dp[0][n-1] << endl;

    print(s, 0, n-1);
    cout << endl;

    return 0;
}