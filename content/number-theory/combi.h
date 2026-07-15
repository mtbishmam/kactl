/**
 * Author: MTB Ishmam
 * Date: 2026-07-15
 * Description: Precomputes factorials and inverse factorials for binomial
 * coefficients modulo a prime. Assumes $0 < N \le MOD$.
 * Time: $O(N)$ construction and $O(1)$ per query.
 */
#pragma once
#include "mint.h"

struct combi {
  int N; vector<mint> fac, ifac, inv;
  combi(int _N) : N(_N), fac(_N), ifac(_N), inv(_N) {
    assert(0 < N && N <= MOD);
    fac[0] = ifac[0] = 1;
    if (N > 1) inv[1] = 1;
    rep(i,2,N) inv[i] = inv[MOD % i] * (-MOD / i);
    rep(i,1,N) {
      fac[i] = fac[i - 1] * i;
      ifac[i] = ifac[i - 1] * inv[i];
    }
  }
  inline mint ncr(int n, int r) const {
    assert(0 <= n && n < N);
    return n < r || r < 0 ? 0 : fac[n] * ifac[r] * ifac[n - r];
  }
};
