#pragma once
#include <random>
#include <chrono>
#include <functional>

// Генератор псевдослучайных чисел, инициализированный временем
auto& get_time_based_generator();

// Случайное целое в диапазоне [min, max]
int random_int(int min, int max);
int random_int();

// Случайное float в диапазоне [min, max]
float random_float(float min, float max);

// Случайное double в диапазоне [min, max]
double random_double(double min, double max);