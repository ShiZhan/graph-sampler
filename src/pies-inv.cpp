#include <iostream>
#include <fstream>
#include <functional>
#include <stdint.h>
#include "options.h"

uint64_t pies_inv(int n_vertex) {
  uint64_t n, u, v;
  return n;
}

int main (int argc, char* argv[]) {
  using namespace std;
  using namespace opt;

  int n_vertex = 2 << 10;

  if (chkOption(argv, argv + argc, "-h")) {
    cout
      << "ses [options]" << endl
      << " -h: ask for help" << endl
      << " -s: sample size (veretx total, default: " << n_vertex << ")" << endl;
    return 0;
  }

  n_vertex = getValue(argv, argv + argc, "-s", n_vertex);

  return 0;
}
