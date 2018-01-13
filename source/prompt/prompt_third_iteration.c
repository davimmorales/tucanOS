---
menu 0: input: (menu_0_option)
  compare: (menu_0_option) == 0
    ---
    ---
    ---
    ---
    branch: where_am_i_0 [line 28]
  compare: (menu_0_option) == 1
      ---
      ---
      ---
      ---
      branch: list_running_processes [line 31]
    compare: (menu_0_option) == 2
      ---
      ---
      ---
      ---
      branch: command_prompt [line 44]
    compare: (menu_0_option) == 3
      ---
      ---
      ---
      ---
      branch: kill_process [line 37?]
     jump: select_running_process [line 40?]
function: where_am_i_0
  ---
  jump: menu_0 [line 1]
function: list_running_processess
  compare: (running_processes[i]==0)
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    true: jump menu_0 [line 1]
    false: output running_processess[i]
      i = i + 1;
      jump: compare: (running_processes[i]==0) [line 33]
function: command_prompt
  --menu 1: input: (menu_1_option)
    --compare: (menu_1_option) == 0
      ---
      ---
      ---
      branch: where_am_i_1 [line 64]
    compare: (menu_1_option) == 1
      ---
      ---
      ---
      ---
      branch: list_files [line 68]
    compare: (menu_1_option) == 2
      ---
      ---
      ---
      ---
      branch: previous_menu_1 [line 67]
      jump: compare: (menu_1_option) == 3 [line 88]
function: where_am_i_1
  ---
  jump: menu_1 [line 44]
function: previous_menu_1 jump: menu_0 [line 1]
function: list_files
  compare: (files[i])==0
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  true: jump menu_1 [line 44]
  false: compare: (files[i]) == 1
    ---
    ---
    ---
    ---
    ---
    false: output files[i]
    true:
      i = i+1
      jump list_files [line 70]
      compare: (menu_1_option) == 3
        ---
        ---
        ---
        ---
        true: branch: create_file [line 0?]
false: function: select_file
---  routine: verify_if_running
    compare: (menu_1_option) == 0
      ---
      ---
      ---
      ---
      true: branch [line 111]
      false: compare: (menu_1_option) == running_processes[i]
        ---
        ---
        ---
        ---
        false: i = i+1; jump: verify_if_running [line 96]
        true: jump menu_1 [line 44]
        ---
        ---
    routine: verify_if_exists
    compare: hd[1][i] == 0
      ---
      ---
      ---
      ---
      ---
      true: jump menu_1 [line 44]
      ---
      false: compare: hd[1][i] == menu_1_option
        ---
        ---
        ---
        true: branch [line 127]
        false: i = i + 1; jump: verify_if_exists [line 111]
          ---
  variable: file_selected memory[0?]
  input: (select_file_menu_option)
    compare: (select_file_menu_option) == 0
      ---
      ---
      ---
      ---
      ---
      true: function: where_am_i_file
        variable (file_selected memory)
        ---
        jump: select_file_menu_option [line 128]
      false: compare: (select_file_menu_option) == 2
        ---
        ---
        ---
        ---
        ---
        ---
        true: jump: menu_1 [line 44]
        false: jump verify_if_1
load return [line 582]
---
  function is_list_running_available;
  place = 0; memory_position = 0;
  i = 0;
    while (list_running_processes[i]!=0) {//not end of list
      ---
      ---
      ---
      ---
      ---
      ---
      ---
      if (list_running_processes[i]!=1) {//not empty space
        ---
        ---
        ---
        ---
        ---
        ---
        if (list_running_processes[i].place==place) {//if it is in memory
          ---
          ---
          ---
          ---
          ---
          ---
          ---
          ---
            memory_position++;
            ---
            }
          }
          i++;
          (back to first while)}
    if (memory_position>2) {
      ---
      ---
      ---
      ---
      place = 1;
        ---
        }
      return place;
      ---
      jump:  run_process [line 195]
      ends: 240
---
---
load return [line 241]
update_program_info.id = selected_file
---
update_program_info.index_process = 0
update_program_info.place = 0
update_program_info.state = 1
---
update_program_info.program_counter = 0
call update_program_info;
function update_program_info
  i = 0;
  ---
  	while(list_programs_info[i]!=0){
      ---
      ---
      ---
      ---
      ---
      ---
      ---
      		if(list_programs_info[i].id == id){
            ---
            ---
            ---
            ---
            ---
            ---
            list_programs_info[i].index_process = index_process;
            list_programs_info[i].place = place;
            list_programs_info[i].state = state;
            list_programs_info[i].program_counter = program_counter;
            break;
            ---
            ---
            ---
            ---
            ---
            ---
            ---
            }
          i++;
          }
          ---
          return from update_program_info
load return [line 271]
insert_list_running.id = selected_file
---
insert_list_running.place = 0//memory
call insert_list_running
function: insert_list_running
  i = 0
  while(list_running[i].id!=0){
    ---
    ---
    ---
    ---
    ---
		if(list.running[i].id==1){
      ---
      ---
      ---
      break
    }
    i++;
    ---
    ---
    ---
  list_running[i].id = id;
  ---
  ---
  list_running[i].place = place;
  ---
  ---
  return from insert_list_running
get_index_hd.id = selected_file
---
load return [line 300]
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
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
}
transfer_hd_to_iram.index_hd = get_index_hd.index_hd
---
call transfer_hd_to_iram
function transfer_hd_to_iram(index_hd){
	i = 0;
	index = index_hd*64;
	while(list_programs[index+i] !=0){
		instructions_memory[i] = list_programs[index+i];
		i++;
	}
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  return from transfer_hd_to_iram
}
PC = 0
load return [line 343]
call is_list_running_empty
function is_list_running_empty(){
	i = 0;
	while(list_running[i] !=0){
		if(list_running[i]!=1) i=1;
	}
	return i;
  ---
  ---
  ---
  ---
  ---
  ---
  return from is_list_running_empty
}
if(is_list_running_empty==0)
  jump [line 196]
else
  jump [line 377]
  ---
  ---
  ---
  ---
compare: (select_file_menu_option) == 1
  true: call is_list_running_empty [line 327]
  false:
  ---
  ---
  ---
  ---
  ---
  compare: (select_file_menu_option) == 3
    true: call rename_file [line ?]
    false:
    ---
    ---
    ---
    compare: (select_file_menu_option) == 4
      true: call delete_file [line ?]
      false:
      ---
      ---
      ---
      compare: (select_file_menu_option) == 5
        true: call edit_file [line ?]
        false:
        ---
        ---
        ---
  load return [line 379]
  call is_list_running_available
  compare: (is_list_running_available) == 0
  false: update_index_process_HD
  true:
  ---
  ---
  ---
  ---
  ---
  load return [line 423]
  function get_running_process{
    i = 0;
    running_process = 0;
    while(list_programs_info[i]!=0){
      if(list_programs_info[i]!=1); info.state == 1
      if(list_programs_info[i].index_process==0){
        running_process = list_programs_info[i].id;
        break;
      }
      i++;
    }
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    return running_process;
  }
  load return [line 478]
  call get_memory_position_available
  function get_memory_position_available(){
    int i = 0;
    int position;
    while(list_programs_info[i]!=0){
      if (list_programs_info[i].id != 1) {
        if (list_programs_info[i].state==1) {
          if (list_programs_info[i].place==0) {
            if(list_programs_info[i].index_process==1){
              position = 2;
              break;
            }if(list_programs_info[i].index_process==2){
              position = 1;
              break;
            }
          }
        }
      }
      i++;
    }
    return position;
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
  }
  update_memory_position.id = get_running_process.running_process
  ---
  update_memory_position.new_index_process = get_memory_position_available.position_available
  ---
  load return [line 529]
  call update_memory_position
  function update_memory_position(id, new_index_process){
  i = 0;
  former_index_process = 0;
  new_index_process_aux;
  while (list_programs_info[i]!=0) {
    if(list_programs_info[i].id==id){
      former_index_process = list_programs_info[i].index_process;
      list_programs_info[i].index_process = new_index_process;
      break;
    }
    i++;
  }

  i=0;
  former_index_process = former_index_process*size_of_section;
  new_index_process_aux = new_index_process*size_of_section;
  while (i<size_of_section) {
    running_processes[new_index_process_aux+i] = running_processes[former_index_process+i];
    i++;
  }
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  }
  save_snapshot.id = get_running_process.id;
  --
  load return [line 198]
  call save_snapshot
  function save_snapshot(running_process){
  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i].id==running_process) {
      break;
    }
    i++;
  }
  i = i+12;
  HD[i] = R[0];
  i++;
  HD[i] = R[1];
  ... HD[i] = R[19]
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  }
if(menu_0_option<10){
  call something
}else{
---
---
selected_process = menu_0_option;
check_if_running.id = menu_0_option;//257
load return [line 635]
call check_if_running
funtion check_if_running(id){
  i = 0;
  is_running = 0;
  while (list_running[i]!=0) {
    if(list_running[i].id == id){
      is_running = 1;
      break;
    }
  }
  return is_running;
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
}
if(check_if_running.is_running==0){
  call menu_0;
}else{//menu_access_process
  input(access_process_menu_option);
  if (access_process_menu_option==0) {
    output(selected_process);
    call menu_access_process; [line 641]
  }else if (access_process_menu_option==2) {
    call menu_0; [line 257]
  }else if(access_process_menu_option==3){
    call kill_process;
  }
  else if(3<access_process_menu_option){
    call menu_access_process; [line 641]
  }
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  else if(access_process_menu_option==1){
    get_index_process.id = selected_process;
    ---
    load return [line 718];
    call get_index_process;
function get_index_process{
  i = 0;
  index_process;
    while (list_programs_info[i]!=0) {
      if (list_programs_info[i]!=1) {
        if (list_programs_info[i].id == id) {
          index_process = list_programs_info.index_process;
          break;
        }
      }
      i++;
    }
    return index_process;
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
    ---
}
    update_memory_position.id = selected_process;
    ---
    update_memory_position.new_index_process = 4;
    ---
    load return [line 724]
    call update_memory_position;
    load return [line 726]
    call get_running_process;
    update_memory_position.id = get_running_process.id;
    ---
    update_memory_position.new_index_process = get_index_process.index_process;
    ---
    load return [line 732]
    call update_memory_position;
    update_memory_position.id = selected_process;
    ---
    update_memory_position.new_index_process = 0;
    load return [line 737]
    call update_memory_position;
    save_snapshot.id = get_running_process.id;
    ---
    load return [line 741]
    call save_snapshot;
    resume_snapshot.id = selected_process.id;
    ---
    load return [line 812]
    call resume_snapshot;
function resume_snapshot(id){
  i = 0;
  while (list_programs_info[i]!=0) {
    if (list_programs_info[i].id==id) {
      break;
    }
    i++;
  }
  i = i+12;
  R[0] = HD[i];
  i++;
  R[1] = HD[i];
  ...   R[19] = HD[i];
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
  ---
    }
    PC <= R[28]
  }
}

  function: update_program_info
  function: kill_process
  ---
  jump: menu_0 [line 1]
  function: select_process
  ---
  jump: menu_0 [line 1]
