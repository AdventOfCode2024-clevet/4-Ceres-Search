#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <regex>

const std::vector<std::pair<int, int>> directions = {
    {0, 1},  {0, -1},  {1, 0},  {-1, 0},
    {1, 1},  {1, -1},  {-1, 1}, {-1, -1}
};

bool isWordAtPosition(const std::vector<std::string> &grid, int x, int y, const std::string &word, int dx, int dy) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < word.length(); ++i) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

int countWordOccurrences(const std::vector<std::string> &grid, const std::string &word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            for (const auto &[dx, dy] : directions) {
                if (isWordAtPosition(grid, x, y, word, dx, dy)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
        return (1);
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return (1);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    int result = countWordOccurrences(lines, "XMAS");
    std::cout << "Result = " << result << std::endl;

    return (0);
}
