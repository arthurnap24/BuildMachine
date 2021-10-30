#pragma once
#include "AsioIncludes.h"

namespace TimerExamples {

class PrinterStrand {
public:
    PrinterStrand(int wait_time_secs);
    
    PrinterStrand(const PrinterStrand& /*other*/) = delete;
    PrinterStrand& operator=(const PrinterStrand& /*other*/) = delete;
    
    PrinterStrand(PrinterStrand&& /*other*/) = delete;
    PrinterStrand& operator=(PrinterStrand&& /*other*/) = delete;
    
    ~PrinterStrand();

    void start();

    boost::asio::io_context& get_io_context();

private:
    void wait_timer1();
    void wait_timer2();
    void print1();
    void print2();

    int count_ = 0;
    int wait_time_secs_ = 0;
    boost::asio::io_context io_;
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_; 
};

void printer_example_strand();

void printer_example_strand_multithread();

}
