#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <quadmath.h>

//Calculate -1/12
__float128 definedSum = 0.0833333333333333333333333333333333q;

//Calculate aproximation ax^2 + bx + c, result in
__float128 leastSquaresA = 0.0q;
__float128 leastSquaresB = 0.0q;
__float128 leastSquaresC = 0.0q;

//Error calculation
__float128 deltaLS = 0.0q;

//static arrays defined globaly for x and y for maximum size possible
static __float128 x[100000000000000];
static __float128 y[100000000000000];

//linear regresion + least square aproximation
void LS();


int main(){
    long long cleni;
    //char arrays for 128-bit results
    char strDS[64];

    char strLS[64];
    char strDLS[64];


    while(1){
        printf("\n  Koliko naravnih stevil sestejem za aproksimacijo vsote (nic = IZHOD):\n       ");
        scanf("%Ld", &cleni);
        printf("\n ------------------------------------------------------------------------------------------------------------------------------------------");

        if(cleni != 0){

            //aproximation functions
            LS(cleni);


            deltaLS = fabsq(leastSquaresC - definedSum);


            quadmath_snprintf(strDS, sizeof strDS, "%.34Qf", definedSum);

            quadmath_snprintf(strLS, sizeof strLS, "%.34Qf", leastSquaresC);

            quadmath_snprintf(strDLS, sizeof strDLS, "%.34Qf", deltaLS);


            printf("  Definirana vsota naravnih stevil je:\n");
            printf("    %s\n ------------------------------------------------------------------------------------------------------------------------------------------\n", strDS);

            printf("  Izracunana vsota naravnih stevil s %lli cleni preko kvadratne aproksimacije je:\n", cleni);
            printf("    %s\n ------------------------------------------------------------------------------------------------------------------------------------------\n", strLS);

            printf("  Razlika med aproksimativno vrednostjo kvadratne funkcije v x=0 in definirano vsoto je:\n");
            printf("    %s\n ------------------------------------------------------------------------------------------------------------------------------------------\n", strDLS);

            leastSquaresA = 0.0q;
            leastSquaresB = 0.0q;
            leastSquaresC = 0.0q;

            deltaLS = 0.0q;

        } else{
            printf("Hvala za uporabo programa");
            return 0;
        }
    }
}

void LS(long long cleni){
    char strA[64];
    char strB[64];
    char strC[64];

    long long i, j;
    __float128 sumX = 0.0q, sumX2 = 0.0q, sumX3 = 0.0q, sumX4 = 0.0q, sumY = 0.0q, sumXY = 0.0q, sumX2Y = 0.0q;


    //Point generation partial sum of natural numbers
    for(i = 0; i < cleni; i++){
        x[i] = i + 1;
        y[i] = x[i] * (x[i] + 1) / 2;
    }

    for(j = 0; j < cleni; j++){
        sumX += x[j];
        sumX2 += x[j] * x[j];
        sumX3 += x[j] * x[j] * x[j];
        sumX4 += x[j] * x[j] * x[j] * x[j];
        sumY += y[j];
        sumXY += x[j] * y[j];
        sumX2Y += x[j] * x[j] * y[j];
    }

    //System of equations:
    //y = a + bx + cx^2
    //x*y = ax + bx^2 + cx^3
    //y*x^2 = ax^2 + bx^3 + cx^4
    //Solve for a, b, c by Cramar rule to calculate D, D(a) and D(b)
    //a = D(a)/D
    //b = D(b)/D
    //c = D(c)/D
    //Reordered equations(solved 3x3 determinants)
    leastSquaresA += (sumX2Y*(sumX2*cleni - sumX*sumX) - sumXY*(sumX3*cleni - sumX*sumX2) + sumY*(sumX3*sumX - sumX2*sumX2))/(sumX4*(sumX2*cleni - sumX*sumX) - sumX3*(sumX3*cleni - sumX*sumX2) + sumX2*(sumX3*sumX - sumX2*sumX2));
    leastSquaresB += (sumX4*(sumXY*cleni - sumY*sumX) - sumX3*(sumX2Y*cleni - sumY*sumX2) + sumX2*(sumX2Y*sumX - sumXY*sumX2))/(sumX4*(sumX2*cleni - sumX*sumX) - sumX3*(sumX3*cleni - sumX*sumX2) + sumX2*(sumX3*sumX - sumX2*sumX2));
    leastSquaresC += (sumX4*(sumX2*sumY - sumX*sumXY) - sumX3*(sumX3*sumY - sumX*sumX2Y) + sumX2*(sumX3*sumXY - sumX2*sumX2Y))/(sumX4*(sumX2*cleni - sumX*sumX) - sumX3*(sumX3*cleni - sumX*sumX2) + sumX2*(sumX3*sumX - sumX2*sumX2));

    quadmath_snprintf(strA, sizeof strA, "%.34Qf", leastSquaresA);
    quadmath_snprintf(strB, sizeof strB, "%.34Qf", leastSquaresB);
    quadmath_snprintf(strC, sizeof strC, "%.34Qf", leastSquaresC);

    printf("\n  Enacba za kvadratno aproksimacijo je:\n");
    printf("    y = %s X^2 + %s X + %s\n ------------------------------------------------------------------------------------------------------------------------------------------\n", strA, strB, strC);
}
