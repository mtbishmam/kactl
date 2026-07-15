/**
 * Author: MTB Ishmam
 * Date: 2026-07-15
 * Description: Modular integer operators. Set {\tt MOD} before using the
 * structure.
 */
#pragma once
const ll MOD = 998244353;
struct mint {
  ll x;
  mint(ll _ = 0) : x((_ % MOD + MOD) % MOD) {}
  mint operator+(const mint&b)const{return x+b.x;}
  mint operator-(const mint&b)const{return x-b.x;}
  mint operator*(const mint&b)const{return x*b.x;}
  mint operator/(const mint&b)const{return*this*inv(b);}
  mint operator^(ll b) const { // a^b^c=(a^b)^c
    assert(b >= 0); // not (a^b)^c -> actual ord
    mint a = *this, ret = 1;
    while (b) {
      if (b & 1) ret = ret * a;
      a = a * a; b >>= 1;
    }
    return ret;
  }
  static ll euclid(ll a, ll b, ll& x, ll& y) {
    if (!b) return x = 1, y = 0, a;
    ll g = euclid(b, a % b, y, x);
    return y -= a / b * x, g;
  }
  static mint inv(const mint&a) {
    ll x, y, g = euclid(a.x, MOD, x, y);
    assert(g == 1);
    return x;
  }
};
