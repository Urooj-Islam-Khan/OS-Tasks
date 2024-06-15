#include <stdio.h>
#include <conio.h>

main() {
    int ms, mp[10], i, temp, n = 0;
    char ch = 'y';

    
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);

    temp = ms;

    for (i = 0; ch == 'y'; i++, n++) {
        printf("\nEnter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);

        if (mp[i] <= temp) {
            printf("Memory is allocated for Process %d\n", i + 1);
            temp -= mp[i];
        } else {
            printf("Memory is Full\n");
            break;
        }

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &ch);  // Note the space before %c to consume any leftover newline character
    }

    printf("\nTotal Memory Available: %d", ms);
    printf("\n\n\tPROCESS\t\tMEMORY ALLOCATED");
    for (i = 0; i < n; i++) {
        printf("\n\t%d\t\t%d", i + 1, mp[i]);
    }

    printf("\n\nTotal Memory Allocated: %d", ms - temp);
    printf(" \nTotal External Fragmentation: %d", temp);

    getch();
}

