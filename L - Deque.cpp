#include <bits/stdc++.h>
using namespace std;

int n;
int64_t dp[3005][3005], tab[3005];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> tab[i];
    }

    for (int L=1; L<=n; L++)
    {
        for (int i=1; i<=n; i++)
        {
            int j= i+L-1;
            if (j<=n)
            {
                if (i==j)
                {
                    dp[i][j]= tab[i];
                }
                else
                {
                    dp[i][j] = max(tab[i]-dp[i+1][j], tab[j] - dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
