function get_index_process(id){
i = 0;
index_process;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i]!=1) {
      if (list_programs_info[i].id == id) {
        index_process = list_programs_info.index_process;
        break;
      }
    }
    i++;
  }
  return index_process;
}
