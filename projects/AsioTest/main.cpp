#include "Printer.h"
#include "PrinterStrand.h"
#include "TimerExamples.h"

int main()
{
  // TimerExamples::blocking_wait();
  // TimerExamples::timer_no_wait();
  // TimerExamples::timer_async_wait();
  // TimerExamples::timer_async_wait_no_work();
  // TimerExamples::timer_async_wait_run_first();
  // TimerExamples::printer_example();
  // TimerExamples::printer_example_two_printers();
  // TimerExamples::printer_example_two_threads();
  // TimerExamples::printer_example_strand();
  TimerExamples::printer_example_strand_multithread();

  return 0;
}
