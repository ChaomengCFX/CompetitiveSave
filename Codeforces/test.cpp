#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M, lim;
    std::cin >> N >> M >> lim;
    N--;
    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    int can = std::upper_bound(B.begin(), B.end(), lim) - B.begin();
    std::vector<int> cnts(M);
    for (int i = 0; i < M; i++) {
        cnts[i] = N - (std::lower_bound(A.begin(), A.end(), B[i]) - A.begin());
    }
    for (int K = 1; K <= M; K++) {
        int cs = M / K;
        int ans = 0;
        ans += can / K;
        
        int low = M - K;
        low += can % K;
        
        for (; low >= can; low -= K) {
            ans += cnts[low] + 1;
        }
        std::cout << ans << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}