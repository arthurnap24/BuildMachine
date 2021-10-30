#include <chrono>
#include <iostream>
#include <thread>

#include "Printer.h"

TimerExamples::Printer::Printer(int wait_time_secs)
    : wait_time_secs_(wait_time_secs)
    , timer_(io_)
{}

void TimerExamples::Printer::start()
{
    wait();
    io_.run();
    print_count();
}

void TimerExamples::Printer::wait()
{
    timer_.expires_after(std::chrono::seconds(wait_time_secs_));
    timer_.async_wait(boost::bind(&Printer::print, this));
}

void TimerExamples::Printer::print()
{
    if (count_ < 5) {
        std::cout << "count = " << count_++ << '\n';
        wait();
    }
}

void TimerExamples::Printer::print_count()
{
    std::cout << "Final count is: " << count_ << '\n';
}

void TimerExamples::printer_example()
{
    Printer printer(1);
    printer.start();
}

void TimerExamples::printer_example_two_printers()
{
  Printer printer1(1);
  Printer printer2(1);
  printer1.start();
  printer2.start();
}

void TimerExamples::printer_example_two_threads()
{
  std::thread thread1([]() {
    Printer printer(1);
    printer.start();
  });

  std::thread thread2([]() {
    Printer printer(1);
    printer.start();
  });

  thread1.join();
  thread2.join();
}
