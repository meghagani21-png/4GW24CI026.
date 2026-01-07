import java.util.Scanner;

class Contact {
    String name;
    String phone;
}

public class PhoneDirectory {

    // Binary Search Method
    static int binarySearch(Contact[] dir, int n, String key) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int cmp = dir[mid].name.compareTo(key);

            if (cmp == 0)
                return mid;
            else if (cmp < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // Sorting Method (Bubble Sort)
    static void sortDirectory(Contact[] dir, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (dir[j].name.compareTo(dir[j + 1].name) > 0) {
                    Contact temp = dir[j];
                    dir[j] = dir[j + 1];
                    dir[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of contacts: ");
        int n = sc.nextInt();

        Contact[] directory = new Contact[n];

        for (int i = 0; i < n; i++) {
            directory[i] = new Contact();
            System.out.print("\nEnter name: ");
            directory[i].name = sc.next();
            System.out.print("Enter phone number: ");
            directory[i].phone = sc.next();
        }

        // Sort before binary search
        sortDirectory(directory, n);

        System.out.print("\nEnter name to search: ");
        String searchName = sc.next();

        int result = binarySearch(directory, n, searchName);

        if (result != -1) {
            System.out.println("\nContact Found!");
            System.out.println("Name: " + directory[result].name);
            System.out.println("Phone: " + directory[result].phone);
        } else {
            System.out.println("\nContact not found.");
        }

        sc.close();
    }
}
