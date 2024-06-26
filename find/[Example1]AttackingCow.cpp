/*进击的奶牛
    一个农场的牛棚分为N个隔间（线性排列），每个隔间的坐标为a[i]（均为正），其中有c头牛不老实，讨厌牛棚里有其他的牛，若把这c头牛牵出分别放进到n个隔间中，使得相邻两头牛的最近距离最大，问此时这个最近距离的最大值是多少。
    第一行输入n，c表示隔间数和牛头数
    第二行输入n个数，表示隔间坐标
    输出最近距离的最大值
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], n;
int f(ll mid)
{
    int res = 0;
    ll pre = -1e9;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] - pre >= mid)
            res++, pre = a[i];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 1, r = 1e9 + 9;
    while (l + 1 != r)
    {
        ll mid = (l + r) >> 1;
        if (f(mid) >= c)
            l = mid;
        else
            r = mid;
    }
    cout << r << '\n';
    return 0;
}
// 函数思想：不考虑放入的牛头，单从最近距离考虑，给出的隔间坐标中我们总能找到这个最大值，而影响这个最大值的优先选择，是在于要放入牛头，且如果最近距离确定，牛头的放入数也是确定的，因此找到了函数关系。
// 若以最近距离为自变量，牛头数为因变量，其呈下降型阶梯函数，即随着最近距离的变大，牛头放入的数量会减小，直至只能放下一头。
// 题中的c即为目标因变量，在函数中要找到这个c对应的自变量（最近距离），查找在这里用二分法实现，即构建一个范围[l,r]，取其中间值mid，判断在此最近距离下，放入的牛头数与目标数c的大小，进而缩进区间。
//二分细节，我们的目标是将最近距离的最大值输出，而他一定在区间的右端点，即让f(mid)=c的情况时，r=mid并输出。
// 因为最近距离固定，f函数中要有一个计数器res记录牛头放入数，pre表示上一个坐标位置，初始化为-∞