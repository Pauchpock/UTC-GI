#ifndef DEF_HOKUYO_WINDOW_HPP
#define DEF_HOKUYO_WINDOW_HPP

// Includes, project.
#include "base-window.hpp"
#include "vec.hpp"

// Includes, standard.
#include <vector>

namespace sy31
{
  class HokuyoWindow
    : public BaseWindow
  {
    public:
      /// Ctor of HokuyoWindow.
      HokuyoWindow();
      
      /// Dtor of HokuyoWindow.
      virtual ~HokuyoWindow();
      
      /// Set the scale of the environment.
      void setScale(float scale);

      /// Render some points.
      void render(std::vector<vec2d> const& points, vec3d const& color);

    private:
      float   mScale;
  };
}

#endif
