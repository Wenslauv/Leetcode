/**
 * \file
 *
 * \author Viachaslau Kukhtsiuk (https://github.com/Wenslauv)
 */


#include <cassert>
#include <iostream>
#include <vector>
#include <string>


namespace leetcode {

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool rows   [9][9]  { false };
        bool columns[9][9]  { false };
        bool cells  [9][9]  { false };

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

        void test1() {
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
            assert( isValid );
        }

        void test2() {
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
            assert( not isValid );
        }

        void runTests() {
            std::cout << "Running predefined tests..." << std::endl;
            
            test1();
            test2();

            std::cout << "All tests passed successfully" << std::endl;
        }
    }   // namespace testing

}   // namespace leetcode



int main(int argc, const char * argv[]) {
    leetcode::testing::runTests();
    return 0;
}
