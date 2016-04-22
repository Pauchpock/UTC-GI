#ifndef DEF_RED_COMPONENT_HPP
#define DEF_RED_COMPONENT_HPP

// Includes, rtmaps
#include "maps.hpp"

namespace sy31
{
  class RedComponent
    : public MAPSComponent
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(RedComponent)
    protected:
      /// Allocate the output images.
      void allocateOutputs(IplImage const& src);

      /// Notre travail
     void fonction(IplImage const& src,IplImage & dst, bool scaled, bool mirror);

    private:
      bool mIsAllocated;
  };
}

#endif

