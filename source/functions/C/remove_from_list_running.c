function remove_from_list_running(id){
  i = 0;
  while (list_running!=0) {
    if (list_running[i].id==id) {
      list_running[i] = 1;
    }
    i++;
  }
}
