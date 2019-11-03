#pragma once

#include <string>
#include <vector>

std::vector<std::string> StrSplit( std::string str, char splitBy, bool fixType = false );
std::string StrFixType( std::string str );
std::string StrJoin( std::vector<std::string> elements, std::string joinBy );
