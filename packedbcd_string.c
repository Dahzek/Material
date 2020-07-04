//gcc 7.4.0
//Version con string
//Desarrollado por @akuseryuinc
#include <stdio.h>

int main(void)
{
    //Declaracion de variables
    char bcd[41], numero[9];
    int  cont = 0, digito = 0, contBinario = 0, cont_bits = 0, pow2 = 0;
    
    fgets(numero, 9, stdin); //Lee el numero a transformar (solo 8 caracteres)
    
    TransformarBCD:
    //Si hay digitos por transformar, recorre el "ciclo"
    if(numero[cont] != '\0'){
        digito = numero[cont]-48; //Extraemos un digito de la string
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
            //La potencia disminuye en 1 a su exponente y pasamos al siguiente bit
            pow2 /= 2; 
            cont_bits++;
            contBinario++;

            goto Binario;
        }
        //Agregamos un espacio, para separar por Nible (medio byte)
        bcd[cont_bits] = ' '; 
        cont_bits++;
        cont++;
    
        goto TransformarBCD; //Salto a la etiqueta TransformarBCD  (Linea 14)
    }
    
    bcd[cont_bits] = '\0'; //Añadimos un null para el cierre correcto de la string
    //Mostramos los datos importantes
    printf("Numero: %s\n", numero);
    printf("Longitud: %i\n", cont);
    printf("Numero expresado en BCD\n%s\n", bcd);
   
    return 0;
}
