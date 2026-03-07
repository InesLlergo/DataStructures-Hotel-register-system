#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
// librería GOTOXY + MARCO
#include "C:\Users\InesL\OneDrive\Documentos\ProyectoDataStructures\lib_3parcial.h"

// procedimientos
void registro(); 
void busqueda(); 
void reportes();
void baja();
void administrador(); 
void musiquita();

// arreglo: Contadores de habitación "reservada" o "libre"
int H[9]={0,0,0,0,0,0,0,0,0}, i; 

// nodo para el registro de datos + apuntadores
struct hotel
{
	char nombre[20],ciudad_origen[20], pago[10]; 
	int habitacion, num_noches, total, num_personas;
	hotel *siguiente;
};

hotel *frente=NULL;
hotel *fin=NULL;
hotel *aux=NULL;
hotel *aux2=NULL;

// variables de busqueda
int nh; 
char encargado[20];

int main ()
{
	 setlocale(LC_CTYPE,"Spanish");
	
	// PANTALLA 0 : PRESENTACION
	system("color 09");
	marco();
	gotoxy(28,8);
	printf("Estructura de Datos");
	gotoxy(28,9);
	printf("-> Tercer Examen Practico");
	gotoxy(28,11);
	printf("Isabel Espinosa Osorio");
	gotoxy(28,12);
	printf("Norma Ines Llergo Sanchez");
	gotoxy(28,13);
	printf("Mariana Varela De Ita");
	
	printf("\n");
	
	gotoxy(28,20);
	printf("De click para continuar");
	Beep(1568,400);
    
	
	
	// PANTALLA: NOMBRE DEL HOTEL + IMAGEN
	gotoxy(10,5); printf("HOTEL: TRANSYLVANIA ");
	//system("start C:\\Users\\InesL\\OneDrive\\Documentos\\ProyectoDataStructures\\HOTEL.jpeg");
	
	getch();
	system("cls");	// Limpiar pantalla
	
	//musiquita();

	// PANTALLA 1: MENU
	system("color 03");
	int opc;
	do
	{
    	gotoxy(10,4); printf("=== MENU ===\n");
        gotoxy(12,5); printf("1. Registro\n");
        gotoxy(12,6); printf("2. Busqueda\n");
        gotoxy(12,7); printf("3. Reportes\n");
        gotoxy(12,8); printf("4. Baja\n");
        gotoxy(12,9); printf("5. Administrador\n");
        gotoxy(12,11); printf("6. Salir\n");
        
        gotoxy(10,14); printf("Seleccione la opcion deseada");
        gotoxy(12,15); scanf("%d",&opc);
        
        //Limpiar pantalla
		system("cls");
		
		switch (opc)
		{
			case 1:
			{
				system("color 6F");
				registro();
				
				gotoxy(23,20); printf("De click para continuar\n");
                Beep(1568,400);
                getch(); system("cls");
				
				break;
			}
			case 2:
			{
				system("color BF");
				busqueda();
				
				gotoxy(23,20); printf("De click para continuar\n");
                Beep(1568,400);
                getch(); system("cls");
                
				break;
			}
			case 3:
			{
				reportes();
				
				getch(); system("cls");
				break;
			}
			case 4:
			{
				system("color CF");
				baja();
				
				gotoxy(23,20); printf("De click para continuar\n");
                Beep(1568,400);
                getch(); system("cls");
                
				break;
			}
			case 5:
			{
				system("color 6F");
				administrador();
                
                Beep(1568,400);
                getch(); system("cls");
                
				break;
			}
            case 6:
            {
                gotoxy(23,20); printf("\nPrograma terminado, vuelva pronto!\n");
                Beep(1568,400);
                break;
            }
            default:
                gotoxy(23,20); printf("\nIntente otra opcion\n");
		}
	}while(opc!=6);
}

void registro()
{
	// PANTALLA DE REGISTRO
    printf("\nHabitaciones: \n");
    printf("\nH1 \tH2 \tH3 \tH4 \tH5 \tH6 \tH7 \tH8 \tH9\n");
	for (i=0;i<9;i++)
    {
        printf("%d \t",H[i]); //imprimir las habitaciones disponibles e indisponibles
    }

    hotel *nn=new hotel();
    
    printf("\n\n");
    gotoxy(7,6); printf("Numero de huespedes: ");
    gotoxy(68,6); scanf("%d",&nn->num_personas);
    
    if(nn->num_personas <=0 || nn->num_personas > 6){
        gotoxy(7, 9); printf("No se acepta esa cantidad de huespedes. Intente nuevamente\n");
    }

    else if (nn->num_personas == 1) //1 huesped en la habitacion
    {
        for(i=0;i<3;i++) //habitaciones 1,2,3
        {
    		if(H[i]==0) 
        	{   
                nn->habitacion=i+1;
                gotoxy(7,7); printf("La habitacion asignada es");
                gotoxy(68,7); printf("H%d", nn->habitacion);
                
                gotoxy(7,8); printf("Nombre del encargado de habitacion: ");
                gotoxy(68,8); scanf("%s",nn->nombre);
    
                gotoxy(7,9); printf("Numero de noches: ");
                gotoxy(68,9); scanf("%d",&nn->num_noches);

                gotoxy(7,10); printf("Ciudad de origen: ");
                gotoxy(68,10); scanf("%s",&nn->ciudad_origen);

                nn->total = (1000 * nn->num_noches);

                gotoxy(7,11); printf("Forma de pago con la que desea alquilar la habitacion: ");
                gotoxy(68,11); scanf("%s",&nn->pago);

                if(frente == NULL)
                {
                    frente = nn;
                    fin = nn;
                }
                else
                {
                    fin -> siguiente = nn;
                    fin = nn;
                }

               	H[i]=1;return;

           	}
            if(H[0]==1&&H[1]==1&&H[2]==1){
                gotoxy(7,8); printf("Las habitaciones 1,2,3 no se encuentran disponibles\n"); break;
            }
        }
    }

    else if(nn->num_personas==2){
        for(i=0;i<7;i++) //habitaciones 4,5,6
        {
    		if(H[i+3]==0) 
        	{
                nn->habitacion=i+4;
                gotoxy(7,7); printf("La habitacion asignada es");
                gotoxy(68,7); printf("H%d", nn->habitacion);
                
                gotoxy(7,8); printf("Nombre del encargado de habitacion: ");
                gotoxy(68,8); scanf("%s",nn->nombre);
    
                gotoxy(7,9); printf("Numero de noches: ");
                gotoxy(68,9); scanf("%d",&nn->num_noches);

                gotoxy(7,10); printf("Ciudad de origen: ");
                gotoxy(68,10); scanf("%s",&nn->ciudad_origen);

                nn->total = (1500 * nn->num_noches);

                gotoxy(7,11); printf("Forma de pago con la que desea alquilar la habitacion: ");
                gotoxy(68,11); scanf("%s",&nn->pago);
                
                if(frente == NULL)
                {
                    frente = nn;
                    fin = nn;
                }
                else
                {
                    fin -> siguiente = nn;
                    fin = nn;
                }

               	H[i+3]=1;return;
           	}
            if(H[3]==1&&H[4]==1&&H[5]==1){
                gotoxy(7,8); printf("Las habitaciones 4,5,6 no se encuentran disponibles\n"); break;
            }
        }
    }

    else if(nn->num_personas >= 3 && nn->num_personas <= 6){
        for(i=0;i<9;i++) // habitaciones 7,8,9
        {
            if(H[i+6]==0)
            {
                nn->habitacion=i+7;
                gotoxy(7,7); printf("La habitacion asignada es");
                gotoxy(68,7); printf("H%d", nn->habitacion);
                
                gotoxy(7,8); printf("Nombre del encargado de habitacion: ");
                gotoxy(68,8); scanf("%s",nn->nombre);
    
                gotoxy(7,9); printf("Numero de noches: ");
                gotoxy(68,9); scanf("%d",&nn->num_noches);

                gotoxy(7,10); printf("Ciudad de origen: ");
                gotoxy(68,10); scanf("%s",&nn->ciudad_origen);

                nn->total = (500 * nn->num_noches);

                gotoxy(7,11); printf("Forma de pago con la que desea alquilar la habitacion: ");
                gotoxy(68,11); scanf("%s",&nn->pago);

                if(frente == NULL)
                {
                    frente = nn;
                    fin = nn;
                }
                else
                {
                    fin -> siguiente = nn;
                    fin = nn;
                }

               	H[i+6]=1; return;
            }
            if(H[6]==1&&H[7]==1&&H[8]==1){
                gotoxy(7,8); printf("\nLas habitaciones 7,8,9 no se encuentran disponibles\n"); break;
            }
        }
    }
}

// se busca por habitacion (nn->habitacion)(habitacion dentro del nuevo nodo) y por nombre (nn->nombre)(nombre dentro del nuevo nodo)
void busqueda() 
{ 
	// PANTALLA DE BUSQUEDA

    int opcionbusca;   //numero de habitacion o encargado  
    
    gotoxy(7,4); printf("Desea realizar la busqueda por:"); 
    gotoxy(7,5); printf("1. Habitacion");
    gotoxy(7,6); printf("2. Nombre");
    gotoxy(7,8); scanf("%d", &opcionbusca); 
    
    if (opcionbusca == 1) 
    {
        gotoxy(10,10); printf("Ingrese el numero de habitacion: ");
        gotoxy(48,10); scanf("%d", &nh); //nh clave para encontrar el numero de habitacion (comparemos el arreglo de habitaciones con nh como posición)
        
        aux = frente;
        while (aux != NULL)
        {
            if (aux->habitacion == nh)
            {
                gotoxy(10,13); printf("Encargado:");
                gotoxy(35,13); printf("%s", aux->nombre);
                gotoxy(10,14); printf("Numero de noches:");
                gotoxy(35,14); printf("%d", aux->num_noches);
                gotoxy(10,15); printf("Ciudad de Origen:");
                gotoxy(35,15); printf("%s", aux->ciudad_origen);
                gotoxy(10,16); printf("Total a pagar:");
                gotoxy(35,16); printf("%d", aux->total);
                gotoxy(10,17); printf("Forma de pago:");
                gotoxy(35,17); printf("%s", aux->pago);
                return;
            }
            aux = aux -> siguiente;
        }
        if(aux==NULL){
            gotoxy(10,12); printf("La habitacion %d no esta ocupada\n",nh);
        }
        printf("\n");
    }
    else if(opcionbusca==2)
    { 
        gotoxy(10,10); printf("Ingrese el nombre del encargado de la habitacion: ");
        gotoxy(68,10); scanf("%s",encargado);
        
        aux = frente;
        while (aux != NULL)
        {
            if (strcmp(aux->nombre, encargado)==0)
            {
                gotoxy(10,14); printf("Numero de noches:");
                gotoxy(35,14); printf("%d", aux->num_noches);
                gotoxy(10,15); printf("Ciudad de Origen:");
                gotoxy(35,15); printf("%s", aux->ciudad_origen);
                gotoxy(10,16); printf("Total a pagar:");
                gotoxy(35,16); printf("%d", aux->total);
                gotoxy(10,17); printf("Forma de pago:");
                gotoxy(35,17); printf("%s", aux->pago);
                return;
            }
            aux = aux -> siguiente;
        }
        if(aux==NULL){
            gotoxy(10,12); printf("El encargado %s no se encuentra en el registro\n",encargado);
        }
    }
    else
    {
        printf("\nOpcion no valida, intente de nuevo\n");
    }
    
}

void reportes()
{
   	FILE*fd;
    fd=fopen("ExamenParcial3.txt","a"); //aqui le quito los espacios porque sino se buguea el archivo
    aux=frente;
	while (aux != NULL)
    {
        //gotoxy(19,14);
    	fprintf(fd,"\nEncargado: %s", aux->nombre);
        //gotoxy(19,15);
		fprintf(fd,"\nNumero de noches: %d", aux->num_noches);
        //gotoxy(19,16);
		fprintf(fd,"\nCiudad de Origen: %s", aux->ciudad_origen);
        //gotoxy(19,17);
		fprintf(fd,"\nTotal a pagar: %d", aux->total);
        //gotoxy(19,18);
		fprintf(fd,"\nForma de pago: %s", aux->pago);
		aux=aux->siguiente;
	}
	fclose(fd);
    int c;
	fd=fopen("ExamenParcial3.txt","rt");
	while((c=fgetc(fd))!=EOF){
		putchar(c);
	}
	fclose(fd);
}

// elimina la informacion de una habitacion (nodo) y desocupa la habitacion (arreglo)
void baja()
{
	// PANTALLA DE BAJA
    int h_baja;
    
    printf("\nHabitaciones: \n");
    printf("\nH1 \tH2 \tH3 \tH4 \tH5 \tH6 \tH7 \tH8 \tH9\n");
	for (i=0;i<9;i++)
    {
        printf("%d \t",H[i]); //imprimir las habitaciones disponibles e indisponibles
    }
    
    gotoxy(7,6); printf("Ingrese el numero de habitacion que desea dar de baja: \t");
    gotoxy(68,6); scanf("%d", &h_baja);
    
    if (h_baja < 1 || h_baja > 9)
    {
        gotoxy(7,9); printf("Numero de habitacion no valido\n");
        return;
    }
    else
    {
        aux = frente;
        while (aux != NULL)
        {
            if (aux->habitacion == h_baja)
            {
                if (aux2 == NULL)
                {
                    frente = aux -> siguiente;
                }
                else
                {
                    aux2 -> siguiente = aux -> siguiente;
                }
                
                if (aux == fin)
                {
                    fin = aux2; // para actualizar el fin en caso de borrar el ultimo
                }
                delete aux;
                H[h_baja-1] = 0;
                gotoxy(7,7); printf("-> La habitacion %d se ha desocupado\n",h_baja);
                
                printf("\nHabitaciones: \n");
                printf("\nH1 \tH2 \tH3 \tH4 \tH5 \tH6 \tH7 \tH8 \tH9\n");
        	    for (i=0;i<9;i++)
        	    {
                    printf("%d \t",H[i]); //imprimir las habitaciones disponibles e indisponibles
                }
                return;
            }
            aux2 = aux;
            aux = aux->siguiente;
        }
        if(aux==NULL){
        gotoxy(7,9); printf("No es posible dar de baja una habitacion desocupada");
		}
    }
    printf("\n");
}

void administrador()
{
	int cod,counter=1;
	int pswrd=123;
	int process;
	int ascii_code = 219;
	
	// PANTALLA: SOLICITUD DE CONTRASEÑA 
	gotoxy(7,4); printf("Ingresa la contraseña\n");
	while(true){
		gotoxy(7,5); printf("Introduce la contraseña: ");
		gotoxy(45,5); scanf("%d",&cod);
		while(pswrd!=cod && counter<4){
			gotoxy(7,7); printf("-> Contraseña incorrecta, intente con otra: ");
			gotoxy(45,5); scanf("%d",&cod);
			counter++;
		}
		break;
	}
    if(counter<4){
    	gotoxy(7,7); printf("                                                            ");
		gotoxy(7,7); printf("Contraseña correcta.");
		gotoxy(7,9); printf("Cargando programa.......\n");
		for( process=0; process<=40; process++){
			Sleep(20);
			printf("%c", ascii_code);
		}
        gotoxy(7,11); printf("Carga completa! presione enter para continuar con el programa");
		getch();
		system("cls");
		
		
		// PANTALLA: BASE DE DATOS
        aux=frente;
	    int ti=0;
    	gotoxy(4, 5); printf("Informacion de clientes registrados\n");
	    while (aux != NULL)
        {
           	printf("\nEncargado: %s", aux->nombre);
            printf("\nNumero de noches: %d", aux->num_noches);
            printf("\nNumero de personas: %d", aux->num_personas);
          	printf("\nCiudad de Origen: %s", aux->ciudad_origen);
            printf("\nTotal a pagar: %d", aux->total);
            printf("\nForma de pago: %s", aux->pago);
            ti=ti+aux->total;
            aux = aux -> siguiente;
        }
        printf("\n_______________________________________\n");
        printf("\nTotal de ingresos por dia: %d\n",ti);
	}else{
		printf("\nContraseña no reconocida");
	}
    getch();
}

void musiquita()
{
    Beep(392, 400); // G
    Beep(440, 400); // A
    Beep(494, 400); // B
    Beep(440, 400); // A
    Beep(392, 400); // G
    Beep(349, 400); // F
    Beep(330, 400); // E
    Beep(349, 400); // F
}


