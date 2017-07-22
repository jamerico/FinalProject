#ifndef AUXILIARQLABEL_H
#define AUXILIARQLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

class AuxiliarQLabel : public QLabel
{
	Q_OBJECT

public:
	AuxiliarQLabel(QWidget *parent);
	~AuxiliarQLabel();

	void mousePressEvent(QMouseEvent *ev);
		
	int x = -1;
	int y = -1;
signals:
	void MousePressed();

public slots:

private:
	
};

#endif // AUXILIARQLABEL_H
