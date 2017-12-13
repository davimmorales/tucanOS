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
}
