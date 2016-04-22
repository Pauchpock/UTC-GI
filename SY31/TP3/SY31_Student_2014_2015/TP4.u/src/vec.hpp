#ifndef DEF_VEC_HPP
#define DEF_VEC_HPP

// Includes, standard.
#include <ostream>

namespace sy31
{
  /** vec2
   * @brief 2D Space vector.
   */
  template <typename T>
  struct vec2
  {
    vec2(T x = T(0), T y = T(0))
      : x(x), y(y)
    {}

    T x;
    T y;
  };

  /** vec3
   * @brief 3D Space vector.
   */
  template <typename T>
  struct vec3
  {
    vec3(T x = T(0), T y = T(0), T z = T(0))
      : x(x), y(y), z(z)
    {}

    T x;
    T y;
    T z;
  };

  typedef vec2<float>     vec2f;
  typedef vec2<double>    vec2d;
  typedef vec3<float>     vec3f;
  typedef vec3<double>    vec3d;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, sy31::vec2<T> const& v)
{ return os << "(" << v.x << ", " << v.y << ")"; }

template <typename T>
std::ostream& operator<<(std::ostream& os, sy31::vec3<T> const& v)
{ return os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }

#endif
