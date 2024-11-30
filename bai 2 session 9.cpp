#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE]; 
    int n; 

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("So phan tu khong hop le!\n");
        return 1; 
    }

    printf("Nhap cac phan tu vao mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int position, newValue;
    printf("Nhap vi tri can sua (tu 0 den %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        return 1; 
    }
    printf("Nhap gia tri moi muon thay the: ");
    scanf("%d", &newValue);

    arr[position] = newValue;

    printf("Mang sau khi sua: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

