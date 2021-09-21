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

ll solve()
{
    ll mat[3][3];

    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];
    cin >> mat[1][0] >> mat[1][2];
    cin >> mat[2][0] >> mat[2][1] >> mat[2][2];

    ll ans = 0;

    // Checking AP at borders
    if (2 * mat[0][1] == mat[0][0] + mat[0][2])
    {
        ans++;
    }

    if (2 * mat[2][1] == mat[2][0] + mat[2][2])
    {
        ans++;
    }

    if (2 * mat[1][0] == mat[0][0] + mat[2][0])
    {
        ans++;
    }

    if (2 * mat[1][2] == mat[0][2] + mat[2][2])
    {
        ans++;
    }

    // cout << ans << endl;
    // Checking AP with middle number;

    map<ll, ll> m;

    if ((mat[0][1] + mat[2][1]) % 2 == 0)
    {
        m[(mat[0][1] + mat[2][1]) / 2]++;
    }

    if ((mat[1][0] + mat[1][2]) % 2 == 0)
    {
        m[(mat[1][0] + mat[1][2]) / 2]++;
    }

    if ((mat[0][0] + mat[2][2]) % 2 == 0)
    {
        m[(mat[0][0] + mat[2][2]) / 2]++;
    }

    if ((mat[0][2] + mat[2][0]) % 2 == 0)
    {
        m[(mat[0][2] + mat[2][0]) / 2]++;
    }

    ll maxi = 0;

    for (auto c : m)
    {
        maxi = max(maxi, c.second);
    }

    ans += maxi;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }

    return 0;
}
