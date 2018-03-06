// Hey here it is!

#import "sudokuChecker.h"

#import <thread>
#import <string>

using namespace std;



class sudokuChecker {

public:
    static const int SUDOKU_SIZE = 9;
    int main(int , const char* []);
    bool singleCheck(int []) noexcept;
    bool sudokuCheck(int [][9]);
};

sudokuChecker::sudokuChecker() {
}


int sudokuChecker::main(int argc, const char* argv[]) {

    int testPuzzle[SUDOKU_SIZE][SUDOKU_SIZE] = {};
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            testPuzzle[i][j] = i;
        }
    }

    sudokuCheck(testPuzzle);

    return 1;
}



/* singleCheck()
    checks that all integers 1 through 9 are
    present in the given array.
*/
bool sudokuChecker::singleCheck(int single[]) {
    int checkList[9] = {0};

    for (int i = 0; i < 9; i++) {
        checkList[single[i]]++;
    }

    for (int i = 0; i < 9; i++) {
        if (checkList[i] != 1) {
            return false;
        }
    }

    return true;

}//singleCheck

bool sudokuChecker::sudokuCheck(int puzzleGrid[][9]) {
    // trust its a 9x9 array

    std::thread threadOne(&sudokuChecker::singleCheck, puzzleGrid[0]);

    threadOne.join();

    // if (x) {
    //     return 0;
    // }
    return true;
}
