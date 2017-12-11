bios(){
  output(bios); //test output
  input(test); //test input
//test RAM
  output(test);
//test HD
  output(sector 1, track 0);
//transfer operating system to instructions memory
  i = 0;
  j = 256;
  while(operating_system[i]!=0){
    instructionsRAM[j] = operating_system[i];
    i++;
    j++;
  }
//initialize registers and data memory
i = 0;
while(i<257){
  RAM[i] = 0;
  i++;
}
registers = 0;

}
