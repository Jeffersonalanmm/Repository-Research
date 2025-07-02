

void shellSort(int arr[], int n) {

{

    int increments[] = {1,4,10,23,57,132,301,701,1750};

    int num_increments = sizeof(increments)/sizeof(increments[0]);

    for (int k = num_increments-1; k >=0; k--){

        int h = increments[k];

        if (h >= n) continue;

        // perform insertion sort with h.

        for (int i = h; i < n; i++) {

            int temp = arr[i];

            int j;

            for (j = i; j >= h; j -= h) {

                if (arr[j - h] > temp) {

                    arr[j] = arr[j - h];

                else

                    break;

            }

            arr[j + h] = temp;

        }

    }

}
