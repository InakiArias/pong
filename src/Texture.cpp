#include "Texture.h"
#include <iostream>

Texture::Texture() {
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture() {
    //Deallocate
    free();
}

bool Texture::loadFromFile(const char* path, bool transparency, int w, int h ) {

    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);

    //Color key image
    if (transparency)
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0, 0 ) );

    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

    //Get image dimensions
    mWidth = w ? w : loadedSurface->w;
    mHeight = h ? h : loadedSurface->h;

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );


    //Return success
    mTexture = newTexture;

    //SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);

    return mTexture != NULL;
}

void Texture::free() {
    //Free texture if it exists
    if( mTexture != NULL ) {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue ) {
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending ) {
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha( Uint8 alpha ) {
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Texture::render( int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, w, h };
    SDL_Rect* dst = w && h ? &renderQuad : NULL;

    //Render to screen
    SDL_RenderCopyEx( gRenderer, mTexture, clip, dst, angle, center, flip );
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

void Texture::setRenderer(SDL_Renderer* r) {
    gRenderer = r;
}

