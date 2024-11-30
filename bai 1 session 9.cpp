#include <stdio.h>
#define MAX_SIZE 100 
int main() {
    int arr[MAX_SIZE];  
    int currentLength = 0;  
    int numElements; 

    printf("Nhap so luong phan tu muon nhap (toi da 100): ");
    scanf("%d", &numElements);

   
    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu không hop le!\n");
        return 1; 
    }

    for (int i = 0; i < numElements; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentLength = numElements; 

    int addIndex, addValue;
    printf("Nhap vi tri muon them phan tu (tu 0 den %d): ", currentLength);
    scanf("%d", &addIndex);
    if (addIndex < 0 || addIndex > currentLength) {
        printf("Vi tri khong hop le!\n");
        return 1; 
    }
    printf("Nhap gia tri phan tu muon thêm: ");
    scanf("%d", &addValue);

    if (addIndex >= currentLength) {
        arr[addIndex] = addValue;
        currentLength = addIndex + 1;
    } else {
      
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
       
        arr[addIndex] = addValue;
        currentLength++; 
    }

    printf("Mang sau khi thêm phan tu: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

