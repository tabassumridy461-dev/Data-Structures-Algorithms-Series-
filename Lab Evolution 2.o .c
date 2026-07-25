#include <stdio.h>

int main()
{
    // অবশ্যই Sorted Array হতে হবে
    int arr[] = {10, 20, 30, 40, 50};

    int size = 5;
    int target = 40;

    // শুরু এবং শেষ index
    int low = 0;
    int high = size - 1;

    // value পাওয়া যায়নি ধরে নিচ্ছি
    int found = 0;

    // যতক্ষণ low <= high
    while(low <= high)
    {
        // মাঝের index বের করা
        int mid = (low + high) / 2;

        // যদি target পাওয়া যায়
        if(arr[mid] == target)
        {
            printf("Found at index %d", mid);

            found = 1;
            break;
        }

        // যদি target বড় হয়
        else if(target > arr[mid])
        {
            // ডান পাশে Search করবে
            low = mid + 1;
        }

        // যদি target ছোট হয়
        else
        {
            // বাম পাশে Search করবে
            high = mid - 1;
        }
    }

    // যদি target না পাওয়া যায়
    if(found == 0)
    {
        printf("Not Found");
    }

    return 0;
}
