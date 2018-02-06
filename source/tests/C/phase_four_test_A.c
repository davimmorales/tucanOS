function phase_four_test_A(){
  int top;
  int count;
  int bottom;
  top = 500000;
  bottom = 50;
  count = 0;
  while (count<top) {
    if (count==top/2) {
      output(count);
    }
    count ++;
  }

  while (bottom<count) {
    if (count==bottom*2) {
      output(count);
    }
    count --;
  }

}
