/**
 * Author: Lukas Polacek, Simon Lindholm
 * Date: 2019-12-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure. Toggle the commented alternatives
 * to enable rollback.
 * Usage: dsu ds(n);
 * Time: $O(\alpha(N))$, or $O(\log(N))$ with rollback.
 * Status: Both variants stress-tested.
 */
#pragma once

struct dsu {
// struct rollback_dsu {
	vi e;
	dsu(int n) : e(n, -1) {}
	// vector<pii> st;
	// rollback_dsu(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	// int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	// int time() { return sz(st); }
	// void rollback(int t) {
	// 	for (int i = time(); i --> t;)
	// 		e[st[i].first] = st[i].second;
	// 	st.resize(t);
	// }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		// st.push_back({a, e[a]});
		// st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
