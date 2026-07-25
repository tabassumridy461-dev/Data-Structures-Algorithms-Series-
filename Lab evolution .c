#include <stdio.h>

int main()
{
    // Array declare করা হয়েছে
    int arr[] = {10, 20, 30, 40, 50};

    // Array-এর total element সংখ্যা
    int size = 5;

    // যে সংখ্যাটি খুঁজবো
    int target = 40;

    // শুরুতে ধরে নিচ্ছি value পাওয়া যায়নি
    int found = 0;

    // প্রথম element থেকে শেষ পর্যন্ত check করবে
    for(int i = 0; i < size; i++)
    {
        // যদি target পাওয়া যায়
        if(arr[i] == target)
        {
            printf("Found at index %d", i);

            found = 1;      // value পাওয়া গেছে
            break;          // Loop বন্ধ
        }
    }

    // যদি কোথাও target না পাওয়া যায়
    if(found == 0)
    {
        printf("Not Found");
    }

    return 0;
}
