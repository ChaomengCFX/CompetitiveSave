#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::string S;
    std::cin >> S;
    std::string ans;
    for (int i = S.size() - 1; i >= 0; i--) {
        char c = S[i];
        if (c == 'w') ans += 'w';
        else if (c == 'p') ans += 'q';
        else if (c == 'q') ans += 'p';
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}