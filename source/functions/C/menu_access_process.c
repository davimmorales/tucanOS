else{//menu_access_process
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
  else if(access_process_menu_option==1){
  }
