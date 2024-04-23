#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiarBuffer()
{
    fflush(stdin);
    fflush(stdout);
}

void limpiarPantalla()
{
    system("pause");
    system("cls");
}

void saltoLinea()
{
    printf("\n");
}

int menu()
{
    int opc = 0;
    printf("/********** MENU PRINCIPAL **********/ \n");
    printf("- Opcion 1: Menu Fichero \n");
    printf("- Opcion 2: Insertar Atleta \n");
    printf("- Opcion 3: Ver Atleta \n");
    printf("- Opcion 4: Modificar Atleta \n");
    printf("- Opcion 5: Eliminar Atleta \n");
    printf("- Opcion 7: Salir \n");
    printf("- Digite su opcion: ");
    scanf("%d", &opc);
    return opc;
}

void newAtleta(FILE *fileAtleta, struct Atleta at){
    //variable de control
    int guardado = 0;
    if(fileAtleta!=NULL){
        limpiarBuffer();
        limpiarPantalla();
        printf(" - DATOS DEL ATLETA -");
        saltoLinea();
        saltoLinea();
        printf("Cedula: ");
        scanf("%s", at.cedula);
        saltoLinea();
        limpiarBuffer();
        printf("Nombre completo: ");
        gets(at.nombreCompleto);
        saltoLinea();
        limpiarBuffer();
        printf("Edad: ");
        scanf("%d", &at.edad);
        saltoLinea();
        limpiarBuffer();
        printf("Sexo: ");
        scanf("%c", &at.sexo);
        saltoLinea();
        limpiarBuffer();
        printf("Telefono: ");
        scanf("%s", at.telefono);
        saltoLinea();
        limpiarBuffer();
        printf("Direccion: ");
        gets(at.direccion);
        saltoLinea();
        limpiarBuffer();
        printf("Pais: ");
        gets(at.pais);
        saltoLinea();
        limpiarBuffer();
        printf("Deporte: ");
        gets(at.dop.deporte);
        saltoLinea();
        limpiarBuffer();
        printf("Cantidad de medallas: ");
        scanf("%d", &at.dop.nMedallas);
        saltoLinea();
        limpiarBuffer();
        printf("Record: ");
        gets(at.dop.descRecord);
        saltoLinea();
        limpiarBuffer();

        guardado=fwrite(&at, sizeof(struct Atleta), 1, fileAtleta);
        if(guardado>0){
            printf("\nLos datos del atleta han sido guardados con exito! \n");
        }
        else{
            printf("\nERROR: intente nuevamente, si el error persiste contacte con el Administrador del Sistema... \n");
        }
    }
    else{
        printf("\nERROR: verifique que el fichero de Atleta exista, que este abierto en modo agregar, y/o finalmente que no esta siendo ocupado por otro programa... \n");
    }

    //CERRAMOS EL FICHERO
    fclose(fileAtleta);
}

void visualizarAtletas(FILE *fileAtleta, struct Atleta at)
{
    //fileAtleta = fopen("archivoAtleta.txt", "r");
    char cedula[20]; //Atleta a buscar
    char opc =' '; //Variable de control
    limpiarBuffer();
    printf("Desea visualizar todos los atletas registrados?\n");
    printf("Digite - S o s - para ver todos los atletas.\n");
    printf("Digite - N o n - para ver un atleta especifico.\n");
    limpiarBuffer();
    printf("Digite su opcion: ");
    scanf("%c", &opc);
    if(opc=='S' || opc=='s'){
        int num = 0; //contador
        limpiarBuffer();
        saltoLinea();
        printf("N° \t Cedula \t Nombre Completo \t Edad \t Sexo \t Telefono \t Direccion \t Pais \n");
        fread(&at, sizeof(struct Atleta), 1, fileAtleta);
        while(!feof(fileAtleta)){
            num++;
            printf("%d \t %s \t\t %s \t %d \t %c \t %s \t %s \t %s \n", num, at.cedula, at.nombreCompleto, at.edad, at.sexo, at.telefono, at.direccion, at.pais);
            fread(&at, sizeof(struct Atleta), 1, fileAtleta);
        }
    }
    else{
        if(opc=='N' || opc=='n'){
            limpiarBuffer();
            saltoLinea();
            int encontrado = 0;
            printf("Digite el numero de cedula del atleta que desea buscar: ");
            scanf("%s", cedula);
            rewind(fileAtleta);
            fread(&at, sizeof(struct Atleta), 1, fileAtleta);
            while(!feof(fileAtleta)){
                if(!strcmp(cedula, at.cedula)){
                    encontrado = 1;
                    limpiarBuffer();
                    printf("----------------------------\n");
                    printf("----- Datos del Atleta -----\n");
                    printf("----------------------------\n");
                    printf("Cedula: %s \n", at.cedula);
                    limpiarBuffer();
                    printf("Nombre Completo: %s \n", at.nombreCompleto);
                    limpiarBuffer();
                    printf("Direccion: %s \n", at.direccion);
                    limpiarBuffer();
                    printf("Edad: %d \n", at.edad);
                    limpiarBuffer();
                    printf("Sexo: %c \n", at.sexo);
                    limpiarBuffer();
                    printf("Telefono: %s \n", at.telefono);
                    limpiarBuffer();
                    printf("Pais: %s \n", at.pais);
                    limpiarBuffer();
                    printf("Deporte: %s \n", at.dop.deporte);
                    limpiarBuffer();
                    printf("Cant. Medallas: %d \n", at.dop.nMedallas);
                    limpiarBuffer();
                    printf("Record: %s \n", at.dop.descRecord);
                    limpiarBuffer();
                    printf("----------------------------\n");
                    saltoLinea();
                    break;
                }
                fread(&at, sizeof(struct Atleta), 1, fileAtleta);
            }
            if(encontrado!=1){
                printf("Ingrese un numero de cedula valido e intente nuevamente! \n");
            }
        }
        else{
            printf("Estimado Usuario, por favor ingrese una opcion valida! \n");
        }

    }
    fclose(fileAtleta);

}

void editarAtleta(FILE *fileAtleta, struct Atleta at){
    bool encontrado = false;
    int borrado = 1;
    char numCedula[20];
    int opcion = 0;

    FILE *temp;
    temp = fopen("temporal.txt", "w+"); //ARCHIVO TEMPORAL VACÍO

    limpiarBuffer();
    printf("Digite el numero de cedula del atleta que desea editar: ");
    scanf("%s", numCedula);

    fread(&at, sizeof(struct Atleta), 1, fileAtleta);
    while(!feof(fileAtleta)){
        if(!strcmp(numCedula, at.cedula)){
            encontrado = true;
            limpiarBuffer();
            printf("----------------------------\n");
            printf("----- Datos del Atleta -----\n");
            printf("----------------------------\n");
            printf("Cedula: %s \n", at.cedula);
            limpiarBuffer();
            printf("Nombre Completo: %s \n", at.nombreCompleto);
            limpiarBuffer();
            printf("Direccion: %s \n", at.direccion);
            limpiarBuffer();
            printf("Edad: %d \n", at.edad);
            limpiarBuffer();
            printf("Sexo: %c \n", at.sexo);
            limpiarBuffer();
            printf("Telefono: %s \n", at.telefono);
            limpiarBuffer();
            printf("Pais: %s \n", at.pais);
            limpiarBuffer();
            printf("Deporte: %s \n", at.dop.deporte);
            limpiarBuffer();
            printf("Cant. Medallas: %d \n", at.dop.nMedallas);
            limpiarBuffer();
            printf("Record: %s \n", at.dop.descRecord);
            limpiarBuffer();
            printf("----------------------------\n");
            saltoLinea();
            printf("Datos que puede editar del Atleta: \n");
            printf("Digite - 1 - para modificar el nombre\n");
            printf("Digite - 2 - para modificar la direccion del domicilio\n");
            printf("Digite - 3 - para modificar la edad\n");
            printf("Digite - 4 - para modificar el sexo\n");
            printf("Digite - 5 - para modificar el telefono\n");
            printf("Digite - 6 - para modificar el pais\n");
            printf("Digite - 7 - para modificar el deporte\n");
            printf("Digite - 8 - para modificar la cantidad de medallas\n");
            printf("Digite - 9 - para modificar el record\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcion);
            limpiarBuffer();
            switch(opcion)
            {
            case 1:
                printf("\n Ingrese el nuevo nombre: ");
                gets(at.nombreCompleto);
                limpiarBuffer();
                saltoLinea();
                break;
            case 2:
                printf("\n Ingrese la nueva direccion del domicilio: ");
                gets(at.direccion);
                limpiarBuffer();
                saltoLinea();
                break;
            case 3:
                printf("\n Ingrese la nueva edad: ");
                scanf("%d", &at.edad);
                limpiarBuffer();
                saltoLinea();
                break;
            case 4:
                printf("\n Ingrese el nuevo sexo: ");
                scanf("%c", &at.sexo);
                limpiarBuffer();
                saltoLinea();
                break;
            case 5:
                printf("\n Ingrese el nuevo telefono: ");
                scanf("%s", at.telefono);
                limpiarBuffer();
                saltoLinea();
                break;
            case 6:
                printf("\n Ingrese el nuevo pais: ");
                gets(at.pais);
                limpiarBuffer();
                saltoLinea();
                break;
            case 7:
                printf("\n Ingrese el nuevo deporte: ");
                gets(at.dop.deporte);
                limpiarBuffer();
                saltoLinea();
                break;
            case 8:
                printf("\n Ingrese la nueva cantidad de medallas: ");
                scanf("%d", &at.dop.nMedallas);
                limpiarBuffer();
                saltoLinea();
                break;
            case 9:
                printf("\n Ingrese el nuevo record: ");
                gets(at.dop.descRecord);
                limpiarBuffer();
                saltoLinea();
                break;
            default:
                printf("ESTIMADO USUARIO, INGRESE UNA OPCION VALIDA! \n");
                limpiarBuffer();
                saltoLinea();
                break;
            }

            fwrite(&at, sizeof(struct Atleta), 1, temp);
            printf("Atleta actualizado con exito! \n");
        }
        else{
            fwrite(&at, sizeof(struct Atleta), 1, temp);
        }
        fread(&at, sizeof(struct Atleta), 1, fileAtleta);
    }
    if(encontrado==false)
    {
        printf("El atleta que solicita no esta registrado, intente nuevamente con otro numero de cedula!\n");
    }

    //CERRAMOS LOS ARCHIVOS
    fclose(temp);
    fclose(fileAtleta);
    //BORRAMOS EL ARCHIVO VIEJO
    borrado = remove("archivoAtleta.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "archivoAtleta.txt");
    }
}

void eliminarAtleta(FILE *fileAtleta, struct Atleta at){
    bool encontrado = false;
    int borrado = 1;
    char numCedula[20];
    int opcion = 0;

    FILE *temp;
    temp = fopen("temporal.txt", "w+"); //ARCHIVO TEMPORAL VACÍO
    
    limpiarBuffer();
    printf("Digite el numero de cedula del atleta que desea eliminar: ");
    scanf("%s", numCedula);

    fread(&at, sizeof(struct Atleta), 1, fileAtleta);
    while(!feof(fileAtleta)){
        if(!strcmp(numCedula, at.cedula)){
            encontrado = true;
            limpiarBuffer();
            printf("----------------------------\n");
            printf("----- Datos del Atleta -----\n");
            printf("----------------------------\n");
            printf("Cedula: %s \n", at.cedula);
            limpiarBuffer();
            printf("Nombre Completo: %s \n", at.nombreCompleto);
            limpiarBuffer();
            printf("Direccion: %s \n", at.direccion);
            limpiarBuffer();
            printf("Edad: %d \n", at.edad);
            limpiarBuffer();
            printf("Sexo: %c \n", at.sexo);
            limpiarBuffer();
            printf("Telefono: %s \n", at.telefono);
            limpiarBuffer();
            printf("Pais: %s \n", at.pais);
            limpiarBuffer();
            printf("Deporte: %s \n", at.dop.deporte);
            limpiarBuffer();
            printf("Cant. Medallas: %d \n", at.dop.nMedallas);
            limpiarBuffer();
            printf("Record: %s \n", at.dop.descRecord);
            limpiarBuffer();
            printf("----------------------------\n");
            saltoLinea();

            printf("\nEsta seguro que desea eliminar el registro de este Atleta?\n");
            printf("\nSi su respuesta es SI, digite - 1 (uno) - de lo contrario digite - 0 (cero) -\n");
            scanf("%d", &opcion);
            if(opcion==1){ 
                printf("El registro ha sido eliminado con exito! \n");
            }
            else{
                fwrite(&at, sizeof(struct Atleta), 1, temp);
                printf("\nRegresando al menu principal... \n");
            }
        }
        else{
            fwrite(&at, sizeof(struct Atleta), 1, temp);
        }
        fread(&at, sizeof(struct Atleta), 1, fileAtleta);
    }
    if(encontrado==false)
    {
        printf("El Atleta que solicita no esta registrado, intente nuevamente con otro numero de cedula!\n");
    }

    //CERRAMOS LOS ARCHIVOS
    fclose(temp);
    fclose(fileAtleta);
    //BORRAMOS EL ARCHIVO VIEJO
    borrado = remove("archivoAtleta.txt");
    if(borrado==0)
    {
        rename("temporal.txt", "archivoAtleta.txt");
    }

}

int menuFichero()
{
    int opc = 0;
    printf("/************** MENU FICHERO **************/ \n");
    printf("- Opcion 1: Abrir fichero en modo lectura. \n");
    printf("- Opcion 2: Abrir fichero en modo Agregar. \n");
    printf("- Opcion 3: Crear un fichero nuevo. \n");
    printf("- Opcion 4: Eliminar un fichero existente. \n");
    printf("- Opcion 5: Regresar al menu anterior \n");
    printf("- Digite su opcion: ");
    scanf("%d", &opc);
    return opc;
}


void gestionarFichero(FILE *fileAtleta)
{
    fileAtleta = fopen("archivoAtleta.txt", "r");
    if(fileAtleta==NULL){
        fileAtleta = fopen("archivoAtleta.txt", "w");
        printf("Creamos el fichero \n");
    }
    else{
        fileAtleta = fopen("archivoAtleta.txt", "a+");
        printf("Abrimos el fichero en modo a+ \n");
    }
}

FILE * abrirFicheroA(){
    FILE *fileAtleta = NULL;
    fileAtleta = fopen("archivoAtleta.txt", "a+");
    if(fileAtleta==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero ha sido abierto en modo agregar. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return fileAtleta;
}

FILE * nuevoFichero(){
    FILE *fileAtleta = NULL;
    fileAtleta = fopen("archivoAtleta.txt", "w");
    if(fileAtleta==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero nuevo ha sido creado. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return fileAtleta;
}

FILE * abrirFichero(){
    FILE *fileAtleta = NULL;
    fileAtleta = fopen("archivoAtleta.txt", "r");
    if(fileAtleta==NULL){
        printf("Error, el fichero no ha sido creado! \n");
    }
    else{
        printf("El fichero ha sido abierto en modo lectura. \n");
        //system("cls");
        printf("\nRegresando al menu principal... \n");
    }
    return fileAtleta;
}

void eliminarFichero(FILE *fileAtleta)
{
    int respuesta = 0;
    int borrado = 1;
    int cerrado = 1;

    printf("\n Esta seguro que desea eliminar el archivo de Atletas? \n");
    printf("\n Si su respuesta es SI, digite - 1 (uno) - de lo contrario digite - 0 (cero) - \n");
    scanf(" %d", &respuesta);
    if(respuesta){
        cerrado = fclose(fileAtleta);
        if(cerrado != 1){
            borrado = remove("archivoAtleta.txt");
            if(borrado!=1){
            printf("\nEl archivo de atletas ha sido eliminado con exito! \n");
            }
            else{
                printf("\nERROR al intentar eliminar el archivo de atletas! \n");
            }
        }
        else{
         //system("cls");
         printf("\nERROR al intentar cerrar el archivo de atletas! \n");
        } 
    }
    else{
        //system("cls");
        printf("\n Regresando al menu principal... \n");
    }
}