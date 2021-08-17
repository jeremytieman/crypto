#include <string>
#include <sstream>

namespace waves
{
  std::string caesar_shift(const std::string& s, const char shift)
  {
    std::stringstream out;

    for(const auto c : s)
    {
      if(('A' <= c) && (c <= 'Z')) out << static_cast<char>((((c - 'A') + shift + 26) % 26) + 'A');
      else if(('a' <= c) && (c <= 'z')) out << static_cast<char>((((c - 'a') + shift + 26) % 26) + 'a');
    }

    return out.str();
  }
}
