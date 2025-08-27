/**
* Author: 
* Date: 2025-08-28
* License: CC0
* Source: Online
* Description: Convert dates to day number and reverse.
*/

int date_to_int(int y, int m, int d) {
  if (m <= 2) y--, m += 12;
  return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

void int_to_date(int z, int &y, int &m, int &d) {
  z += 306;
  int a = z + 68569;
  int b = 4*a/146097;
  a = a - (146097*b + 3)/4;
  int c = 4000*(a + 1)/1461001;
  a = a - 1461*c/4 + 31;
  int e = 80*a/2447;
  d = a - 2447*e/80;
  a = e/11;
  m = e + 2 - 12*a;
  y = 100*(b - 49) + c + a;
}
