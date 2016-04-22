#ifndef DEF_BASE_WINDOW_HPP
#define DEF_BASE_WINDOW_HPP

// Includes, project.
#include "vec.hpp"

namespace sy31
{
  class BaseWindow
  {
    public:
      /// Ctor of BaseWindow.
      BaseWindow();

      /// Dtor of BaseWindow.
      virtual ~BaseWindow();

      /// Clear the window.
      void clear();

      /// refresh the window.
      void refresh();

      /// Close the window.
      void close();

      /// Open the window.
      void open(size_t width, size_t height);

      /// Get the window's width.
      size_t getWidth() const
      { return mWidth; }

      /// Get the window's height.
      size_t getHeight() const
      { return mHeight; }

      /// Set the background color.
      void setBackgroundColor(vec3f const& color);

      /// Process the events.
      virtual void processEvents();

    protected:
      /// On scrolling event.
      virtual void onMouseMove(int dx, int dy);

      /// On wheel move.
      virtual void onWheelMove(int dv);

    private:
      // Prevent from copying a window.
      BaseWindow(BaseWindow const& w);
      BaseWindow& operator=(BaseWindow const& w);

      /// Initialize the viewport.
      void initializeViewport();

      size_t      mWidth;
      size_t      mHeight;
      bool        mIsOpened;
  };
}

#endif /* end of include guard: DEF_BASE_WINDOW_HPP */
