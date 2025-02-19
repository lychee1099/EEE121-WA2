#pragma once

#include <chrono>
#include <fstream>

// lifetime

class Timer {
    public:
        Timer(std::string name, std::ofstream &csv_file);
        ~Timer();

    private:
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point stop;
        std::chrono::microseconds duration;

        std::string _name = "";
        std::ofstream* _csv_file;
};