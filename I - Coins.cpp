#include <bits/stdc++.h>
using namespace std;
int n;
double a[3000], dp[3000][3000], suma;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
 
    for (int i=0; i < n; i++)
    {
        cin >> a[i];
    }
 
    dp[0][1] = a[0];
    dp[0][0] = 1.0 - a[0];
 
    for (int i=1; i < n; i++)
    {
        for (int j=0; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j] * (1.0 - a[i]);
            if (j)
                dp[i][j] += (dp[i - 1][j - 1] * a[i]);
        }
    }
 
    for (int i=n/2+1; i<=n; i++)
    {
        suma += dp[n-1][i];
    }
 
    cout << setprecision(10) << suma << endl;
 
    return 0;
}
