#include <SDL.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, 0);
    if (!window) {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Sets the initial background color to green
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_r) {
                    // Changes the background color to a random color when 'r' is pressed
                    SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
