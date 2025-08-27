/**
 * Author: Ruhan Habib
 * Date: 2025-08-28
 * License: CC0
 * Source: 
 * Description: Gives normalized line equation $ax + by = c$, passing throuhg points p and q.
 */
tuple<ll,ll,ll> get_line_eq (Point p, Point q) {
  Point normal = (q - p).perp();
  if (normal.x < 0) {
    normal.x *= -1;
    normal.y *= -1;
  } else if (normal.x == 0 && normal.y < 0) {
    normal.y *= -1;
  } // ax + by = c
  ll c = normal.dot(p);
  ll g = gcd(c, gcd(normal.x, normal.y));
  return {normal.x / g, normal.y / g, c / g};
}
