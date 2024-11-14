#include <stdio.h>
#define max_product 100

int main() {
    int ID;
    int stock_in[max_product];
    int stock_out[max_product];
    int current_stock[max_product];
    int num_product;
    int i;
    int totalSales = 0;//전체재고 수량 
    int total_in = 0;//전체 입고 수량
    int total_out = 0;//전체 판매 수량
    double saleRate=0.0;//전체 판매율 
    int maxId = -1;//최대 판매량 ID
    int minId = -1;//최소 판매량 ID
    int maxSales = -1;//최대 판매량
    int minSales = 1000;//최소 판매량

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
            totalSales += stock_out[i];
     

        if (stock_out[i] > maxSales) {
            maxSales = stock_out[i];
            maxId = i;
        }
        if (stock_out[i] < minSales) {
            minSales = stock_out[i];
            minId = i;
        }
        if (current_stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i+1, current_stock[i]);
        }
     }
   
    printf("재고수량: ");
    for (int i = 0; i < num_product; i++) {
        int current_stock = stock_in[i] - stock_out[i];
        printf("%d",current_stock);

        totalSales += stock_out[i];
    }
    printf("\n");
    
    for(int i=0;i<num_product;i++){
        total_in+=stock_in[i];
    }
    
    if (total_in > 0) {
        saleRate = ((double)totalSales / total_in) * 100;
    }
        printf("총 판매량: %d (총 판매율:%.2f%%)\n",totalSales,saleRate);

    printf("최대 판매량 상품: ID %d, 판매량 %d\n", maxId+1, maxSales);
    printf("최소 판매량 상품: ID %d, 판매량 %d\n", minId+1, minSales);

    return 0;
}
