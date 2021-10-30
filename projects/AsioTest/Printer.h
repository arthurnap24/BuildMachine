#pragma once
#include "AsioIncludes.h"

namespace TimerExamples {

class Printer {
public:
    Printer(int wait_time_secs);
    
    Printer(const Printer& /*other*/) = delete;
    Printer& operator=(const Printer& /*other*/) = delete;
    
    Printer(Printer&& /*other*/) = delete;
    Printer& operator=(Printer&& /*other*/) = delete;
    
    ~Printer() = default;

    void start();

private:
    void wait();
    void print();
    void print_count();

    int wait_time_secs_ = 0;
    int count_ = 0;
    boost::asio::io_context io_;
    boost::asio::steady_timer timer_;
};

void printer_example();

void printer_example_two_printers();

void printer_example_two_threads();

}
