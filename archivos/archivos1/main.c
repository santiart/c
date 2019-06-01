#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char marca[50];
    float cilindrada;
} eAuto;

void mostrarAutos(eAuto* lista,int tam);
void mostrarAuto(eAuto* unAuto);


int main()
{
    /*
       FILE* f;
       char x;
       char cadena[]="EL UNIVERSO ES REALMENTE CONFUSO";


       f=fopen("./archivo.txt","r");


       if(f==NULL)
       {
           printf("No se pudo abrir el archivo\n");
           exit(1);
       }

       while(!feof(f))
       {
           fgets((cad,8,f));
           printf("%s",cad);
           break;
       }

       //fprintf(f,"hola %s mundo",cadena);
       fclose(f);
    */

    eAuto auto1= {1234,"ford",1.6};
    eAuto auto2= {1222,"renault",1.0};
    eAuto auto3= {5555,"peugeot",1.2};

    eAuto* lista=(eAuto*)malloc(3*sizeof(eAuto));

    *(lista) =auto1;
    *(lista+1)=auto2;
    *(lista+2)=auto3;


    //mostrarAutos(lista,3);
    int cont=0;
    int cant;
    FILE* f;
    f=fopen("./autos.dat","rb");
    if(f==NULL)
    {
        exit(1);

    }
    while(!feof(f))
    {
        fread(lista,sizeof(eAuto),1,f);

    }
    mostrarAutos(lista,3);
    //fwrite(lista,sizeof(eAuto),3,f);

    for(int i=0; i<3; i++)
    {
        cant=fwrite(lista+cont,sizeof(eAuto),1,f);
        if(cant<1)
        {
            if(feof(f)==0)
            {
                break;
            }
            else
            {
                printf("Seprodujo un erro al leer el archivo\n");
            }
            cont++;
        }
         }

        fclose(f);


        return 0;
    }
    void mostrarAutos(eAuto* lista,int tam)
    {
        if(lista!=NULL&&tam>0)
        {
            for(int i=0; i<tam; i++)
            {
                mostrarAuto(lista+i);
            }
        }


    }

    void mostrarAuto(eAuto* unAuto)
    {

        if(unAuto!=NULL)
        {
            printf("%d %s %.2f\n",unAuto->id,unAuto->marca,unAuto->cilindrada);
        }
    }
