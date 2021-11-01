#include <chrono>
#include <iostream>
#include <thread>

#include "Printer.h"

namespace Printers {

Printer::Printer(int wait_time_secs)
    : wait_time_secs_(wait_time_secs)
    , timer_(io_)
{}

Printer::~Printer()
{
    std::cout << "Final count is: " << count_ << '\n';
}

void Printer::start()
{
    wait();
    io_.run();
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

} // namespace Printers
