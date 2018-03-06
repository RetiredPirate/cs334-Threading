// Hey here it is!

#import "sudokuChecker.h"

#import <pthread.h>
#import <string>
#import <cstdlib>
#import <iostream>

using namespace std;


#define SUDOKU_SIZE 9;


sudokuChecker::sudokuChecker() {
}


int main() {

    int testPuzzle[SUDOKU_SIZE][SUDOKU_SIZE] = {};
    int i;
    for (i = 0; i < SUDOKU_SIZE; i++) {
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

    pthread_t threads[1];
    int rc;
    int i;

    for (i = 0; i < 1; i++) {
        cout << "Creating thread.";
        rc = pthread_create(&threads[i], NULL, sudokuChecker::singleCheck, puzzleGrid[0]);

        if (rc) {
            cout << "failed.";
            exit(-1);
        }
    }

    // threadOne.join();

    // if (x) {
    //     return 0;
    // }
pthread_exit(NULL);

    return true;
}
