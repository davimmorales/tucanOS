function get_state(id){
  id = id;
  state = 0;
  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i].id==id) {
      state = list_programs_info[i].state;
    }
    i++;
  }
  return state;
}
