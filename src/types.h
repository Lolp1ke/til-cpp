#pragma once

#include <regex>
#include <string>
#include <variant>
#include <vector>

typedef std::string string;
typedef std::regex regexp;

template<typename T>
using vector = std::vector<T>;

template<typename... T>
using variant = std::variant<T...>;