#include <cstdio>
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

int python_style_mod(int x, int m)
{
    return ((x % m) + m) % m;
}

int f(int curr, char command, int val)
{
    int mult = (command == 'L') ? -1 : 1;
    return python_style_mod((curr + val * mult), 100);
}

int solve_part_1(char* filename)
{
    int count = 0;
    int curr = 50;
    string line;
    ifstream file(filename);

    while (getline(file, line)) 
    {
        char command = line[0];
        int val = stoi(line.substr(1));
        curr = f(curr, command, val);
        if (curr == 0) count++;
    }

    return count;
}


int main(int argc, char **argv)
{
    int solution1 = solve_part_1(argv[1]);
    cout << solution1;
    return 0;
}