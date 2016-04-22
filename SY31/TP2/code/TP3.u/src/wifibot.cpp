// Includes, project.
#include "wifibot.hpp"
#include "math.h"

using namespace sy31;

Wifibot::Wifibot(double entrax, double wheelRadius)
{
	mEntrax = entrax;
    mWheelRadius = wheelRadius;
}

void
Wifibot::updateOdometry(double dt, double left, double right)
{
  mPosition.x  += dt * getLinearSpeed(left, right)*cos(mPosition.th);
  mPosition.y  += dt * getLinearSpeed(left, right)*sin(mPosition.th);
  mPosition.th += -mWheelRadius*(mPosition.x+mPosition.y)/mEntrax;
}

void
Wifibot::resetOdometry()
{
	mPosition.x = 0.0;
	mPosition.y = 0.0;
	mPosition.th = 0.0;
}

void
Wifibot::setEntrax(double entrax)
{
  mEntrax = entrax;
}

void
Wifibot::setWheelRadius(double radius)
{
  mWheelRadius = radius;
}

double
Wifibot::getLinearSpeed(double left, double right) const
{
  return mWheelRadius*( left + right ) / 2;
}

double
Wifibot::getAngularSpeed(double left, double right) const
{
	return  -mWheelRadius*(left - right) / mEntrax;
}
