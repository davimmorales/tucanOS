function create_program(id, position_available){
  list_programs_info[position_available*32+start] = id;
  list_programs_info[position_available*32+start].index_hd = position_available;
}
