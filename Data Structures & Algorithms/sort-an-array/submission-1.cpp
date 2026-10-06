class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void merge(vector<int>& v, int left, int mid, int right) {
        // Retrieve the sizes of the left and right partitions respectively
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary vectors to store numbers from
        // the left and right partition so we can
        // rearrange them in the original vector
        vector<int> L(n1);
        vector<int> R(n2);

        // Fill L with values from the left partition
        for (int i = 0; i < n1; i++) {
            L[i] = v[left + i];
        }

        // Fill R with values from the right partition
        for (int i = 0; i < n2; i++) {
            R[i] = v[mid + 1 + i];
        }

        // Create variables to keep track of where we are in L and R
        // respectively
        int i = 0;
        int j = 0;

        // Pointer in original array
        int k = left;

        // While i and j are within bounds
        while (i < n1 && j < n2) {
            // Set the current index of the original array to the smaller value
            if (L[i] <= R[j]) {
                v[k] = L[i];
                i++;
            } else {
                v[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining values in L
        while (i < n1) {
            v[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining values in R
        while (j < n2) {
            v[k] = R[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<int>& v, int left, int right) {
        // Calculate the size of the current partition
        int n = right - left + 1;

        // If the size <= 1, it is already sorted
        if (n <= 1) {
            return;
        }

        // Calculate the mid value
        int mid = left + (right - left) / 2;

        // Recursively call mergesort on these two new partitions
        mergesort(v, left, mid);
        mergesort(v, mid + 1, right);

        // Merge the two partitions after they've been sorted
        merge(v, left, mid, right);
    }
};