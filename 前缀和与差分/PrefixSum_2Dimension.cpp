//二维数组通过前缀和区间求和
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 9;
ll a[N][N], prefix[N][N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            prefix[i][j] = a[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            cout << '\n';
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
// 二维前缀和prefix[N][M]:从a[1][1]到a[n][m]矩阵方块内的数字和
// 矩阵数形结合,prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j]