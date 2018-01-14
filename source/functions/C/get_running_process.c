function get_running_process(){
  int i = 0;
  int running_process;
  while(list_programs_info[i]!=0){
      if (list_programs_info[i].index_process==0) {
        if (list_programs_info[i].state==1) {
          running_process = list_programs_info[i].id;
        }
      }
    i++;
  }
  return running_process;
}
