test print_memory_and_HD(){
  i = 0;
  while (i<end_of_memory) {
    if(memory[i]!=0){
      output(memory[i]);
      i++;
    }
  }

  i = 0;
  while(i<end_of_HD){
    if(list_programs_info!=0){
      output(list_programs_info[i]);
      i++;
    }
  }
}
