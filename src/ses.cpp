#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <random>
#include <ctime>
#include <stdint.h>
#include "options.h"

typedef std::pair<uint64_t, std::string> sample;
bool operator<(sample a, sample b) { return a.first < b.first; }

uint64_t ses(uint64_t sample_size, int seed) {
  std::mt19937_64 gen(seed);
  std::uniform_int_distribution<uint64_t> ud(0, 0xffffffffffffffff);

  uint64_t n = 0, r;
  std::priority_queue<sample> reservoir;
  std::string line;
  while (getline(std::cin, line)) {
    r = ud(gen);
    if (reservoir.size() < sample_size)
      reservoir.push(sample(r, line));
    else if (reservoir.top().first > r) {
      reservoir.pop();
      reservoir.push(sample(r, line));
    }
    n++;
  }

  while(!reservoir.empty()) {
    std::cout << reservoir.top().second << std::endl;
    reservoir.pop();
  }

  return n;
}

int main (int argc, char* argv[]) {
  using namespace std;
  using namespace opt;

  uint64_t sample_size = 2 << 15;

  if (chkOption(argv, argv + argc, "-h")) {
    cout
      << "ses [options]" << endl
      << " -h: ask for help" << endl
      << " -s: sample size, default: " << sample_size << ")" << endl
      << " -r: srand,       default: current time" << endl;
    return 0;
  }

  sample_size = getValue(argv, argv + argc, "-s", sample_size);
  int seed    = getValue(argv, argv + argc, "-r", time(NULL));

  uint64_t n_edge = ses(sample_size, seed);

  return 0;
}
