//gcc 7.4.0
//Desarrollado por @akuseryinc

#include <stdio.h>

int main(void)
{
    //Declaracion de variables
    int numero = 0, copianum = 0, digito =  0, copiadigito = 0, cont_bits = 0, longitud = 0, cont = 0, contPotencia = 1, contBinario = 0, pow2 = 0, potencia = 1;
    char bcd[41];
    
    scanf("%i", &numero); //Lee el numero a transformar
    
    copianum = numero; //Copia el numero, para trabajar con este
    
    CalcularLongitud: //Calcula la longitud del numero ingresado
    if(copianum != 0){
       longitud++;
       copianum/=10;
       goto CalcularLongitud;
    } 
    
    copianum = numero;
    
    printf("Numero: %i\n", numero);
    printf("Longitud: %i\n", longitud);
    
    cont = longitud-1;
    
    CalcularPotencia: //Calcula x cuanto tendre que dividir para obtener el primer digito
    if(contPotencia <= cont){
        potencia *= 10;
        contPotencia++;
        goto CalcularPotencia;
    }
    
    TransformarBCD:
    //Si hay digitos por transformar, recorre el "ciclo"
    if(potencia > 0){
        digito = copianum/potencia; //Consigo el primer digito
        copiadigito = digito;
        
        pow2 = 8; //Setea pow2 en 8 (2 elevado a 3)
        contBinario = 0; //Setea contBinario en 0
        
        Binario: //Pasamos el numero a binario
        if(contBinario <= 3){
            //Si el digito es mayor a 2 elevado a X se asigna un 1 y se le resta 2^X
            if(digito >= pow2){
                bcd[cont_bits] = '1';
                digito -= pow2;
            }
            //Si no, se asigna un 0
            else {
                bcd[cont_bits] = '0';
            }
            
            pow2 /= 2; //La potencia disminuye en 1 a su exponente
            cont_bits++;
            contBinario++;

            goto Binario;
        }
        
        //Añade una separacion x nible
        bcd[cont_bits] = ' ';
        cont_bits++;
        
        copianum -= copiadigito*potencia; //Elimino el primer numero
        potencia /= 10; //Calculo x cuanto tendre que dividir para obtener el primer digito
                 
        goto TransformarBCD;
    }
    
    bcd[cont_bits] =  '\0'; //Añade un caracter nulo a la cadena
   
    printf("Numero expresado en BCD\n%s\n", bcd);
   
    return 0;
}
