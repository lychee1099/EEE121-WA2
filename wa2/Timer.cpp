#include "Timer.hpp"
#include <iostream>

// ASSUMES CSV_FILE ALREADY OPEN
Timer::Timer(std::string name, std::ofstream &csv_file) {
    _name = name;
    start = std::chrono::high_resolution_clock::now();

   _csv_file = &csv_file;
}

// WILL NOT CLOSE CSV_FILE
Timer::~Timer() {
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << _name << " " << duration.count() << " in microseconds" << std::endl;

    *(_csv_file) << duration.count() << "\n";
}