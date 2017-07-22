#include "auxiliarqlabel.h"

AuxiliarQLabel::AuxiliarQLabel(QWidget *parent)
	: QLabel(parent)
{

}

AuxiliarQLabel::~AuxiliarQLabel()
{

}

void AuxiliarQLabel::mousePressEvent(QMouseEvent *ev){

	if (ev->buttons() == 0x01)
	{
		if (ev->x() <= this->size().width() && ev->y() <= this->size().height())
		{
			this->x = ev->x();
			this->y = ev->y();
		}		
	}
	else if (ev->buttons() == 0x02)
	{
		this->x = -1;
		this->y = -1;
	}
	emit MousePressed();
}