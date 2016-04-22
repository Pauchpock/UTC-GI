#ifndef DEF_WIFIBOT_HPP
#define DEF_WIFIBOT_HPP

namespace sy31
{
  class Wifibot
  {
    public:
      // Position of the wifibot.
      struct Position {
        /// Ctor of Position from three values.
        Position(double x, double y, double th)
          : x(x), y(y), th(th)
        {}
        /// Default ctor of Position.
        Position()
          : x(0.0), y(0.0), th(0.0)
        {}

        double x;   ///< Coordinate x, in meter.
        double y;   ///< Coordinate y, in meter.
        double th;  ///< Orientation, in radian.
      };

      /** Ctor of Wifibot.
       * @param entrax Entrax in m.
       * @param wheelRadius Radius of the wheels in m.
       */
      Wifibot(double entrax = 1.0, double wheelRadius = 1.0);

      /** Update the wifibot odometry using wheel speeds in rad/s.
       * @param dt Elapsed time in seconds.
       * @param left Left speed in rad/s.
       * @param right Right speed in rad/s.
       */
      void updateOdometry(double dt, double left, double right);

      /// Reset the odometry.
      void resetOdometry();

      /** Change the wifibot's entrax.
       * @param entrax Entrax in m, must be positive.
       */
      void setEntrax(double entrax);

      /** Change the wifibot's wheel radius.
       * @param radius Radius in m, must be positive.
       */
      void setWheelRadius(double radius);

      /** Get the wifibot's position.
       * @return Current odometry of the robot.
       */
      Position const& getPosition() const
      { return mPosition; }

    private:
      /// Get the wifibot's linear speed (m/s) from wheel speeds (rad/s).
      double getLinearSpeed(double left, double right) const;

      /// Get the wifibot's angular speed (rad/s) from wheel speeds (rad/s).
      double getAngularSpeed(double left, double right) const;

    private:
      double      mEntrax;
      double      mWheelRadius;
      Position    mPosition;
  };
}
#endif /* end of include guard: DEF_WIFIBOT_HPP */
