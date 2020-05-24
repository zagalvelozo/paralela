#include <stdio.h>
#include <stdlib.h>

int billetes(int sal)
{
    int resto20, aux20, resto10, aux10, resto5, aux5, resto2, aux2, resto1, aux1;
    aux20 = sal / 20000;
    resto20 = sal % 20000;

    aux10 = resto20 / 10000;
    resto10 = resto20 % 10000;

    aux5 = resto10 / 5000;
    resto5 = resto10 % 5000;

    aux2 = resto5 / 2000;
    resto2 = resto5 % 2000;

    aux1 = resto2 / 1000;
    resto1 = resto2 % 1000;

    if (resto1 != 0)
    {
        printf("no se puede retirar las monedas");
        return 0;
    }
    else
    {
        printf("se puede retirar el monto");
        return 1;
    }
}

int main()
{
    int saldo, giro, abono, fsaldo, op, a;
    printf("ingrese su saldo actual: ");
    scanf("%d", &saldo);
    printf("su saldo actual es=%d", saldo);
    printf("desea girar\n 1.SI    2.NO \n");
    scanf("%d", &op);
    if (op == 1)
    {
        printf("cuanto desea girar \n");
        scanf("%d", &giro);
        if (saldo > giro)
        {
            billetes(giro);
        }
        if (billetes(giro) == 1)
        {
            fsaldo = saldo - giro;
            printf("su saldo es: %d", fsaldo);
        }
        if (op == 2)
        {
            printf("Operación Cancelada");
        }
    }
}
