#pragma once

#ifndef XMASCOUNTER_HPP
    #define XMASCOUNTER_HPP

    #include <string>
    #include <vector>

    namespace CeresSearch
    {
        class XMASCounter
        {
            public:
                static int countXMASOccurrencesPartOne(const std::vector<std::string> &grid)
                {
                    static const std::vector<std::pair<int, int>> directions = {
                        {0, 1},  {0, -1},  {1, 0},  {-1, 0},
                        {1, 1},  {1, -1},  {-1, 1}, {-1, -1}
                    };

                    int rows = grid.size();
                    int cols = grid[0].size();
                    int count = 0;

                    for (int x = 0; x < rows; ++x) {
                        for (int y = 0; y < cols; ++y) {
                            for (const auto &[dx, dy] : directions) {
                                if (isWordAtPosition(grid, x, y, "XMAS", dx, dy)) {
                                    ++count;
                                }
                            }
                        }
                    }

                    return (count);
                }

                static int countXMASOccurrencesPartTwo(const std::vector<std::string> &grid)
                {
                    int rows = grid.size();
                    int cols = grid[0].size();
                    int count = 0;

                    for (int x = 1; x < rows - 1; ++x) {
                        for (int y = 1; y < cols - 1; ++y) {
                            if (grid[x][y] == 'A') {
                                if (isMAS(grid, x - 1, y - 1, 1, 1) && isMAS(grid, x - 1, y + 1, 1, -1))
                                {
                                    ++count;
                                }
                            }
                        }
                    }

                    return (count);
                }

            private:
                static bool isWordAtPosition(const std::vector<std::string> &grid, int x, int y, const std::string &word, int dx, int dy)
                {
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

                static bool isMAS(const std::vector<std::string> &grid, int x, int y, int dx, int dy)
                {
                    int rows = grid.size();
                    int cols = grid[0].size();

                    std::string mas = "MAS";
                    std::string reversed_mas = "SAM";

                    std::string candidate;
                    for (int i = 0; i < 3; ++i) {
                        int nx = x + i * dx;
                        int ny = y + i * dy;

                        if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) {
                            return false;
                        }
                        candidate += grid[nx][ny];
                    }

                    return (candidate == mas || candidate == reversed_mas);
                }
        };
    }

#endif /* XMASCOUNTER_HPP */
