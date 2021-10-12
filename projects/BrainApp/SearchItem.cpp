#include "DataSource.h"
#include "SearchItem.h"

SearchItem::SearchItem(const std::string& keyword)
  : keyword_(keyword)
{}

std::string SearchItem::result()
{
  result_ = DataSource::get_result(keyword_); 
  return result_;
}
