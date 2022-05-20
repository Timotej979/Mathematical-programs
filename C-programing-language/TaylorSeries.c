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
        printf("\n  Taylor series for function:\n    -e^x (1)\n    -sin(x) (2)\n    -cos(x) (3)\n    -log(1 + x) developed around number 0 (4)\n    -Exit the program (5)\n------------------------------\n  Input your pick:\n   ");
        scanf("%d", &stikalo);

        if(stikalo != 5){
            printf("  Around which x should the series be developed: \n   ");
            scanf("%lf", &x);


            printf("  How many Taylor series parts should be calculated:\n    -10^n (1)\n    -Input a number of parts (2)\n   ");
            scanf("%d", &vrsta);


            if(vrsta == 1){
                printf("  Input exponent 10-ke:\n   ");
                scanf("  %d", &deset);
                cleni = pow(10, deset);
            } else if(vrsta == 2){
                printf("  Input a number of parts:\n   ");
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
                printf("  Thanks for using my program.");
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

    printf("  Aproximation e^x around point %g with %g part is:\n", x, cleni);
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

    printf("  Aproximation sin(x) around point %g with %g parts is:\n", x, cleni);
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

    printf("  Aproximation cos(x) around point %g with %g parts is:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}

void logarithm(double x, double cleni){
    char str[64];

    for(int i = 1; i <= cleni; i++){
        result += pow(-1, i+1) * (pow(x, i)/(i));
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Aproximation log(1 + x) around point %g with %g parts is:\n", x, cleni);
    printf("  %s\n--------------------------------------------------", str);
    result = 0.0q;
}
