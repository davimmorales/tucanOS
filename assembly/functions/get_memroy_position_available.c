function get_memory_position_available(){
  int i = 0;
  int position;
  while(list_programs_info[i]!=0){
    if(list_programs_info[i].place==0){
      if(list_programs_info[i].index_process==1){
        position = 2;
        break;
      }else{
        position = 1;
        break;
      }
    }
          i++;
    return position;
  }
