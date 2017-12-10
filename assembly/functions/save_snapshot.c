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
}
