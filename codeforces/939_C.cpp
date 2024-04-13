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


        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        vector<int> oper;
        vector<int> where;
        vector<vector<int>> perm;

        for (int i = 0; i < n; i++)
        {
            vector<int> now(n, 0);
            for (int j = 1; j <= n; j++)
            {
                now[j - 1] = j;
            }
            matrix.push_back(now);
            oper.push_back(1);
            where.push_back(i + 1);
            perm.push_back(now);
        }


    }
}