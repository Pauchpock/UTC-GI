// Includes, project.
#include "hokuyo-window.hpp"

// Includes, standard.
#include <stdexcept>

// Includes, SDL.
#include <SDL.h>

// Includes, OpenGL.
#include <Windows.h>
#include <gl/GL.h>

using namespace sy31;

HokuyoWindow::HokuyoWindow()
  : BaseWindow()
  , mScale(1.f)
{

}

HokuyoWindow::~HokuyoWindow()
{
}

void
HokuyoWindow::setScale(float scale)
{
  mScale = scale;
}

void
HokuyoWindow::render(std::vector<vec2d> const& points, vec3d const& color)
{
  glPushMatrix();
  glScalef(mScale, mScale, 1.f);

  glBegin(GL_POINTS);
    glColor3dv(&color.x);
    for (size_t i = 0; i < points.size(); ++i)
      glVertex2dv(&points[i].x);
  glEnd();

  glPopMatrix();
}
