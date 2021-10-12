#include <iostream>

#include "SearchItem.h"

int main()
{
  SearchItem search_item("Hello");
  std::cout << search_item.result() << std::endl;

  SearchItem search_item2("King Kong");
  std::cout << search_item2.result() << std::endl;
  
  return 0;
}
