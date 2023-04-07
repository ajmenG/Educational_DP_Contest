#include <bits/stdc++.h>
using namespace std;

int n, k, h[100005], dp[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> h[i];
        dp[i]=-1;
    }

    dp[1]=0;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=k; j++)
        {
            if (dp[i+j]!=-1)
                dp[i+j] = min(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
            else
                dp[i+j] = dp[i]+abs(h[i+j]-h[i]);
        }
    }

    cout << dp[n];

    return 0;
}
