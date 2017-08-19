/********************************************************************************
** Form generated from reading UI file 'cameracalib.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACALIB_H
#define UI_CAMERACALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraCalib
{
public:
    QSlider *minHSlider;
    QSlider *minSSlider;
    QSlider *minVSlider;
    QSlider *maxHSlider;
    QSlider *maxSSlider;
    QSlider *maxVSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *colorComboBox;
    QLabel *label_8;
    QLabel *minHvalueLabel;
    QLabel *minSvalueLabel;
    QLabel *minVvalueLabel;
    QLabel *maxHvalueLabel;
    QLabel *maxSvalueLabel;
    QLabel *maxVvalueLabel;
    QLabel *minAreavalueLabel;
    QSlider *maxAreaSlider;
    QLabel *label_10;
    QSlider *minAreaSlider;
    QLabel *label_11;
    QLabel *maxAreavalueLabel;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveCamCalibButton;
    QPushButton *addColorButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *CameraCalib)
    {
        if (CameraCalib->objectName().isEmpty())
            CameraCalib->setObjectName(QStringLiteral("CameraCalib"));
        CameraCalib->resize(875, 288);
        minHSlider = new QSlider(CameraCalib);
        minHSlider->setObjectName(QStringLiteral("minHSlider"));
        minHSlider->setGeometry(QRect(30, 70, 200, 20));
        minHSlider->setFocusPolicy(Qt::StrongFocus);
        minHSlider->setAutoFillBackground(false);
        minHSlider->setMaximum(180);
        minHSlider->setOrientation(Qt::Horizontal);
        minHSlider->setTickPosition(QSlider::NoTicks);
        minSSlider = new QSlider(CameraCalib);
        minSSlider->setObjectName(QStringLiteral("minSSlider"));
        minSSlider->setGeometry(QRect(30, 120, 200, 20));
        minSSlider->setMaximum(255);
        minSSlider->setOrientation(Qt::Horizontal);
        minVSlider = new QSlider(CameraCalib);
        minVSlider->setObjectName(QStringLiteral("minVSlider"));
        minVSlider->setGeometry(QRect(30, 170, 200, 20));
        minVSlider->setMaximum(255);
        minVSlider->setOrientation(Qt::Horizontal);
        maxHSlider = new QSlider(CameraCalib);
        maxHSlider->setObjectName(QStringLiteral("maxHSlider"));
        maxHSlider->setGeometry(QRect(270, 70, 200, 20));
        maxHSlider->setMaximum(180);
        maxHSlider->setSliderPosition(180);
        maxHSlider->setOrientation(Qt::Horizontal);
        maxSSlider = new QSlider(CameraCalib);
        maxSSlider->setObjectName(QStringLiteral("maxSSlider"));
        maxSSlider->setGeometry(QRect(270, 120, 200, 20));
        maxSSlider->setMaximum(255);
        maxSSlider->setSliderPosition(255);
        maxSSlider->setOrientation(Qt::Horizontal);
        maxVSlider = new QSlider(CameraCalib);
        maxVSlider->setObjectName(QStringLiteral("maxVSlider"));
        maxVSlider->setGeometry(QRect(270, 170, 200, 20));
        maxVSlider->setMaximum(255);
        maxVSlider->setSliderPosition(255);
        maxVSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(CameraCalib);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 81, 16));
        label_3 = new QLabel(CameraCalib);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 111, 16));
        label_4 = new QLabel(CameraCalib);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 150, 141, 16));
        label_5 = new QLabel(CameraCalib);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 50, 81, 16));
        label_6 = new QLabel(CameraCalib);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 100, 111, 16));
        label_7 = new QLabel(CameraCalib);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(270, 150, 141, 16));
        colorComboBox = new QComboBox(CameraCalib);
        colorComboBox->setObjectName(QStringLiteral("colorComboBox"));
        colorComboBox->setGeometry(QRect(70, 15, 161, 22));
        label_8 = new QLabel(CameraCalib);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 20, 47, 13));
        minHvalueLabel = new QLabel(CameraCalib);
        minHvalueLabel->setObjectName(QStringLiteral("minHvalueLabel"));
        minHvalueLabel->setGeometry(QRect(240, 70, 47, 13));
        minSvalueLabel = new QLabel(CameraCalib);
        minSvalueLabel->setObjectName(QStringLiteral("minSvalueLabel"));
        minSvalueLabel->setGeometry(QRect(240, 120, 47, 13));
        minVvalueLabel = new QLabel(CameraCalib);
        minVvalueLabel->setObjectName(QStringLiteral("minVvalueLabel"));
        minVvalueLabel->setGeometry(QRect(240, 170, 47, 13));
        maxHvalueLabel = new QLabel(CameraCalib);
        maxHvalueLabel->setObjectName(QStringLiteral("maxHvalueLabel"));
        maxHvalueLabel->setGeometry(QRect(480, 70, 47, 13));
        maxSvalueLabel = new QLabel(CameraCalib);
        maxSvalueLabel->setObjectName(QStringLiteral("maxSvalueLabel"));
        maxSvalueLabel->setGeometry(QRect(480, 120, 47, 13));
        maxVvalueLabel = new QLabel(CameraCalib);
        maxVvalueLabel->setObjectName(QStringLiteral("maxVvalueLabel"));
        maxVvalueLabel->setGeometry(QRect(480, 170, 47, 13));
        minAreavalueLabel = new QLabel(CameraCalib);
        minAreavalueLabel->setObjectName(QStringLiteral("minAreavalueLabel"));
        minAreavalueLabel->setGeometry(QRect(240, 220, 47, 13));
        maxAreaSlider = new QSlider(CameraCalib);
        maxAreaSlider->setObjectName(QStringLiteral("maxAreaSlider"));
        maxAreaSlider->setGeometry(QRect(270, 220, 200, 20));
        maxAreaSlider->setMaximum(154000);
        maxAreaSlider->setSliderPosition(154000);
        maxAreaSlider->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(CameraCalib);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 200, 111, 16));
        minAreaSlider = new QSlider(CameraCalib);
        minAreaSlider->setObjectName(QStringLiteral("minAreaSlider"));
        minAreaSlider->setGeometry(QRect(30, 220, 200, 20));
        minAreaSlider->setMaximum(154000);
        minAreaSlider->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(CameraCalib);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(270, 200, 141, 16));
        maxAreavalueLabel = new QLabel(CameraCalib);
        maxAreavalueLabel->setObjectName(QStringLiteral("maxAreavalueLabel"));
        maxAreavalueLabel->setGeometry(QRect(480, 220, 47, 13));
        groupBox = new QGroupBox(CameraCalib);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(520, 10, 341, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 320, 240));
        label->setAutoFillBackground(true);
        widget = new QWidget(CameraCalib);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(125, 245, 239, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveCamCalibButton = new QPushButton(widget);
        saveCamCalibButton->setObjectName(QStringLiteral("saveCamCalibButton"));

        horizontalLayout->addWidget(saveCamCalibButton);

        addColorButton = new QPushButton(widget);
        addColorButton->setObjectName(QStringLiteral("addColorButton"));

        horizontalLayout->addWidget(addColorButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        minHSlider->raise();
        minSSlider->raise();
        minVSlider->raise();
        maxHSlider->raise();
        maxSSlider->raise();
        maxVSlider->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        saveCamCalibButton->raise();
        colorComboBox->raise();
        label_8->raise();
        addColorButton->raise();
        minHvalueLabel->raise();
        minSvalueLabel->raise();
        minVvalueLabel->raise();
        maxHvalueLabel->raise();
        maxSvalueLabel->raise();
        maxVvalueLabel->raise();
        minAreavalueLabel->raise();
        maxAreaSlider->raise();
        label_10->raise();
        minAreaSlider->raise();
        label_11->raise();
        maxAreavalueLabel->raise();
        deleteButton->raise();
        groupBox->raise();
        addColorButton->raise();

        retranslateUi(CameraCalib);

        QMetaObject::connectSlotsByName(CameraCalib);
    } // setupUi

    void retranslateUi(QWidget *CameraCalib)
    {
        CameraCalib->setWindowTitle(QApplication::translate("CameraCalib", "CameraCalib", Q_NULLPTR));
        label_2->setText(QApplication::translate("CameraCalib", "M\303\255nimo Hue (H)", Q_NULLPTR));
        label_3->setText(QApplication::translate("CameraCalib", "M\303\255nimo Saturation (S)", Q_NULLPTR));
        label_4->setText(QApplication::translate("CameraCalib", "M\303\255nimo Value/Brigthness (V)", Q_NULLPTR));
        label_5->setText(QApplication::translate("CameraCalib", "M\303\241ximo Hue (H)", Q_NULLPTR));
        label_6->setText(QApplication::translate("CameraCalib", "M\303\241ximo Saturation (S)", Q_NULLPTR));
        label_7->setText(QApplication::translate("CameraCalib", "M\303\241ximo Value/Brigthness (V)", Q_NULLPTR));
        label_8->setText(QApplication::translate("CameraCalib", "Cor:", Q_NULLPTR));
        minHvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        minSvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        minVvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        maxHvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        maxSvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        maxVvalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        minAreavalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("CameraCalib", "M\303\255nima \303\201rea (pixel)", Q_NULLPTR));
        label_11->setText(QApplication::translate("CameraCalib", "M\303\241xima \303\201rea (pixel)", Q_NULLPTR));
        maxAreavalueLabel->setText(QApplication::translate("CameraCalib", "0", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CameraCalib", "Resultado", Q_NULLPTR));
        label->setText(QApplication::translate("CameraCalib", "TextLabel", Q_NULLPTR));
        saveCamCalibButton->setText(QApplication::translate("CameraCalib", "Salvar", Q_NULLPTR));
        addColorButton->setText(QApplication::translate("CameraCalib", "Adicionar", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("CameraCalib", "Deletar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CameraCalib: public Ui_CameraCalib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACALIB_H
