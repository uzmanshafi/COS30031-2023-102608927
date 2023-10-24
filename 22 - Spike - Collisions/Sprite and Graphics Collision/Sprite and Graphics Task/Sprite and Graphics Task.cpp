#include <SDL.h>
#include <iostream>
#include <cmath>

struct Vector2 {
    float x, y;
};

class Box {
public:
    SDL_Rect rect;

    bool Intersects(const Box& other) const {
        return rect.x < other.rect.x + other.rect.w &&
            rect.x + rect.w > other.rect.x &&
            rect.y < other.rect.y + other.rect.h &&
            rect.y + rect.h > other.rect.y;
    }
};

class Circle {
public:
    Vector2 center;
    float radius;

    bool Intersects(const Circle& other) const {
        float dx = center.x - other.center.x;
        float dy = center.y - other.center.y;
        float distance = sqrt(dx * dx + dy * dy);
        return distance < (radius + other.radius);
    }
};

// Helper function to render a circle
void SDL_RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Collision Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    Box staticBox;
    staticBox.rect = { 300, 250, 50, 50 };

    Box movingBox;
    movingBox.rect = { 50, 50, 50, 50 };

    Circle staticCircle;
    staticCircle.center = { 650, 300 };
    staticCircle.radius = 25;

    Circle movingCircle;
    movingCircle.center = { 100, 500 };
    movingCircle.radius = 25;

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_UP:    movingBox.rect.y -= 10; break;
                case SDLK_DOWN:  movingBox.rect.y += 10; break;
                case SDLK_LEFT:  movingBox.rect.x -= 10; break;
                case SDLK_RIGHT: movingBox.rect.x += 10; break;
                case SDLK_w:     movingCircle.center.y -= 10; break;
                case SDLK_s:     movingCircle.center.y += 10; break;
                case SDLK_a:     movingCircle.center.x -= 10; break;
                case SDLK_d:     movingCircle.center.x += 10; break;
                }
            }
        }

        bool boxCollided = movingBox.Intersects(staticBox);
        bool circleCollided = movingCircle.Intersects(staticCircle);

        SDL_RenderClear(renderer);

        // Renders static box and circle
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &staticBox.rect);
        SDL_RenderDrawCircle(renderer, staticCircle.center.x, staticCircle.center.y, staticCircle.radius);

        // Renders moving box with collision visualization
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &movingBox.rect);

        // Renders moving circle with collision visualization
        SDL_SetRenderDrawColor(renderer, boxCollided ? 255 : 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawCircle(renderer, movingCircle.center.x, movingCircle.center.y, movingCircle.radius);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
