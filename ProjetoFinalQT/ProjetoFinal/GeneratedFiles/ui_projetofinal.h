/********************************************************************************
** Form generated from reading UI file 'projetofinal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETOFINAL_H
#define UI_PROJETOFINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetoFinalClass
{
public:
    QAction *actionCalibrar_Filtros_de_Cor;
    QAction *actionCalibrar_Controle;
    QAction *actionNovo_Robo;
    QWidget *centralWidget;
    QPushButton *startButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkShowimageBox;
    QCheckBox *checkShowTraj;
    QCheckBox *checkShowDrawBox;
    QCheckBox *checkShowBlob;
    QFrame *line;
    QPushButton *pauseButton;
    QLabel *label;
    QPlainTextEdit *XYText;
    QFrame *line_2;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QDoubleSpinBox *DASpinBox;
    QLabel *label_9;
    QDoubleSpinBox *IASpinBox;
    QDoubleSpinBox *PASpinBox;
    QLabel *label_10;
    QGroupBox *groupBox_4;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *DLSpinBox;
    QDoubleSpinBox *ILSpinBox;
    QDoubleSpinBox *PLSpinBox;
    QGroupBox *groupBox;
    QLabel *label_12;
    QDoubleSpinBox *IASpinBox_2;
    QLabel *label_13;
    QDoubleSpinBox *IASpinBox_3;
    QMenuBar *menuBar;
    QMenu *menuOp_es;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetoFinalClass)
    {
        if (ProjetoFinalClass->objectName().isEmpty())
            ProjetoFinalClass->setObjectName(QStringLiteral("ProjetoFinalClass"));
        ProjetoFinalClass->resize(884, 534);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProjetoFinalClass->sizePolicy().hasHeightForWidth());
        ProjetoFinalClass->setSizePolicy(sizePolicy);
        actionCalibrar_Filtros_de_Cor = new QAction(ProjetoFinalClass);
        actionCalibrar_Filtros_de_Cor->setObjectName(QStringLiteral("actionCalibrar_Filtros_de_Cor"));
        actionCalibrar_Controle = new QAction(ProjetoFinalClass);
        actionCalibrar_Controle->setObjectName(QStringLiteral("actionCalibrar_Controle"));
        actionNovo_Robo = new QAction(ProjetoFinalClass);
        actionNovo_Robo->setObjectName(QStringLiteral("actionNovo_Robo"));
        centralWidget = new QWidget(ProjetoFinalClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(340, 420, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 300, 165, 107));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkShowimageBox = new QCheckBox(layoutWidget);
        checkShowimageBox->setObjectName(QStringLiteral("checkShowimageBox"));

        verticalLayout->addWidget(checkShowimageBox);

        checkShowTraj = new QCheckBox(layoutWidget);
        checkShowTraj->setObjectName(QStringLiteral("checkShowTraj"));
        checkShowTraj->setEnabled(false);

        verticalLayout->addWidget(checkShowTraj);

        checkShowDrawBox = new QCheckBox(layoutWidget);
        checkShowDrawBox->setObjectName(QStringLiteral("checkShowDrawBox"));
        checkShowDrawBox->setEnabled(false);

        verticalLayout->addWidget(checkShowDrawBox);

        checkShowBlob = new QCheckBox(layoutWidget);
        checkShowBlob->setObjectName(QStringLiteral("checkShowBlob"));
        checkShowBlob->setEnabled(false);

        verticalLayout->addWidget(checkShowBlob);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(560, -30, 20, 801));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);
        pauseButton->setGeometry(QRect(430, 420, 75, 23));
        pauseButton->setFlat(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 10, 361, 231));
        label->setAutoFillBackground(true);
        XYText = new QPlainTextEdit(centralWidget);
        XYText->setObjectName(QStringLiteral("XYText"));
        XYText->setGeometry(QRect(10, 300, 281, 141));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(570, 285, 311, 41));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(600, 150, 241, 121));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 80, 81, 20));
        DASpinBox = new QDoubleSpinBox(groupBox_3);
        DASpinBox->setObjectName(QStringLiteral("DASpinBox"));
        DASpinBox->setGeometry(QRect(110, 50, 71, 22));
        DASpinBox->setMinimum(-100);
        DASpinBox->setMaximum(100);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 50, 81, 20));
        IASpinBox = new QDoubleSpinBox(groupBox_3);
        IASpinBox->setObjectName(QStringLiteral("IASpinBox"));
        IASpinBox->setGeometry(QRect(110, 80, 71, 22));
        IASpinBox->setMinimum(-100);
        IASpinBox->setMaximum(100);
        PASpinBox = new QDoubleSpinBox(groupBox_3);
        PASpinBox->setObjectName(QStringLiteral("PASpinBox"));
        PASpinBox->setGeometry(QRect(110, 20, 71, 22));
        PASpinBox->setMinimum(-100);
        PASpinBox->setMaximum(100);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 91, 16));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(600, 20, 241, 121));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 81, 20));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 81, 20));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 91, 16));
        DLSpinBox = new QDoubleSpinBox(groupBox_4);
        DLSpinBox->setObjectName(QStringLiteral("DLSpinBox"));
        DLSpinBox->setGeometry(QRect(110, 40, 71, 22));
        DLSpinBox->setMinimum(-100);
        DLSpinBox->setMaximum(100);
        ILSpinBox = new QDoubleSpinBox(groupBox_4);
        ILSpinBox->setObjectName(QStringLiteral("ILSpinBox"));
        ILSpinBox->setGeometry(QRect(110, 70, 71, 22));
        ILSpinBox->setMinimum(-100);
        ILSpinBox->setMaximum(100);
        PLSpinBox = new QDoubleSpinBox(groupBox_4);
        PLSpinBox->setObjectName(QStringLiteral("PLSpinBox"));
        PLSpinBox->setGeometry(QRect(110, 10, 71, 22));
        PLSpinBox->setMinimum(-100);
        PLSpinBox->setMaximum(100);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(600, 320, 241, 111));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 101, 16));
        IASpinBox_2 = new QDoubleSpinBox(groupBox);
        IASpinBox_2->setObjectName(QStringLiteral("IASpinBox_2"));
        IASpinBox_2->setGeometry(QRect(110, 20, 71, 22));
        IASpinBox_2->setMinimum(-100);
        IASpinBox_2->setMaximum(100);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 60, 101, 16));
        IASpinBox_3 = new QDoubleSpinBox(groupBox);
        IASpinBox_3->setObjectName(QStringLiteral("IASpinBox_3"));
        IASpinBox_3->setGeometry(QRect(110, 60, 71, 22));
        IASpinBox_3->setMinimum(-100);
        IASpinBox_3->setMaximum(100);
        ProjetoFinalClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjetoFinalClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 884, 21));
        menuOp_es = new QMenu(menuBar);
        menuOp_es->setObjectName(QStringLiteral("menuOp_es"));
        ProjetoFinalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetoFinalClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjetoFinalClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjetoFinalClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjetoFinalClass->setStatusBar(statusBar);

        menuBar->addAction(menuOp_es->menuAction());
        menuOp_es->addAction(actionCalibrar_Filtros_de_Cor);
        menuOp_es->addAction(actionCalibrar_Controle);
        menuOp_es->addAction(actionNovo_Robo);

        retranslateUi(ProjetoFinalClass);

        pauseButton->setDefault(false);


        QMetaObject::connectSlotsByName(ProjetoFinalClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetoFinalClass)
    {
        ProjetoFinalClass->setWindowTitle(QApplication::translate("ProjetoFinalClass", "ProjetoFinal", Q_NULLPTR));
        actionCalibrar_Filtros_de_Cor->setText(QApplication::translate("ProjetoFinalClass", "Calibrar Filtros de Cor", Q_NULLPTR));
        actionCalibrar_Controle->setText(QApplication::translate("ProjetoFinalClass", "Calibrar Controle dos r\303\264bos", Q_NULLPTR));
        actionNovo_Robo->setText(QApplication::translate("ProjetoFinalClass", "Cadastro Rob\303\264s", Q_NULLPTR));
        startButton->setText(QApplication::translate("ProjetoFinalClass", "Iniciar", Q_NULLPTR));
        checkShowimageBox->setText(QApplication::translate("ProjetoFinalClass", "Mostrar a imagem da C\303\242mera", Q_NULLPTR));
        checkShowTraj->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Trajet\303\263ria", Q_NULLPTR));
        checkShowDrawBox->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Desenho Rob\303\264", Q_NULLPTR));
        checkShowBlob->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Blobs Imagem", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("ProjetoFinalClass", "Pausar", Q_NULLPTR));
        label->setText(QApplication::translate("ProjetoFinalClass", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ProjetoFinalClass", "Angular", Q_NULLPTR));
        label_11->setText(QApplication::translate("ProjetoFinalClass", "Integrador (I) :", Q_NULLPTR));
        label_9->setText(QApplication::translate("ProjetoFinalClass", "Derivativo (D) :", Q_NULLPTR));
        label_10->setText(QApplication::translate("ProjetoFinalClass", "Proporcional (P) :", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("ProjetoFinalClass", "Linear", Q_NULLPTR));
        label_7->setText(QApplication::translate("ProjetoFinalClass", "Integrador (I) :", Q_NULLPTR));
        label_6->setText(QApplication::translate("ProjetoFinalClass", "Derivativo (D) :", Q_NULLPTR));
        label_5->setText(QApplication::translate("ProjetoFinalClass", "Proporcional (P) :", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ProjetoFinalClass", "ESC", Q_NULLPTR));
        label_12->setText(QApplication::translate("ProjetoFinalClass", "Maximizante (deg):", Q_NULLPTR));
        label_13->setText(QApplication::translate("ProjetoFinalClass", "Valor do M\303\241ximo", Q_NULLPTR));
        menuOp_es->setTitle(QApplication::translate("ProjetoFinalClass", "Configura\303\247\303\265es", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProjetoFinalClass: public Ui_ProjetoFinalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETOFINAL_H
