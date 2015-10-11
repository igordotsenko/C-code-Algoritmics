/* 
 * Task:
 * There are <farmerQuantity> farmers
 * Each farmer has an <amount> liters of milk which cost <price>
 * There is need to buy <amountNeeded> liters of milk
 * 
 * Program calculates total <minPrice> for <amountNeeded> liters of milk and prints it to "task.out" file
 * If fermers do not have enough quantity of milk, output is 0
 *
 * Input: 
 * <farmerQuantity> <amountNeeded>
 * <amount1> <price1>
 * <amount2> <price2>
 * .....
 * <amountN> <priceN>
 * (contained in "task.in" file)
 *
 * Output: minimum cost of needed amount of milk
 *
 * Input and output example:
 * Input:
 * 3 10
 * 5 1
 * 8 2
 * 8 3
 *
 * Output:
 * 15
 *
 * Restrictions:
 * 0 <= farmerQuantity <= 100 000 000
 * 0 <= amountNeeded <= 300 000 000
 * 0 <= amount <= 300 000 000
 * 1 <= price <= 1 000
 *
 * Can be included <stdio.h> only
 */

#include <stdio.h>

#define MAXPRICE 1001

unsigned long long fileScan(FILE *source) {
    unsigned long long value;
    
    fscanf(source, "%llu", &value);
    
    return value;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned long long farmerQuantity = fileScan(in);
    unsigned long long amountNeeded = fileScan(in);
    unsigned long long amount[MAXPRICE];
    unsigned long long availableAmount = 0;
    unsigned long long minPrice = 0;
    
    if ( farmerQuantity == 0 || amountNeeded == 0 ) {
        fprintf(out, "0\n");
        return 0;
    }
    for ( int i = 0; i < MAXPRICE; i++ ) {
        amount[i] = 0;
    }
    for ( int price = 0, milkAmount = 0; fscanf(in, "%d", &milkAmount) == 1; ) {
        fscanf(in, "%d", &price);
        amount[price] += milkAmount;
        availableAmount += milkAmount;
    }
    if ( amountNeeded > availableAmount ) {
        fprintf(out, "0\n");
        return 0;
    }
    for ( int price = 0; amountNeeded > 0; price++ ) {
        if ( amountNeeded > amount[price] ) {
            minPrice += price * amount[price];
            amountNeeded -= amount[price];
        } else {
            minPrice += price * amountNeeded;
            amountNeeded = 0;
        }
    }
    
    fprintf(out, "%llu\n", minPrice);
    
    fclose(out);
    
    return 0;
}
