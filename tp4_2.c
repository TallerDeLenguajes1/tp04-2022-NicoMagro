#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//DEFINO LAS ESTRUCTURAS

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

//DEFINO LAS FUNCIONES

void cargarTarea(Tarea **tareasPendientes, int cantTareas);
void estadoTarea(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cantTareas);
void mostrarTareasRealizadas(Tarea **tareasRealizadas, int cantTareas);
void mostrarTareasPendientes(Tarea **tareasPendientes, int cantTareas);

//MAIN

int main()
{
    srand(time(NULL));
    int cantTareas;
    printf("Ingrese la cantidad de tareas que deseea cargar: ");
    scanf("%d", &cantTareas);

    Tarea **tareasPendientes = (Tarea**)malloc(sizeof(Tarea*)*cantTareas);
    Tarea **tareasRealizadas = (Tarea**)malloc(sizeof(Tarea*)*cantTareas);

    cargarTarea(tareasPendientes, cantTareas);
    estadoTarea(tareasPendientes, tareasRealizadas, cantTareas);
    mostrarTareasRealizadas(tareasRealizadas, cantTareas);
    mostrarTareasPendientes(tareasPendientes, cantTareas);

    free(tareasPendientes);
    free(tareasRealizadas);
    return 0;
}

void cargarTarea(Tarea **tareasPendientes, int cantTareas)
{
    printf("\n----------CARGA DE TAREAS----------\n\n");
    for (int i = 0; i < cantTareas; i++)
    {
        printf("\n----------TAREA %d----------\n", i+1);
        tareasPendientes[i] = (Tarea*)malloc(sizeof(Tarea));
        char aux[100];
        tareasPendientes[i]->TareaID = i;
        printf("ID de la tarea: %d", tareasPendientes[i]->TareaID);
        printf("\nIngrese la descripcion de la tarea: ");
        scanf(" %s", &aux);
        tareasPendientes[i]->Descripcion = (char*)malloc(sizeof(char)*strlen(aux+1));
        strcpy(tareasPendientes[i]->Descripcion, aux);
        tareasPendientes[i]->Duracion = rand()%90 + 10;
        printf("Duracion de la tarea: %d", tareasPendientes[i]->Duracion);
    }
}

void estadoTarea(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cantTareas)
{
    char estado;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("\nLa tarea %d ya fue realizada o aun esta pendiente: (Ingrese 'r' si esta realizada, o 'p' si aun esta pendiente)", i+1);
        scanf(" %c", &estado);
        if (estado == 'r')
        {
            tareasRealizadas[i] = (Tarea*)malloc(sizeof(Tarea));
            tareasRealizadas[i]->TareaID = tareasPendientes[i]->TareaID;
            tareasRealizadas[i]->Duracion = tareasPendientes[i]->Duracion;
            tareasRealizadas[i]->Descripcion = (char*)malloc(sizeof(char)*strlen(tareasPendientes[i]->Descripcion+1));
            strcpy(tareasRealizadas[i]->Descripcion, tareasPendientes[i]->Descripcion);
            tareasPendientes[i] = NULL;
        }
        else
        {
            tareasRealizadas[i] = NULL;
        }
    }
}

void mostrarTareasRealizadas(Tarea **tareasRealizadas, int cantTareas)
{
    printf("\n----------MUESTRA DE LAS TAREAS REALIZADAS----------\n\n");
    for (int i = 0; i < cantTareas; i++)
    {
        if (tareasRealizadas[i] != NULL)
        {
            printf("----------TAREA %d----------", i+1);
            printf("\nID de la tarea: %d", tareasRealizadas[i]->TareaID);
            printf("\nDescripcion de la terea: %s", tareasRealizadas[i]->Descripcion);
            printf("\nDuracion de la tarea: %d", tareasRealizadas[i]->Duracion);
        }
    }   
}

void mostrarTareasPendientes(Tarea **tareasPendientes, int cantTareas)
{
    printf("\n\n----------MUESTRA DE LAS TAREAS PENDIENTES----------\n\n");
    for (int i = 0; i < cantTareas; i++)
    {
        if (tareasPendientes[i] != NULL)
        {
            printf("----------TAREA %d----------", i+1);
            printf("\nID de la tarea: %d", tareasPendientes[i]->TareaID);
            printf("\nDescripcion de la terea: %s", tareasPendientes[i]->Descripcion);
            printf("\nDuracion de la tarea: %d", tareasPendientes[i]->Duracion);
        }
    }   
}