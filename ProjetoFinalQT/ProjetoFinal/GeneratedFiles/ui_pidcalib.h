/********************************************************************************
** Form generated from reading UI file 'pidcalib.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIDCALIB_H
#define UI_PIDCALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PIDCalib
{
public:
    QLabel *label_14;
    QFrame *line_4;
    QFrame *line_5;
    QTabWidget *tabWidget;
    QWidget *tabTraj;
    QComboBox *trajComboBox;
    QLabel *label_12;
    QCheckBox *clockwiseCheckBoxTraj;
    QWidget *tabPointAndClick;
    QLabel *label_15;
    QWidget *tabLemniscata;
    QLabel *label_17;
    QLabel *radiusLabelLemniscata;
    QSlider *radiusSliderLemniscata;
    QSlider *periodSliderLemniscata;
    QLabel *periodLabelLemniscata;
    QLabel *label_18;
    QCheckBox *clockwiseCheckBoxLemniscata;
    QLabel *label_16;
    QWidget *tabCirculo;
    QSlider *radiusSliderCirculo;
    QSlider *periodSliderCirculo;
    QCheckBox *clockwiseCheckBoxCirculo;
    QLabel *radiusLabelCirculo;
    QLabel *label_21;
    QLabel *periodLabelCirculo;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *tabLinha;
    QCheckBox *clockwiseCheckBoxLinha;
    QLabel *label_24;
    QLabel *sentidoLabelLinha;
    QPushButton *stopTestButton;
    QPushButton *startTestButton;
    QCheckBox *manualCheckBox;
    QCheckBox *congelaCheckBox;
    QCheckBox *showCarsCheckBox;
    QGroupBox *groupBox_4;
    QPushButton *newRobotButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *newPIDButton;
    QComboBox *robotComboBox;
    QComboBox *pidComboBox;
    QPushButton *saveButton;
    QComboBox *robotSecComboBox;
    QLabel *label_3;
    QTextBrowser *text;
    QCheckBox *LogStatCheckBox;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QDoubleSpinBox *DASpinBox;
    QLabel *label_9;
    QDoubleSpinBox *IASpinBox;
    QDoubleSpinBox *PASpinBox;
    QLabel *label_10;
    QGroupBox *groupBox;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *DLSpinBox;
    QDoubleSpinBox *ILSpinBox;
    QDoubleSpinBox *PLSpinBox;
    QGroupBox *groupBox_5;
    QDoubleSpinBox *kAngDesSpinBox;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *velSpinBox;

    void setupUi(QWidget *PIDCalib)
    {
        if (PIDCalib->objectName().isEmpty())
            PIDCalib->setObjectName(QStringLiteral("PIDCalib"));
        PIDCalib->resize(674, 378);
        PIDCalib->setMouseTracking(true);
        PIDCalib->setFocusPolicy(Qt::NoFocus);
        label_14 = new QLabel(PIDCalib);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(125, 0, 70, 16));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(false);
        font.setStyleStrategy(QFont::PreferDefault);
        label_14->setFont(font);
        label_14->setAutoFillBackground(false);
        line_4 = new QFrame(PIDCalib);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 0, 98, 20));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        line_4->setFont(font1);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(PIDCalib);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(222, 0, 98, 20));
        line_5->setFont(font1);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(PIDCalib);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 19, 301, 171));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabTraj = new QWidget();
        tabTraj->setObjectName(QStringLiteral("tabTraj"));
        trajComboBox = new QComboBox(tabTraj);
        trajComboBox->setObjectName(QStringLiteral("trajComboBox"));
        trajComboBox->setGeometry(QRect(70, 20, 201, 22));
        label_12 = new QLabel(tabTraj);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 61, 16));
        clockwiseCheckBoxTraj = new QCheckBox(tabTraj);
        clockwiseCheckBoxTraj->setObjectName(QStringLiteral("clockwiseCheckBoxTraj"));
        clockwiseCheckBoxTraj->setGeometry(QRect(0, 50, 101, 20));
        clockwiseCheckBoxTraj->setLayoutDirection(Qt::RightToLeft);
        clockwiseCheckBoxTraj->setChecked(true);
        tabWidget->addTab(tabTraj, QString());
        tabPointAndClick = new QWidget();
        tabPointAndClick->setObjectName(QStringLiteral("tabPointAndClick"));
        label_15 = new QLabel(tabPointAndClick);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 0, 181, 21));
        tabWidget->addTab(tabPointAndClick, QString());
        tabLemniscata = new QWidget();
        tabLemniscata->setObjectName(QStringLiteral("tabLemniscata"));
        label_17 = new QLabel(tabLemniscata);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 35, 47, 13));
        radiusLabelLemniscata = new QLabel(tabLemniscata);
        radiusLabelLemniscata->setObjectName(QStringLiteral("radiusLabelLemniscata"));
        radiusLabelLemniscata->setGeometry(QRect(250, 75, 47, 13));
        radiusSliderLemniscata = new QSlider(tabLemniscata);
        radiusSliderLemniscata->setObjectName(QStringLiteral("radiusSliderLemniscata"));
        radiusSliderLemniscata->setGeometry(QRect(70, 75, 171, 22));
        radiusSliderLemniscata->setMaximum(100);
        radiusSliderLemniscata->setOrientation(Qt::Horizontal);
        periodSliderLemniscata = new QSlider(tabLemniscata);
        periodSliderLemniscata->setObjectName(QStringLiteral("periodSliderLemniscata"));
        periodSliderLemniscata->setGeometry(QRect(70, 35, 171, 22));
        periodSliderLemniscata->setMaximum(100);
        periodSliderLemniscata->setOrientation(Qt::Horizontal);
        periodLabelLemniscata = new QLabel(tabLemniscata);
        periodLabelLemniscata->setObjectName(QStringLiteral("periodLabelLemniscata"));
        periodLabelLemniscata->setGeometry(QRect(250, 35, 47, 13));
        label_18 = new QLabel(tabLemniscata);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 75, 47, 13));
        clockwiseCheckBoxLemniscata = new QCheckBox(tabLemniscata);
        clockwiseCheckBoxLemniscata->setObjectName(QStringLiteral("clockwiseCheckBoxLemniscata"));
        clockwiseCheckBoxLemniscata->setGeometry(QRect(-28, 110, 131, 17));
        clockwiseCheckBoxLemniscata->setLayoutDirection(Qt::RightToLeft);
        label_16 = new QLabel(tabLemniscata);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 0, 281, 21));
        tabWidget->addTab(tabLemniscata, QString());
        tabCirculo = new QWidget();
        tabCirculo->setObjectName(QStringLiteral("tabCirculo"));
        radiusSliderCirculo = new QSlider(tabCirculo);
        radiusSliderCirculo->setObjectName(QStringLiteral("radiusSliderCirculo"));
        radiusSliderCirculo->setGeometry(QRect(70, 75, 171, 22));
        radiusSliderCirculo->setMaximum(100);
        radiusSliderCirculo->setOrientation(Qt::Horizontal);
        periodSliderCirculo = new QSlider(tabCirculo);
        periodSliderCirculo->setObjectName(QStringLiteral("periodSliderCirculo"));
        periodSliderCirculo->setGeometry(QRect(70, 35, 171, 22));
        periodSliderCirculo->setMaximum(100);
        periodSliderCirculo->setOrientation(Qt::Horizontal);
        clockwiseCheckBoxCirculo = new QCheckBox(tabCirculo);
        clockwiseCheckBoxCirculo->setObjectName(QStringLiteral("clockwiseCheckBoxCirculo"));
        clockwiseCheckBoxCirculo->setGeometry(QRect(-28, 110, 131, 17));
        clockwiseCheckBoxCirculo->setLayoutDirection(Qt::RightToLeft);
        radiusLabelCirculo = new QLabel(tabCirculo);
        radiusLabelCirculo->setObjectName(QStringLiteral("radiusLabelCirculo"));
        radiusLabelCirculo->setGeometry(QRect(250, 75, 47, 13));
        label_21 = new QLabel(tabCirculo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 35, 47, 13));
        periodLabelCirculo = new QLabel(tabCirculo);
        periodLabelCirculo->setObjectName(QStringLiteral("periodLabelCirculo"));
        periodLabelCirculo->setGeometry(QRect(250, 35, 47, 13));
        label_22 = new QLabel(tabCirculo);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 75, 47, 13));
        label_23 = new QLabel(tabCirculo);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 0, 281, 21));
        tabWidget->addTab(tabCirculo, QString());
        tabLinha = new QWidget();
        tabLinha->setObjectName(QStringLiteral("tabLinha"));
        clockwiseCheckBoxLinha = new QCheckBox(tabLinha);
        clockwiseCheckBoxLinha->setObjectName(QStringLiteral("clockwiseCheckBoxLinha"));
        clockwiseCheckBoxLinha->setGeometry(QRect(-4, 60, 131, 17));
        clockwiseCheckBoxLinha->setLayoutDirection(Qt::RightToLeft);
        label_24 = new QLabel(tabLinha);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 0, 281, 21));
        sentidoLabelLinha = new QLabel(tabLinha);
        sentidoLabelLinha->setObjectName(QStringLiteral("sentidoLabelLinha"));
        sentidoLabelLinha->setGeometry(QRect(150, 60, 81, 16));
        tabWidget->addTab(tabLinha, QString());
        stopTestButton = new QPushButton(PIDCalib);
        stopTestButton->setObjectName(QStringLiteral("stopTestButton"));
        stopTestButton->setGeometry(QRect(10, 220, 75, 23));
        startTestButton = new QPushButton(PIDCalib);
        startTestButton->setObjectName(QStringLiteral("startTestButton"));
        startTestButton->setGeometry(QRect(10, 196, 75, 23));
        manualCheckBox = new QCheckBox(PIDCalib);
        manualCheckBox->setObjectName(QStringLiteral("manualCheckBox"));
        manualCheckBox->setGeometry(QRect(100, 200, 101, 17));
        congelaCheckBox = new QCheckBox(PIDCalib);
        congelaCheckBox->setObjectName(QStringLiteral("congelaCheckBox"));
        congelaCheckBox->setGeometry(QRect(100, 220, 121, 17));
        showCarsCheckBox = new QCheckBox(PIDCalib);
        showCarsCheckBox->setObjectName(QStringLiteral("showCarsCheckBox"));
        showCarsCheckBox->setGeometry(QRect(220, 200, 91, 17));
        groupBox_4 = new QGroupBox(PIDCalib);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 250, 311, 111));
        newRobotButton = new QPushButton(groupBox_4);
        newRobotButton->setObjectName(QStringLiteral("newRobotButton"));
        newRobotButton->setGeometry(QRect(200, 20, 75, 23));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 20, 47, 13));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(22, 40, 31, 31));
        label_2->setWordWrap(false);
        newPIDButton = new QPushButton(groupBox_4);
        newPIDButton->setObjectName(QStringLiteral("newPIDButton"));
        newPIDButton->setGeometry(QRect(200, 50, 75, 23));
        robotComboBox = new QComboBox(groupBox_4);
        robotComboBox->setObjectName(QStringLiteral("robotComboBox"));
        robotComboBox->setGeometry(QRect(52, 20, 141, 22));
        robotComboBox->setAutoFillBackground(true);
        pidComboBox = new QComboBox(groupBox_4);
        pidComboBox->setObjectName(QStringLiteral("pidComboBox"));
        pidComboBox->setGeometry(QRect(52, 50, 141, 22));
        pidComboBox->setAutoFillBackground(true);
        saveButton = new QPushButton(groupBox_4);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(200, 80, 75, 23));
        robotSecComboBox = new QComboBox(groupBox_4);
        robotSecComboBox->setObjectName(QStringLiteral("robotSecComboBox"));
        robotSecComboBox->setEnabled(true);
        robotSecComboBox->setGeometry(QRect(52, 80, 141, 22));
        robotSecComboBox->setAutoFillBackground(true);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(2, 80, 47, 13));
        text = new QTextBrowser(PIDCalib);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(335, 250, 321, 111));
        LogStatCheckBox = new QCheckBox(PIDCalib);
        LogStatCheckBox->setObjectName(QStringLiteral("LogStatCheckBox"));
        LogStatCheckBox->setGeometry(QRect(220, 220, 70, 17));
        groupBox_6 = new QGroupBox(PIDCalib);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(340, 10, 316, 231));
        groupBox_2 = new QGroupBox(groupBox_6);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 115, 191, 111));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 80, 81, 20));
        DASpinBox = new QDoubleSpinBox(groupBox_2);
        DASpinBox->setObjectName(QStringLiteral("DASpinBox"));
        DASpinBox->setGeometry(QRect(110, 50, 71, 22));
        DASpinBox->setMinimum(-100);
        DASpinBox->setMaximum(100);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 50, 81, 20));
        IASpinBox = new QDoubleSpinBox(groupBox_2);
        IASpinBox->setObjectName(QStringLiteral("IASpinBox"));
        IASpinBox->setGeometry(QRect(110, 80, 71, 22));
        IASpinBox->setMinimum(-100);
        IASpinBox->setMaximum(100);
        PASpinBox = new QDoubleSpinBox(groupBox_2);
        PASpinBox->setObjectName(QStringLiteral("PASpinBox"));
        PASpinBox->setGeometry(QRect(110, 20, 71, 22));
        PASpinBox->setMinimum(-100);
        PASpinBox->setMaximum(100);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 91, 16));
        groupBox = new QGroupBox(groupBox_6);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 15, 191, 101));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 81, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 81, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 91, 16));
        DLSpinBox = new QDoubleSpinBox(groupBox);
        DLSpinBox->setObjectName(QStringLiteral("DLSpinBox"));
        DLSpinBox->setGeometry(QRect(110, 40, 71, 22));
        DLSpinBox->setMinimum(-100);
        DLSpinBox->setMaximum(100);
        ILSpinBox = new QDoubleSpinBox(groupBox);
        ILSpinBox->setObjectName(QStringLiteral("ILSpinBox"));
        ILSpinBox->setGeometry(QRect(110, 70, 71, 22));
        ILSpinBox->setMinimum(-100);
        ILSpinBox->setMaximum(100);
        PLSpinBox = new QDoubleSpinBox(groupBox);
        PLSpinBox->setObjectName(QStringLiteral("PLSpinBox"));
        PLSpinBox->setGeometry(QRect(110, 10, 71, 22));
        PLSpinBox->setMinimum(-100);
        PLSpinBox->setMaximum(100);
        groupBox_5 = new QGroupBox(groupBox_6);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(210, 130, 91, 80));
        kAngDesSpinBox = new QDoubleSpinBox(groupBox_5);
        kAngDesSpinBox->setObjectName(QStringLiteral("kAngDesSpinBox"));
        kAngDesSpinBox->setGeometry(QRect(10, 30, 71, 22));
        kAngDesSpinBox->setDecimals(3);
        kAngDesSpinBox->setMaximum(1000);
        kAngDesSpinBox->setValue(0.01);
        groupBox_3 = new QGroupBox(groupBox_6);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(210, 20, 91, 80));
        velSpinBox = new QDoubleSpinBox(groupBox_3);
        velSpinBox->setObjectName(QStringLiteral("velSpinBox"));
        velSpinBox->setGeometry(QRect(10, 30, 71, 22));
        velSpinBox->setDecimals(0);
        velSpinBox->setMaximum(1000);

        retranslateUi(PIDCalib);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PIDCalib);
    } // setupUi

    void retranslateUi(QWidget *PIDCalib)
    {
        PIDCalib->setWindowTitle(QApplication::translate("PIDCalib", "PIDCalib", Q_NULLPTR));
        label_14->setText(QApplication::translate("PIDCalib", "\303\201rea de Teste", Q_NULLPTR));
        label_12->setText(QApplication::translate("PIDCalib", "Trajet\303\263ria:", Q_NULLPTR));
        clockwiseCheckBoxTraj->setText(QApplication::translate("PIDCalib", "Sentido Hor\303\241rio", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabTraj), QApplication::translate("PIDCalib", "Carga de trajetoria", Q_NULLPTR));
        label_15->setText(QApplication::translate("PIDCalib", "Selecione um ponto na imagem", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabPointAndClick), QApplication::translate("PIDCalib", "Point and Click", Q_NULLPTR));
        label_17->setText(QApplication::translate("PIDCalib", "Per\303\255odo :", Q_NULLPTR));
        radiusLabelLemniscata->setText(QApplication::translate("PIDCalib", "0", Q_NULLPTR));
        periodLabelLemniscata->setText(QApplication::translate("PIDCalib", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("PIDCalib", " Raio :", Q_NULLPTR));
        clockwiseCheckBoxLemniscata->setText(QApplication::translate("PIDCalib", "Sentido Hor\303\241rio", Q_NULLPTR));
        label_16->setText(QApplication::translate("PIDCalib", "Selecione um ponto na imagem para ser o centro da curva", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabLemniscata), QApplication::translate("PIDCalib", "Lemniscata", Q_NULLPTR));
        clockwiseCheckBoxCirculo->setText(QApplication::translate("PIDCalib", "Sentido Hor\303\241rio", Q_NULLPTR));
        radiusLabelCirculo->setText(QApplication::translate("PIDCalib", "0", Q_NULLPTR));
        label_21->setText(QApplication::translate("PIDCalib", "Per\303\255odo :", Q_NULLPTR));
        periodLabelCirculo->setText(QApplication::translate("PIDCalib", "0", Q_NULLPTR));
        label_22->setText(QApplication::translate("PIDCalib", " Raio :", Q_NULLPTR));
        label_23->setText(QApplication::translate("PIDCalib", "Selecione um ponto na imagem para ser o centro do c\303\255rculo", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabCirculo), QApplication::translate("PIDCalib", "Circulo", Q_NULLPTR));
        clockwiseCheckBoxLinha->setText(QApplication::translate("PIDCalib", "Sentido do Moviento", Q_NULLPTR));
        label_24->setText(QApplication::translate("PIDCalib", "Selecione dois pontos na imagem para definir uma linha", Q_NULLPTR));
        sentidoLabelLinha->setText(QApplication::translate("PIDCalib", "Baixo/Esquerda", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabLinha), QApplication::translate("PIDCalib", "Linha", Q_NULLPTR));
        stopTestButton->setText(QApplication::translate("PIDCalib", "Pausar", Q_NULLPTR));
        startTestButton->setText(QApplication::translate("PIDCalib", "Iniciar", Q_NULLPTR));
        manualCheckBox->setText(QApplication::translate("PIDCalib", "Controle Manual", Q_NULLPTR));
        congelaCheckBox->setText(QApplication::translate("PIDCalib", "Congela/Descongela", Q_NULLPTR));
        showCarsCheckBox->setText(QApplication::translate("PIDCalib", "Mostrar Rob\303\264", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        newRobotButton->setText(QApplication::translate("PIDCalib", "Novo", Q_NULLPTR));
        label->setText(QApplication::translate("PIDCalib", " Rob\303\264:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PIDCalib", "PID:", Q_NULLPTR));
        newPIDButton->setText(QApplication::translate("PIDCalib", "Nova", Q_NULLPTR));
        saveButton->setText(QApplication::translate("PIDCalib", "Salvar", Q_NULLPTR));
        label_3->setText(QApplication::translate("PIDCalib", " Rob\303\264 2:", Q_NULLPTR));
        LogStatCheckBox->setText(QApplication::translate("PIDCalib", "Log Stat", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("PIDCalib", "Par\303\242metros do PID", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("PIDCalib", "Angular", Q_NULLPTR));
        label_11->setText(QApplication::translate("PIDCalib", "Integrador (I) :", Q_NULLPTR));
        label_9->setText(QApplication::translate("PIDCalib", "Derivativo (D) :", Q_NULLPTR));
        label_10->setText(QApplication::translate("PIDCalib", "Proporcional (P) :", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PIDCalib", "Linear", Q_NULLPTR));
        label_7->setText(QApplication::translate("PIDCalib", "Integrador (I) :", Q_NULLPTR));
        label_6->setText(QApplication::translate("PIDCalib", "Derivativo (D) :", Q_NULLPTR));
        label_5->setText(QApplication::translate("PIDCalib", "Proporcional (P) :", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("PIDCalib", "AngDesejado", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("PIDCalib", "Cruise Control", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PIDCalib: public Ui_PIDCalib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIDCALIB_H
