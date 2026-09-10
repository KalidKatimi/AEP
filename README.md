# AEP
oi



    #include <stdio.h>
    #include <math.h>

    float calcinss(float salbruto){
        float sal2 ;

        if(salbruto <= 1412.00){
            sal2 = salbruto * 0.075;
            salbruto -= sal2; 
            return salbruto;
        }

        else if(salbruto > 1412.00 && salbruto <= 2666.68){
            salbruto *= 0.91;
            return salbruto;
        }
        else if(salbruto > 2666.68 && salbruto <= 4000.03){
            salbruto *= 0.88;
            return salbruto;
        }
        else{
            salbruto *= 0.86;
            return salbruto;

        }
    }
   

    int main(){

    float sal, sal_com_desconto;

    printf("Entre com o valor do Salario: ");
    scanf("%f", &sal);


    sal_com_desconto = calcinss(sal);


    printf("\nO valor total com o reajuste eh de: R$ %.2f",sal_com_desconto);


    return 0;

}
