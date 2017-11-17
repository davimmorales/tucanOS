variables:
  place;
  memory_position;
  i;
  index_process;
  id;

structures:
  running_process{
    id;
    place;
  }

  program_info{

  }
---------------------------------------------------------------------

lists:
  list_running_processes{
    running_process;
    size = 16;
  }

  list_hd_state{
    binary;
    size = 16;
  }

  list_programs{
    program_info;
    size = 16;
  }

---------------------------------------------------------------------

function verify_RAM_for_running_process{
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

  while (list_programs[i]!=0) {//not end of list
    if (list_programs[i].place==1) {//it's in HD
      list_hd_state[list_programs[i].index_process] = 1;
    }
    i++;
  }

  i = 0;
  while (list_hd_state!=0) {//not vacant
    i++;
  }
  index_process = i;

}
