function edit_line(id){
  instruction;
  line = input();
  output(01068175);
  opcode = input();
  output(02058175);
  register_a = input();
  output(03058175);
  register_b = input();
  output(04058175);
  register_c = input();
  output(05098175);
  immediate = input();

  shiftl(ocpode, 15);
  shiftl(opcode, 11);
  shiftl(register_a, 15);
  shiftl(register_a, 6);
  shiftl(register_b, 15);
  shiftl(register_b, 1);
  shiftl(register_c, 11);

  instruction = opcode + register_a + register_b + register_c + immediate;

  while (list_programs_info[i].id!=id) {
    i = i+1;
  }

  list_programs[list_programs_info[i].index_hd].line = instruction;

}
