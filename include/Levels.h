#include <ctime>
#include <chrono>
#pragma once
enum Levels {informational = 2, important = 1, critical = 0};
const auto t = std::chrono::system_clock::now();

