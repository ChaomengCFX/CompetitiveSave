#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < _size; _i++) { std::cerr << _vec[_i]; if (_i != _size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> pieces(N);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> pieces[i];
        sum += pieces[i];
    }
    std::sort(pieces.begin(), pieces.end(), std::greater<int>());

    std::vector<bool> vis(N, false);
    auto dfs = [&](auto&& dfs, int cur, int target) -> bool {
        LOGV(vis, N)
        for (int i = 0; i < N; i++) {
            if (vis[i]) continue;
            if (cur + pieces[i] < target) {
                vis[i] = true;
                if (dfs(dfs, cur + pieces[i], target)) {
                    return true;
                }
                vis[i] = false;
            } else if (cur + pieces[i] == target) {
                vis[i] = true;
                return true;
            }
        }
        return false;
    };
    LOGV(pieces, N)
    int min = sum;
    for (int len = 1; len < sum; len++) {
        if (sum % len != 0) continue; // 剪枝掉非因数
        int L = sum / len;
        bool ok = true;
        vis.resize(N, false);
        while (L--) {
            if (!dfs(dfs, 0, len)) {
                ok = false;
                break;
            }
        }
        LOG(len << " = " << ok)
        if (ok) min = std::min(min, len);
    }

    std::cout << min << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
#if 0
, , , , , , , 28, 27, 27, 26, 26, 26, 25, 25, , , 21, 20, 19, 15, 13, 6, 3
48 22
47 23
43 27
38 32
36 34
#endif