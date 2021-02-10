#include <iostream>
#include <fstream>
#include <SDL.h>
#include <math.h>
#include "Math/Vector3.h"
#include "Ray.h"

void writeToImage(int width, int height);
void renderToWindow(int width, int height);
void putPixel(int xLoc, int yLoc, Uint32* currentPixel, SDL_Texture* currentTexture);
Vector3 rayToColor(Ray r);


struct cameraX
{
	Vector3 lowerLeftCorner;
	Vector3 horizontal;
	Vector3 vertical;
	Vector3 origin;
};


int main(int argc, char *argv[]) 
{
	std::cout << "Init RayTracer";


	renderToWindow(800, 600);

	return 0;
}

/// @brief creates a image if the raytracer's output
/// @param width Columns in image matrix
/// @param height Rows in image matrix
void writeToImage(int width, int height)
{
	std::ofstream outputImage("outputImage.ppm");

	outputImage << "P3\n" << width << " " << height << "\n255\n";

	for (int j = height -1; j >=0 ; j--) 
	{
		for (int i = 0; i < width; i++) 
		{
			float rAmount = float(i) / float(width);
			float gAmount = float(j) / float(height);
			float bAmount = 0.2f;
			int r = int(255.99*rAmount);
			int g = int(255.99*gAmount);
			int b = int(255.99*bAmount);

			outputImage << r << " " << g << " " << b << "\n";
		}
	}

	outputImage.close();
}

void renderToWindow(int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Rect screenRect = { 0,0,width, height };
	SDL_Window* window = SDL_CreateWindow("Basic Ray Tracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenRect.w, screenRect.h, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, screenRect.w, screenRect.h);

	struct cameraX cam;

	cam.lowerLeftCorner = Vector3(-2.0, -1.0, -1.0);
	cam.horizontal = Vector3(4.0, 0.0, 0.0);
	cam.vertical = Vector3(0.0, 2.0, 0.0);
	cam.origin = Vector3(0.0, 0.0, 0.0);

	SDL_Event event;
	SDL_PollEvent(&event);

	int frame = 0;

	while (event.type != SDL_QUIT)
	{
			SDL_PollEvent(&event);

			int pitch;
			uint32_t* pixels;
			SDL_LockTexture(texture, &screenRect, (void**)&pixels, &pitch);
			uint32_t startTicks = SDL_GetTicks();

			//RX here
			for (int y = screenRect.h - 1; y >= 0; y--) 
			{
				for (int x = 0; x < screenRect.w; x++) 
				{

					float u = float(x) / float(screenRect.w);
					float v = float(y) / float(screenRect.h);

					Ray currentRay(cam.origin, cam.lowerLeftCorner + u * cam.horizontal + (v)*cam.vertical);
					Vector3 col = rayToColor(currentRay);
					//Vector3 col(0.0,0.0,1.0);
					//Vector3 col(u, -v, 0.2);

					int r = int(255.0 * col.x);
					int g = int(255.0 * col.y);
					int b = int(255.0 * col.z);

					int pixelColor = 65536 * b + 256 * g + r;
					//int pixelColor = 65536 * col.x + 256 * col.y + col.z;


					pixels[y * screenRect.w + x] = pixelColor;
				}
			}
			

			uint32_t endTicks = SDL_GetTicks();
			SDL_UnlockTexture(texture);

			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texture, &screenRect, &screenRect);
			SDL_RenderPresent(renderer);

			char title[32];
			SDL_SetWindowTitle(window, SDL_itoa(endTicks - startTicks, title, 10));

			frame++;
	}

	

}

void putPixel(int xLoc, int yLoc, Uint32* currentPixel, SDL_Texture* currentTexture)
{
	int bpp = 4;
}

Vector3 rayToColor(Ray r) 
{
	Vector3 unitDirection = r.direction.normalize();
	float t = 0.5 * (-unitDirection.y + 1.0);
	return (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
}
