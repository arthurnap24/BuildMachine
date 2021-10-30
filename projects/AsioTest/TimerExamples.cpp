#include <chrono>
#include <iostream>

#include "AsioIncludes.h"
#include "TimerExamples.h"
#include "Printer.h"
#include "PrinterStrand.h"

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

void TimerExamples::printer_example_strand()
{
    PrinterStrand p(1);
    p.start();
}

void TimerExamples::printer_example_strand_multithread()
{
    PrinterStrand p1(1);
    std::thread t([&p1]() {
        p1.get_io_context().run();
    });
    p1.start();
    t.join();
}
