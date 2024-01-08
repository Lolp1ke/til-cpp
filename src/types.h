#pragma once

#include <array>
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

template<typename T, size_t N>
using array = std::array<T, N>;
