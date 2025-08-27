/**
*  Author: tkacper
*  Date: 28-08-2025
*  License: 
*  Source: https://codeforces.com/blog/entry/143059
*  Description:
*/
template<int N> void solve(int n) {
  if (n > N) {
    solve<min(2*N, 1'000'000)>(n);
    return;
  }
  // Now solving with bitset<N>;
}
// call solve<1>(n)
