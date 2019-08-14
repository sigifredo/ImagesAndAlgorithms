#include <iostream>

void print(int i, int arr[3])
{
    std::cout << "F**" << i << " = (" << arr[0] << ", " << arr[1] << ", " << arr[2] << ")" << std::endl;
}

void F(int arr[3])
{
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = arr[0] + arr[1];
}

int main()
{
    int arr[] = {0, 1, 1};

    for (int i = 0; i < 5; i++)
    {
        F(arr);
        print(i+1, arr);
    }
}
