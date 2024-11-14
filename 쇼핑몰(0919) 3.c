#include <stdio.h>
#define max_product 5
#define LOW_STOCK 2


void inputStock(int stock_in[]) {
    printf("전체 상품의 입고수량: ");
    for (int i = 0; i < max_product; i++) {
        scanf("%d", &stock_in[i]);
    }
}
void indiviProduct(int stock_in[]) {
    int ID, amount;
    printf("상품 ID : ");
    scanf("%d", &ID);
    if (ID >= 0 && ID < max_product) {
        printf("입고수량: ");
        scanf("%d", &amount);
        stock_in[ID] += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}
void inputSales(int stock_out[]) {
    printf("전체 상품의 판매수량 입력: ");
    for (int i = 0; i < max_product; i++) {
        scanf("%d", &stock_out[i]);
    }
}

void indiviSales(int stock_out[]) {
    int ID, amount;
    printf("상품 ID : ");
    scanf("%d", &ID);
    if (ID >= 0 && ID < max_product) {
        printf("판매수량: ");
        scanf("%d", &amount);
        stock_out[ID] += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}


void currentProduct(int stock_in[], int stock_out[]) {
    printf("상품 현황:\n");

    int totalSales = 0;
    int maxSales = -1, minSales = 1000; 
    int maxId = -1, minId = -1;


    printf("재고수량: ");
    for (int i = 0; i < max_product; i++) {
        int stockQuantity = stock_in[i] - stock_out[i];
        printf("%d ", stockQuantity);
    }
    printf("\n");


    for (int i = 0; i < max_product; i++) {
        totalSales += stock_out[i];

        if (stock_out[i] > maxSales) {
            maxSales = stock_out[i];
            maxId = i;
        }
        if (stock_out[i] < minSales) {
            minSales = stock_out[i];
            minId = i;
        }
    }

    double saleRate = 0.0; 
    int total_in = 0;
    for (int i = 0; i < max_product; i++) {
        total_in += stock_in[i];
    }

    if (total_in > 0) {
        saleRate = ((double)totalSales / total_in) * 100;
    }

    
    printf("총 판매량 : %d (판매율 %.2f%%)\n", totalSales, saleRate);


    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxId,maxSales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minId,minSales);


    for (int i = 0; i < max_product; i++) {
        int stockQuantity = stock_in[i] - stock_out[i];
        if (stockQuantity <= 2 && stockQuantity > 0) {
            printf("상품 ID: %d, 재고부족(%d)\n", i+1, stockQuantity);
        }
        else if (stockQuantity <= 0) {
            printf("상품 ID: %d, 재고부족(%d)\n", i+1, stockQuantity);
        }
    }


    printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
}



int main() {

    int stock_in[max_product] = { 0 };  
    int stock_out[max_product] = { 0 };
    int choice;

    while (1) {
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n2. 판매\n3. 상품현황\n4. 종료\n");
        printf("입력: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("1. 전체 상품 입고\n2. 개별 상품 입고\n");
            scanf("%d", &choice);
            if (choice == 1) {
                inputStock(stock_in);
            }
            else if (choice == 2) {
                indiviProduct(stock_in);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 2: 
            printf("1. 전체 상품 판매\n2. 개별 상품 판매\n");
            scanf("%d", &choice);
            if (choice == 1) {
                inputSales(stock_out);
            }
            else if (choice == 2) {
                indiviSales(stock_out);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 3: 
            currentProduct(stock_in, stock_out);
            break;


        case 4: 
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }
}
