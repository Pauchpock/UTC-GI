// Includes, project.
#include "base-window.hpp"

// Includes, standard.
#include <stdexcept>

// Includes, SDL.
#include <SDL.h>

// Includes, OpenGL.
#include <Windows.h>
#include <gl/GL.h>

using namespace sy31;

BaseWindow::BaseWindow()
{
}

BaseWindow::~BaseWindow()
{
  close();
}

void
BaseWindow::clear()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void
BaseWindow::refresh()
{
  SDL_GL_SwapBuffers();
}

void
BaseWindow::close()
{
  if (!mIsOpened)
    return;
  SDL_Quit();
  mIsOpened = false;
}

void
BaseWindow::open(size_t width, size_t height)
{
  if (mIsOpened)
    close();

  if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    throw std::runtime_error("cannot initialize SDL");
  if (SDL_SetVideoMode(width, height, 32, SDL_OPENGL) == NULL)
    throw std::runtime_error("cannot open the SDL window");
  SDL_WM_SetCaption( "OpenGL - Cluster Viewer", NULL );

  mWidth = width;
  mHeight = height;
  mIsOpened = true;

  initializeViewport();
}

void
BaseWindow::setBackgroundColor(vec3f const& color)
{
  glClearColor(color.x, color.y, color.z, 0.f);
}

void
BaseWindow::processEvents()
{
  // Grab the events from the SDL queue.
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        break;
      default:
        break;
    }
  }
}

void
BaseWindow::onMouseMove(int dx, int dy)
{
}

void
BaseWindow::onWheelMove(int dv)
{
}

void
BaseWindow::initializeViewport()
{
  glViewport(0, 0, (GLint) mWidth, (GLint) mHeight);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, mWidth, 0, mHeight, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(mWidth / 2.f, mHeight / 2.f, 0.f);
}
