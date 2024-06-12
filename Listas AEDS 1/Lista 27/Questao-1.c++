#include <iostream>
#include <cstring>
#include <math.h>

#define maxCor 30

class Quadrado
{
    private:
        double lado;
        char cor[maxCor];

    public:
        void setlado(double lado)
        {
            this->lado = lado;
        }

        double getlado() 
        { 
            return this->lado; 
        }

        void setcor(char *cor)
        {
            strcpy(this->cor, cor);
        }

        char *getcor() 
        { 
            return this->cor; 
        }

        float perimetro()
        {
            return this->lado * 4;
        }

        float area()
        {
            return pow(this->lado, 2);
        }

        void leia()
        {
            double lado;
            char cor[maxCor];
            printf("\nLado: ");
            scanf("%lf", &lado);
            printf("\nCor: ");
            fflush(stdin);
            fgets(cor, maxCor, stdin);
            
                setlado(lado);
                setcor(cor);      
        }

        void escreva()
        {
            printf("\nLado: %.2lf", getlado());
            printf("\nCor: %s", getcor());
            printf("\nPerimetro: %.2lf", perimetro());
            printf("\nArea: %.2lf", area());
        }

};

int main()
{
    Quadrado *quadrado;
    quadrado = new Quadrado;
    quadrado->leia();
    quadrado->escreva();

}