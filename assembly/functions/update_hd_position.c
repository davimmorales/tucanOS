function update_hd_position(id, new_index_process){
  i = 0;
  former_index_process = 0;
  new_index_process_aux;
  while (list_programs_info[i]!=0) {
    if(list_programs_info[i].id==id){
      former_index_process = list_programs_info[i].index_process;
      list_programs_info[i].index_process = new_index_process;
      break;
    }
    i++;
  }

  i=0;
  former_index_process = former_index_process*size_of_section; (20)
  new_index_process_aux = new_index_process*size_of_section;
  while (i<size_of_section) {
    running_processes_hd[new_index_process_aux+i] = running_processes[former_index_process+i];
    i++;
  }
}
