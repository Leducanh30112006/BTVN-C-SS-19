#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void inDanhSachSinhVien(struct SinhVien sv[], int length);
void themSinhVien(struct SinhVien sv[], int *currentLength);
void suaSinhVien(struct SinhVien sv[], int length);
void xoaSinhVien(struct SinhVien sv[], int *currentLength);
void timKiemSinhVien(struct SinhVien sv[], int length);
void sapXepSinhVien(struct SinhVien sv[], int length);
int main() {
    struct SinhVien sv[50] = {
        {1, "Le Duc Anh", 18, "0974935754"},
        {2, "Le Duc B", 17, "0981234567"},
        {3, "Le Duc C", 22, "0976543210"},
        {4, "Le Duc D", 25, "0961237890"},
        {5, "Le Duc E", 24, "0959876543"}
    };
    int currentLength = 5;
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                inDanhSachSinhVien(sv, currentLength);
                break;
            case 2:
                themSinhVien(sv, &currentLength);
                break;
            case 3:
                suaSinhVien(sv, currentLength);
                break;
            case 4:
                xoaSinhVien(sv, &currentLength);
                break;
            case 5:
                timKiemSinhVien(sv, currentLength);
                break;
            case 6:
                sapXepSinhVien(sv, currentLength);
                break;
            case 7:
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
void inDanhSachSinhVien(struct SinhVien sv[], int length) {
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
void themSinhVien(struct SinhVien sv[], int *currentLength) {
    struct SinhVien newStudent;
    newStudent.id = *currentLength + 1;
    printf("Nhap thong tin sinh vien moi:\n");
    printf("Nhap ten sinh vien: ");
    fgets(newStudent.name, 50, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Nhap so dien thoai sinh vien: ");
    fgets(newStudent.phoneNumber, 20, stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';
    sv[*currentLength] = newStudent;
    (*currentLength)++;
}
void suaSinhVien(struct SinhVien sv[], int length) {
    int idToFind, found = 0;
    printf("Nhap id sinh vien can sua: ");
    scanf("%d", &idToFind);
    getchar();
    for (int i = 0; i < length; i++) {
        if (sv[i].id == idToFind) {
            found = 1;
            printf("Nhap ten moi cho sinh vien: ");
            fgets(sv[i].name, 50, stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
            printf("Nhap tuoi moi cho sinh vien: ");
            scanf("%d", &sv[i].age);
            getchar();
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co id %d\n", idToFind);
    }
}
void xoaSinhVien(struct SinhVien sv[], int *currentLength) {
    int idToDelete, found = 0;
    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    getchar();
    for (int i = 0; i < *currentLength; i++) {
        if (sv[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co id %d\n", idToDelete);
    }
}
void timKiemSinhVien(struct SinhVien sv[], int length) {
    char nameToFind[50];
    int found = 0;
    printf("Nhap ten sinh vien can tim: ");
    fgets(nameToFind, 50, stdin);
    nameToFind[strcspn(nameToFind, "\n")] = '\0';
    for (int i = 0; i < length; i++) {
        if (strcmp(sv[i].name, nameToFind) == 0) {
            printf("Sinh vien duoc tim thay: ID: %d, Name: %s, Age: %d, Phone Number: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten %s\n", nameToFind);
    }
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
