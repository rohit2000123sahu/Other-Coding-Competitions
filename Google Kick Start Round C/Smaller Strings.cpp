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

ll dp[100005][2][2];                        // Dp for memoization

// Here val1 and val2 are as follows
// val1 == 0 if the character at the place of first pointer will be smaller than the present one
// val1 == 1 if the character at the place of first pointer will be eqaul or greater than the present one

// val2 == 0 if the character at the place of second pointer will be smaller than the present one
// val2 == 1 if the character at the place of second pointer will be eqaul or greater than the present one

ll solve(ll i, ll j, ll val1, ll val2)      
{
    if (i > j)                              // Base cases
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

    if (dp[i][val1][val2] != -1)                // Just memoization
    {
        return dp[i][val1][val2];
    }

    ll ch1 = s[i] - 'a';
    ll ch2 = s[j] - 'a';

    ll it = 0;
    ll ans = 0;

    for (it = 0; it < k; it++)                 // We will iterate through all the characters
    {
        if (val1 == 0)                         // If the val1 is 0 it means we already have a smaller character infront so now we can have any character
        {
            ans += solve(i + 1, j - 1, 0, 0);
        }
        else
        {
            if (it < ch1)                       // Else if it is less than ch1 then val1 will become zero and val2 doesn't matter
            {
                ans += solve(i + 1, j - 1, 0, 0);
            }
            else if (it == ch1)                 // If it been equal to ch1 then 
            {
                if (i != j)                     // Now we will be checking ch2
                {
                    if (it > ch2)              // if it is greater than ch2 then val2 will become 1 and val1 is already 1
                    {
                        ans += solve(i + 1, j - 1, 1, 1);
                    }
                    else if (it == ch2)        // If it is equal then val2 will remain as it is
                    {
                        ans += solve(i + 1, j - 1, 1, val2);
                    }
                    else if (it < ch2)         // Else val2 will become zero
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
