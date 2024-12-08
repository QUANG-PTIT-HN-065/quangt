#include <stdio.h>

int main() {
    int choice;
    int i, n, arr[100];
    do {
        printf("\nMenu\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Sap xep va hien thi so le dung truoc, so chan dung sau\n");
        printf("15. Dao nguoc mang\n");
        printf("16. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so luong: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri: ");
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 3: {
                int count = 0, sum;
                for (i = 0; i < n; i++) {
                    sum = 0;
                    for (int a = 1; a <= arr[i] / 2; a++) {
                        if (arr[i] % a == 0) {
                            sum += a;
                        }
                    }
                    if (sum == arr[i] && arr[i] > 0) {
                        count++;
                    }
                }
                printf("Co %d so la so hoan hao\n", count);
                break;
            }
            case 4: {
                int count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] < 2) continue;
                    int isPrime = 1;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) {
                        count++;
                    }
                }
                printf("So luong so nguyen to la: %d\n", count);
                break;
            }
            case 5: {
                int max = arr[0], max_2 = -1e9;
                for (i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        max_2 = max;
                        max = arr[i];
                    } else if (arr[i] > max_2 && arr[i] != max) {
                        max_2 = arr[i];
                    }
                }
                printf("Gia tri lon thu 2 la: %d\n", max_2);
                break;
            }
            case 6: {
                int min = arr[0], min_2 = 1e9;
                for (i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        min_2 = min;
                        min = arr[i];
                    } else if (arr[i] < min_2 && arr[i] != min) {
                        min_2 = arr[i];
                    }
                }
                printf("Gia tri nho thu 2 la: %d\n", min_2);
                break;
            }
            case 7: {
                int val, pos;
                printf("Nhap gia tri muon them: ");
                scanf("%d", &val);
                printf("Nhap vi tri muon them: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = val;
                    n++;
                }
                break;
            }
            case 8: {
                int pos;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;
            }
            case 9: {
                for (i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep tang dan:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 16:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 16);
    return 0;
}

	
