#include "../utilities/template.h"

#include "../../content/number-theory/mint.h"

int main() {
  mt19937_64 gen(123456789);
  rep(it,0,1000000) {
    mint a((ll) gen()), b((ll) gen());
    assert(0 <= a.x && a.x < MOD);
    assert(0 <= b.x && b.x < MOD);
    assert(((a + b) - b).x == a.x);
    if (b.x) assert(((a / b) * b).x == a.x);
  }
  mint a = 2;
  ll cur = 1;
  rep(i,0,100) {
    assert((a ^ i).x == cur);
    cur = cur * 2 % MOD;
  }
  cout << "Tests passed!" << endl;
}
