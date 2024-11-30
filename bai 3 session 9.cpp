#include <stdio.h>
#define MAX_SIZE 100 
int main() {
    int arr[MAX_SIZE];  
    int currentLength;  
    int numElements;    

    printf("Nhap so luong phan tu muon nhap (toi da 100): ");
    scanf("%d", &numElements);
  
    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu khong hop le!\n");
        return 1; 
    }

    for (int i = 0; i < numElements; i++) {
        printf("Nh?p ph?n t? %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentLength = numElements; 

    printf("Mang ban dau: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int deleteIndex;
    printf("Nhap vi tri can xoa (tu 0 den %d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi tri khong hop le!\n");
        return 1; 
    }
  
    for (int i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currentLength--;  
  
    printf("Mang sau khi xoa phan tu toi vi tri %d: ", deleteIndex);
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
  
