#include <stdio.h>
#include <string.h>

struct Contact {
    char name[30];
    char phone[15];
};


int binarySearch(struct Contact dir[], int n, char key[]) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = strcmp(dir[mid].name, key);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


void sortDirectory(struct Contact dir[], int n) {
    struct Contact temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(dir[j].name, dir[j + 1].name) > 0) {
                temp = dir[j];
                dir[j] = dir[j + 1];
                dir[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Contact directory[50];
    int n, i;
    char searchName[30];

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter name: ");
        scanf("%s", directory[i].name);
        printf("Enter phone number: ");
        scanf("%s", directory[i].phone);
    }

   
    sortDirectory(directory, n);

    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    int result = binarySearch(directory, n, searchName);

    if (result != -1) {
        printf("\nContact Found!");
        printf("\nName: %s", directory[result].name);
        printf("\nPhone: %s\n", directory[result].phone);
    } else {
        printf("\nContact not found.\n");
    }

    return 0;
}
