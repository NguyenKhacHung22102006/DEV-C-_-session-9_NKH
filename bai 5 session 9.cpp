#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100 
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void nhapMang(int arr[], int *currentLength) {
    printf("Nhap so luong phan tu can nhap: ");
    scanf("%d", currentLength);

    if (*currentLength > MAX_SIZE || *currentLength <= 0) {
        printf("So phan tu khong hop le!\n");
        return;
    }

    for (int i = 0; i < *currentLength; i++) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong!\n");
        return;
    }

    printf("Gia tri cac phan tu dang quan ly: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inChanVaTinhTong(int arr[], int currentLength) {
    int tong = 0;
    printf("Gia tri cac phan tu chan: ");
    for (int i = 0; i < currentLength; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cua cac phan tu chan: %d\n", tong);
}

void inMaxMin(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong!\n");
        return;
    }

    int max = arr[0], min = arr[0];
    for (int i = 1; i < currentLength; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

void inSoNguyenToVaTinhTong(int arr[], int currentLength) {
    int tong = 0;
    printf("Gia tri cac phan tu la so nguyen to: ");
    for (int i = 0; i < currentLength; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cua cac so nguyen tu: %d\n", tong);
}

void thongKeSoLanXuatHien(int arr[], int currentLength) {
    int num, count = 0;
    printf("Nhap vao mot so de thong ke: ");
    scanf("%d", &num);

    for (int i = 0; i < currentLength; i++) {
        if (arr[i] == num) {
            count++;
        }
    }

    printf("So %d xuat hien %d lan trong mang.\n", num, count);
}
void themPhanTu(int arr[], int *currentLength) {
    if (*currentLength >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu!\n");
        return;
    }

    int addIndex, addValue;
    printf("Nhap vi tri muon them (tu 0 den %d): ", *currentLength);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > *currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri phan tu muon them: ");
    scanf("%d", &addValue);

    for (int i = *currentLength; i > addIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[addIndex] = addValue;
    (*currentLength)++;  
}
int main() {
    int arr[MAX_SIZE];  
    int currentLength = 0; 
    int choice;  
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &currentLength);  
                break;
            case 2:
                inMang(arr, currentLength); 
                break;
            case 3:
                inChanVaTinhTong(arr, currentLength); 
                break;
            case 4:
                inMaxMin(arr, currentLength); 
                break;
            case 5:
                inSoNguyenToVaTinhTong(arr, currentLength);  
                break;
            case 6:
                thongKeSoLanXuatHien(arr, currentLength); 
                break;
            case 7:
                themPhanTu(arr, &currentLength); 
                break;
            case 8:
                printf("Thoat khoi chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 8);  // L?p l?i cho d?n khi ch?n thoát
    return 0;
}

