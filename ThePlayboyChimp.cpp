#include <bits/stdc++.h>
using namespace std;

vector<int> PlayboyChimp(vector<int> arr, int h)
{
    vector<int> ans;
    int l = 0, r = arr.size() - 1, left = 0, right = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == h)
        {
            left = arr[m - 1];
            if ((m + 1) == arr.size())
            {
                right = -1;
            }
            else
                right = arr[m + 1];
            break;
        }
        else if (arr[m] < h)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    ans.push_back(left);
    ans.push_back(right);
    return ans;
}

int main()
{
    int N, Q;
    scanf("%d", &N);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    while (Q--)
    {
        int height;
        scanf("%d", &height);
        vector<int> ans;
        ans = PlayboyChimp(arr, height);
        printf("%d ", ans[0]);
        if (ans[1] == -1)
            printf("X\n");
        else
            printf("%d\n", ans[1]);
    }
    return 0;
}
