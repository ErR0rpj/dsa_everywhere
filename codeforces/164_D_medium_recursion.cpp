#include <bits/stdc++.h>
using namespace std;

long long group(long long current, int pending, vector<int> balls, int pos, int n)
{
    long long ans = current;
    int now = balls[pos];
    if (pending > 0)
    {
        if (pending >= now)
        {
            pending -= now;
            now = 0;
        }
        else
        {
            now -= pending;
            pending = 0;
        }
    }

    if (pending == 0)
    {
        current += now % 998244353;
        pending += now;
    }
    ans = current;

    for (int i = pos + 1; i < n; i++)
    {
        ans += group(current, pending, balls, i, n) % 998244353;
    }

    return ans % 998244353;
}

int main()
{
    int n;
    cin >> n;

    vector<int> balls;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        balls.push_back(a);
    }

    sort(balls.begin(), balls.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += group(0, 0, balls, i, n) % 998244353;
        // cout << "Returing ans: " << ans << "\n";
    }

    ans = ans % 998244353;
    cout << ans << "\n";
}