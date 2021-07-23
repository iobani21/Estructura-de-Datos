#include<stdlib.h>
#include <stdio.h>
#include<string.h>
typedef struct Capsula
{
	char nom[20];
	char app[20];
	char apm[20];
	int edad ;
}Capsula;

typedef struct elCola
 {
 	Capsula capsula;
 	struct elCola *siguiente;
 }eCola;

typedef struct cola
{
	struct elCola *Frente;
	struct elCola *Final_Fan;
	int tamanio;
}Cola;

typedef struct elementoPila
{
  Cola cola;
  struct elementoPila *siguiente;
}ePila;

typedef struct Pila
{
  struct elementoPila *tope;
  int size;
}Pila;


typedef struct elementoLista
 {
 	Pila pila;
 	struct elementoLista *siguiente;
 	
 }eLista;

typedef struct Lista 
{
	int size;
	struct elementoLista *inicio;
}Lista;


void BorrarPantalla()
{
 	system("clear");	
}

int SubDesbordamiento(ePila *tope)
{
	if(tope!=NULL)
	{
		return 1;
	}

 return 0;
}

Capsula Rellenar()
{
	Capsula p;
	printf("Ingresa el nombre del Humano\n");
	scanf("%s",(p.nom));
	printf("Ingresa el apellido materno del humano\n");
	scanf("%s",p.app);
	printf("Ingresa el apellido paterno del humano\n");
	scanf("%s",p.apm);
	printf("Ingresa la edad del Humano\n");
	scanf("%i",&p.edad);
	return p;

}
int InsertarECola(eCola **Inicio, eCola **Final_Fan, Capsula cap,int tamanio)
{
	if(tamanio==0)
	{
		eCola *nuevo=(eCola*) malloc(sizeof(eCola));
		nuevo->capsula=cap;
		nuevo->siguiente=nuevo;	
		(*Inicio)=nuevo;
		(*Final_Fan)=nuevo;
		return 1;
	}
	else
	{
		if((*Inicio)==(*Final_Fan))
		{
			if((*Inicio)->capsula.edad>cap.edad)
			{
			 eCola *nuevo=(eCola*) malloc(sizeof(eCola));
			 nuevo->capsula=cap;
			 nuevo->siguiente=(*Inicio);
			 (*Inicio)=nuevo;
			 (*Final_Fan)->siguiente=nuevo;
			 return 1;
			}
			else
			{
			 eCola *nuevo=(eCola*) malloc(sizeof(eCola));
			 nuevo->capsula=cap;
			 nuevo->siguiente=(*Inicio);
			 (*Inicio)->siguiente=nuevo;
			 (*Final_Fan)=nuevo;
			 return 1;
			}
	 	}
	 	else
	 	{
	 		if((*Inicio)->capsula.edad>cap.edad && (*Final_Fan)->siguiente==(*Inicio))
	 		{
	 		 eCola *nuevo=(eCola*) malloc(sizeof(eCola));
			 nuevo->capsula=cap;
			 nuevo->siguiente=(*Inicio);
			 (*Final_Fan)->siguiente=nuevo;
			 (*Inicio)=nuevo;
			 return 1;
	 		}
	 		else
	 		{
	 			if((*Inicio)->capsula.edad<cap.edad && (*Final_Fan)->siguiente==(*Inicio))
	 			{
	 				if((*Inicio)->siguiente->capsula.edad>cap.edad)
	 				{
	 				 	eCola *nuevo=(eCola*) malloc(sizeof(eCola));
						nuevo->capsula=cap;
						nuevo->siguiente=(*Inicio)->siguiente;
						(*Inicio)->siguiente=nuevo;
						return 1;	
	 				}
	 				else
	 				{
	 				return InsertarECola(&(*Inicio)->siguiente,&(*Final_Fan),cap,tamanio);
	 				}
	 			}
	 			else
	 			{
	 				if((*Inicio)->capsula.edad>cap.edad)
	 				{
	 				 	eCola *nuevo=(eCola*) malloc(sizeof(eCola));
						nuevo->capsula=cap;
						nuevo->siguiente=(*Inicio);
						(*Inicio)=nuevo;
						return 1;
	 				}
	 				else
	 				{
	 					return InsertarECola(&(*Inicio)->siguiente,&(*Final_Fan),cap,tamanio);
	 				}
	 			}
	 		}
		}
 	}
	return 0;
}
void RecorrerCola(eCola *Inicio,eCola *Final_Fan,eCola *reccorer,int contador)
{
	if(reccorer!=Final_Fan)
	{
	printf("Capsula #%i |NOMBRE:%s |APPELLIDO PAT:%s |APPELLIDO :%s | EDAD:%i \n",contador,reccorer->capsula.nom,reccorer->capsula.app,reccorer->capsula.apm,reccorer->capsula.edad);
	contador++;
	RecorrerCola(Inicio,Final_Fan,reccorer->siguiente,contador);
	return;
	}
	if(reccorer==Final_Fan)
	{
		printf("Capsula #%i |NOMBRE:%s |APPELLIDO PAT:%s |APPELLIDO :%s | EDAD:%i \n",contador,reccorer->capsula.nom,reccorer->capsula.app,reccorer->capsula.apm,reccorer->capsula.edad);
		return;
	}
	return;  
}

int BuscarHumano(eCola *Inicio,eCola *Final_Fan,eCola *recorrer,int contador,int num)
{
	if(recorrer!=Final_Fan)
	{
		if(contador==num)
		{
			return contador;
		}
		else
		{
			contador++;
			 return BuscarHumano(Inicio,Final_Fan,recorrer->siguiente,contador,num);
		}		
	}
	if(recorrer==Final_Fan)
	{
		if(contador==num)
		{
			return contador;
		}
		else
		{
			printf("No se encontro Humano en la cola \n");
			return -1;
		}
	}
	return -1;
}
int EliminarECola(eCola **Inicio,eCola **Final_Fan,int num,int contador,int band)
 {
 eCola *aux;
 	if(band==0)
 	{
		if((*Inicio)!=(*Final_Fan))
		{
		(*Final_Fan)->siguiente=(*Inicio)->siguiente;
		(*Inicio)=(*Inicio)->siguiente;
		return 1;
		}
		else
		{
			if((*Inicio)==(*Final_Fan))
			{
				free((*Final_Fan));
				free((*Inicio));
				(*Final_Fan)=NULL;
				(*Inicio)=NULL;
				return 1;
			}
		}
 	}
 	if(band==1)
 	{
		if(num==contador)
		{
			(*Inicio)->siguiente=(*Final_Fan)->siguiente;
			(*Final_Fan)=(*Inicio);
			return 1;
		}
		else
		{
			if(num!=contador)
			{
				contador++;
				return	EliminarECola(&(*Inicio)->siguiente,&(*Final_Fan),num,contador,1);
			}
		}	
 	}
 	if(band==2)
 	{
		if(num==contador)
		{
			(*Inicio)->siguiente=(*Inicio)->siguiente->siguiente;
			return 1;
		}
		else
		{
			if(num!=contador)
			{
				contador ++;
				return	EliminarECola(&(*Inicio)->siguiente,&(*Final_Fan),num,contador,2);
			}
		}
 	}
 return 0;
}


ePila* pop(ePila **tope)
{

	ePila *aux =(*tope);
	(*tope)=(*tope)->siguiente;
	aux->siguiente=NULL;
	return aux;
}

int push(ePila **tope)
{
	
	Capsula cap;	
	ePila *nuevo=(ePila*) malloc(sizeof(ePila));	
	if(!nuevo)
	{
		printf("Desbordamiento de pila \n");
		return 0;
	}		
 	nuevo->cola.tamanio=0;
 	nuevo->cola.Frente=NULL;
 	nuevo->cola.Final_Fan=NULL;
	nuevo->siguiente=(*tope);
	(*tope)=nuevo;
	return 1;
}

void pushTemp(ePila **tope, ePila *temp)
{
	ePila *nuevo=(ePila*) malloc(sizeof(ePila));	
	nuevo->cola=temp->cola;
	nuevo->siguiente=(*tope);
	(*tope)=nuevo;
	return ;
}

void ModificarCola(eCola **Inicio,eCola **Final_Fan,char nom[],char app[],char apm[],int contador,int size)
{
	int x;
	char opc ='s';
	if(contador<=size)
	{
	if (strcmp((*Inicio)->capsula.nom,nom) == 0 && strcmp((*Inicio)->capsula.app,app) == 0 && strcmp((*Inicio)->capsula.apm,apm) == 0)
	{

			while(opc=='s')
 		{

		printf("Humano Encontrado:\n");
		printf("1.-Modificar Nombre\n");
		printf("2.-Modificar Apellido Paterno\n");
		printf("3.-Modificar Apellido Materno\n");
		printf("4.-Salir\n");
		scanf("%i",&x);
		switch(x)
		{
			case 1:
			printf("Ingresa el nuevo nombre\n");
			scanf("%s",(*Inicio)->capsula.nom);
			break;
			case 2 :
			printf("Ingresa el nuevo apellido paterno\n");
			scanf("%s",(*Inicio)->capsula.app);
			break;
			case 3 :
			printf("Ingresa el nuevo apellido materno\n");
			scanf("%s",(*Inicio)->capsula.apm);
			break;
			case 4:
			return;
			break;

		}
		}
	}
	else
	{
		contador++;
		ModificarCola(&(*Inicio),&(*Final_Fan),nom,app,apm,contador,size);
		return;
	}
	}
	else
	{
		printf("HUMANO NO ENCONTRADO\n");
		return;
	}

}

int LiberarCola(eCola **Inicio,eCola **Final_Fan,char nom[],char app[],char apm[],int size,int band)
{

	eCola *aux;
 if(size==1)
 {

 	if (strcmp((*Inicio)->capsula.nom,nom) == 0 && strcmp((*Inicio)->capsula.app,app) == 0 && strcmp((*Inicio)->capsula.apm,apm) == 0)
 	{
 		
 			free((*Final_Fan));
			free((*Inicio));
				(*Final_Fan)=NULL;
				(*Inicio)=NULL;
				printf("Capsula Liberada\n");
 		return 1;
 	}
 	else
 	{
 		
 		return 0;		
 	}
 }
 else

 	if(size==2)
 	{
	 if (strcmp((*Inicio)->capsula.nom,nom) == 0 && strcmp((*Inicio)->capsula.app,app) == 0 && strcmp((*Inicio)->capsula.apm,apm) == 0)
	  	{
	  		aux=(*Inicio);
	  		(*Inicio)=(*Final_Fan);
	  		(*Final_Fan)->siguiente=(*Final_Fan);
	  		free(aux);
	  		printf("Capsula Liberada\n");
	  		return 1;
	  	}
	  	else
	  	{
	  	if (strcmp((*Inicio)->siguiente->capsula.nom,nom) == 0 && strcmp((*Inicio)->siguiente->capsula.app,app) == 0 && strcmp((*Inicio)->siguiente->capsula.apm,apm) == 0)
	  	{
	  		aux=(*Final_Fan);
	  		(*Final_Fan)=(*Inicio);
	  		(*Inicio)->siguiente=(*Inicio);
	  		free(aux);
	  		printf("Capsula Liberada\n");
	  		return 1;
	  	}
	  	else
	  	{
	  	
	  		return 0;
	  	}
	  	}	
 	}
 	else
 	{
 	 if(size>2)
 	 {
 	 	if(band==0)
 	 	{
 	 		if (strcmp((*Inicio)->capsula.nom,nom) == 0 && strcmp((*Inicio)->capsula.app,app) == 0 && strcmp((*Inicio)->capsula.apm,apm) == 0)
 	 		{
 	 			aux=(*Inicio);
 	 			(*Inicio)=(*Inicio)->siguiente;
 	 			(*Final_Fan)->siguiente=(*Inicio);
 	 			free(aux);
 	 			printf("Capsula Liberada\n");
 	 			return 1;
 	 		}
 	 	if (strcmp((*Inicio)->siguiente->capsula.nom,nom) == 0 && strcmp((*Inicio)->siguiente->capsula.app,app) == 0 && strcmp((*Inicio)->siguiente->capsula.apm,apm) == 0)
 	 		{
 	 			aux=(*Inicio)->siguiente;
 	 			(*Inicio)->siguiente=(*Inicio)->siguiente->siguiente;
 	 			free(aux);
 	 			printf("Capsula Liberada\n");
 	 			return 1;
 	 		}
 	 		else
 	 		{
 	 			return LiberarCola(&(*Inicio)->siguiente,&(*Final_Fan),nom,app,apm,size,1);
 	 		}
 	 	}
 	 	else
 	 	{
 	 		if(band==1)
 	 		{
 	 		if (strcmp((*Inicio)->siguiente->capsula.nom,nom) == 0 && strcmp((*Inicio)->siguiente->capsula.app,app) == 0 && strcmp((*Inicio)->siguiente->capsula.apm,apm) == 0)
 	 		{
 	 			if((*Inicio)->siguiente==(*Final_Fan))
 	 			{
 	 				aux=(*Inicio)->siguiente;
 	 				(*Inicio)->siguiente=((*Final_Fan)->siguiente);
 	 				(*Final_Fan)=(*Inicio);
 	 				free(aux);
 	 				printf("Capsula Liberada\n");
 	 				return 1;
 	 			}
 	 			else
 	 			{   aux=(*Inicio)->siguiente;
 	 				(*Inicio)->siguiente=(*Inicio)->siguiente->siguiente;
 	 				free(aux);

 	 				printf("Capsula Liberada\n");
 	 				return 1;
 	 			}
 	 		}
 	 		else
 	 		{
 	 			if((*Inicio)->siguiente!=(*Final_Fan))
 	 			{
 	 				return LiberarCola(&(*Inicio)->siguiente,&(*Final_Fan),nom,app,apm,size,1);
 	 			}
 	 			else
 	 			{
 	 		
 	 				return 0;
 	 			}		
 	 		}
 	 		}
 	 	}
 	 }
 	}
 
return 0;
}

void MenuCola(Cola *cola)
{
	Capsula  cap;
	int posicion;
	char opc ='s';
	int num;
	char nom[20];
	char app[20];
	char apm[20];
 	int x;
 	int y;
 	int z;
 	int sum;
	while(opc=='s')
 	{

 		if((cola)->Frente==NULL)
 		{
 		
 		  (cola)->tamanio=0;
 		  (cola)->Frente=NULL;
 		  (cola)->Final_Fan=NULL;	
 		}
 		printf("__________________________________________\n");
 		printf("|MENU DE GRUPOS ROTATORIOS\n");
 	    printf("__________________________________________\n");
		printf("1.-Agregar Humano \n");
		printf("2.-Ver Capsulas \n");
		printf("3.-Liberar Humano\n");
		printf("4.-Numero de Humanos en Cola Rotatoria\n");
		printf("5.-Modificar Datos de Humano\n");
		printf("6.-Salir\n");
		scanf("%i",&x);
		BorrarPantalla();
		printf("__________________________________________\n");
		printf("               RESULTADOS\n");
		printf("__________________________________________\n");
		switch(x)
		{
			case 1:
			 cap=Rellenar();	
    	 	 (cola)->tamanio=(cola)->tamanio+InsertarECola(&((cola)->Frente),&((cola)->Final_Fan),cap,(cola)->tamanio);	
    	 	break;
    	 	case 2:
    	 	 if((cola)->Frente!=NULL && (cola)->Final_Fan!=NULL)
    	 	 {
    	 		RecorrerCola(((cola)->Frente),((cola)->Final_Fan),((cola)->Frente),1);
    	 	 }
    	 	 else
    	 		printf("Cola Vacia\n");
    	 	break;
    	 	case 3:
    	 	 printf("Ingresa la Capsula a Eliminar \n");
    	 	 scanf("%i",&num);
    	 	 posicion=BuscarHumano((cola)->Frente,(cola)->Final_Fan,(cola)->Frente,1,num);
    	 	 if(posicion!=-1)
    	 		{
    	 		 if(posicion==1)
    	 		 {
    	      		(cola)->tamanio=(cola)->tamanio-EliminarECola(&((cola)->Frente),&((cola)->Final_Fan),posicion,1,0);
    	 		 }
    	 		 else
    	 		 {
    	 			if(BuscarHumano((cola)->Frente,(cola)->Final_Fan,(cola)->Frente,1,num)==(cola)->tamanio)	
    	 			{
    	 			 posicion--;
    	 			 (cola)->tamanio=(cola)->tamanio-EliminarECola(&((cola)->Frente),&((cola)->Final_Fan),posicion,1,1);	
    	 			}
    	 			else
    	 			{
    	 			 posicion--;
    	 			 (cola)->tamanio=(cola)->tamanio-EliminarECola(&((cola)->Frente),&((cola)->Final_Fan),posicion,1,2);		
		    	 	}
    	 		 }
    	 		 if((cola)->tamanio==0)
    	 		 {
    	 		 	printf("Grupo Rotatorio se Elimino\n");
	     		 	(cola)->Frente=NULL;
 		  		 	(cola)->Final_Fan=NULL;
    	 		 }
    	 	 }	
    	 	break;
    	 	case 4:
    	 	 printf("Numero de Capsulas #%i \n",(cola)->tamanio );
    	 	break;
    	 	case 5:
    	 	printf("Ingresa el Nombre\n");
    	 	scanf("%s",nom);
    	 	printf("Ingresa el app\n");
    	 	scanf("%s",app);
    	 	printf("Ingresa el apm\n");
    	 	scanf("%s",apm);
    	 	ModificarCola(&(cola)->Frente,&(cola)->Final_Fan,nom,app,apm,1,cola->tamanio);
    	 	break;
    	 	case 6:
    	 	return;
    	 	break;
    	}	
	}
	return;
}

void BuscarPila(ePila **tope,int npila, int contador,ePila **temp,int band)
{
	ePila *puntero;
 	if(contador==npila )
 	{
		if(band==1)
		{
		 MenuCola(&((*tope)->cola));
		 band=2;
		 BuscarPila(&(*tope),npila,contador,&(*temp),band);
		 return;
		}
		else
		{
			if(band==2)
			{
				if((*temp)!=NULL)
				{
				 puntero=pop(&(*temp));
				 pushTemp((&(*tope)),puntero);
				 if((*temp)!=NULL)
					{
					 BuscarPila(&(*tope),npila,contador,&(*temp),band);
					 return;
					}
					else
					{
					 printf("Modificacion exitosa\n");
					 return;
					}
				}
			}
		}
 	}
 else
 {
	if(contador<npila)
	{
		puntero=pop(&(*tope));
		pushTemp((&(*temp)),puntero);
		contador++;
		BuscarPila(&(*tope),npila,contador,&(*temp),band);
		return;
	}
 }
 return;
}


int EliminarPila(ePila **tope,int npila, int contador,ePila **temp,int band,int size)
{
	
 ePila *puntero;
 	if(size==1 && npila==0)
 	{
 	 free((*tope));
 	 (*tope)==NULL;
 	 return 1;
 	}
 	else
 	{
 		if(npila+1==1)
 		{
 	 	 puntero=(*tope);
		 (*tope)=(*tope)->siguiente;
	 	 free(puntero);
	 	 return 1;
 		}
 		else
 		{
 		 if(contador==npila )
 			{
			 	if(band==1)
			 	{
					if((npila+1)==size)
					{
	 				 puntero=(*tope)->siguiente;
	 				 (*tope)->siguiente=NULL;	
	 				 free(puntero);
					}
					else
					{
	  				 puntero=(*tope)->siguiente;
	 				 (*tope)->siguiente=(*tope)->siguiente->siguiente;
	  				 free(puntero);
					}	
			        band=2;
					return EliminarPila(&(*tope),npila,contador,&(*temp),band,size);
				}	
			else
			{
				if(band==2)
				{
					if((*temp)!=NULL)
					{
					 puntero=pop(&(*temp));
					 pushTemp((&(*tope)),puntero);
					 	if((*temp)!=NULL)
						{
				 		 return EliminarPila(&(*tope),npila,contador,&(*temp),band,size);
						}
						else
						{
							if((*temp)==NULL)
							{
							 printf("Eliminacion exitosa\n");
							 return 1;
							}
						}
					}
				}
			}
 		}
     else
 	 {
		if(contador<npila)
		{
			puntero=pop(&(*tope));
			pushTemp((&(*temp)),puntero);
			contador++;
			return EliminarPila(&(*tope),npila,contador,&(*temp),band,size);
		}
 	 }
    }
 }
 return 1;
}


int LiberarPila(ePila **tope,ePila **temp,int band,char nom[],char app[],char apm[],int band2)
{
 ePila *puntero;
 int x;
 if(band == 0)
 {

 	x=LiberarCola(&(*tope)->cola.Frente,&(*tope)->cola.Final_Fan,nom,app,apm,(*tope)->cola.tamanio,0);
 	if(x==1)
 	{
 		(*tope)->cola.tamanio=(*tope)->cola.tamanio-x;
 		return LiberarPila(&(*tope),&(*temp),1,nom,app,apm,1);
 	}
 	else
 	{		
 		    puntero=pop(&(*tope));
			pushTemp((&(*temp)),puntero);
			if((*tope)!=NULL)
			{
			return LiberarPila(&(*tope),&(*temp),0,nom,app,apm,0);
 			}
 			else
 			{
 			return LiberarPila(&(*tope),&(*temp),1,nom,app,apm,0);
 			}
 	}
 }

 if(band==1)
 {
 	if((*temp)!=NULL)
					{
					 puntero=pop(&(*temp));
					 pushTemp((&(*tope)),puntero);
					 	if((*temp)!=NULL)
						{
				 		return LiberarPila(&(*tope),&(*temp),1,nom,app,apm,band2);
						}
						else
						{
							if((*temp)==NULL)
							{
							
							 return band2;
							}
						}
					}
 }
 return 0;
}



int LiberarLista (eLista **Inicio,char nom[],char app[],char apm[])
{
int x;
 	Pila *temp=(Pila*) malloc(sizeof(Pila));
 	temp->tope=NULL;
 	temp->size=0;	
	if((*Inicio)->pila.size>0)
	{
	 x=LiberarPila(&(*Inicio)->pila.tope,&(temp)->tope,0,nom,app,apm,0);
		if(x==1)
		{
			return 1;	
		}	
		else
		{	
			if((*Inicio)->siguiente!=NULL)
			{
				return LiberarLista(&(*Inicio)->siguiente,nom,app,apm);
			}
			else
			{
	    		printf("Capsula No Encontrada\n");
				return 0;
			}
		}
	}
	else
	{
 		if((*Inicio)->siguiente!=NULL)
  		{
  			return LiberarLista(&(*Inicio)->siguiente,nom,app,apm);
 		}
  		else
  		{
  			printf("Capsula No Encontrada\n");
  			return 0;
  		}	
	}
 return 0;
}


void RecorrerPila(ePila *tope,int c)
{	
	printf("-->Pila #%i ---\n",c);
	if(tope->cola.Frente!=NULL)
	{
    	RecorrerCola((tope->cola.Frente),(tope->cola.Final_Fan),(tope->cola.Frente),1);
	}
	else
	{
		printf("Pila Vacia\n");
	}

	if(tope->siguiente!=NULL)
	{
		c++;
		RecorrerPila(tope->siguiente,c);
	}
 return;
}


int InsertarLista(eLista **inicio)
{
	eLista *nuevo=(eLista*) malloc(sizeof(eLista));
	if(!nuevo)
	{
		printf("Desbordamiento de lista\n");
		return 0;
	}
	  	nuevo->pila.size=0;
	  	nuevo->pila.tope=NULL;

	 nuevo->siguiente=(*inicio);
	 (*inicio)=nuevo;
	 nuevo->pila.tope=NULL;
	 return 1;
}


void MenuPila(Pila *pila)
{

	Capsula  cap;
	int posicion;
	char opc ='s';
	int num;
	char nom[20];
	char app[20];
	char apm[20];
 	int x;
 	int y;
 	int z;
 	Pila *temp=(Pila*) malloc(sizeof(Pila));
 	temp->tope=NULL;
 	temp->size=0;
 	int sum;
 	int pilaopcion;
	while(opc=='s')
 	{

 		if((pila)->tope==NULL)
 		{
 		
 		  (pila)->size=0;
 		  (pila)->tope=NULL;
 		  temp->tope=NULL;
 		}
 		printf("__________________________________________\n");
 		printf("MENU DE PILAS \n");
 	    printf("__________________________________________\n");
		printf("1.-Agregar Pila\n");
		printf("2.-Recorrer  Pilas \n");
		printf("3.-Entrar a Pila \n");
		printf("4.-Eliminar Nodo Pila \n");
		printf("5.-Salir\n");
		scanf("%i",&x);
		BorrarPantalla();
		printf("__________________________________________\n");
		printf("               RESULTADOS\n");
		printf("__________________________________________\n");
		switch(x)
		{
			case 1:
    		 sum=pila->size+push(&(pila->tope));
    		 pila->size=sum;
    		 printf("Numero Nodos Pilas # %i \n",pila->size );
    		break;

			case 2:
			 z=SubDesbordamiento(pila->tope);
    			if(z==1)
    			{
    			 RecorrerPila(pila->tope,1);	
    			}
    			else 
    			 printf("Grupo Rotatorio Vacio\n");
    		break;


			case 3:
			if(pila->size>0)
			{
		 	 printf("Ingresa la Pila que quieres abrir\n");
			 scanf("%i",&pilaopcion);
			 if(pilaopcion<=pila->size)
			 {
			  BuscarPila(&(pila->tope),pilaopcion,1,&(temp->tope),1);
			 }
			 else
			 {
			 	printf("Numero de Nodos Pila es %i,ingresa un numero igual o menor \n",pila->size );
			 }

					
			}
			else
			{
				printf("Pila Vacio\n");
			}
			break;
			
    		case 4:
    			if(pila!=NULL)
				{
				 printf("Ingresa el numero de Pila que quieres eliminar\n");
				 scanf("%i",&pilaopcion);
					if(pilaopcion<=pila->size)
					{
					 pilaopcion=pilaopcion-1;
					 sum=pila->size-EliminarPila(&(pila->tope),pilaopcion,1,&(temp->tope),1,pila->size);	
					 pila->size=sum;
					}
				 else
				 {
					printf("Error Pila no Encontrada \n");
				 }
				}
    		break;
    		
    		case 5:
    		return;
    		break;
			}
			if(pila->size==0)
			{
		  	 (pila)->tope=NULL;	
		     temp->tope=NULL;
			}
		}
	return ;
}


void RecorrerLista(eLista *inicio,int c)
{
	if(inicio!=NULL)
	{
		printf("---Bateria  #%i --- \n",c);
	if((inicio)->pila.tope!=NULL)
	{	
		RecorrerPila((inicio)->pila.tope,1);
	}
	else
	{
		printf("Bateria Vacia\n");
	}

	if(inicio->siguiente!=NULL)
	{
		c++;
		RecorrerLista(inicio->siguiente,c);
		return;
	}
	}
	else
	{
		printf("Bateria Vacia\n");
	}
	return;
}

void BuscarLista(eLista **Inicio,int opc,int contador)
{
	if((*Inicio)==NULL)
	{
		printf("Bateria Vacia\n");
		return ;
	}
	else
	{
		if(opc==contador)
		{
			MenuPila(&(*Inicio)->pila);
			return;
		}
		else
			if(contador<opc)
			{
				contador++;
				BuscarLista(&(*Inicio)->siguiente,opc,contador);
				return;
			}
	}
	return ;
}





int EliminarLista (eLista **Inicio,int size , int opc,int contador)
{
	eLista *aux;
 if(size==1 && (opc)+1==1)
 {

 	aux=(*Inicio);
 	free(aux);
 	(*Inicio)=NULL;
	return 1; 	
 }
 else
 {
 	if(contador==1 && opc==0)
 	{
 		aux=(*Inicio);
 		(*Inicio)=(*Inicio)->siguiente;
 		free(aux);
 		return 1;
 	}
 	 else
 {
 	if(contador!=opc)
 	{
 		contador++;
 		EliminarLista(&(*Inicio),size,opc,contador);
 		return 1;
 	}
 	else
 	{
 	 if(contador==opc)
 	 {
 	 	aux=(*Inicio)->siguiente;
 	 	(*Inicio)->siguiente=(*Inicio)->siguiente->siguiente;
 	 	free(aux);
 	 	return 1;
 	 }
 	}
 }
 }

return 0;
}


int main(int argc, char const *argv[])
{

	Capsula  cap;
	int posicion;
	char opc ='s';
	char opc2='n';
	int num;
	char nom[20];
	char app[20];
	char apm[20];
 	int x;
 	int y;
 	int z;
 	int sum;
 	int listaopcion;
 	Lista *lista=(Lista*) malloc(sizeof(Lista));
	lista->inicio=NULL;
	lista->size=0;
	while(opc=='s')
 	{

 		if((lista)->inicio==NULL)
 		{	  
 		  
 		  (lista)->size=0;
 		}
 		printf("__________________________________________\n");
 		printf("MENU DE ESTRUCTURAS \n");
 	    printf("__________________________________________\n");
		printf("|1.-Crear Bateria \n");
		printf("|2.-Recorrer Baterias \n");
		printf("|3.-Entrar a Bateria \n");
		printf("|4.-Eliminar  Bateria\n");
		printf("|5.-Liberar Capsula\n");
		printf("|6.-Salir\n");
		scanf("%i",&x);
		BorrarPantalla();
		printf("__________________________________________\n");
		printf("               RESULTADOS\n");
		printf("__________________________________________\n");
		switch(x)
		{
			case 1:
			 sum=lista->size+InsertarLista(&(lista->inicio));
    		 lista->size=sum;
    		 printf("Numero de Baterias # %i \n",lista->size );
			break;
			case 2:
			 RecorrerLista(lista->inicio,1);
			break;
			case 3:
				if(lista!=NULL)
				{
		 	 		printf("Ingresa la Bateria que quieres abrir\n");
			 		scanf("%i",&listaopcion);
			 		if(listaopcion<=lista->size)
			 		{
			 			BuscarLista(&(lista)->inicio,listaopcion,1);		
			 		}
			 		else
			 		{
			 			printf("El numero de Nodos es %i , ingresa un numero menor o igual \n",lista->size );
			 		}
				}
				else
				{
					printf("Error Bateria vacia\n");
				}
			break;
			case 4:
				if(lista->size!=0)
				{
			 		printf("Ingresa la Bateria  que quieres eliminar\n");
			 		scanf("%i",&listaopcion);
			 		if(listaopcion<=lista->size)
			 		{
			 			listaopcion--;
			 			sum=EliminarLista(&(*lista).inicio,lista->size,listaopcion,1);
			 			lista->size=lista->size-sum;
			 		}
			 		else
			 		{
			 			printf("Numero de Baterias %i , ingresa un numero igual o menor  \n",lista->size );
			 		}
				}
				else
				{
					printf("Error Bateria Vacia \n");
				}
			break;
			case 5:
			
			if(lista->inicio!=NULL)
			{
			
				printf("Ingresa El nombre que quieres Liberar\n");
				scanf("%s",nom);
				printf("Ingresa El apellido paterno que quieres Liberar\n");
				scanf("%s",app);
				printf("Ingresa El apellido materno que quieres Liberar\n");
				scanf("%s",apm);
				x=LiberarLista(&(lista)->inicio,nom,app,apm);
				RecorrerLista(lista->inicio,1);
		}
		else
		{
			printf("Lista Vacia\n");
		}
		break;

		case 6:
		opc=opc2;
		break;
		}
 
	}
	return 0;
}