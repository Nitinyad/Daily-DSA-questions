class Solution {
  public:
    // Function to count the number of students needed to allocate the pages
    int countStudents(int arr[], int n, long long mid) {
        int allocatedStu = 1;  // Start with one student
        long long pages = 0;   // Accumulate pages for the current student

        for (int i = 0; i < n; i++) {
            if (pages + arr[i] > mid) {  // Allocate to a new student if adding pages exceeds mid
                allocatedStu++;
                pages = arr[i];          // Start count for the new student
            } else {
                pages += arr[i];         // Continue adding pages to the current student
            }
        }

        return allocatedStu;
    }
    
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1; // More students than books

        long long low = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            low = max(low, (long long)arr[i]); // Minimum value of low should be the maximum book size
        }
        long long high = sum;

        while (low <= high) {
            long long mid = (low + high) / 2;  // Use long long for mid calculation
            int students = countStudents(arr, n, mid);
            if (students > m) {        // More students needed, increase low
                low = mid + 1;
            } else {                   // Fewer or equal students needed, try for fewer pages
                high = mid - 1;
            }
        }

        return low; // The minimum number of pages
    }
};

