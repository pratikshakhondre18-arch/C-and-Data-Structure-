#include <stdio.h>

void print_arr(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    int pass = 0;
    int comp = 0;
    int swap = 0;

    for(i = 0; i < n - 1; i++)
    {
        pass++;

        for(j = 0; j < n - 1 - i; j++)
        {
            comp++;

            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap++;
            }
        }
    }

    printf("\nBubble Sort\n");
    printf("Passes      : %d\n", pass);
    printf("Comparisons : %d\n", comp);
    printf("Swaps       : %d\n", swap);
}

void selection_sort(int arr[], int n)
{
    int i, j, temp;
    int pass = 0;
    int comp = 0;
    int swap = 0;

    for(i = 0; i < n - 1; i++)
    {
        pass++;

        for(j = i + 1; j < n; j++)
        {
            comp++;

            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap++;
            }
        }
    }

    printf("\nSelection Sort\n");
    printf("Passes      : %d\n", pass);
    printf("Comparisons : %d\n", comp);
    printf("Swaps       : %d\n", swap);
}
void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    int pass = 0;
    int comp = 0;

    for(i = 1; i < n; i++)
    {
        pass++;

        for(j = i; j > 0; j--)
        {
            comp++;

            if(arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }

    printf("\nInsertion Sort\n");
    printf("Passes      : %d\n", pass);
    printf("Comparisons : %d\n", comp);
}
int main()
{
    int arr[100], temp[100];
    int n, i, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("Menu..\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("  \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        for(i = 0; i < n; i++)
        {
            temp[i] = arr[i];
        }

        switch(choice)
        {
            case 1:
                bubble_sort(temp, n);
                printf("Sorted Array: ");
                print_arr(temp, n);
                break;

            case 2:
                selection_sort(temp, n);
                printf("Sorted Array: ");
                print_arr(temp, n);
                break;

            case 3:
                insertion_sort(temp, n);
                printf("Sorted Array: ");
                print_arr(temp, n);
                break;

            case 4:
                printf("\nArray: ");
                print_arr(arr, n);
                break;
  
            case 5:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}