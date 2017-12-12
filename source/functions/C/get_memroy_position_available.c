function get_memory_position_available(){
  i = 0;
  int list_running_map[9];
  while(i<10){
    list_running_map[i] = 0;
    i++;
  }

  int i = 0;
  int position;
  while(list_programs_info[i]!=0){
    if (list_programs_info[i].id != 1) {
      if (list_programs_info[i].state==1) {
        list_running_map[list_programs_info[i].index_process] = 1;
      }
    }
    i++;
  }

  i = 0;
  while(i<10){
    if(list_running_hd_map[i]==0){
      position_available = i;
      break;
    }
  }
}
