#include <stdio.h>
#include <string.h> // For strcmp function
#include <stdlib.h> // For standard library functions

struct fileTable {
    char name[20];
    int sb, nob;
} ft[30];

int main() {
    int i, j, n;
    char s[20];

    printf("Enter no of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);

        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &ft[i].sb);

        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("\nFile Not Found");
    } else {
        printf("\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t%d\t\t", ft[i].name, ft[i].sb, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d, ", ft[i].sb + j);
        }
    }

    // Pause the program before exit
    printf("\nPress any key to exit...");
    getchar(); // To consume the newline left by the last input
    getchar(); // To wait for the user to press a key

    return 0;
}

