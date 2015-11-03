/***********************************************************************
 School works
 Copyright (C) 2015-2016 Philippe VIENNE - Gabriel AUGENDRE

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "headers/utilSudoku.h"
#include "headers/main.h"
#include "headers/sudoku.h"

int main(int argc, char *argv[]) {
    FILE *fich;
    int sudoku[9][9];

    if (argc != 2) {
        printf(" usage: %s nomFich.txt \n", argv[0]);
        exit(-1);
    }

    fich = fopen(argv[1], "r");

    if (!fich) {
        perror("Erreur d'ouverture du fichier\n");
        exit(1);
    }

    lireSudoku(fich, sudoku);
    printf(" sudoku lu: \n");
    ecrireSudoku(stdout, sudoku);

    if (sudokuValide(sudoku)) {
        printf("Et en plus il est valide !\n");
        solveSudoku(sudoku);
        printf("Résolution: \n");
        ecrireSudoku(stdout, sudoku);
        if (sudokuValide(sudoku)) {
            printf("La solution est valide !\n");
        }
    } else {
        printf("\nLe sudoku lu n'est pas valide, pas de résolution possible.\n");
    }

    return 0;
}
