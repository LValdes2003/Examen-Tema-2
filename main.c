#include <stdio.h>
#include <string.h>

// Estructura "Estudiante"
struct Estudiante {
    char nombre[50];
    int edad;
    double promedio;
    char materias[5][50];
    int numMaterias;
};

// Funcion para mostrar un estudiante
void mostrarEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %f\n", estudiante.promedio);
}

// Mostrar las Materias de un estudiante
void mostrarMaterias(struct Estudiante estudiante) {
    for (int i = 0; i < 5; i++) {
        printf("Materia %d: %s\n", i + 1, estudiante.materias[i]);
    }
}

// Agregar una materia a un estudiante
void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    // averiguar si hay espacio para agregar una materia
    if (estudiante->numMaterias < 5) {
        strncpy(estudiante->materias[estudiante->numMaterias], materia, sizeof(estudiante->materias[0]) - 1);
        estudiante->materias[estudiante->numMaterias][sizeof(estudiante->materias[0]) - 1] = '\0'; // Null-terminate the string
        estudiante->numMaterias++; // Increment the number of subjects
        // Exito
        printf("Materia agregada: %s\n", materia);
    } else {
        // Fracaso
        printf("No se pueden agregar mas materias\n");
    }
}

// Eliminar una materia de un estudiante
void eliminarMateria(struct Estudiante *estudiante, const char *materia) {
    // Encuentra la materia a eliminar
    for (int i = 0; i < estudiante->numMaterias; i++) {
        // Averiguar si la materia es la que se quiere eliminar
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Muve todas las materias una posicion a la izquierda
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--; // Baja el numero de materias
            // Exito
            printf("Materia eliminada: %s\n", materia);
            return;
        }
    }
    // Fracaso
    printf("Materia no encontrada: %s\n", materia);
}

// Estructura "Asistencia"
struct Asistencia {
    struct Estudiante estudiante;
    char fecha[50];
    char materia[50];
    int estado; // 0 = ausente, 1 = presente
};

// Funcion para registrar asistencia
int registrarAsistencia(struct Asistencia *asistencia, const char *fecha, const char *materia, int estado) {
    // Copiar la fecha y materia
    strncpy(asistencia->fecha, fecha, sizeof(asistencia->fecha) - 1);
    asistencia->fecha[sizeof(asistencia->fecha) - 1] = '\0'; // Null-terminate the string

    strncpy(asistencia->materia, materia, sizeof(asistencia->materia) - 1);
    asistencia->materia[sizeof(asistencia->materia) - 1] = '\0'; // Null-terminate the string

    asistencia->estado = estado; // Establecer el estado
    return 1; // Exito
}

// Mostrar asistencia
void mostrarAsistencia(struct Asistencia asistencia) {
    printf("Fecha: %s\n", asistencia.fecha);
    printf("Materia: %s\n", asistencia.materia);
    printf("Estado: %s\n", asistencia.estado ? "true" : "false");
}

int main() {
    // Inicializar estudiantes
    struct Estudiante estudiante1 = {"Leonardo", 19, 0.5,
                                     {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};
    struct Estudiante estudiante2 = {"Maria", 25, 17.5,
                                     {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};

    // Informacion de estudiante 1
    printf("Estudiante 1:\n");
    mostrarEstudiante(estudiante1);
    mostrarMaterias(estudiante1);
    printf("\n");

    // Modificacion de materias de estudiante 1
    eliminarMateria(&estudiante1, "Matematicas");
    agregarMateria(&estudiante1, "Historia");
    printf("Nuevas materias:\n");
    mostrarMaterias(estudiante1);
    printf("\n");

    // Mostrar estudiante 2
    printf("Estudiante 2:\n");
    mostrarEstudiante(estudiante2);

    return 0;
}
