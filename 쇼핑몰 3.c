#include <stdio.h>
#define max_product 5
#define LOW_STOCK 2
#define MAX_NAME_LENGTH 30


void inputStock(int stock_in[]) {
    printf("전체 상품의 입고수량: ");
    for (int i = 0; i < max_product; i++) {
        scanf_s("%d", &stock_in[i]);
    }
}
void quantityReceiv(int stock_in[]) {
    int product_id, amount;
    printf("상품 ID (0-%d): ", max_product - 1);
    scanf_s("%d", &product_id);
    if (product_id >= 0 && product_id < max_product) {
        printf("입고수량: ");
        scanf_s("%d", &amount);
        stock_in[product_id] += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}
void inputSales(int stock_out[]) {
    printf("전체 상품의 판매수량 입력: ");
    for (int i = 0; i < max_product; i++) {
        scanf_s("%d", &stock_out[i]);
    }
}

void quantitySales(int stock_out[]) {
    int product_id, amount;
    printf("상품 ID : ", max_product - 1);
    scanf_s("%d", &product_id);
    if (product_id >= 0 && product_id < max_product) {
        printf("판매수량: ");
        scanf_s("%d", &amount);
        stock_out[product_id] += amount;
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }
}

void inputProductNames(char product_names[][MAX_NAME_LENGTH]) {
    for (int i = 1; i < max_product+1; i++) {
        printf("ID %d 상품명: ", i);
        scanf("%s", product_names[i]);
    }
}

void currentProduct(int stock_in[], int stock_out[], char product_names[][MAX_NAME_LENGTH]) {
    printf("상품 현황:\n");

    int total_sales = 0;
    int max_sales = -1, min_sales = 1000; 
    int max_id = -1, min_id = -1;

    for (int i = 0; i < max_product; i++) {
        int current_stock = stock_in[i] - stock_out[i];
        printf("상품 ID %d: 재고수량 %d\n", i, current_stock);

        total_sales += stock_out[i];

        // 최대, 최소 판매량 계산
        if (stock_out[i] > max_sales) {
            max_sales = stock_out[i];
            max_id = i;
        }
        if (stock_out[i] < min_sales) {
            min_sales = stock_out[i];
            min_id = i;
        }

        // 재고 부족 
        if (current_stock <= LOW_STOCK) {
            printf("상품 ID %d: 재고부족(%d)\n", i, current_stock);
        }
    }

    float sales_rate = 0.0;
    int total_in = 0;
    for (int i = 0; i < max_product; i++) {
        total_in += stock_in[i];
    }

    if (total_in > 0) {
        sales_rate = ((float)total_sales / total_in) * 100;
    }

    printf("총 판매량: %d\n", total_sales);
    printf("판매율: %.2f%%\n", sales_rate);
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_sales);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_sales);
}

int main() {

    int stock_in[max_product] = { 0 };  // 초기 입고 수량
    int stock_out[max_product] = { 0 }; // 초기 판매 수량
    char product_names[max_product][MAX_NAME_LENGTH]; // 상품명 저장
    int choice;

    while (1) {
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n2. 판매\n3. 상품현황\n4. 상품명 입력\n5. 종료\n");
        printf("입력: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: 
            printf("1. 전체 상품 입고\n2. 개별 상품 입고\n");
            scanf_s("%d", &choice);
            if (choice == 1) {
                inputStock(stock_in);
            }
            else if (choice == 2) {
                quantityReceiv(stock_in);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 2: 
            printf("1. 전체 상품 판매\n2. 개별 상품 판매\n");
            scanf_s("%d", &choice);
            if (choice == 1) {
                inputSales(stock_out);
            }
            else if (choice == 2) {
                quantitySales(stock_out);
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
            break;

        case 3: 
            currentProduct(stock_in, stock_out,product_names);
            break;

        case 4:
            inputProductNames(product_names);
            break;

        case 5: 
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 선택입니다.\n");
            break;
        }
    }
}
