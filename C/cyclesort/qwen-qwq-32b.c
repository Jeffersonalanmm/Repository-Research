void cycleSort(int arr[], int n) {

{

    for (int cycleStart = 0; cycleStart < n; cycleStart++) {

        int item = arr[cycleStart];

        int pos = cycleStart;

        for (int i = cycleStart + 1; i < n; i++)

            if (arr[i] < item)

                pos++;

 

        // Handle duplicates.

        while (item == arr[pos]

            pos++;

 

        if (pos != cycleStart) {

            swap(&arr[pos], &item);

        }

 

        // Now, continue the cycle.

        while (pos != cycleStart) {

            pos = cycleStart;

            for (int i = cycleStart + 1; i < n; i++)

                if (arr[i] < item)

                    pos++;

                else if (arr[i] == item)

                    pos++;

 

            while (item == arr[pos]

                pos++;

 

            if (pos != cycleStart) {

                swap(&arr[pos], &item);

            }

        }

    }

}
