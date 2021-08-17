#include <string>
#include <sstream>
#include <iostream>

namespace waves
{
  int calculateShift(const char kv)
  {
      if(('A' <= kv) && (kv <= 'Z')) return kv - 'A';
      else if(('a' <= kv) && (kv <= 'z')) return kv - 'a';
      return 0;
  }

  std::string vigenereEncrypt(const std::string& s, const std::string& key)
  {
    std::cout << -5 % 26 << "\n";
    std::stringstream out;
    auto curKey = std::begin(key);

    for(const auto c : s)
    {
      if((!(('A' <= c) && (c <= 'Z'))) && (!(('a' <= c) && (c <= 'z')))) continue;      
      const auto kv = *curKey++;
      if(curKey == std::end(key)) curKey = std::begin(key);
      int shift = calculateShift(kv);
      if(('A' <= c) && (c <= 'Z')) out << static_cast<char>((((c - 'A') + shift) % 26) + 'A');
      else if(('a' <= c) && (c <= 'z')) out << static_cast<char>((((c - 'a') + shift) % 26) + 'a');
    }
    
    return out.str();
  }

  std::string vigenereDecrypt(const std::string& s, const std::string& key)
  {
    std::stringstream out;
    auto curKey = std::begin(key);

    for(const auto c : s)
    {
      if((!(('A' <= c) && (c <= 'Z'))) && (!(('a' <= c) && (c <= 'z')))) continue;
      const auto kv = *curKey++;
      if(curKey == std::end(key)) curKey = std::begin(key);
      int shift = calculateShift(kv);
      if(('A' <= c) && (c <= 'Z')) out << static_cast<char>((((c - 'A') - shift + 26) % 26) + 'A');
      else if(('a' <= c) && (c <= 'z')) out << static_cast<char>((((c - 'a') - shift + 26) % 26) + 'a');
    }
    
    return out.str();
  }
}
