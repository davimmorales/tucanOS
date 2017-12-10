function get_hd_position_available(){
  i = 0;
  int list_running_hd_map[15];
  while(i<16){
    list_running_hd_map[i] = 0;
    i++;
  }

  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i].id!=1) {
      if (list_programs_info[i].state==1) {
        if (list_programs_info[i].place==1) {
          list_running_hd_map[list_programs_info[i].index_process] = 1;
    }
  }
}
i++;
}

i = 0;
while(i<16){
  if(list_running_hd_map[i]==0){
    hd_position_available = i;
    break;
  }
}

return hd_position_available;
}
