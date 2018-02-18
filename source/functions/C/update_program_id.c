update_program_id(previous_id, new_id){
int i;
i = 0;
while (list_programs_info[i].id!=0) {
  if (list_programs_info[i].id==previous_id) {
    list_programs_info[i].id = new_id;
    break;
  }
}
}
