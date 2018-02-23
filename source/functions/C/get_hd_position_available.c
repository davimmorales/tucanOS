function get_hd_position_available(){
  i = 0;
  position_hd = 0;

  while (list_programs_info[i].id!=0) {
    if (list_programs_info[i].id==1) {
      break;
    }
    i = i + 1;
  }
  position_hd = i;
}
