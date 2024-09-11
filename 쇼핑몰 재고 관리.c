#include <stdio.h>
#define max_product 100

int main() {
    int ID;
    int stock_in[max_product];
    int stock_out[max_product];
    int current_stock[max_product];
    int num_product;
    int i;

    printf("상품의 개수 입력: ");
    scanf_s("%d", &num_product);
    if (num_product >= max_product) {
        printf("상품입력 불가능");
    }
    printf("상품 별 입고수량 입력: ");
    for (i = 0; i < num_product; i++) {
        scanf_s("%d", &stock_in[i]);
    }
    printf("상품 별 판매수량 입력: ");
    for (i = 0; i < num_product; i++) {
        scanf_s("%d", &stock_out[i]);
    }
    for (i = 0; i < num_product; i++) {
        current_stock[i] = stock_in[i] - stock_out[i];
    }
    printf("ID 입력: ");
    scanf_s("%d", &ID);
    if (ID >= 0 && ID < num_product) {
    printf("%d ID에 해당하는 제품의 재고 수량: %d\n",ID, current_stock[ID]);
    }
    else {
        printf("잘못된 ID입니다\n");
    }
    for(i=0;i<num_product;i++){
    printf("%d",current_stock[i]);
    }

    return 0;
}


