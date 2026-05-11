/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 04 – Dynamic Structures
 *   Hari dan Tanggal    : Senin, 04 Mei 2025
 *   Nama (NIM)          : Muhammad Zaki Azzamy Syauqi (13224045)
 *   Nama File           : soal1.c
 *   Deskripsi           : Diberi input:
 *                           N m11 m12 .. mNN
 *                         Dimana N adalah ukuran adj matrix NxN, mNN adalah elemen pada indeks N, N.
 *                         Output:
 *                         - Degree setiap baris (jumlah 1 pada baris)
 *                         - Maksimum degree dari node (indeks terkecil)
 *                         - Node dengan derajat 0
 *                         Format output:
 *                           for each found: FOUND position / NOT FOUND
 *                           LIST ... / LIST EMPTY
 * 
 *                         Contoh:
 *                         Input: 6 2 10 2 20 1 5 4 20 3 10 4 10
 *                         
 *                         Output: 
 *                         FOUND 2
 *                         NOT FOUND
 *                         LIST 5 20
 * 
 *                         5 10 20, find 20 --> 2, delete 10, list 5 20
 *                         Referensi:
 *                          1. Jawaban soal TP saya
 *                          2. Jawaban untuk soal di kelas saya
 */

#include <stdio.h>

// void countDegreeOfAdj(int N, int[][N] adj) {
//     for (int i = 0; i < N; i += 1) {
//         int count = 0;
//         for (int j = 0; j < N; j += 1) {
//             if (adj[i][j] == 1) count += 1;
//         }

//         printf("DEGREE %d %d\n", i, count);
//     }

//     return;
// }

// void maxDegNode(int N, int [N][N] adj) {
//     int max_node = 0;
//     int max_count = 0;
//     for (int i = 0; i < N; i += 1) {
//         int count = 0;
//         for (int j = 0; j < N; j += 1) {
//             if (adj[i][j] == 1) count += 1;
//         }

//         if (count > max_count) {
//             max_count = count;
//             max_node = i;
//         }
//     }

//     printf("MAX_VERTEX %d\n", max_node);
//     return;
// }

// void checkIsolated(int N, int [N][N] adj) {
//     printf("ISOLATED");
//     int has_isolated = 0;
//     for (int i = 0; i < N; i += 1) {
//         for (int j = 0; j < N; j += 1) {
//             if (adj[i][j] == 0) {
//                 has_isolated = 1;
//                 printf(" %d", i);
//                 break;
//             }
//         }
//     }

//     if (has_isolated) {
//         printf(" NONE\n;");
//     }

//     printf("\n");
//     return;
// }

int main() {
    int N;
    
    /* Input */
    scanf("%d", &N);
    int adj[N][N];
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            scanf("%d", &adj[i][j]);
        }
    }

    // countDegreeOfAdj(N, adj);
    for (int i = 0; i < N; i += 1) {
        int count = 0;
        for (int j = 0; j < N; j += 1) {
            if (adj[i][j] == 1) count += 1;
        }

        printf("DEGREE %d %d\n", i, count);
    }

    // maxDegNode(N, adj);
    int max_node = 0;
    int max_count = 0;
    for (int i = 0; i < N; i += 1) {
        int count = 0;
        for (int j = 0; j < N; j += 1) {
            if (adj[i][j] == 1) count += 1;
        }

        if (count > max_count) {
            max_count = count;
            max_node = i;
        }
    }

    printf("MAX_VERTEX %d\n", max_node);

    // checkIsolated(N, adj);
    printf("ISOLATED");
    int has_isolated = 0;
    for (int i = 0; i < N; i += 1) {
        int is_isolated = 1;
        for (int j = 0; j < N; j += 1) {
            if (adj[i][j] == 1) {
                is_isolated = 0;
            }
        }
        if (is_isolated) {
            printf(" %d", i);
            has_isolated = 1;
        }
    }

    if (!has_isolated) {
        printf(" NONE");
    }

    printf("\n");

    return 0;
}