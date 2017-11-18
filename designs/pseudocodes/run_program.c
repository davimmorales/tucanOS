variables:
  place;
  memory_position;
  i;
  index_process;
  id;

structures:
  type_running_process{
    id;
    place;
  }

  type_program_info{

  }
---------------------------------------------------------------------

lists:
  list_running_processes{
    type_running_process;
    size = 16;
  }

  list_hd_state{
    binary;
    size = 16;
  }

  list_programs_info{
    type_program_info;
    size = 16;
  }

---------------------------------------------------------------------

function is_list_running_empty{
  place = 0;
  memory_position = 0;
  i = 0;
  while (list_running_processes[i]!=0) {//not end of list
    while (list_running_processes[i]!=1) {//not empty space
      if (list_running_processes[i].place==place) {//if it is in memory
        memory_position++;
      }
      i++;
    }
  }
  if (memory_position>2) {
    place = 1;
  }
  return place;
}

function update_index_process_RAM{
  index_process = 1;//second data memory position
  i = 0;
  while (list_running_processes[i]!=0) {//not end of list
      if (list_running_processes[i].place==0) {//data memory
        if (list_running_processes[i].id!=id) {//not the program we are moving
          if (list_running_processes[i].index_process==1) {//second position is taken
            index_process = 2;//put into third position
          }
        }
      }
      i++;
  }
}

function update_index_process_HD{
  i = 0;
  index_process = 0;

  while (list_programs_info[i]!=0) {//not end of list
    if (list_programs_info[i].place==1) {//it's in HD
      list_hd_state[list_programs_info[i].index_process] = 1;
    }
    i++;
  }

  i = 0;
  while (list_hd_state!=0) {//not vacant
    i++;
  }
  index_process = i;
}

function update_program_info(id, index_process, place, state, program_counter){
	i = 0;
	while(list_programs_info[i]!=0){
		if(list_programs_info[i].id == id){
			list_programs_info[i].index_process = index_process;
      list_programs_info[i].place = place;
      list_programs_info[i].state = state;
      list_programs_info[i].program_counter = program_counter;
    }
    i++;
  }
}



function int main() {
  place = is_list_running_empty();
  if (place==0) {//there is still space in RAM
    update_index_process_RAM();
  }else{//there is only space in HD
    update_index_process_HD();
  }
}
