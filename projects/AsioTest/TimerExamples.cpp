#include <chrono>
#include <iostream>

#include "AsioIncludes.h"
#include "TimerExamples.h"

void TimerExamples::blocking_wait()
{
    boost::asio::io_context io;
    std::cout << "Will wait for 2 secs\n";
    boost::asio::steady_timer timer(io, std::chrono::seconds(2));
    timer.wait();
    std::cout << "Hello, world!\n";
}

void TimerExamples::timer_no_wait()
{
    boost::asio::io_context io;
    std::cout << "Timer 2 secs, no wait, return ASAP\n";
    boost::asio::steady_timer timer(io, std::chrono::seconds(2));
    std::cout << "Hello, world!\n";
}

void TimerExamples::timer_async_wait()
{
    boost::asio::io_context io;
    std::cout << "Will wait async for 2 secs\n";
    boost::asio::steady_timer timer(io, std::chrono::seconds(2));
    timer.async_wait([](const boost::system::error_code& /*e*/) {
        std::cout << "Hello, world!\n";
    });
    io.run();
}

void TimerExamples::timer_async_wait_no_work()
{
    boost::asio::io_context io;
    std::cout << "Async 2 secs, no work, return ASAP\n";
    boost::asio::steady_timer timer(io, std::chrono::seconds(2));
    io.run();
}

void TimerExamples::timer_async_wait_run_first()
{
    boost::asio::io_context io;
    std::cout << "Async 2 secs, run before wait, return ASAP\n";
    boost::asio::steady_timer timer(io, std::chrono::seconds(2));
    io.run();
    timer.async_wait([](const boost::system::error_code& /*e*/) {
        std::cout << "Hello, world!\n";
    });
}