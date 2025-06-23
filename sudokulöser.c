#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int grid[SIZE][SIZE] = {
    { 0, 2, 0, 0, 1, 0, 9, 0, 8},
    { 5, 0, 0, 4, 3, 0, 1, 0, 0},
    { 0, 0, 0, 9, 0, 0, 0, 7, 5},
    { 3, 0, 6, 1, 8, 0, 7, 2, 0},
    { 0, 5, 2, 6, 0, 4, 8, 1, 0},
    { 0, 8, 7, 0, 9, 3, 4, 0, 6},
    { 7, 6, 0, 0, 0, 9, 2, 0, 1},
    { 0, 0, 8, 0, 5, 1, 0, 0, 4},
    { 4, 0, 1, 0, 6, 0, 0, 9, 0}
};

bool erlaubt(int zeile, int spalte, int zahl) {
    for(int x = 0; x < SIZE; x++) {
        if(grid[zeile][x] == zahl || grid[x][spalte] == zahl){
            return false;
        }
    }

    int startZeile = (zeile / 3) * 3;
    int startSpalte = (spalte / 3) * 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[startZeile + i][startSpalte + j] == zahl) {
                return false;
            }
        }
    }
    
    return true;
}

bool löse() {
    for(int zeile = 0; zeile < SIZE; zeile++) {
        for(int spalte = 0; spalte < SIZE; spalte++) {
            if(grid[zeile][spalte] == 0) {
                for(int zahl = 1; zahl <= 9; zahl++){
                    if(erlaubt(zeile, spalte, zahl)){
                        grid[zeile][spalte] = zahl;
                        if(löse()){
                            return true;
                        }
                        grid[zeile][spalte] = 0;
                    }

                        
                    
                } return false;
            }
        }
    } return true;
}

void drucke_grid() {
    for(int i = 0; i < SIZE; i++){
        if(i % 3 == 0){
            printf(" ------+-----+-----+\n");
        }
        for(int j = 0; j < SIZE; j++){
            if(j % 3 == 0){
                printf(" | ");
            }
            printf("%d", grid[i][j]);
    } printf(" |\n");
}
}

int main() {

    printf(" Sudoku: \n");
    drucke_grid();

    if(löse()){
        printf("\n gelöstes Sudoku:\n");
        drucke_grid();
    } else{
        printf("Keine Lösung.\n");
    }

    return 0;
}
