/// https://atcoder.jp/contests/dp/tasks/dp_k

#include <bits/stdc++.h>
using namespace std;

long double dp[100005];
int n, k, tab[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> tab[i];
    }

    for (int j=1; j<=k; j++)
    {
        for (int i=1; i<=n; i++)
        {
            if (j >= tab[i] && dp[j-tab[i]]==false)
            {
                dp[j]=true;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second");

    return 0;
}

