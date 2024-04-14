// Learning: First I thought that greedy approach will be the solution. Like, alloting the colors with the higher count first and then alloting
// the ones with lower into them and along with with recursively counting for all the sets. But it is wrong. The correct logic is to
// see that there are only space for two balls in a group so there will be min: sum of balls divided by 2 groups. Also, we see that
// if the highest count of a ball is greater than the divided by 2 value of total then it will be considered as the group count. After
// that we store the count of sum apperaring in a DP and solve for each set after sorting the balls

#include <bits/stdc++.h>
using namespace std;

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

    sort(balls.begin(), balls.end());

    long long ans = 0;
    int mp[5004] = {0};
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int current = balls[i];

        for (int j = 5000; j >= 0; j--)
        {
            int sum = j;
            int count = mp[j];
            if (count == 0)
                continue;
            int total = sum + current;
            if (total % 2 == 1)
            {
                total = (total + 1) / 2;
            }
            else
            {
                total = total / 2;
            }

            if (total >= current)
            {
                ans += ((long long)count * (long long)total) % 998244353;
            }
            else
            {
                ans += ((long long)count * (long long)current) % 998244353;
            }
            // cout << ans << "\n";
            mp[sum + current] = (count + mp[sum + current]) % 998244353;
        }
    }

    ans = ans % 998244353;
    cout << ans << "\n";
}