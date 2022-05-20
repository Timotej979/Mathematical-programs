#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <quadmath.h>

__float128 result = 0.0q;
__float128 pi = 1.0q;
__float128 e = 0.0q;

void piBin();
void eBin();

void piPrib();
void ePrib();


int main()
{
    int ukaz;
    int vrsta;
    int eks;

    double cleniPrib;
    double cleni;
    double alpha = 0.5;

    while(1){
        printf("\n  Za katero  stevilo naj izracunam binomsko vrsto (1 + x)^alfa:\n    -pi(1)\n    -e(2)\n    -Izhod iz programa(3)\n    ");
        scanf("%d", &ukaz);

        if(ukaz != 3){
            printf("  Koliko clenov naj uporabim za priblizek stevila pi/e:\n    ");
            scanf("%lf", &cleniPrib);

            printf("  Koliko clenov naj uporabim za binomsko vrsto:\n    ");
            scanf("%lf", &cleni);

        }

        switch(ukaz){
            case 1:
                piPrib(cleniPrib);
                piBin(cleni, alpha);
                break;
            case 2:
                ePrib(cleniPrib);
                eBin(cleni, alpha);
                break;
            case 3:
                printf("--------Hvala za uporabo programa--------");
                return 0;
        }
    }
}

void piPrib(double cleniPrib){
    char str[64];
    double i, j;
    __float128 f;

    //Vietova serija za pi
    for(i = cleniPrib; i > 1; i--){
        f = 2.0q;
        for(j = 1; j < i; j++){
            f = 2.0q + sqrtq(f);
        }
        f = sqrtq(f);
        pi = pi * f / 2.0q;
    }
    pi *= sqrtq(2.0q) / 2.0q;
    pi = 2.0q / pi;

    quadmath_snprintf(str, sizeof str, "%.34Qf", pi);

    printf("  Priblizek stevila pi po Vietovi vrsti z %g cleni je:\n", cleniPrib);
    printf("  %s\n  ------------------------------\n", str);
}

void ePrib(double cleniPrib){
    char str[64];

    //harmonic series
    double f = 1;
    for(int i = 0; i < cleniPrib; i++){
        e += 1/f;
        f *= (i + 1);
    }
    quadmath_snprintf(str, sizeof str, "%.34Qf", e);

    printf("  Priblizek stevila e po harmonicni vrsti z %g cleni je:\n", cleniPrib);
    printf("  %s\n  ------------------------------------\n", str);
}



void piBin(double cleni, double alpha){
    char str[64];
    double f = 1.0f;
    double newAlpha = alpha;
    __float128 binom = 0.0q;

    for(int k = 1; k < cleni; k++){
        //binomial series expansion for sqrt(pi) by 2*sqrt(pi/4)
        binom += newAlpha/f;

        result += binom * pow(pi/4.0, k);

        newAlpha *= (alpha - k);
        f *= (k + 1);

        binom = 0.0q;
    }
    result = 2* result + 1.0q;

    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Binomska vrsta (1 + x )^alfa z alfo %g in razvojem po x = pi je:\n", alpha);
    printf("  %s\n  ------------------------------------\n", str);

    pi = 1.0q;
    result = 0.0q;
}

void eBin(double cleni, double alpha){
    char str[64];
    double f = 1.0f;
    double newAlpha = alpha;
    __float128 binom = 0.0q;

    for(int k = 1; k < cleni; k++){
        //binomial series expansion for sqrt(e) by 2*sqrt(e/4)
        binom += newAlpha/f;

        result += binom * pow(e/4.0, k);

        newAlpha *= (alpha - k);
        f *= (k + 1);

        binom = 0.0q;
    }
    result = 2 * result + 1.0q;

    quadmath_snprintf(str, sizeof str, "%.34Qf", result);

    printf("  Binomska vrsta (1 + x)^alfa z alfo %g in razvojem po x = e je:\n", alpha);
    printf("  %s\n  ------------------------------------\n", str);

    e = 0.0q;
    result = 0.0q;
}
