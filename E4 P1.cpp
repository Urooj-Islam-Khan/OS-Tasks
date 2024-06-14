#include <stdio.h>
#include <conio.h>

main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    // Input total memory available
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);

    // Input block size
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    // Calculate the number of blocks and external fragmentation
    nob = ms / bs;
    ef = ms - (nob * bs);

    // Input the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    // Input memory required for each process
    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    // Display number of blocks available
    printf("\nNumber of Blocks available in memory: %d", nob);

    // Display process memory requirements and allocation status
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += bs - mp[i];
            p++;
        }
    }

    // Check if there are processes left that cannot be accommodated
    if (i < n) {
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");
    }

    // Display total internal and external fragmentation
    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d", ef);

    getch();
}

