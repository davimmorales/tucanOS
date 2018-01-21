function get_memory_position_available(){
  i = 0;
  position_available = 3;
  array_memory_positions[3] = 0;
    while (list_programs_info[i].id!=0) {
      if (list_programs_info[i].id!=1) {
        if (list_programs_info[i].state==1) {
          array_memory_positions[list_programs_info[i].index_process] = 1;
        }
      }
      i++;
  }

  if (array_memory_positions[1]==0) {
    position_available = 1;
  }if(array_memory_positions[2]==0){
    position_available = 2;
  }

  return position_available;
}
