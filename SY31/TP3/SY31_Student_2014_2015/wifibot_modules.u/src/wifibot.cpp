// Includes, project.
#include "wifibot.hpp"

// Includes, standard.
#include <cassert>
#include <cmath>
#include <iostream>

using namespace sy31;

Wifibot::Wifibot(double entrax, double wheelRadius)
  : mEntrax(0.0)
  , mWheelRadius(0.0)
{
  setEntrax(entrax);
  setWheelRadius(wheelRadius);
  resetOdometry();
}

void
Wifibot::updateOdometry(double dt, double left, double right)
{
  assert(dt > 0.0);

  double v = getLinearSpeed(left, right);
  double w = getAngularSpeed(left, right);

  mPosition.x  += v * dt * std::cos(mPosition.th);
  mPosition.y  += v * dt * std::sin(mPosition.th);
  mPosition.th += w * dt;
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
  assert(entrax > 0.0);
  mEntrax = entrax;
}

void
Wifibot::setWheelRadius(double radius)
{
  assert(radius > 0.0);
  mWheelRadius = radius;
}

double
Wifibot::getLinearSpeed(double left, double right) const
{
  return mWheelRadius * (left + right) / 2.0;
}

double
Wifibot::getAngularSpeed(double left, double right) const
{
  return - mWheelRadius * (right - left) / mEntrax;
}
