#include <string>

class SearchItem {
public:
  SearchItem(const std::string& keyword);
  std::string result();

private:
  std::string keyword_{};
  std::string result_{};
};
