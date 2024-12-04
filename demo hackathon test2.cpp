#include <stdio.h>
#define MAX 100
int main()
{
    int arr[MAX][MAX];
    int choice;
    int row = 0, col = 0; 
    int result, tmp[100], temp, value, count, found;
    do {
        printf("\nMENU\n");
        printf(" 1.Nhap kich co va cac phan tu cua mang.\n");
        printf(" 2.In gia tri cac phan tu cua Mang theo ma tran.\n");
        printf(" 3.In ra cac phan tu nnam tren duong bien va tinh tich.\n");
        printf(" 4.In ra cac phan tu nam tren duong cheo chinh.\n");
        printf(" 5.In ra cac phan tu nam tren duong cheo phu.\n");
        printf(" 6.Sap xep duong cheo chinh theo thu tu tang dan.\n");
        printf(" 7.Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang.\n");
        printf(" 8.Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Nhap so hang: ");
                scanf("%d", &row);
                printf("Nhap so cot: ");
                scanf("%d", &col);
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        printf("Nhap phan tu thu a[%d][%d]: ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }
                break;

            case 2:
                if(row == 0 || col == 0) {
                    printf("Chua nhap kich co mang.\n");
                } else {
                    for(int i = 0; i < row; ++i) {            
                        for(int j = 0; j < col; ++j) {
                            printf("%d ", a[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:
                if(row == 0 || col == 0) {
                    printf("Chua nhap kich co mang.\n");
                } else {
                    result = 1;
                    for(int i = 0; i < row; ++i) {
                        for(int j = 0; j < col; ++j) {
                            if(i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                                printf("%d ", a[i][j]);
                                result *= a[i][j];
                            }                
                        }
                    }
                    printf("Tich cua cac phan tu tren duong bien la: %d\n", result);
                }
                break;

            case 4:
                if(row == 0 || col == 0) {
                    printf("Chua nhap kich co mang.\n");
                } else if(row == col) {
                    printf("Cac phan tu nam tren duong cheo chinh: ");
                    for(int i = 0; i < row; ++i) {
                        printf("%d ", a[i][i]);
                    }
                    printf("\n");
                } else {
                    printf("Mang khong phai ma tran vuong.\n");
                }
                break;

            case 5:
                if(row == 0 || col == 0) {
                    printf("Chua nhap kich co mang.\n");
                } else if(row == col) {
                    printf("Cac phan tu nam tren duong cheo phu: ");
                    for(int i = 0; i < row; ++i) {
                        printf("%d ", a[i][col - i - 1]);
                    }
                    printf("\n");
                } else {
                    printf("Mang khong phai ma tran vuong.\n");
                }
                break;

            case 6:
                if(row == 0 || col == 0) {
                    printf("Chua nhap kich co mang.\n");
                } else if(row == col) {
                    for(int i = 0; i < row; i++) {
                        tmp[i] = a[i][i];
                    }
                    for(int i = 0; i < row - 1; i++) {
                        for(int j = i + 1; j < row; j++) {
                            if(tmp[i] > tmp[j]) {
                                temp = tmp[i];
                                tmp[i] = tmp[j];
                                tmp[j] = temp;
                            }
                        }
                    }
                    for(int i = 0; i < row; i++) {
                        a[i][i] = tmp[i];
                    }
                } else {
                    printf("Mang khong phai ma tran vuong.\n");
                }
                break;

            case 7:
                printf("Nhap mot so de kiem tra: ");
                scanf("%d", &value);
                found = 0;
                count = 0;
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        if(a[i][j] == value) {
                            if(!found) {
                                printf("So %d xuat hien trong mang o vi tri: ", value);
                                found = 1;
                            }
                            printf("(%d, %d) ", i + 1, j + 1);
                            ++count;
                        }
                    }
                }
                if(!found) {
                    printf("Khong tim thay %d trong mang.\n", value);
                }
                break;

            case 8:
                printf("Thoat.\n");
                return 0;

            default:
                printf("Lua chon khong hop le.\n");
                break;
        }    
    } while (choice != 8);
    
    return 0;
}
