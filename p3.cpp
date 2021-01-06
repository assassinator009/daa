#include <stdio.h>
#include<conio.h>
void countingSort(int arr[], int n) {
  int arr1[10];

  int x = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > x)
      x = arr[i];
  }


  int count_arr[10];

  for ( i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for ( i = 0; i < n; i++) {
    count_arr[arr[i]]++;
  }

  for ( i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for ( i = n - 1; i >= 0; i--) {
    arr1[count_arr[arr[i]] - 1] = arr[i];
    count_arr[arr[i]]--;
  }

  for ( i = 0; i < n; i++) {
    arr[i] = arr1[i];
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  clrscr();
  int n = sizeof(arr) / sizeof(arr[0]);
  countingSort(arr, n);
  display(arr, n);
  getch();
  return 0;
}