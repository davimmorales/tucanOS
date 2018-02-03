function show_waiting_processes(){
  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i].state>=2) {
      output(list_programs_info[i].id);
    }
    i++;
  }
}
