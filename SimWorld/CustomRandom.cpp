#include <CustomRandom.h>

auto& get_time_based_generator() {
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generator(seed);
    return generator;
}

int random_int(int min, int max) {
    static auto& gen = get_time_based_generator();
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int random_int() {
    return random_int(0, 1000);
}

float random_float(float min, float max) {
    static auto& gen = get_time_based_generator();
    std::uniform_real_distribution<float> distrib(min, max);
    return distrib(gen);
}


double random_double(double min, double max) {
    static auto& gen = get_time_based_generator();
    std::uniform_real_distribution<double> distrib(min, max);
    return distrib(gen);
}