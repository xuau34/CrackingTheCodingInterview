/*
Time : O(width/8)
Space: O(1)
 */

void drawLine( byte screen[], int width, int x1, int x2, int y){
  if(width % 8) throw "Invalid width";
  int cols = width >> 3;
  int base = cols * y;
  int l = x1 / 8, r = x2 / 8;
  int mask = (1 << (8 - (x1 % 8))) - 1;
  screen[l] |= mask;
  mask = (1 << (8 - (x2 % 8))) - 1;
  screen[r] |= ~(mask);
  for(int i = l + 1; i < r; ++i){
    screen[i + base] = (1<<8) - 1;
  }
}
