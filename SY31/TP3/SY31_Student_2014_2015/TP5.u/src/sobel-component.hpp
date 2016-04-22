#ifndef DEF_SOBEL_COMPONENT_HPP
#define DEF_SOBEL_COMPONENT_HPP

// Includes, rtmaps
#include "maps.hpp"

namespace sy31
{
  class SobelComponent
    : public MAPSComponent
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(SobelComponent)
    protected:
      /// Compute a convolution.
      int convolution(IplImage const& src, int x, int y, int const* mask);

      /// Allocate the output images.
      void allocateOutputs(IplImage const& src);

      /// RGB to Grayscale.
      void rgb2gray(IplImage const& src, IplImage& dst);

      /// Compute a sobel filter.
      void compute_sobel(IplImage const& src, IplImage& dst);

    private:
      bool mIsAllocated;
  };
}

#endif

