#pragma once
#include <vector>
#include "Dibujo.hpp"

class EscenaOeste {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_fondo;
    std::vector<Dibujo> elementos;
    
    EscenaOeste(int x, int y, int ancho, int alto, ftxui::Color color = ftxui::Color::Yellow)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_fondo(x, y, GenerarFondoDesierto(ancho, alto), color) {}
    
    // Genera el fondo del desierto con montañas y coyote integrado
    static std::vector<std::u32string> GenerarFondoDesierto(int ancho, int alto) {
        std::vector<std::u32string> figura;
        
        figura.push_back(U"                                                       _____");
        figura.push_back(U"                                                     /'     `\\");
        figura.push_back(U"  __                                            ___/'         `\\");
        figura.push_back(U"/'  `\\_                          _            /'                \\");
        figura.push_back(U"       \\________________________( )_________/'                   `\\_______");
        figura.push_back(U"                             _  | |                _");
        figura.push_back(U"          _                 ( \ |  | _           ( ) _");
        figura.push_back(U"       _ ( )                 \ `|  |( )        _| |/ )");
        figura.push_back(U"      ( \| | _                 \\,  |/'/'       ( \\  /'");
        figura.push_back(U"       \,. |/ )                  | /'          \\  |");
        figura.push_back(U"         |  /'                   |  |           | |");
        figura.push_back(U"         | |                                    | |");
        figura.push_back(U"");
        figura.push_back(U"");
        figura.push_back(U"                                                          /\\_/\\");
        figura.push_back(U"                                                         ( o.o )");
        figura.push_back(U"                                                          > ^ <");
        figura.push_back(U"                                                         /|   |\\");
        figura.push_back(U"                                                        (_|   |_)");
        figura.push_back(U"                                                          |   |");
        figura.push_back(U"                                                         ~~ ~~");
        
        return figura;
    }
    
    // CACTUS GRANDE (detallado)
    static std::vector<std::u32string> GenerarCactus1() {
        return {
            U"    _    _",
            U"   | |  | |",
            U"  -| |  | |-",
            U"_   | |- | |",
            U"| |  | |  | |-",
            U"|.|  -| ||/  |",
            U"| |-  |  ___/",
            U"|.|   | | |",
            U"|  \\_|| |",
            U" \\____  |",
            U"  |   | |-",
            U"      | |",
            U"     -| |",
            U"      |_|"
        };
    }
    
    // CACTUS PEQUEÑO
    static std::vector<std::u32string> GenerarCactus2() {
        return {
            U"    ||",
            U"    ||",
            U"  -.||.-",
            U"    ||",
            U"    ||",
            U"   _||_",
            U"  |    |",
            U"  |    |",
            U"  |____|"
        };
    }
    
    // COWBOY DISPARANDO
    static std::vector<std::u32string> GenerarCowboy() {
        return {
            U"        ___",
            U"     __|___|__",
            U"      ('o_o')",
            U"      _\\~-~/_",
            U"     //\\__/\\ \\",
            U"    / )O  O( .\\",
            U"    \\ \\    / \\_/",
            U"    )/_|  |_\\",
            U"   // /(\\/)\\  \\",
            U"   /_/      \\_\\",
            U"  (_||      ||_)",
            U"    \\| |__| |/",
            U"     | |  | |",
            U"     | |  | |",
            U"     |_|  |_|",
            U"     /_\\  /_\\"
        };
    }
    
    // NATIVO CON RIFLE
    static std::vector<std::u32string> GenerarNativo() {
        return {
            U"                 .,",
            U"        .    ____/__,",
            U"      .' \\  / \\==\\```",
            U"     /    \\ 77 \\ |",
            U"    /_.----\\\\__,-----.",
            U"<--(\\_|_____<__|_____/",
            U"    \\  ````/|   ``/```",
            U"     `.   / |    I|",
            U"       `./  |____I|",
            U"            !!!!!!!",
            U"            | | I |",
            U"            | | I |",
            U"            \\ \\ I |",
            U"            | | I |",
            U"           _|_|_I_|",
            U"          /__/____| "
        };
    }
    
    // BALA/DISPARO
    static std::vector<std::u32string> GenerarBala() {
        return {
            U"------"
        };
    }
    
    // PLANTA RODANTE
    static std::vector<std::u32string> GenerarPlantaRodante() {
        return {
            U"    ___",
            U"   //   \\",
            U"  || o o ||",
            U"  \\  -  /",
            U"   \\___/",
            U"   ~~~~~"
        };
    }
    
    // Agrega un elemento a la escena
    void AgregarElemento(const Dibujo& elemento) {
        elementos.push_back(elemento);
    }
    
    // Crea la escena completa con posiciones iniciales
    void CrearEscenaCompleta() {
        // Índice 0: Cactus grande (izquierda)
        Dibujo cactus1(x + 5, y + 15, GenerarCactus1(), ftxui::Color::Green);
        AgregarElemento(cactus1);
        
        // Índice 1: Cowboy (centro-izquierda)
        Dibujo cowboy(x + 25, y + 13, GenerarCowboy(), ftxui::Color::Yellow);
        AgregarElemento(cowboy);
        
        // Índice 2: Bala (compartida - se mueve según quien dispare)
        Dibujo bala(x + 200, y + 16, GenerarBala(), ftxui::Color::Red);
        AgregarElemento(bala);
        
        // Índice 3: Nativo (centro-derecha)
        Dibujo nativo(x + 55, y + 13, GenerarNativo(), ftxui::Color::Red);
        AgregarElemento(nativo);
        
        // Índice 4: Cactus pequeño (derecha)
        Dibujo cactus2(x + 85, y + 20, GenerarCactus2(), ftxui::Color::GreenLight);
        AgregarElemento(cactus2);
    }
    
    // Mueve un elemento específico por índice
    void MoverElemento(int indice, int nuevo_x, int nuevo_y) {
        if (indice >= 0 && indice < (int)elementos.size()) {
            elementos[indice].x = nuevo_x;
            elementos[indice].y = nuevo_y;
        }
    }
    
    // Obtiene la posición actual de un elemento
    std::pair<int, int> ObtenerPosicion(int indice) const {
        if (indice >= 0 && indice < (int)elementos.size()) {
            return {elementos[indice].x, elementos[indice].y};
        }
        return {0, 0};
    }
    
    // Dibuja toda la escena
    void Dibujar(ftxui::Screen& screen) const {
        dibujo_fondo.Dibujar(screen);
        for (const auto& elemento : elementos) {
            elemento.Dibujar(screen);
        }
    }
    
    // Obtiene el número de elementos
    int NumeroElementos() const {
        return elementos.size();
    }
    
    // Índices para facilitar el acceso a los elementos
    enum Indices {
        CACTUS_GRANDE = 0,
        COWBOY = 1,
        BALA = 2,
        NATIVO = 3,
        CACTUS_PEQUENO = 4
    };
};