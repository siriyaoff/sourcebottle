#include <iostream>
#include <tuple>
#include <vector>
#define v vector
#define MOD 1000000007

using namespace std;
using vi = vector<int>;
using ll = long long;

tuple<ll, ll> modinv(ll a, ll b, ll s1, ll s2, ll t1, ll t2) {
    if (b == 0) return {s1, t1};
    ll q = a / b, t;
    t = s2;
    s2 = s1 - q * s2;
    s1 = t;
    t = t2;
    t2 = t1 - q * t2;
    t1 = t;
    return modinv(b, a % b, s1, s2, t1, t2);
}

ll getinv(ll a, ll b) {
    ll f = 0;
    if (a < b) {
        ll t = a;
        a = b;
        b = t;
        f = 1;
    }
    if (f)
        f = get<1>(modinv(a, b, 1, 0, 0, 1));
    else
        f = get<0>(modinv(a, b, 1, 0, 0, 1));
    if (f < 0) f += MOD;
    return f;
}

ll pow(ll x, ll p) {
    ll r = 1;
    while (p) {
        if (p & 0x01) r = r * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, ans;
    cin >> n >> k;
    v<ll> facto(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        facto[i] = (facto[i - 1] * i) % MOD;
    }
    ans = facto[n] * pow(facto[k], MOD - 2) % MOD;
    ans = ans * pow(facto[n - k], MOD - 2) % MOD;
    cout << ans;
    return 0;
}

// #include <cstdio>
// #define MOD 1000000007

// int fastExp(int n, int r)
// {
// 	int ret = 1;
// 	while (r)
// 	{
// 		if (r & 1) ret = 1l * ret * n % MOD;
// 		n = 1l * n * n % MOD;
// 		r >>= 1;
// 	}

// 	return ret;
// }
// int main()
// {
// 	int n, k;
// 	scanf("%d %d", &n, &k);

// 	if (k > n / 2) k = n - k;

// 	int a = 1, b = 1;
// 	for (int i = 0; i < k; ++i)
// 	{
// 		a = 1l * a * (n - i) % MOD;
// 		b = 1l * b * (k - i) % MOD;
// 	}

// 	b = fastExp(b, MOD - 2);
// 	printf("%d", 1l * a * b % MOD);

// 	return 0;
// }