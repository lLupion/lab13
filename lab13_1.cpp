#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
    double sum=0,sum_SD=0;
    int i =0;
    while(i<N){
        sum += A[i];
        i++;
    }
    B[0]=sum/N;
    int a =0;
    while(a<N){
        sum_SD+=pow(A[a],2);
        a++;
    }
    B[1]=sqrt((sum_SD/N)-((sum/N)*(sum/N)));

    double pro=1;
    int b=0;
    while(b<N){
        pro *= A[b];
        b++;
    }
    B[2]=pow(pro,(1.0/N));
    double sum_HM=0;
    int c=0;
    while(c<N){
        sum_HM += 1/A[c];
        c++;
    }
    B[3]= N/sum_HM;
    double max = A[0], min = A[0];
    for (int f = 0; f < N; f++) {
        if (A[f] > max) max = A[f];
        if (A[f] < min) min = A[f];
    }
    B[4] = max;
    B[5] = min;

}