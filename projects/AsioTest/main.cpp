#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void blocking_wait()
{
  boost::asio::io_context io;
  std::cout << "Will wait for 5 seconds" << std::endl;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  std::cout << "Calling wait" << std::endl;
  t.wait(); // will finish the timer's count from when it was created
  std::cout << "Hello, world!" << std::endl;
}

void timer_no_wait()
{
  boost::asio::io_context io;
  std::cout << "Will wait for 2 seconds, no wait" << std::endl;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(2));
  // no wait returns right away
  std::cout << "Hello, world!" << std::endl;
}

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

void timer_async_wait()
{
  boost::asio::io_context io;
  std::cout << "Will wait async for 2 seconds" << std::endl;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(2));
  std::cout << "Calling async_wait with print function" << std::endl;
  t.async_wait(&print); // introduces work for the io_context
  io.run();
}

void timer_async_wait_no_work()
{
  boost::asio::io_context io;
  std::cout << "Will not wait" << std::endl;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(2));
  // no work given to the io_context
  io.run();
}

void timer_async_wait_run_first()
{
  boost::asio::io_context io;
  std::cout << "Will not wait, either" << std::endl;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(2));
  io.run();
  t.async_wait(&print);
}

void wait(boost::asio::steady_timer* t);

class Printer {
public:
  Printer(int wait_for_secs) :
    t_(io_, boost::asio::chrono::seconds(wait_for_secs))
  {}

  void start() {
    wait();
    io_.run();
    print_count();
  }

private:
  void wait() {
    t_.async_wait(boost::bind(&Printer::print, this,
      boost::asio::placeholders::error));
  }

  void print(const boost::system::error_code& /*e*/) {
    if (count_ < 5) {
      std::cout << "Hello, count = " << count_++ << std::endl;
      t_.expires_at(t_.expiry() + boost::asio::chrono::seconds(1));
      wait();
    }
  }

  void print_count()
  {
    std::cout << "Final count is: " << count_ << std::endl;
  }

  int count_ = 0;
  boost::asio::io_context io_;
  boost::asio::steady_timer t_;
};

void timer_async_wait_bind()
{
  Printer printer(2); // RAII
  printer.start();
}

int main()
{
  // blocking_wait();
  // timer_no_wait();
  // timer_async_wait();
  // timer_async_wait_no_work();
  // timer_async_wait_run_first();
  timer_async_wait_bind();

  return 0;
}
