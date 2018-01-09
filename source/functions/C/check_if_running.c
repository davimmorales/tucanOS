function check_if_running(id){
  i = 0;
  is_running = 0;
  while (list_programs_info[i]!=0) {
    if(list_programs_info[i].id==id){
      if (list_programs_info[i].status==1) {
        is_running = 1;
        break;
      }
    }
    i++;
  }
  return is_running;
}
