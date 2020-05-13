//
//  main.cpp
//  boj2751
//
//  Created by 박세란 on 2020/05/13.
//  Copyright © 2020 박세란. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

//A: 정렬할 자료
//p: 자료의 시작 원소
//q: 자료의 중간 지점
//r: 자료의 끝 원소

vector<int> A(1000000);
vector <int> tmp(1000000);

void merge(int p, int q, int r){
    int i = p;
    int j = q+1;
    int k = p;
    

    //각각 정렬된 두 배열이 비어있지 않을 때 까지
    //두 배열의 현재 상태에서 가장 왼쪽에 있는 원소를 비교하여, 둘 중 더 작은 원소를 tmp에 넣는다.
    while(i<=q && j<=r){
        if(A[i] < A[j]){
            tmp[k++] = A[i++];
        }else{
            tmp[k++] = A[j++];
        }
    }//해당 반복문이 끝났다는 건 두 배열 중에서 tmp로의 정렬이 끝난 배열이 있다는 의미임 >> 나머지 원소가 남은 배열은 그대로 뒤에 붙이면 됨

    //한 번의 정렬에서 아래 두 반복문은 하나만 실행되게 됨 >> 그 반복문에선 나머지 원소를 tmp에 추가하는 동작을 함
    //앞 쪽 배열의 원소가 남아있는 경우
    while(i<=q){
        tmp[k++] = A[i++];
    }
    //뒷 쪽 배열의 원소가 남아있는 경우
    while(j<=r){
        tmp[k++] = A[j++];
    }

    for(int i = p; i <= r; i++){
        A[i] = tmp[i];
    }

}


void mergeSort( int p, int r)
{
    if(p < r){
        int q = (p+r)/2;
        mergeSort( p, q);
        mergeSort( q+1, r);
        merge( p, q, r);
    }

}





int main() {
    int n;
    cin >> n;
    int p = 0;
    int r = n-1;
    for(int i =0; i<= r;i++){
        cin >> A[i];
    }
    
    if(n == 1){
        cout << A[0] << "\n";
    }else{
        mergeSort(p, r);

        for(int i = p; i <= r; i++){
              cout << tmp[i] << "\n";
          }
        
    }





    return 0;
}

