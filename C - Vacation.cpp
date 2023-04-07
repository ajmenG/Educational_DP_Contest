#include <bits/stdc++.h>
using namespace std;

int n, h[100005][3], dp[100005][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> h[i][1] >> h[i][2] >> h[i][3];
    }

    dp[1][1] = h[1][1];
    dp[1][2] = h[1][2];
    dp[1][3] = h[1][3];

    for (int i=1; i<=n; i++)
    {
        dp[i][1] = max(dp[i-1][2]+h[i][1], dp[i-1][3]+h[i][1]);
        dp[i][2] = max(dp[i-1][1]+h[i][2], dp[i-1][3]+h[i][2]);
        dp[i][3] = max(dp[i-1][1]+h[i][3], dp[i-1][2]+h[i][3]);
    }

    cout << max(dp[n][1], max(dp[n][2], dp[n][3]));

    return 0;
}
