#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <quadmath.h>

__float128 result = 0.0q;

void eksponent();
void sinus();
void cosinus();
void logarithm();


int main()
{
    int stikalo;
    int vrsta;
    int deset;

    double cleni;
    double x;


    while(1){
        printf("\n  Taylorjeva vrsta za funkcijo:\n    -e^x (1)\n    -sin(x) (2)\n    -cos(x) (3)\n    -log(1 + x) razvit v okolici stevila 0 (4)\n    -Izhod iz programa (5)\n------------------------------\n  Vpisi svojo izbiro:\n   ");
        scanf("%d", &stikalo);

        if(stikalo != 5){
            printf("  Vpisi okoli katerega x se razvije vrsta: \n   ");
            scanf("%lf", &x);


            printf("  Koliko clenov Taylorjeve vrste izracunam:\n    -10^n (1)\n    -poljubno stevilo (2)\n   ");
            scanf("%d", &vrsta);


            if(vrsta == 1){
                printf("  Vpisi eksponent 10-ke:\n   ");
                scanf("  %d", &deset);
                cleni = pow(10, deset);
            } else if(vrsta == 2){
                printf("  Vpisi poljubno stevilo clenov:\n   ");
                scanf("  %lf", &cleni);
            }
        }

        switch(stikalo){
            case 1:
                eksponent(x, cleni);
                break;
            case 2:
                sinus(x, cleni);
                break;
            case 3:
                cosinus(x, cleni);
                break;
            case 4:
                logarithm(x, cleni);
                break;
            case 5:
                printf("  Hvala za uporabo programa.");
                return 0;
        }
    }
}

void eksponent(double x, double cleni){
    double f = 1;
    char str[64];

    for(int i = 0; i < cleni; i++){
        result = result + (pow(x, i)/f);
        f *= (i + 1);
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Priblizek e^x okoli tocke %g z %g cleni je:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}

void sinus(double x, double cleni){
    double f = 1;
    char str[64];

    for(int i = 0; i < cleni; i++){
        result += pow(-1, i) * (pow(x, 2*i + 1)/(2*i + 1));
        f *= ((2*i + 3) * (2*i +2));
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Priblizek sin(x) okoli tocke %g z %g cleni je:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}

void cosinus(double x, double cleni){
    double f = 1;
    char str[64];

    for(int i = 0; i < cleni; i++){
        result += pow(-1, i) * (pow(x, 2*i)/(2*i));
        f *= ((2*i + 2)* (2*i +1));
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Priblizek cos(x) okoli tocke %g z %g cleni je:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}

void logarithm(double x, double cleni){
    char str[64];

    for(int i = 1; i <= cleni; i++){
        result += pow(-1, i+1) * (pow(x, i)/(i));
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Priblizek log(1 + x) okoli tocke %g z %g cleni je:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}
