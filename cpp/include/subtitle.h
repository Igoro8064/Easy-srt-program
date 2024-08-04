#pragma once

#include <string>

class Subtitle {
 public:
  int start;
  int end;
  std::string text;

  Subtitle();  // Default constructor
  Subtitle(int start, int end, const std::string& text);
};
