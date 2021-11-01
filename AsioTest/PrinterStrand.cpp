#include <chrono>
#include <iostream>
#include <thread>

#include "PrinterStrand.h"

namespace Printers {

PrinterStrand::PrinterStrand(int wait_time_secs)
    : wait_time_secs_(wait_time_secs)
    , strand_(boost::asio::make_strand(io_))
    , timer1_(io_)
    , timer2_(io_)
{}

PrinterStrand::~PrinterStrand()
{
    std::cout << "Final count is: " << count_ << '\n';
}

void PrinterStrand::start()
{
    wait_timer1();
    wait_timer2();
    io_.run();
}

boost::asio::io_context& PrinterStrand::get_io_context()
{
    return io_;
}

void PrinterStrand::wait_timer1()
{
    timer1_.expires_after(std::chrono::seconds(wait_time_secs_));
    timer1_.async_wait(boost::asio::bind_executor(strand_,
        boost::bind(&PrinterStrand::print1, this)));
}

void PrinterStrand::wait_timer2()
{
    timer2_.expires_after(std::chrono::seconds(wait_time_secs_));
    timer2_.async_wait(boost::asio::bind_executor(strand_,
        boost::bind(&PrinterStrand::print2, this)));
}

void PrinterStrand::print1()
{
    if (count_ < 10) {
        std::cout << "count = " << count_++ << '\n';
        wait_timer1();
    }
}

void PrinterStrand::print2()
{
    if (count_ < 10) {
        std::cout << "count = " << count_++ << '\n';
        wait_timer2();
    }
}

} // namespace Printers
