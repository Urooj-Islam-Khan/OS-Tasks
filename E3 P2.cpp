#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block {
    int bno;
    struct block *next;
};

struct fileTable {
    char name[20];
    int nob;
    struct block *sb;
} ft[30];

int main() {
    int i, j, n;
    char s[20];
    struct block *temp;

    printf("Enter number of files: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);

        printf("Enter number of blocks in file %d: ", i + 1);
        if (scanf("%d", &ft[i].nob) != 1) {
            printf("Invalid input\n");
            return 1;
        }

        ft[i].sb = (struct block*)malloc(sizeof(struct block));
        if (ft[i].sb == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        temp = ft[i].sb;

        printf("Enter the blocks of the file: ");
        if (scanf("%d", &temp->bno) != 1) {
            printf("Invalid input\n");
            return 1;
        }
        temp->next = NULL;

        for (j = 1; j < ft[i].nob; j++) {
            temp->next = (struct block*)malloc(sizeof(struct block));
            if (temp->next == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            temp = temp->next;
            if (scanf("%d", &temp->bno) != 1) {
                printf("Invalid input\n");
                return 1;
            }
            temp->next = NULL;
        }
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0)
            break;
    }

    if (i == n) {
        printf("\nFile Not Found\n");
    } else {
        printf("\nFILE NAME\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t", ft[i].name, ft[i].nob);

        temp = ft[i].sb;
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d -> ", temp->bno);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        temp = ft[i].sb;
        while (temp != NULL) {
            struct block *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}

