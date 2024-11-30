#include <stdio.h>
#define MAX_SIZE 100 
void inMaTran(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    printf("Gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inLeVaTinhTong(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    int tong = 0;
    printf("Gia tri cac phan tu le: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                tong += arr[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong);
}

void inDuongBienVaTinhTich(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    int tich = 1;
    printf("Gia tri cac phan tu tren duong bien: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", arr[i][j]);
                tich *= arr[i][j];
            }
        }
    }
    printf("\nTich cua cac phan tu duong bien: %d\n", tich);
}

void inDuongCheoChinh(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    printf("Gia tri cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    printf("Gia tri cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", arr[i][m - i - 1]);
    }
    printf("\n");
}

void inDaiTongMax(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    int maxSum = -1, maxRow = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    printf("Dai co tong gia tri lon nhat la: ");
    for (int j = 0; j < m; j++) {
        printf("%d ", arr[maxRow][j]);
    }
    printf("\nTong cua dong nay: %d\n", maxSum);
}
int main() {
    int arr[MAX_SIZE][MAX_SIZE];  
    int n, m; 
    int choice;  

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua ma tran\n");
        printf("2. In ra gia tri cac phan tu cua ma tran\n");
        printf("3. In ra gia tri cac phan tu le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh\n");
        printf("6. In ra cac phan tu tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap kich co ma tran (so hang, so cot): ");
                scanf("%d %d", &n, &m);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Nhap gia tri cho phan tu [%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            case 2:
                inMaTran(arr, n, m); 
                break;
            case 3:
                inLeVaTinhTong(arr, n, m);
                break;
            case 4:
                inDuongBienVaTinhTich(arr, n, m); 
                break;
            case 5:
                inDuongCheoChinh(arr, n, m); 
                break;
            case 6:
                inDuongCheoPhu(arr, n, m);  
                break;
            case 7: inDaiTongMax(arr, n, m); 
                break;
            case 8:
                printf("Thoat khoi chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 8); 
    return 0;
}

