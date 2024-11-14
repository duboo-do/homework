#include <stdio.h>
#define max_product 100

int main() {
    int ID;
    int stock_in[max_product];
    int stock_out[max_product];
    int current_stock[max_product];
    int num_product;
    int i;
    int total_stock = 0;//전체재고 수량 
    int total_in = 0;//전체 입고 수량
    int total_out = 0;//전체 판매 수량
    float total_per;//전체 판매율 
    int max_id = -1;//최대 판매량 ID
    int min_id = -1;//최소 판매량 ID
    int max = -1;//최대 판매량
    int min = 1000;//최소 판매량

    printf("상품의 개수 입력: ");
    scanf("%d", &num_product);

    if (num_product > max_product || num_product <= 0) {
        printf("상품입력 불가능\n");
        return 1;//오류 발생시 종료
    }
    printf("상품 별 입고수량 입력: ");
    for (i = 0; i < num_product; i++) {
        scanf("%d", &stock_in[i]);
        total_in += stock_in[i];
    }

     printf("상품 별 판매수량 입력: ");
     for (i = 0; i < num_product; i++) {
         scanf("%d", &stock_out[i]);
         total_out += stock_out[i];
     }
     for (i = 0; i < num_product; i++) {
            current_stock[i] = stock_in[i] - stock_out[i];
            total_stock += stock_out[i];
     

        if (stock_out[i] > max) {
            max = stock_out[i];
            max_id = i;
        }
        if (stock_out[i] < min) {
            min = stock_out[i];
            min_id = i;
        }
        if (current_stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i+1, current_stock[i]);
        }
     }
   
    printf("재고수량: ");
    for (int i = 0; i < num_product; i++) {
        int current_stock = stock_in[i] - stock_out[i];
        printf("%d",current_stock);

        total_stock += stock_out[i];
    }
    printf("\n");

    printf("총 판매량: %d\n", total_stock);
    if (total_in > 0) {
        total_per = ((float)total_out / total_in) * 100;
        printf("전체 판매율:%.2f%%\n", total_per);
    }

    printf("최대 판매량 상품: ID %d, 판매량 %d\n", max_id+1, max);
    printf("최소 판매량 상품: ID %d, 판매량 %d\n", min_id+1, min);

    return 0;
}
