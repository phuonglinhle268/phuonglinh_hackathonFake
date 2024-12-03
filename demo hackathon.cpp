#include <stdio.h>
#define MAX 100

int main() {
	int n = 0;
	int choice, value, number, temp;
	int ar[MAX];
	do {
	printf("\nMENU\n");
	printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
	printf("2. In ra gia tri cac phan tu dang quan li\n");
	printf("3. In ra gia tri lon nhat trong mang\n");
	printf("4. In ra cac phan tu co gia tri la so nguyen to\n");
	printf("5. Them mot phan tu vao trong mang\n");
	printf("6. Xoa mot phan tu o trong mang\n");
	printf("7. Sap xep mang theo thu tu tang dan\n");
	printf("8. Tim kiem phan tu va in ra vi tri index cua phan tu do\n");
	printf("9. Thoat\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			int mang(int arr[]) {
				int n;
				printf("Nhap so phan tu cua mang: ");
				scanf("%d", &n);
				printf("Nhap cac phan tu trong mang: \n");
				for (int i = 0; i < n; i++) {
					printf("Phan tu %d: ", i + 1);
					scanf("%d", &arr[i]);
				}
				return n;
			}
			break;
		case 2:
		    int print(int arr[], int n) {
		    	printf("Gia tri cac phan tu trong mang la: ");
		    	for (int i = 0; i < n; i++) {
		    		printf("%d", arr[i]);
				}
				printf("\n");
				return 0;
			}
			break;
		case 3:
			if (n > 0) {
				int max = arr[0];
				for (int i = 1; i < n; i++) {
					if (arr[i] > max) {
						max = arr[i];
					}
				}
				print("Gia tri lon nhat trong mang la: %d\n", max);
			} else {
				printf("Mang trong.\n");
			}
			break;
		case 4:
			printf("Cac phan tu la so nguyen to la: ");
			for (int i = 0; i < n; i++) {
				if (arr[i] <= 1) {
					continue;
				}
				int prime = 1; 
				for (int j = 2; j * j <= arr[i]; j++) {
					if (arr[i] % j == 0) {
						prime = 0;
						break;
					}
				}
				if (prime) {
					printf("%d", arr[i]);
				}
			}
			printf("\n");
			break;
		case 5:
			if (n >= MAX) {
				printf("Khong hop le");
			} else {
				printf("Nhap gia tri can them: ");
				scanf("%d", &value);
				arr[n++] = value;
				printf("Phan tu %d duoc them vao mang\n", value);
			}
		    break;
		case 6:
			printf("Nhap gia tri can xoa: ");
			scanf("%d", &value);
			number = -1;
			for(int i = 0; i < n; i++) {
				if (arr[i] == value) {
					number = i;
					break
				}
			} 
			if (number != -1) {
				for (int i = number; i < n - 1; i++) {
					arr[i] = arr[i + 1];
				}
				n--;
				printf("Phan tu %d da duoc xoa.\n", value);
			} else {
				printf("Phan tu %d khong ton tai trong mang.\n", value);
			}
			break;
		case 7:
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (arr[i] > arr[j]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			printf("Mang sau khi sap xep: ");
			for (int i = 0; i < n; i++) {
				printf("%d", arr[i]);
			}
			printf("\n");
			break;
		case 8:
			printf("Nhap phan tu can tim: ");
			scanf("%d", &value);
			number = -1;
			for (int i = 0; i < n; i++) {
				if (arr[i] == value) {
					number = i;
					break;
				}
			}
			if (number != -1) {
				printf("Phan tu %d da duoc xoa.\n", value, number);
			} else {
				printf("Phan tu %d khong ton tai trong mang.\n", value);
			}
			break;
		case 9:
			printf("Thoat.\n");
			break;
		default:
			printf("Lua chon khong hop le. Nhap lai.\n");		
	}	
} while (choice != 9);
	
return 0;
}

