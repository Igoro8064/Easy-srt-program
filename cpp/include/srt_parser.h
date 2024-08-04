#ifndef SRT_PARSER_H
#define SRT_PARSER_H

#include <string>
#include <vector>

#include "subtitle.h"

std::vector<Subtitle> parseSRT(const std::string& filepath);
void exportSRT(const std::vector<Subtitle>& subtitles,
               const std::string& filepath);

#endif
