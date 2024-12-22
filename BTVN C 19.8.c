#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void sapXepSinhVien(struct SinhVien sv[], int length);
void inSinhVien(struct SinhVien sv[], int length);
int main() {
    struct SinhVien sv[5] = {
        {1, "Le Duc Anh", 18, "0974935754"},
        {2, "Le Duc B", 17, "0981234567"},
        {3, "Le Duc C", 22, "0976543210"},
        {4, "Le Duc D", 25, "0961237890"},
        {5, "Le Duc E", 24, "0959876543"}
    };
    int length = 5;
    printf("Thong tin cac sinh vien truoc khi sap xep:\n");
    inSinhVien(sv, length);
    sapXepSinhVien(sv, length);
    printf("Thong tin cac sinh vien sau khi sap xep theo ten:\n");
    inSinhVien(sv, length);

    return 0;
}
void sapXepSinhVien(struct SinhVien sv[], int length) {
    struct SinhVien temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void inSinhVien(struct SinhVien sv[], int length) {
    printf("Thong tin cac sinh vien:\n");
    for (int i = 0; i < length; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("\n");
    }
}
