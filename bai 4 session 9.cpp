#include <stdio.h>
#define MAX_SIZE 100 
void nhapMang(int arr[], int *currentLength);
void hienThiMang(int arr[], int currentLength);
void themPhanTu(int arr[], int *currentLength);
void suaPhanTu(int arr[], int currentLength);
void xoaPhanTu(int arr[], int *currentLength);
int main() {
    int arr[MAX_SIZE];  
    int currentLength = 0; 
    int choice; 
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapMang(arr, &currentLength);  
                break;
            case 2:
                hienThiMang(arr, currentLength);  
                break;
            case 3: themPhanTu(arr, &currentLength);
                break;
            case 4:
                suaPhanTu(arr, currentLength); 
                break;
            case 5:
                xoaPhanTu(arr, &currentLength);  
                break;
            case 6:
                printf("Thoat khoi chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 6); 

    return 0;
}
void nhapMang(int arr[], int *currentLength) {
    int numElements;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &numElements);
    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu khong hop le!\n");
        return;
    }

    for (int i = 0; i < numElements; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    *currentLength = numElements;  
}
void hienThiMang(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong!\n");
        return;
    }

    printf("Mang hien tai: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int *currentLength) {
    if (*currentLength >= MAX_SIZE) {
        printf("Mang da day. Khong the them phan tu!\n");
        return;
    }

    int addIndex, addValue;
    printf("Nhap vi tri muon them (t? 0 d?n %d): ", *currentLength);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > *currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri muon them: ");
    scanf("%d", &addValue);

    for (int i = *currentLength; i > addIndex; i--) {
        arr[i] = arr[i - 1];
    }

    arr[addIndex] = addValue;
    (*currentLength)++;  
}
void suaPhanTu(int arr[], int currentLength) {
    int position, newValue;

    if (currentLength == 0) {
        printf("Mang rong! Khong the sua!\n");
        return;
    }

    printf("Nhap vi tri muon sua (t? 0 d?n %d): ", currentLength - 1);
    scanf("%d", &position);

    if (position < 0 || position >= currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[position] = newValue;  
}
void xoaPhanTu(int arr[], int *currentLength) {
    int deleteIndex;

    if (*currentLength == 0) {
        printf("Mang rong! Khong the xoa!\n");
        return;
    }

    printf("Nhap vi tri muon xoa (t? 0 d?n %d): ", *currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= *currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = deleteIndex; i < *currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*currentLength)--;  
}


