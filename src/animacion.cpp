#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"
#include "EscenaOeste.hpp"

using namespace ftxui;

int main() {
    auto screen = Screen::Create(Dimension::Fixed(100), Dimension::Fixed(35));
    
    EscenaOeste escena(0, 0, 100, 35, Color::Yellow);
    escena.CrearEscenaCompleta();
    
    int frame = 0;
    bool cowboy_dispara = true;
    int bala_cowboy_x = 42;
    int bala_nativo_x = 55;
    
    std::cout << "\033[2J\033[H Duelo en el Oeste - Presiona Ctrl+C para salir\n\n";
    
    while(true) {
        screen.Clear();
        
        // === FASE 1: Cowboy dispara (frames 0-60) ===
        if (frame >= 0 && frame < 60) {
            cowboy_dispara = true;
            
            // Bala del cowboy se mueve hacia la derecha
            bala_cowboy_x = 42 + (frame / 3);
            escena.MoverElemento(EscenaOeste::BALA, bala_cowboy_x, 16);
            
            // Cowboy retrocede al disparar (primeros 10 frames)
            int cowboy_offset = (frame < 10) ? (frame % 2) : 0;
            escena.MoverElemento(EscenaOeste::COWBOY, 25 - cowboy_offset, 13);
            
            // Nativo se agacha para esquivar (frames 30-50)
            int nativo_y = 13;
            if (frame > 30 && frame < 50) {
                nativo_y = 13 + 2; // Se agacha
            }
            escena.MoverElemento(EscenaOeste::NATIVO, 55, nativo_y);
        }
        
        // === PAUSA (frames 60-80) ===
        else if (frame >= 60 && frame < 80) {
            // Resetear posiciones
            escena.MoverElemento(EscenaOeste::COWBOY, 25, 13);
            escena.MoverElemento(EscenaOeste::NATIVO, 55, 13);
            // Ocultar bala del cowboy (moverla fuera de pantalla)
            escena.MoverElemento(EscenaOeste::BALA, 200, 16);
        }
        
        // === FASE 2: Nativo dispara (frames 80-140) ===
        else if (frame >= 80 && frame < 140) {
            cowboy_dispara = false;
            
            // Bala del nativo se mueve hacia la izquierda
            bala_nativo_x = 55 - ((frame - 80) / 3);
            escena.MoverElemento(EscenaOeste::BALA, bala_nativo_x, 16);
            
            // Nativo retrocede al disparar (primeros 10 frames después del 80)
            int nativo_offset = ((frame - 80) < 10) ? ((frame - 80) % 2) : 0;
            escena.MoverElemento(EscenaOeste::NATIVO, 55 + nativo_offset, 13);
            
            // Cowboy se agacha para esquivar (frames 110-130)
            int cowboy_y = 13;
            if (frame > 110 && frame < 130) {
                cowboy_y = 13 + 2; // Se agacha
            }
            escena.MoverElemento(EscenaOeste::COWBOY, 25, cowboy_y);
        }
        
        else {
            // Resetear todo
            escena.MoverElemento(EscenaOeste::COWBOY, 25, 13);
            escena.MoverElemento(EscenaOeste::NATIVO, 55, 13);
            escena.MoverElemento(EscenaOeste::BALA, 200, 16); // Fuera de pantalla
            
            if (frame >= 160) {
                frame = -1; // Reiniciar ciclo
            }
        }
        
        // Dibujar la escena
        escena.Dibujar(screen);
        std::cout << "\033[H";
        screen.Print();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(110));
        frame++;
    }
    
    return 0;
}