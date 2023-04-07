#include <bits/stdc++.h>
using namespace std;

string s1, s2, ans;
int maxi, akt, dp[3005][3005];

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);

    cin >> s1 >> s2;
    s1 = "#" + s1;
    s2 = "#" + s2;


    //jezeli sa takie same w obydwu slowach to daje jeden
    for (int i=1; i<s1.size(); i++)
    {
        for (int j=1; j<s2.size(); j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]+1));
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=s1.size()-1, j=s2.size()-1;
    while(i>0 && j>0)
    {
        if (s1[i]==s2[j])
        {
            ans += s1[i];
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
