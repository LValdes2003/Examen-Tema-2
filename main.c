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
    printf("Promedio: %.1f\n", estudiante.promedio);
}

void mostrarMaterias(struct Estudiante estudiante) {
    for (int i = 0; i < 5; i++) {
        printf("Materia %d: %s\n", i + 1, estudiante.materias[i]);
    }
}

void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    if (estudiante->numMaterias < 5) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        printf("Materia agregada: %s\n", materia);
    } else {
        printf("No se pueden agregar mas materias\n");
    }
}

void eliminarMateria(struct Estudiante *estudiante, const char *materia) {
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Eliminar materia encontrada moviendo las materias restantes
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            printf("Materia eliminada: %s\n", materia);
            return;
        }
    }
    printf("Materia no encontrada: %s\n", materia);
}

struct Asistencia {
    struct Estudiante estudiante;
    char fecha[50];
    char materia[50];
    int estado; // 0 for false, 1 for true
};

int registrarAsistencia(struct Asistencia *asistencia, const char *fecha, const char *materia, int estado) {
    strcpy(asistencia->fecha, fecha);
    strcpy(asistencia->materia, materia);
    asistencia->estado = estado;
    return 1;
}

void mostrarAsistencia(struct Asistencia asistencia) {
    printf("Fecha: %s\n", asistencia.fecha);
    printf("Materia: %s\n", asistencia.materia);
    printf("Estado: %s\n", asistencia.estado ? "true" : "false");
}

int main() {
    struct Estudiante estudiante1 = {"Leonardo", 19, 0.5,
                                     {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};
    struct Estudiante estudiante2 = {"Maria", 25, 17.5,
                                     {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};

    printf("Estudiante 1:\n");
    mostrarEstudiante(estudiante1);
    mostrarMaterias(estudiante1);
    printf("\n");

    eliminarMateria(&estudiante1, "Matematicas");
    agregarMateria(&estudiante1, "Historia");
    printf("Nuevas materias:\n");
    mostrarMaterias(estudiante1);
    printf("\n");

    printf("Estudiante 2:\n");
    mostrarEstudiante(estudiante2);

    return 0;
}