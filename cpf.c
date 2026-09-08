```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
    int soma1, resto1, digito1;
    int soma2, resto2, digito2;

    printf("Informe os 11 digitos do CPF:\n");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);

    // Cálculo do primeiro dígito verificador
    soma1 = (d1 * 10) + (d2 * 9) + (d3 * 8) + (d4 * 7) + (d5 * 6) + (d6 * 5) + (d7 * 4) + (d8 * 3) + (d9 * 2);
    resto1 = (soma1 * 10) % 11;

    if (resto1 == 10) {
        digito1 = 0;
    } 
    else if (resto1 == 11) {
        digito1 = 0;
    } 
    else {
        digito1 = resto1;
    }

    // Cálculo do segundo dígito verificador
    soma2 = (d1 * 11) + (d2 * 10) + (d3 * 9) + (d4 * 8) + (d5 * 7) + (d6 * 6) + (d7 * 5) + (d8 * 4) + (d9 * 3) + (digito1 * 2);
    resto2 = (soma2 * 10) % 11;

    if (resto2 == 10) {
        digito2 = 0;
    } 
    else if (resto2 == 11) {
        digito2 = 0;
    } 
    else {
        digito2 = resto2;
    }

    // Validação final
    if (digito1 == d10) {
        if (digito2 == d11) {
            printf("CPF Valido\n");
        } 
        else {
            printf("CPF Invalido\n");
        }
    } 
    else {
        printf("CPF Invalido\n");
    }

    return 0;
}

```
