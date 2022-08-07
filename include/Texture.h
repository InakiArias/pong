#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

//Texture wrapper class
class Texture {
  public:

    Texture();
    ~Texture();

    //Loads image at specified path
    bool loadFromFile(const char* path, bool transparency = false, int w = 0, int h = 0 );

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, int w = 0, int h = 0, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    int getWidth();
    int getHeight();

    void setRenderer(SDL_Renderer* r);

  private:
    SDL_Texture* mTexture;
    SDL_Renderer* gRenderer;

    int mWidth;
    int mHeight;
};
#endif // TEXTURE_H
