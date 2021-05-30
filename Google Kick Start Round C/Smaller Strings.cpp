#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef unordered_map<ll, ll> uml;
typedef vector<pl> vpl;
typedef map<ll, ll> ml;

ll n, k;
string s;

ll dp[100005][2][2];

ll solve(ll i, ll j, ll val1, ll val2)
{
    if (i > j)
    {

        if (val1 == 0)
        {
            return 1;
        }
        else if (val1 == 1 && val2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[i][val1][val2] != -1)
    {
        return dp[i][val1][val2];
    }

    ll ch1 = s[i] - 'a';
    ll ch2 = s[j] - 'a';

    ll it = 0;
    ll ans = 0;

    for (it = 0; it < k; it++)
    {
        if (val1 == 0)
        {
            ans += solve(i + 1, j - 1, 0, 0);
        }
        else
        {
            if (it < ch1)
            {
                ans += solve(i + 1, j - 1, 0, 0);
            }
            else if (it == ch1)
            {
                if (i != j)
                {
                    if (it > ch2)
                    {
                        ans += solve(i + 1, j - 1, 1, 1);
                    }
                    else if (it == ch2)
                    {
                        ans += solve(i + 1, j - 1, 1, val2);
                    }
                    else if (it < ch2)
                    {
                        ans += solve(i + 1, j - 1, 1, 0);
                    }
                }
                else
                {
                    ans += solve(i + 1, j, 1, val2);
                }
            }
        }

        ans %= MOD;
    }
    // cout << i << " " << val1 << " " << val2 << " " << ans << endl;
    dp[i][val1][val2] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;

    ll index = 1;

    while (T--)
    {
        cin >> n >> k >> s;

        ll i;

        memset(dp, -1, sizeof(dp));

        cout << "Case #" << index << ": ";

        cout << solve(0, n - 1, 1, 1) << endl;
        index++;
    }

    return 0;
}
