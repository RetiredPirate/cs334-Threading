// Hey here it is!

//#import "sudokuChecker.h"

#import <pthread.h>
#import <string>
#import <cstdlib>
#import <iostream>

using namespace std;


#define SUDOKU_SIZE 9

#ifndef INVALID
#define INVALID 0
#endif

int **testPuzzle;
bool isValid;



/* rowCheck()
    checks that all integers 1 through 9 are
    present in the given array.
*/
void *rowCheck(void* _index) {

    for (int index = 0; index < SUDOKU_SIZE; index++) {

        int checkList[SUDOKU_SIZE] = {0};

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            checkList[testPuzzle[i][index]-1]++;
        }

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            if (checkList[i] != 1) {
                isValid = false;
                return NULL;
            }
        }

    }


    return NULL;
}//singleCheck



/* columnCheck()
    checks that all integers 1 through 9 are
    present in the given array.
*/
void *columnCheck(void* _index) {

    for (int index = 0; index < SUDOKU_SIZE; index++) {

        int checkList[SUDOKU_SIZE] = {0};

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            checkList[testPuzzle[index][i]-1]++;
        }

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            if (checkList[i] != 1) {
                isValid = false;
                return NULL;
            }
        }

    }


    return NULL;
}//singleCheck



/* columnCheck()
    checks that all integers 1 through 9 are
    present in the given array.
*/
void *boxCheck(void* _index) {

    for (int indexI = 0; indexI < 3; indexI++) {
        for (int indexJ = 0; indexJ < 3; indexJ++) {

            int checkList[SUDOKU_SIZE] = {0};

            for (int i = 3*indexI; i < 3*(indexI+1); i++) {
                for (int j = 3*indexJ; j < 3*(indexJ+1); j++) {
                    checkList[testPuzzle[i][j]-1]++;
                }
            }

            for (int i = 0; i < SUDOKU_SIZE; i++) {
                if (checkList[i] != 1) {
                    isValid = false;
                    return NULL;
                }
            }

        }
    }


    return NULL;
}//singleCheck



/* sudokuCheck()
    spawns a thread to check the validity of each row, column and box
*/
void sudokuCheck() {

    isValid = true;

    pthread_t threads[3];

    cout << "Creating thread: " << 0 << endl;
    pthread_create(&threads[0], NULL, rowCheck, NULL);

    cout << "Creating thread: " << 1 << endl;
    pthread_create(&threads[1], NULL, columnCheck, NULL);

    cout << "Creating thread: " << 2 << endl;
    pthread_create(&threads[2], NULL, boxCheck, NULL);


    for (int i = 0; i < SUDOKU_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

}

/* main()
    Creates a valid or an invalid table and calls sudokuCheck()
        to spawn threads and check the puzzle validity.
*/
int main() {

    // Only create one puzzle at a time

    // Fresh Puzzle
    testPuzzle = new int*[SUDOKU_SIZE];
    for (int i = 0; i < SUDOKU_SIZE; i++)  {
        testPuzzle[i] = new int[SUDOKU_SIZE];
    }

    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (i == 0) {
                testPuzzle[i][j] = j+1;
            }
            if (i == 1) {
                testPuzzle[i][j] = (j+3)%9+1;
            }
            if (i == 2) {
                testPuzzle[i][j] = (j+6)%9+1;
            }
            if (i == 3) {
                testPuzzle[i][j] = (j+1)%9+1;
            }
            if (i == 4) {
                testPuzzle[i][j] = (j+4)%9+1;
            }
            if (i == 5) {
                testPuzzle[i][j] = (j+7)%9+1;
            }
            if (i == 6) {
                testPuzzle[i][j] = (j+2)%9+1;
            }
            if (i == 7) {
                testPuzzle[i][j] = (j+5)%9+1;
            }
            if (i == 8) {
                testPuzzle[i][j] = (j+8)%9+1;
            }
        }
    }

    // print puzzle to make sure its valid
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            cout << testPuzzle[i][j] << " ";
        }
        cout << endl;
    }

    sudokuCheck(); //spawns threads

    string validity;

    if (isValid) {
        validity = "valid";
    }
    else {
        validity = "invalid";
    }

    cout << endl << "The puzzle is " << validity << "!" << endl;

    cout << endl << endl << endl;





    // Make the puzzle invalid and test again
    testPuzzle[0][0] = 5;
    testPuzzle[4][5] = 7;

    // print puzzle
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            cout << testPuzzle[i][j] << " ";
        }
        cout << endl;
    }

    sudokuCheck(); //spawns threads

    delete testPuzzle;

    if (isValid) {
        validity = "valid";
    }
    else {
        validity = "invalid";
    }

    cout << endl << "The puzzle is " << validity << "!" << endl;


    return 1;
}
