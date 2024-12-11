/*
https://atcoder.jp/contests/arc189/tasks/arc189_a
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5 + 5;
int inv[N];

int calc(vector<int> a) {
    int n = a.size();
    int ans = 1;
    if (a[0] == 0) return 0;
    int z = 0;
    for (int l = 0; l < n; ) {
        int r = l;
        while (r < n && a[r] == a[l]) r++;
        int len = r - l;
        if (len % 2 == 0) return 0;
        for (int i = 1; i <= len - 2; i += 2) ans = 1LL * ans * i % MOD;
        for (int i = 1; i <= len / 2; i++) ans = 1LL * ans * inv[i] % MOD;
        z += len / 2;
        l = r;
    }
    for (int i = 1; i <= z; i++) ans = 1LL * ans * i % MOD;
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    cout << calc(a) << '\n';
}