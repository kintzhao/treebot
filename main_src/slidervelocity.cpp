#include "slidervelocity.h"
#include <QMouseEvent>
SliderVelocity::SliderVelocity(QWidget *parent):QSlider(parent)
{

}


void SliderVelocity::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        emit signalvalueChanged(this->value());
    }
    else
    {
        QSlider::mouseReleaseEvent(event);
    }
}
