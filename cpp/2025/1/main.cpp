#include <fstream>
#include <iostream>
#include <string>

#define MAX_ROTATION 100
#define MIN_ROTATION 0
#define START_ROTATION 50

using namespace std;

int python_style_mod(int x, int m) { return ((x % m) + m) % m; }

int update_dial(int curr, char command, int val) {
	int direction = (command == 'L') ? -1 : 1;
	return python_style_mod((curr + val * direction), MAX_ROTATION);
}

int solve_part_1(char *filename) {
	int count = 0;
	int curr = START_ROTATION;

	ifstream file(filename);

	for (std::string line; std::getline(file, line);) {
		char command = line[0];
		int val = stoi(line.substr(1));
		curr = update_dial(curr, command, val);
		if (curr == 0) count++;
	}

	return count;
}

int count_zero_hits(int curr, int val, int direction) {
	int distance_to_zero = (direction == 1) ? (MAX_ROTATION - curr) : curr;

	if (distance_to_zero == 0) distance_to_zero = MAX_ROTATION;

	if (val < distance_to_zero)
		return 0;

	return 1 + (val - distance_to_zero) / MAX_ROTATION;
}

int solve_part_2(char *filename) {
	int count = 0;
	int curr = START_ROTATION;

	ifstream file(filename);

	for (string line; getline(file, line);) {
		char command = line[0];
		int val = stoi(line.substr(1));

		int direction = (command == 'L') ? -1 : 1;

		count += count_zero_hits(curr, val, direction);
		curr = python_style_mod(curr + val * direction, MAX_ROTATION);
	}

	return count;
}

int main(int argc, char **argv) {
	char *filename = argv[1];
	int solution1 = solve_part_1(filename);
	cout << "Part 1: " << solution1 << "\n";
	int solution2 = solve_part_2(filename);
	cout << "Part 2: " << solution2 << endl;
	return 0;
}
