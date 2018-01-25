function context_exchange_selection(output_watchdog){
  selector = output_watchdog;
  if (selector>0) {
    if (selector<4) {
      call context_exchange(selector);
    }else if (selector<5) {
      call treat_waiting();
    }else if (selector<6) {
      call treat_halt();
    }
  }
}
