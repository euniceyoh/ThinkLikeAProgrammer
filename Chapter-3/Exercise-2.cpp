/*
 Excercise 3-2:
 Rewrite the code that finds the agent with the best monthly sales average so that it finds
 the agent with the highest median sales. As stated earlier, the median of a set of values is
 the “one in the middle,” such that half of the other values are higher and half of the other
 values are lower. If there is an even number of values, the median is the simple average of
 the two values in the middle. For example, in the set 10, 6, 2, 14, 7, 9, the values in the
 middle are 7 and 9. The average of 7 and 9 is 8, so 8 is the median.

 */

#include <iostream>
using std::cin;
using std::cout;

int compareSales(const void* A, const void* B){
    int* saleA = (int*) (A);
    int* saleB = (int*) (B);
    return *saleA - *saleB;
}

double medianSale(int sales[], int ARRAY_SIZE){
    double median;
    int medianPosition = ARRAY_SIZE / 2;
    
    if(ARRAY_SIZE % 2 == 0){
        int secondPosition = medianPosition - 1;
        median = (sales[secondPosition] + sales[medianPosition]) / 2.0;
    }
    else {
        median = sales[medianPosition];
    }
    
    return median;
}

int main(int argc, const char * argv[]) {
    
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    
    //sorting each agent's monthly sales
    for(int agentSales = 0; agentSales < NUM_AGENTS; agentSales++){
        qsort(sales[agentSales], NUM_MONTHS, sizeof(int), compareSales);
    }
    
    //outputting the sorted arrays of sales
    for(int agent = 0; agent < NUM_AGENTS; agent++){
        cout << "Agent " << agent + 1 << " Monthly Sales:\n";
        
        for(int months = 0; months < NUM_MONTHS; months++){
            cout << sales[agent][months] << " ";
        }
        cout << "\n\n";
    }
    
    //testing if correct median is outputted
    for(int agent = 0; agent < NUM_AGENTS; agent++){
        double agentMedian = medianSale(sales[agent], NUM_MONTHS);
        cout << "Agent " << agent + 1 << " Median: " << agentMedian << "\n";
    }
    cout << "\n";
    
    /*
     comparing the median of each agent and
     tracking the agent with the highest median sale
     */
    double highMedian = medianSale(sales[0], NUM_MONTHS);
    int highAgent = 1;
    
    for(int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentMedian = medianSale(sales[agent], NUM_MONTHS);
        
        if(agentMedian > highMedian){
            highMedian = agentMedian;
            highAgent = agent + 1;
        }
    }
    cout << "Agent #" << highAgent << " has highest median of " << highMedian << "\n";
    
}
