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

ll dp[2000005];

// It is just based on the sum of first n natural numbers.
// We have calculated and stored it in the dp

ll solve()
{
    ll g;
    cin >> g;

    ll i = 0;
    ll ans = 0;
    while (g >= dp[i] && i <= 2000000)
    {
        ll temp = g - dp[i];
        if (temp % (i + 1) == 0 && temp / (i + 1) != 0)
        {
            ans++;
        }
        i++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;

    ll i;

    dp[0] = 0;

    for (i = 1; i <= 2000000; i++)
    {
        dp[i] = i + dp[i - 1];
    }

    ll index = 1;

    while (T--)
    {
        cout << "Case #" << index << ": ";

        cout << solve() << endl;
        index++;
    }

    return 0;
}
