#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <random>
#include <ctime>
#include <stdint.h>
#include "options.h"
#include "utils.h"

class Sample {
public:
  uint64_t r;
  std::string e;
  Sample(uint64_t r, std::string e) : r(r), e(e) {}
  friend bool operator<(Sample a, Sample b) { return a.r < b.r; }
};

uint64_t sns1(uint64_t sample_size, int seed) {
  std::mt19937_64 gen(seed);
  std::uniform_int_distribution<uint64_t> ud(0, 0xffffffffffffffff);

  uint64_t n = 0, r, u, v;
  std::priority_queue<Sample> reservoir;
  std::set<uint64_t> vertexes;
  std::string line;
  while (getline(std::cin, line)) {
    SSCANF((line.c_str(), "%lln %lln", &u, &v));

    bool r_filling = reservoir.size() < sample_size;

    if (reservoir.size() < sample_size)
      reservoir.push(Sample(r, line));
    else if (reservoir.top().r > r) {
      reservoir.pop();
      reservoir.push(Sample(r, line));
    }
    n++;
  }

  while (!reservoir.empty()) {
    std::cout << reservoir.top().e << std::endl;
    reservoir.pop();
  }

  return n;
}

template <typename K, typename V>
V getOrElse(const std::map<K, V>& m, const K k, const V d) {
  auto itr = m.find(k);
  if (itr == m.end())
    return d;
  else
    return itr->second;
}

uint64_t sns2(char* vfile) {
  uint64_t n = 0, u, v;
  std::string line;

  std::set<uint64_t> vertexes;
  if (vfile) {
    std::ifstream vfstream(vfile);
    if (vfstream) {
      uint64_t v_orig = 0, v_mapped = 0;
      while (getline(vfstream, line)) {
        SSCANF((line.c_str(), "%ull", &v));
        vertexes.insert(v);
      }
      vfstream.close();
    }
  }

  while (getline(std::cin, line)) {
    SSCANF((line.c_str(), "%lln %lln", &u, &v));
  }

  return n;
}

uint64_t sns(char *efile, uint64_t sample_size, int seed) {
  uint64_t n = 0, u, v;
  std::string line;

  if (efile) {
    std::ifstream efstream(efile);
    if (efstream) {
      while (getline(efstream, line)) {
        SSCANF((line.c_str(), "%ull %ull", &u, &v));
      }
      efstream.close();
    }
  }

  return n;
}

int main(int argc, char* argv[]) {
  using namespace std;
  using namespace opt;

  uint64_t sample_size = 2 << 15;

  if (chkOption(argv, argv + argc, "-h")) {
    cout
      << "pass 1: sns [options]" << endl
      << " -h: ask for help" << endl
      << " -s: sample size, default: " << sample_size << endl
      << " -r: srand,       default: current time" << endl << endl
      << "pass 2: sns [options]" << endl
      << " -v: vertexes     [vertex file]" << endl << endl
      << "2 passes: sns [options]" << endl
      << " -e: edges        [edge file]" << endl;
    return 0;
  }

  sample_size = getValue(argv, argv + argc, "-s", sample_size);
  int seed    = getValue(argv, argv + argc, "-r", time(NULL));
  char* efile = getOption(argv, argv + argc, "-e");
  char* vfile = getOption(argv, argv + argc, "-v");

  if (efile)
    uint64_t n = sns(efile, sample_size, seed);
  else if (vfile)
    uint64_t n = sns2(vfile);
  else
    uint64_t n = sns1(sample_size, seed);

  return 0;
}
