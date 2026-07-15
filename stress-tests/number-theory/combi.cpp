#include "../utilities/template.h"

#include "../../content/number-theory/combi.h"

int main() {
  const int smallN = 300;
  combi small(smallN);
  vector<vector<ll>> choose(smallN, vector<ll>(smallN));
  choose[0][0] = 1;
  rep(n,1,smallN) {
    choose[n][0] = choose[n][n] = 1;
    rep(r,1,n) choose[n][r] = (choose[n - 1][r - 1] + choose[n - 1][r]) % MOD;
  }
  rep(n,0,smallN) {
    rep(r,0,n + 1) assert(small.ncr(n, r).x == choose[n][r]);
    assert(small.ncr(n, -1).x == 0);
    assert(small.ncr(n, n + 1).x == 0);
  }

  const int largeN = 200000;
  combi large(largeN);
  rep(i,1,largeN) {
    assert((large.inv[i] * i).x == 1);
    assert((large.fac[i] * large.ifac[i]).x == 1);
  }
  mt19937_64 gen(987654321);
  rep(it,0,1000000) {
    int n = static_cast<int>(gen() % (largeN - 2)) + 1;
    int r = static_cast<int>(gen() % n);
    assert(large.ncr(n, r).x == large.ncr(n, n - r).x);
    assert((large.ncr(n, r) + large.ncr(n, r + 1)).x == large.ncr(n + 1, r + 1).x);
  }
  cout << "Tests passed!" << endl;
}
