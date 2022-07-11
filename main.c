#include <stdio.h>
#include <stdlib.h>

int validar(int ,int );
int buscar(int [],int , int );
void ordenar(int [],int [],int );

int main()
{
    int x,codigo,dia,horas,vsueldo[50]={0},vcodigo[50]={0},importetotal=0,vcodigo2[50]={0},vhoras[50]={0},vdia[28]={0},maxhorasdia,maxdia,chofernotrabajo=0,vnotrabajo[50]={0};

    printf("Ingrese codigo de chofer: ");
    codigo=validar(0,50);
    while(codigo!=0)
    {
        printf("Ingrese dia: ");
        dia=validar(1,28);
        printf("Ingrese cantidad de horas: ");
        horas=validar(0,16);
        printf("\n");

        vcodigo[codigo-1]=codigo;
        if(codigo>=1&&codigo<=15)
            vsueldo[codigo-1]+=horas*65;
        else if(codigo>=16&&codigo<=32)
            vsueldo[codigo-1]+=horas*55;
        else if(codigo>=33)
            vsueldo[codigo-1]+=horas*50;

        if(codigo>=1&&codigo<=15)
        {
            vcodigo2[codigo-1]=codigo;
            vhoras[codigo-1]+=horas;
        }

        vdia[dia-1]+=horas;

        vnotrabajo[codigo-1]+=horas;

        printf("Ingrese codigo de chofer: ");
        codigo=validar(0,50);
    }
    ordenar(vsueldo,vcodigo,50);
    printf("Codigo              Sueldo\n");
    for(x=0;x<50;x++)
    {
        if(vcodigo[x]!=0)
        printf("%d              %d\n",vcodigo[x],vsueldo[x]);//punto 1
    }

    for(x=0;x<50;x++)
    {
        importetotal+=vsueldo[x];
    }
        printf("El importe total es %d\n",importetotal);//punto 2

    ordenar(vhoras,vcodigo2,15);
    printf("El chofer que mas horas trabajo en los codigos de 1 a 15 es: %d. Este trabajo %d horas\n",vcodigo2[0],vhoras[0]);//punto 3

    maxhorasdia=vdia[0];
    for(x=0;x<28;x++)
    {
        if(vdia[x]>maxhorasdia)
        {
            maxhorasdia=vdia[x];
            maxdia=x+1;
        }

    }
    printf("El dia que mas horas se trabajo es: %d\n",maxdia);//punto 4

    for(x=0;x<50;x++)
    {
        if(vnotrabajo[x]==0)
            chofernotrabajo++;
    }
    printf("No trabajaron un total de: %d choferes",chofernotrabajo);//punto 5

    return 0;
}
int validar(int min,int max)
{
    int dato;

    do{
        scanf("%d",&dato);
    }while(dato<min||dato>max);

    return dato;
};
int buscar(int v[],int a,int cant)
{
    int pos=-1,x=0;

    while(pos==-1&&x<cant)
    {
        if(a==v[x])
            pos=x;
        else
            x++;
    }

    return pos;
};
void ordenar(int v[],int b[],int can)
{
    int x,aux,aux2,sen=0;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<can-1;x++)
        {
            if(v[x]<v[x+1])
            {
                aux=v[x];
                v[x]=v[x+1];
                v[x+1]=aux;

                aux2=b[x];
                b[x]=b[x+1];
                b[x+1]=aux2;

                sen=0;
            }
        }
        can=can-1;
    }
};
