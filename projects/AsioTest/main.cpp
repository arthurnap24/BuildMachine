#include <iostream>
#include <boost/asio.hpp>

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

int main()
{
  //blocking_wait();
  //timer_no_wait();
  //timer_async_wait();
  //timer_async_wait_no_work();
  timer_async_wait_run_first();

  return 0;
}
