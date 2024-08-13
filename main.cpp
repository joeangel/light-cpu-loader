#include <unistd.h>
#include <thread>
#include <vector>
#include <chrono>

const int BUSY_TIME = 1;  // busy ms time for each cpu
const int IDLE_TIME = 1999; // idle ms time for each cpu

void simulate_cpu_load() {
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();

	// make cpu busy
        while (std::chrono::high_resolution_clock::now() - start < std::chrono::microseconds(BUSY_TIME)) {}

	// make cpu idle
        usleep(IDLE_TIME);
    }
}

int main(int argc, char* argv[]) {
    // get cpu count
    unsigned int num_cpus = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    // new thread for each cpu
    for (unsigned int i = 0; i < num_cpus; ++i) {
        threads.push_back(std::thread(simulate_cpu_load));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

