#ifndef EULERDATA_H
#define EULERDATA_H

class EulerData
{
public:
  float yaw;
  float pitch;
  float roll;

  EulerData(){yaw = 0;pitch = 0;roll = 0;}
  ~EulerData();
  void changeYaw(float const e){yaw = e;}
  void changePitch(float const e){pitch = e;}
  void changeRoll(float const e){roll = e;}

  float getYaw(){return yaw;}
  float getPitch(){return pitch;}
  float getRoll(){return roll;}


};

#endif // EULERDATA_H
