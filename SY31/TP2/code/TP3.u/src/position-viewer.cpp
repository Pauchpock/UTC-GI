// Includes, project.
#include "position-viewer.hpp"

// Includes, standard.
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

// Includes, SDL.
#include <SDL.h>

// Includes, OpenGL.
#include <gl/GL.h>

using namespace sy31;

const size_t WINDOW_W = 640;
const size_t WINDOW_H = 480;

double rad2deg(double rad) { return rad * (180.0 / M_PI); }
double deg2rad(double deg) { return deg * (M_PI / 180.0); }

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(PositionViewer)
  MAPS_INPUT("iWifibotPosition", MAPS::FilterFloat64, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(PositionViewer)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(PositionViewer)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(PositionViewer)
  MAPS_ACTION("ResetOdometry", PositionViewer::ResetOdometry)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
  PositionViewer, "PositionViewer", "1.0", 128,
  MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
  1, // Nb of inputs
  0, // Nb of outputs
  0, // Nb of properties
  1) // Nb of actions

////////////////////////////////////////////////////////////////
// RTMaps - Birth
////////////////////////////////////////////////////////////////
void
PositionViewer::Birth()
{
  mWidth  = WINDOW_W;
  mHeight = WINDOW_H;
  if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    Error("cannot initialize SDL");
  if (SDL_SetVideoMode(mWidth, mHeight, 32, SDL_OPENGL) == NULL)
    Error("cannot open the SDL window");
  SDL_WM_SetCaption( "OpenGL - Position Viewer", NULL );

  glViewport(0, 0, (GLint) mWidth, (GLint) mHeight);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, mWidth, 0, mHeight, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(mWidth / 2.f, mHeight / 2.f, 0.f);
  glScaled(100.0, 100.0, 1.0);

  mTrajectory = Trajectory();
}

////////////////////////////////////////////////////////////////
// RTMaps - Core
////////////////////////////////////////////////////////////////
void
PositionViewer::Core() 
{
  MAPSIOElt* input = StartReading(Input(0));
  if (!input)
    return;
  if (input->VectorSize() != 3)
    Error("WifibotPosition's size must be 3");

  // Append the new position to the trajectory: inverse Oy because the axis are inversed.
  mTrajectory.Append(Wifibot::Position(input->Float64(0),
                                       -input->Float64(1),
                                       input->Float64(2)));

  drawTrajectory();
  processEvents();
  SDL_GL_SwapBuffers();
}

////////////////////////////////////////////////////////////////
// RTMaps - Death
////////////////////////////////////////////////////////////////
void
PositionViewer::Death()
{
  // Couic! :(
  SDL_Quit();
}

void
PositionViewer::drawTrajectory()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_STRIP);
    glColor3f(1.f, 0.f, 0.f);
    MAPSList<Wifibot::Position>::MAPSIterator it(mTrajectory);
    for (; it != mTrajectory.End(); ++it)
      glVertex2d((*it).x, (*it).y);
  glEnd();

  Wifibot::Position last;
  if (!mTrajectory.Empty())
    last = *(mTrajectory.IterLast());
 
  glPushMatrix();
    glTranslated(last.x, last.y, 0.0);
    glRotated(-rad2deg(last.th), 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
      glColor3f(1.f, 0.f, 0.f);
      glVertex2f(0.f, -0.1f);
      glVertex2f(0.f, +0.1f);
      glColor3f(0.f, 0.f, 1.f);
      glVertex2f(0.1f, 0.f);
    glEnd();
  glPopMatrix();

  glFlush();
}

void
PositionViewer::processEvents()
{
  // Grab the events from the SDL queue.
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        Report("you cannot close the window, you must stop the simulation");
        break;
      default:
        break;
    }
  }
}

void
PositionViewer::reset()
{
  mTrajectory = Trajectory();
}

void
PositionViewer::ResetOdometry(MAPSModule *module, int actionNb)
{
	if (MAPS::IsRunning())
	{
		PositionViewer* pv = (PositionViewer*) module;
    pv->reset();
	}
}
