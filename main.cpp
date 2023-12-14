#include <iostream>

// Estructura "Estudiante"
struct Estudiante {
    char nombre[50];
    int edad;
    double promedio;
    char materias[5][50];
    int numMaterias;
};



// Funcion para mostrar un estudiante
void mostrarEstudiante(Estudiante estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}

void mostrarMaterias(Estudiante estudiante) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Materia " << i + 1 << ": " << estudiante.materias[i] << std::endl;
    }
}

void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    if (estudiante->numMaterias < 5) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        std::cout << "Materia agregada: " << materia << std::endl;
    } else {
        std::cout << "No se pueden agregar mas materias" << std::endl;
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
            std::cout << "Materia eliminada: " << materia << std::endl;
            return;
        }
    }
    std::cout << "Materia no encontrada: " << materia << std::endl;
}

struct Asistencia {
    struct Estudiante estudiante;
    char fecha[50];
    char materia[50];
    bool estado;
};

bool registrarAsistencia(struct Asistencia *asistencia, const char *fecha, const char *materia, bool estado) {
    strcpy(asistencia->fecha, fecha);
    strcpy(asistencia->materia, materia);
    asistencia->estado = estado;
    return true;
}

void mostrarAsistencia(struct Asistencia asistencia) {
    std::cout << "Fecha: " << asistencia.fecha << std::endl;
    std::cout << "Materia: " << asistencia.materia << std::endl;
    std::cout << "Estado: " << (asistencia.estado ? "true" : "false") << std::endl;
}

int main() {
    Estudiante estudiante1 = {"Leonardo", 19, 0.5,
                              {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};
    Estudiante estudiante2 = {"Maria", 25, 17.5,
                              {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};

    std::cout << "Estudiante 1: " << std::endl;
    mostrarEstudiante(estudiante1);
    mostrarMaterias(estudiante1);
    std::cout << std::endl;

    eliminarMateria(&estudiante1, "Matematicas");
    agregarMateria(&estudiante1, "Historia");
    std::cout << "Nuevas materias: " << std::endl;
    mostrarMaterias(estudiante1);
    std::cout << std::endl;

    std::cout << "Estudiante 2: " << std::endl;
    mostrarEstudiante(estudiante2);

    return 0;
}
