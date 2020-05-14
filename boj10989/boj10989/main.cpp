//
//  main.cpp
//  boj10989
//
//  Created by 박세란 on 2020/05/13.
//  Copyright © 2020 박세란. All rights reserved.
//

//일단 메모리 제약이 8MB(8 * 2^10 * 2^10 == 약 8,000,000 Byte)
//그럼 생각을 해보면 int가(4 Byte) 약 2,000,000 개 들어갈 수 있는 메모리인데,
//문제의 입력 값 개수의 범위는 int가 10,000,000개까지 들어올 수 있다고 함
//따라서 입력 처리 자체로 메모리 초과임

//그래서 결국 int 값에 대하여, 2,000,000 개만 처리 가능함
//그 숫자를 기준으로 삼아서 처리할 방법을 찾아보면,
//10,000가 눈에 띄는데 이는 입력 값 내용의 범위임

//cin & cout이 scanf & printf 보다 많이 느리다고 함
//그래서 cstdio 넣고 scanf & printf 사용해봄

//vector랑 일반 배열이랑 뭐가 더 빠를까
//배열로 했을 때>> 2024kb    2356ms
//벡터로 했을 때>> 1984kb    2364ms
//너무 미세한 차이인데 아무튼 벡터로 하면 메모리는 절약 됨

#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

//int numlist[10001] = {0};
vector<int> numlist(10001);
int n,a,i,j;

int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        scanf("%d",&a);
        numlist[a]++;
    }
    
    for(i = 1; i <= 10000; i++){
        for(j = 0; j< numlist[i]; j++){
            printf("%i\n", i);
        }
    }
    
    
    return 0;
}
