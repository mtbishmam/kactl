/**
* Author: 
* Date: 2025-08-28
* License: 
* Source: https://cp-algorithms.com/geometry/minkowski.html
* Description: Minkowski sum of two sets $A + B = \{a + b | a \in A, b \in B\}$. P and Q must be ccw oriented polygons. Cool application: Minimum distance between two polygons P and Q in $\mathcal{O}(|P| + |Q|)$. Negate Q and take the sum P + (-Q). Then find shortest distance from (0, 0) to the polygon. If origin is already inside answer is 0, otherwise it is distance between the origin and some edge/vertex. 
**/

typedef Point<ll> P;
void reorder_polygon(vector<P> &p){
  int pos = 0;
  for(int i = 1; i < sz(p); i++) {
    if(p[i].y < p[pos].y || (p[i].y == p[pos].y && p[i].x < p[pos].x))
      pos = i;
  }rotate(p.begin(), p.begin()+pos, p.end());
}
vector<P> minkowski(vector<P>p, vector<P>q){
  reorder_polygon(p); reorder_polygon(q);
  p.push_back(p[0]); p.push_back(p[1]);
  q.push_back(q[0]); q.push_back(q[1]);

  vector<P> result; int i = 0, j = 0;
  while(i < sz(p) - 2 || j < sz(q) - 2) {
    result.push_back(p[i] + q[j]);
    auto c = (p[i + 1] - p[i]).cross(q[j + 1] - q[j]);
    if(c >= 0 && i < sz(q) - 2) ++i;
    if(c <= 0 && j < sz(p) - 2) ++j;
  } return result;
}
