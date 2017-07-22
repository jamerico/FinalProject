/********************************************************************************
** Form generated from reading UI file 'roboconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOCONFIG_H
#define UI_ROBOCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoboConfig
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QComboBox *nomeComboBox;
    QComboBox *pidComboBox;
    QComboBox *xBeeAdressComboBox;
    QSpinBox *VelSpinBox;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QComboBox *TipoObjetoComboBox;
    QComboBox *trajComboBox;
    QComboBox *corPriComboBox;
    QComboBox *corSecComboBox;
    QComboBox *corTerComboBox;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *saveButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *RoboConfig)
    {
        if (RoboConfig->objectName().isEmpty())
            RoboConfig->setObjectName(QStringLiteral("RoboConfig"));
        RoboConfig->resize(560, 196);
        pushButton = new QPushButton(RoboConfig);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(-320, 210, 75, 23));
        widget = new QWidget(RoboConfig);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 103, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        widget1 = new QWidget(RoboConfig);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(130, 20, 126, 121));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        nomeComboBox = new QComboBox(widget1);
        nomeComboBox->setObjectName(QStringLiteral("nomeComboBox"));

        verticalLayout_2->addWidget(nomeComboBox);

        pidComboBox = new QComboBox(widget1);
        pidComboBox->setObjectName(QStringLiteral("pidComboBox"));

        verticalLayout_2->addWidget(pidComboBox);

        xBeeAdressComboBox = new QComboBox(widget1);
        xBeeAdressComboBox->setObjectName(QStringLiteral("xBeeAdressComboBox"));

        verticalLayout_2->addWidget(xBeeAdressComboBox);

        VelSpinBox = new QSpinBox(widget1);
        VelSpinBox->setObjectName(QStringLiteral("VelSpinBox"));
        VelSpinBox->setMaximum(500);
        VelSpinBox->setSingleStep(5);

        verticalLayout_2->addWidget(VelSpinBox);

        widget2 = new QWidget(RoboConfig);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(270, 20, 85, 151));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(widget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        widget3 = new QWidget(RoboConfig);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(365, 20, 176, 156));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        TipoObjetoComboBox = new QComboBox(widget3);
        TipoObjetoComboBox->setObjectName(QStringLiteral("TipoObjetoComboBox"));

        verticalLayout_4->addWidget(TipoObjetoComboBox);

        trajComboBox = new QComboBox(widget3);
        trajComboBox->setObjectName(QStringLiteral("trajComboBox"));

        verticalLayout_4->addWidget(trajComboBox);

        corPriComboBox = new QComboBox(widget3);
        corPriComboBox->setObjectName(QStringLiteral("corPriComboBox"));

        verticalLayout_4->addWidget(corPriComboBox);

        corSecComboBox = new QComboBox(widget3);
        corSecComboBox->setObjectName(QStringLiteral("corSecComboBox"));

        verticalLayout_4->addWidget(corSecComboBox);

        corTerComboBox = new QComboBox(widget3);
        corTerComboBox->setObjectName(QStringLiteral("corTerComboBox"));

        verticalLayout_4->addWidget(corTerComboBox);

        widget4 = new QWidget(RoboConfig);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(20, 150, 236, 25));
        horizontalLayout = new QHBoxLayout(widget4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        newButton = new QPushButton(widget4);
        newButton->setObjectName(QStringLiteral("newButton"));

        horizontalLayout->addWidget(newButton);

        saveButton = new QPushButton(widget4);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        deleteButton = new QPushButton(widget4);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        pushButton->raise();
        newButton->raise();
        saveButton->raise();
        deleteButton->raise();
        pidComboBox->raise();
        nomeComboBox->raise();
        corTerComboBox->raise();
        corPriComboBox->raise();
        corSecComboBox->raise();
        xBeeAdressComboBox->raise();
        TipoObjetoComboBox->raise();
        trajComboBox->raise();
        label_8->raise();
        label_9->raise();
        VelSpinBox->raise();
        label_2->raise();
        deleteButton->raise();

        retranslateUi(RoboConfig);

        QMetaObject::connectSlotsByName(RoboConfig);
    } // setupUi

    void retranslateUi(QWidget *RoboConfig)
    {
        RoboConfig->setWindowTitle(QApplication::translate("RoboConfig", "RoboConfig", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RoboConfig", "PushButton", Q_NULLPTR));
        label_2->setText(QApplication::translate("RoboConfig", "Nome :", Q_NULLPTR));
        label_4->setText(QApplication::translate("RoboConfig", "PID :", Q_NULLPTR));
        label_6->setText(QApplication::translate("RoboConfig", "Endere\303\247o do X-Bee :", Q_NULLPTR));
        label_9->setText(QApplication::translate("RoboConfig", "SetPointVel", Q_NULLPTR));
        label_7->setText(QApplication::translate("RoboConfig", "Tipo de Objeto:", Q_NULLPTR));
        label_8->setText(QApplication::translate("RoboConfig", "Trajet\303\263ria", Q_NULLPTR));
        label->setText(QApplication::translate("RoboConfig", "Cor Prim\303\241ria :", Q_NULLPTR));
        label_5->setText(QApplication::translate("RoboConfig", "Cor Secund\303\241ria :", Q_NULLPTR));
        label_3->setText(QApplication::translate("RoboConfig", "Cor Terci\303\241ria :", Q_NULLPTR));
        newButton->setText(QApplication::translate("RoboConfig", "Novo", Q_NULLPTR));
        saveButton->setText(QApplication::translate("RoboConfig", "Salvar", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("RoboConfig", "Deletar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RoboConfig: public Ui_RoboConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOCONFIG_H
