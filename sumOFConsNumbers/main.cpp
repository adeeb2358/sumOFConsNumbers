//
//  main.cpp
//  sumOFConsNumbers
//
//  Created by adeeb mohammed on 22/02/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// program for finding sum of non consecutive numbers.

#include <iostream>
#include <vector>
#include <climits>

// more optimized solution
int findSumOfConsNumOpt(std::vector<int> inputArr){
    int maxSum = INT_MIN;
    int sumSoFar = 0;
    for(auto i:inputArr){
        sumSoFar += i;
        if(sumSoFar > maxSum){
            maxSum = sumSoFar;
        }
        if(sumSoFar < 0){
            sumSoFar = 0;
        }
    }
    return maxSum;
}

// custom solution
int findSumOfConsecutiveNumbers(std::vector<int> inputArr){
    int maxSum   = INT_MIN;
    int sumSoFar = 0;
    for(int i = 0; i < inputArr.size(); i++){
        if(sumSoFar < sumSoFar+inputArr.at(i)){
            sumSoFar += inputArr.at(i);
        }else{
            if(maxSum < sumSoFar){
                maxSum = sumSoFar;
            }
            sumSoFar = inputArr.at(i);
        }
        if(maxSum < sumSoFar){
            maxSum = sumSoFar;
        }
        
        if(sumSoFar < 0){
            sumSoFar = 0;
        }
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    std::cout << "The max Sum of consecutive array: "<<findSumOfConsecutiveNumbers({-1,-2,-3,-4,6,-1,-5,-6,0})<< std::endl;
    std::cout << "The max Sum of consecutive array Opt: "<<findSumOfConsNumOpt({-1,-2,-3,-4,6,-1,-5,-6,0})<< std::endl;
    
    return 0;
}
