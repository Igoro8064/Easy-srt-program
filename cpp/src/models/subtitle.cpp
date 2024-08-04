#include "subtitle.h"

Subtitle::Subtitle() : start(0), end(0), text("") {}

Subtitle::Subtitle(int start, int end, const std::string& text)
    : start(start), end(end), text(text) {}
