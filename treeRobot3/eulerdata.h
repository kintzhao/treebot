#ifndef EULERDATA_H
#define EULERDATA_H
#include <QStringList>
class EulerData
{
public:
  float frontYaw;
  float frontYitch;
  float frontRoll;
  float rearYaw;
  float rearPitch;
  float rearRoll;
  int   length;
  int   width;
  int   height;

  EulerData(){frontYaw = 0;frontYitch = 0;frontRoll = 0;
              rearYaw = 0;rearPitch = 0;rearRoll = 0;
             length = 0;width = 0;height = 0;
             _dataSize = 44;}
  ~EulerData();
  void changeFrontYaw(float const e){frontYaw = e;}
  void changeFrontPitch(float const e){frontYitch = e;}
  void changeFrontRoll(float const e){frontRoll = e;}
  void changeRearYaw(float const e){rearYaw = e;}
  void changeRearPitch(float const e){rearPitch = e;}
  void changeRearRoll(float const e){rearRoll = e;}
  void changeLength(int const e){length = e;}
  void changeWidth(int const e){width = e;}
  void changeHeight(int const e){height = e;}
  void changeFrontGestureData(const float y,const float p,const float r)
  {
      changeFrontYaw(y);changeFrontPitch(p);changeFrontRoll(r);
  }
  void changeRearGestureData(const float y,const float p,const float r)
  {
      changeRearYaw(y);changeRearPitch(p);changeRearRoll(r);
  }
  float getFrontYaw(){return frontYaw;}
  float getFrontPitch(){return frontYitch;}
  float getFrontRoll(){return frontRoll;}
  float getRearYaw(){return rearYaw;}
  float getRearPitch(){return rearPitch;}
  float getRearRoll(){return rearRoll;}
  int   getLength(){return length;}
  int   getWidth(){return width;}
  int   getHeight(){return height;}
  int   dataSize(){return _dataSize;}
  QStringList& toStringList()
  {
    _stringList.clear();
    _stringList.append(QString("%1").arg(frontYaw));
    _stringList.append(QString("%1").arg(frontYitch));
    _stringList.append(QString("%1").arg(frontRoll));
    _stringList.append(QString("%1").arg(rearYaw));
    _stringList.append(QString("%1").arg(rearPitch));
    _stringList.append(QString("%1").arg(rearRoll));
    _stringList.append(QString("%1").arg(length));
    _stringList.append(QString("%1").arg(width));
    _stringList.append(QString("%1").arg(height));
    return _stringList;
  }
  QStringList getEulerDataStringList(){return _stringList;}
private:
    int _dataSize ;//= 44;
    QStringList _stringList;
};

#endif // EULERDATA_H
