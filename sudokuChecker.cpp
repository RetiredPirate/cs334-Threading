// Hey here it is!

import<thread>



class sudokuChecker {


    bool sudokuCheck(int[][] puzzleGrid) {
        // trust its a 9x9 array

        for(int i = 0; )



    }


    /* singleCheck()
        checks that all integers 1 through 9 are
        present in the given array.
    */
    bool singleCheck(int[] single) {
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

}
