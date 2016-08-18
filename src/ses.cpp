#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <stdint.h>
#include "options.h"
#include "utils.h"

class Sample {
public:
	uint64_t r;
	uint64_t v;
	std::vector<uint64_t> e;
	Sample(uint64_t r, uint64_t v) : r(r), v(v) {}
};

bool operator<(Sample a, Sample b) { return a.r < b.r; }

uint64_t sns(uint64_t sample_size, int seed) {
	std::mt19937_64 gen(seed);
	std::uniform_int_distribution<uint64_t> ud(0, 0xffffffffffffffff);

	uint64_t n = 0, u, v;
	std::priority_queue<Sample> reservoir;
	std::string line;
	while (getline(std::cin, line)) {
		SSCANF((line.c_str(), "%lln %lln", &u, &v));
		n++;
	}

	return n;
}

int main(int argc, char* argv[]) {
	using namespace std;
	using namespace opt;

	uint64_t sample_size = 2 << 13;

	if (chkOption(argv, argv + argc, "-h")) {
		cout
			<< "ses [options]" << endl
			<< " -h: ask for help" << endl
			<< " -s: sample size, default: " << sample_size << ")" << endl
			<< " -r: srand,       default: current time" << endl;
		return 0;
	}

	sample_size = getValue(argv, argv + argc, "-s", sample_size);
	int seed = getValue(argv, argv + argc, "-r", time(NULL));

	uint64_t n_edge = sns(sample_size, seed);

	return 0;
}
