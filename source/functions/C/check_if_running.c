funtion check_if_running(id){
  i = 0;
  is_running = 0;
  while (list_running[i]!=0) {
    if(list_running[i].id == id){
      is_running = 1;
      break;
    }
  }
  return is_running;
}
