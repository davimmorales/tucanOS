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

function is_list_running_available{
  place = 0;
  memory_position = 0;
  i = 0;
  while (list_running_processes[i]!=0) {//not end of list
    if (list_running_processes[i].id!=1) {//not available space
      if (list_running_processes[i].place==place) {//if it is in memory
        memory_position++;
      }
    }
    i++;
  }
  if (memory_position>2) {
    place = 1;
  }
  return place;
}

function get_index_process_RAM{
  index_process = 1;//second data memory position
  other_process_id;
  i = 0;
  while (list_running_processes[i]!=0) {//not end of list
      if (list_running_processes[i].place==0) {//data memory
        if (list_running_processes[i].id!=id) {//not the program we are moving
          other_process_id = list_running_processes[i].id;
          break;
        }
      }
      i++;
  }
  i = 0
  while (list_programs_info[i].id!=other_process_id) {
    i++;
  }
  if (list_programs_info[i].index_process==1) {//second position is taken
    index_process = 2;//put into third position
  }
  return index_process;
}

function get_running_process{
  i = 0;
  running_process = 0;
  while(list_programs_info[i]!=0){
    if(list_programs_info[i].index_process==0){
      running_process = list_programs_info[i].id;
      break;
    }
    i++;
  }
  return running_process;
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

function insert_list_running(id, place){
	i = 0;//position to insert
	while(list_running[i].id!=0){
		if(list.running[i].id==1){
			break;
		}
		i++;
	}

	list_running[i].id = id;
	list_running[i].place = place;
}

function is_list_running_empty(){
	i = 0;
	while(list_running[i] !=0){
		i++;
	}
	return i;
}

function get_index_hd(id){
	i = 0;
	while(list_programs_info[i]!=0){
		if(list_programs_info[i].id == id){
			index_hd = list_programs_info.index_hd;
			break;
		}
		i++;
	}
	return index_hd;
}

function transfer_hd_to_iram(index_hd){
	i = 0;
	index = index_hd*64;
	while(list_programs[index+i] !=0){
		instructions_memory[i] = list_programs[index+i];
		i++;
	}
}


function int main() {
  place = is_list_running_available();
  if (place==0) {//there is still space in RAM
    update_index_process_RAM();
  }else{//there is only space in HD
    update_index_process_HD();
  }
}
