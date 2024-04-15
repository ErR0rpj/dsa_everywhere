// Learnings: Read the question throughly with all the inputs and outputs as my logic was perfect at first just the approach needed was wrong.
// If I might have read the question properly I could have thought of the approach. The question is of pattern called contstructive algorithm.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;

        for (int i = n; i >= 1; i--)
        {
            sum += i * ((i * 2) - 1);
        }

        cout << sum << " " << 2 * n << "\n";

        for (int i = 0; i < 2 * n; i++)
        {
            cout << (i % 2) + 1 << " " << (i / 2) + 1 << " ";
            for (int j = n; j >= 1; j--)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}