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
