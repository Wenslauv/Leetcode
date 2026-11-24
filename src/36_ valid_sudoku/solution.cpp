/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#include <doctest/doctest.h>


namespace leetcode::valid_sudoku {

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool rows   [9][9]  {  };
        bool columns[9][9]  {  };
        bool cells  [9][9]  {  };

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {

                char& ch = board[i][j];
                if ( ch == '.')
                    continue;

                int value = ch - '0' - 1;

                int cell = (i / 3) * 3 + j / 3;

                if (rows[i][value] or columns[j][value] or cells[cell][value])
                    return false;

                rows[i][value] = columns[j][value] = cells[cell][value] = true;
            }
        }

        return true;
    }

    namespace testing {

        using Sudoku = std::vector<std::vector<char>>;

        TEST_CASE("0036. Valid Sudoku") {

            SUBCASE("test 1") {
                Sudoku board {
                    {'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}
                };

                bool isValid = isValidSudoku(board);
                CHECK( isValid );
            }


            SUBCASE("test 2") {
                Sudoku board {
                    {'8','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}
                };

                bool isValid = isValidSudoku(board);
                CHECK( not isValid );
            }

        }
    }   // namespace testing

}   // namespace leetcode::valid_sudoku
