#include <algorithm>
#include <cstdio>
#include <cstdlib>

int B[100001];
int DP[100001][2];

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int iCnt = 0; iCnt < n; ++iCnt) {
            scanf("%d", &B[iCnt]);
        }

        DP[0][0] = 0;
        DP[0][1] = 0;

        for (int iCnt = 1; iCnt < n; ++iCnt) {
            DP[iCnt][0] = std::max(DP[iCnt - 1][0], DP[iCnt - 1][1] + abs(B[iCnt - 1] - 1));
            DP[iCnt][1] = std::max(DP[iCnt - 1][0] + abs(1 - B[iCnt]), DP[iCnt - 1][1] + abs(B[iCnt - 1] - B[iCnt]));
        }

        printf("%d\n", std::max(DP[n - 1][0], DP[n - 1][1]));
    }
}