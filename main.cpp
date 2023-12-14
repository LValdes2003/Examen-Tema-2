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

// Funcion para mostrar las materias de un estudiante
void mostrarMaterias(Estudiante estudiante) {
    for (int i = 0; i < estudiante.numMaterias; i++) {
        std::cout << "Materia " << i + 1 << ": " << estudiante.materias[i] << std::endl;
    }
}

// Funcion para agregar una materia a la lista de materias de un estudiante
void agregarMateria(struct Estudiante *estudiante, const char *materia) {
    if (estudiante->numMaterias < 5) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        std::cout << "Materia agregada: " << materia << std::endl;
    } else {
        std::cout << "No se pueden agregar más materias" << std::endl;
    }
}

// Funcion para eliminar una materia de la lista de materias de un estudiante
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

// Estructura "Asistencia"
struct Asistencia {
    struct Estudiante estudiante;
    char fecha[50];
    char materia[50];
    bool estado;
};

// Funcion para registrar la asistencia de un estudiante a una materia en una fecha específica
bool registrarAsistencia(struct Asistencia *asistencia, const char *fecha, const char *materia, bool estado) {
    strcpy(asistencia->fecha, fecha);
    strcpy(asistencia->materia, materia);
    asistencia->estado = estado;
    return true;
}

// Funcion para mostrar la información de asistencia de un estudiante
void mostrarAsistencia(struct Asistencia asistencia) {
    std::cout << "Fecha: " << asistencia.fecha << std::endl;
    std::cout << "Materia: " << asistencia.materia << std::endl;
    std::cout << "Estado: " << (asistencia.estado ? "Asistió" : "No asistió") << std::endl;
}

int main() {
    // Inicializar estudiantes
    Estudiante estudiante1 = {"Leonardo", 19, 0.5, {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};
    Estudiante estudiante2 = {"Maria", 25, 17.5, {"Matematicas", "Fisica", "Quimica", "Programacion", "Ingles"}};

    // Mostrar información del estudiante 1
    std::cout << "Estudiante 1: " << std::endl;
    mostrarEstudiante(estudiante1);
    mostrarMaterias(estudiante1);
    std::cout << std::endl;

    // Eliminar y agregar materias al estudiante 1
    eliminarMateria(&estudiante1, "Matematicas");
    agregarMateria(&estudiante1, "Historia");

    // Mostrar las nuevas materias del estudiante 1
    std::cout << "Nuevas materias: " << std::endl;
    mostrarMaterias(estudiante1);
    std::cout << std::endl;

    // Mostrar información del estudiante 2
    std::cout << "Estudiante 2: " << std::endl;
    mostrarEstudiante(estudiante2);

    return 0;
}
