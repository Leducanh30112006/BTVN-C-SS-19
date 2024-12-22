#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void xoaSinhVien(int id, struct SinhVien sv[], int *currentLength);
void inSinhVien(struct SinhVien sv[], int currentLength);
int main() {
    struct SinhVien sv[50] = {
        {1, "Le Duc Anh", 18, "0974935754"},
        {2, "Le Duc B", 17, "0981234567"},
        {3, "Le Duc C", 22, "0976543210"},
        {4, "Le Duc D", 25, "0961237890"},
        {5, "Le Duc E", 24, "0959876543"}
    };
    int currentLength = 5;
    int idToDelete;
    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    xoaSinhVien(idToDelete, sv, &currentLength);
    inSinhVien(sv, currentLength);

    return 0;
}
void xoaSinhVien(int id, struct SinhVien sv[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (sv[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co id %d\n", id);
    }
}
void inSinhVien(struct SinhVien sv[], int currentLength) {
    printf("Thong tin cac sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("\n");
    }
}
