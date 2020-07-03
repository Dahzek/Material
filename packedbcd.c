//gcc 7.4.0
//Version con entero
//Desarrollado por @akuseryuinc

#include <stdio.h>

int main(void)
{
    //Declaracion de variables
    int numero = 0, copianum = 0, digito =  0, copiadigito = 0, cont_bits = 0, longitud = 0, cont = 0, contPotencia = 1, contBinario = 0, pow2 = 0, potencia = 1;
    char bcd[41];
    
    scanf("%i", &numero); //Lee el numero a transformar
    if(numero == 0){
        longitud = 1;
        goto CalcularPotencia;
    }
    
    copianum = numero; //Copia el numero, para trabajar con este
    
    CalcularLongitud:
    if(copianum != 0){
       longitud++;
       copianum/=10;
       goto CalcularLongitud;
    }
    
    copianum = numero;
    cont = longitud-1;
    
    CalcularPotencia: //Calculo x cuanto tendre que dividir para obtener el primer digito
    if(contPotencia <= cont){
        potencia *= 10;
        contPotencia++;
        goto CalcularPotencia;
    }
    
    TransformarBCD:
    if(potencia > 0){
        digito = copianum/potencia; //Consigo el primer digito
        copiadigito = digito;
        
        pow2 = 8; //Setea contBinario en 0
        contBinario = 0; //Setea contBinario en 0
        
        Binario: //Pasamos el numero a binario
        if(contBinario <= 3){
            if(digito >= pow2){
                bcd[cont_bits] = '1';
                digito -= pow2;
            }
            
            else {
                bcd[cont_bits] = '0';
            }
            
            pow2 /= 2;
            cont_bits++;
            contBinario++;
            goto Binario;
        }
        
        copianum -= copiadigito*potencia; //Elimino el primer numero
        potencia /= 10; //Calculo x cuanto tendre que dividir para obtener el primer digito
       
        goto TransformarBCD;
    }
    
    bcd[cont_bits] =  '\0'; //Añade un caracter nulo a la cadena
    
    printf("Numero: %i\n", numero);
    printf("Longitud: %i\n", longitud);
    printf("Numero expresado en BCD\n%s\n", bcd);
   
    return 0;
}
