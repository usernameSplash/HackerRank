#include <algorithm>
#include <cstdio>
#include <cstdlib>

int DP[1001];

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        int coinValue[4] = { 1, 2, 5, 10 };
        int coins[4];
        scanf("%d", &n);
        scanf("%d %d %d %d", &coins[0], &coins[1], &coins[2], &coins[3]);

        for (int i = 0; i < 4; ++i) {
            if (coins[i] * coinValue[i] > n) {
                coins[i] = (n / coinValue[i]) + 1;
            }
        }
        for (int i = 0; i <= n; ++i) {
            DP[i] = 0;
        }

        for (int a = 0; a <= coins[0]; ++a) {
            for (int b = 0; b <= coins[1]; ++b) {
                for (int c = 0; c <= coins[2]; ++c) {
                    for (int d = 0; d <= coins[3]; ++d) {
                        int idx = a + b * 2 + c * 5 + d * 10;
                        if (idx > n) {
                            continue;
                        }
                        DP[idx]++;
                    }
                }
            }
        }

        printf("%d\n", DP[n]);
    }

    return 0;
}