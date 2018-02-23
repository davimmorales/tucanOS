function check_if_exists_list_programs_info(id){
  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i]==id) {
      return 1;
    }
    i = i + 1
  }
  return 0;
}
