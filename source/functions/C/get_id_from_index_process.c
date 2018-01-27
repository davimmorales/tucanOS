function get_id_from_index_process(index_process){
  i = 0;
  id = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i]!=1) {
      if (list_programs_info[i].state>0) {
        if (list_programs_info[i].state<3) {
          if (list_programs_info[i].index_process==index_process) {
            id = list_programs_info[i].id;
          }
        }
      }
    }
    i++;
  }
  return id;
}
