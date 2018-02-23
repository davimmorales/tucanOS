function delete_file(id){
  i = 0;
  while (list_programs_info[i]!=id) {
    i = i + 1;
  }
  list_programs_info[i] = 1;
}
