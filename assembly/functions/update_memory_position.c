function update_memory_position(id, former_index_process, new_index_process){
  i = 0;
  while (list_programs_info[i]!=0) {
    if(list_programs_info[i].id==id){
      list_programs_info[i].index_process = new_position;
      break;
    }
    i++;
  }

  i=0;
  former_position = former_position*size_of_section;
  new_position = new_position*size_of_section;
  while (i<size_of_section) {
    running_processes[new_position+i] = running_processes[former_position+i];
    i++;
  }
}
