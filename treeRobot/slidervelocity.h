#ifndef SLIDERVELOCITY_H
#define SLIDERVELOCITY_H
#include <QSlider>

class SliderVelocity : public QSlider
{
    Q_OBJECT
public:
    SliderVelocity(QWidget *parent);
protected:
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void signalvalueChanged(const int v);

};

#endif // SLIDERVELOCITY_H
