#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Directory {
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir[10];

int dcnt = 0;  // Directory count

int main() {
    int i, ch, k;
    char f[30], d[30];

    while (1) {
        printf("\n\n1. Create Directory\t2. Create File\t3. Delete File");
        printf("\n4. Search File\t\t5. Display\t6. Exit");
        printf("\nEnter your choice -- ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (dcnt < 10) {
                    printf("\nEnter name of directory: ");
                    scanf("%s", dir[dcnt].dname);
                    dir[dcnt].fcnt = 0;
                    dcnt++;
                    printf("Directory created");
                } else {
                    printf("\nMaximum number of directories reached.");
                }
                break;

            case 2:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        if (dir[i].fcnt < 10) {
                            printf("Enter name of the file: ");
                            scanf("%s", dir[i].fname[dir[i].fcnt]);
                            dir[i].fcnt++;
                            printf("File created");
                        } else {
                            printf("Directory %s is full, cannot create file.", d);
                        }
                        break;
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found", d);
                }
                break;

            case 3:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is deleted", f);
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt - 1]);
                                dir[i].fcnt--;
                                break;
                            }
                        }
                        if (k == dir[i].fcnt) {
                            printf("File %s not found", f);
                        }
                        break;
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found", d);
                }
                break;

            case 4:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is found", f);
                                break;
                            }
                        }
                        if (k == dir[i].fcnt) {
                            printf("File %s not found", f);
                        }
                        break;
                    }
                }
                if (i == dcnt) {
                    printf("Directory %s not found", d);
                }
                break;

            case 5:
                if (dcnt == 0) {
                    printf("\nNo Directories");
                } else {
                    printf("\nDirectory\tFiles");
                    for (i = 0; i < dcnt; i++) {
                        printf("\n%s\t\t", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            printf("\t%s", dir[i].fname[k]);
                        }
                    }
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option, try again.");
        }
    }

    return 0;
}
