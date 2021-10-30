#include <chrono>
#include <iostream>
#include <thread>

#include "Printer.h"

namespace Printers {

Printer::Printer(int wait_time_secs)
    : wait_time_secs_(wait_time_secs)
    , timer_(io_)
{}

void Printer::start()
{
    wait();
    io_.run();
    print_count();
}

void Printer::wait()
{
    timer_.expires_after(std::chrono::seconds(wait_time_secs_));
    timer_.async_wait(boost::bind(&Printer::print, this));
}

void Printer::print()
{
    if (count_ < 5) {
        std::cout << "count = " << count_++ << '\n';
        wait();
    }
}

void Printer::print_count()
{
    std::cout << "Final count is: " << count_ << '\n';
}

} // namespace Printers
