/********************************************************************************
** Form generated from reading UI file 'projetofinal.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QPushButton *pauseButton;
    QPlainTextEdit *XYText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkShowimageBox;
    QCheckBox *checkShowDrawBox;
    QCheckBox *checkShowBlob;
    QCheckBox *checkShowTraj;
    QGroupBox *groupBox_3;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *freqSenoideCoringa;
    QDoubleSpinBox *ampSenoideCoringa;
    QGroupBox *groupBox;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *DLSpinBox;
    QDoubleSpinBox *ILSpinBox;
    QDoubleSpinBox *PLSpinBox;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QDoubleSpinBox *DASpinBox;
    QLabel *label_9;
    QDoubleSpinBox *IASpinBox;
    QDoubleSpinBox *PASpinBox;
    QLabel *label_10;
    QComboBox *pidComboBoxMain;
    QLabel *label_2;
    QPushButton *saveButton;
    QGroupBox *groupBox_4;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *DLSpinBox_3;
    QComboBox *maxEscComboBox;
    QMenuBar *menuBar;
    QMenu *menuOp_es;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetoFinalClass)
    {
        if (ProjetoFinalClass->objectName().isEmpty())
            ProjetoFinalClass->setObjectName(QStringLiteral("ProjetoFinalClass"));
        ProjetoFinalClass->resize(772, 390);
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
        startButton->setGeometry(QRect(380, 300, 75, 23));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);
        pauseButton->setGeometry(QRect(470, 300, 75, 23));
        pauseButton->setFlat(false);
        XYText = new QPlainTextEdit(centralWidget);
        XYText->setObjectName(QStringLiteral("XYText"));
        XYText->setGeometry(QRect(10, 30, 341, 301));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 555, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkShowimageBox = new QCheckBox(layoutWidget);
        checkShowimageBox->setObjectName(QStringLiteral("checkShowimageBox"));

        horizontalLayout->addWidget(checkShowimageBox);

        checkShowDrawBox = new QCheckBox(layoutWidget);
        checkShowDrawBox->setObjectName(QStringLiteral("checkShowDrawBox"));
        checkShowDrawBox->setEnabled(false);

        horizontalLayout->addWidget(checkShowDrawBox);

        checkShowBlob = new QCheckBox(layoutWidget);
        checkShowBlob->setObjectName(QStringLiteral("checkShowBlob"));
        checkShowBlob->setEnabled(false);

        horizontalLayout->addWidget(checkShowBlob);

        checkShowTraj = new QCheckBox(layoutWidget);
        checkShowTraj->setObjectName(QStringLiteral("checkShowTraj"));
        checkShowTraj->setEnabled(false);

        horizontalLayout->addWidget(checkShowTraj);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 130, 191, 91));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 50, 81, 20));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 20, 91, 16));
        freqSenoideCoringa = new QDoubleSpinBox(groupBox_3);
        freqSenoideCoringa->setObjectName(QStringLiteral("freqSenoideCoringa"));
        freqSenoideCoringa->setGeometry(QRect(110, 50, 71, 22));
        freqSenoideCoringa->setMinimum(-100);
        freqSenoideCoringa->setMaximum(100);
        ampSenoideCoringa = new QDoubleSpinBox(groupBox_3);
        ampSenoideCoringa->setObjectName(QStringLiteral("ampSenoideCoringa"));
        ampSenoideCoringa->setGeometry(QRect(110, 20, 71, 22));
        ampSenoideCoringa->setMinimum(-100);
        ampSenoideCoringa->setMaximum(100);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(570, 190, 191, 101));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 81, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 81, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 91, 16));
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 60, 191, 111));
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
        pidComboBoxMain = new QComboBox(centralWidget);
        pidComboBoxMain->setObjectName(QStringLiteral("pidComboBoxMain"));
        pidComboBoxMain->setGeometry(QRect(600, 30, 151, 22));
        pidComboBoxMain->setAutoFillBackground(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(570, 30, 31, 31));
        label_2->setWordWrap(false);
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(630, 300, 75, 23));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(360, 30, 191, 91));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 50, 81, 20));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 20, 91, 16));
        DLSpinBox_3 = new QDoubleSpinBox(groupBox_4);
        DLSpinBox_3->setObjectName(QStringLiteral("DLSpinBox_3"));
        DLSpinBox_3->setGeometry(QRect(110, 50, 71, 22));
        DLSpinBox_3->setMinimum(-100);
        DLSpinBox_3->setMaximum(100);
        maxEscComboBox = new QComboBox(groupBox_4);
        maxEscComboBox->setObjectName(QStringLiteral("maxEscComboBox"));
        maxEscComboBox->setGeometry(QRect(110, 20, 69, 22));
        ProjetoFinalClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjetoFinalClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 21));
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
        pauseButton->setText(QApplication::translate("ProjetoFinalClass", "Pausar", Q_NULLPTR));
        checkShowimageBox->setText(QApplication::translate("ProjetoFinalClass", "Mostrar a imagem da C\303\242mera", Q_NULLPTR));
        checkShowDrawBox->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Desenho Rob\303\264", Q_NULLPTR));
        checkShowBlob->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Blobs Imagem", Q_NULLPTR));
        checkShowTraj->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Trajet\303\263ria", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ProjetoFinalClass", "Senoide", Q_NULLPTR));
        label_12->setText(QApplication::translate("ProjetoFinalClass", "Freq", Q_NULLPTR));
        label_13->setText(QApplication::translate("ProjetoFinalClass", "Amp", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ProjetoFinalClass", "Linear", Q_NULLPTR));
        label_7->setText(QApplication::translate("ProjetoFinalClass", "Integrador (I) :", Q_NULLPTR));
        label_6->setText(QApplication::translate("ProjetoFinalClass", "Derivativo (D) :", Q_NULLPTR));
        label_5->setText(QApplication::translate("ProjetoFinalClass", "Proporcional (P) :", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ProjetoFinalClass", "Angular", Q_NULLPTR));
        label_11->setText(QApplication::translate("ProjetoFinalClass", "Integrador (I) :", Q_NULLPTR));
        label_9->setText(QApplication::translate("ProjetoFinalClass", "Derivativo (D) :", Q_NULLPTR));
        label_10->setText(QApplication::translate("ProjetoFinalClass", "Proporcional (P) :", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProjetoFinalClass", "PID:", Q_NULLPTR));
        saveButton->setText(QApplication::translate("ProjetoFinalClass", "Salvar", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("ProjetoFinalClass", "Funcao Maximizante", Q_NULLPTR));
        label_14->setText(QApplication::translate("ProjetoFinalClass", "Valor do Max", Q_NULLPTR));
        label_15->setText(QApplication::translate("ProjetoFinalClass", "Posicao Max", Q_NULLPTR));
        maxEscComboBox->clear();
        maxEscComboBox->insertItems(0, QStringList()
         << QApplication::translate("ProjetoFinalClass", "1", Q_NULLPTR)
         << QApplication::translate("ProjetoFinalClass", "2", Q_NULLPTR)
         << QApplication::translate("ProjetoFinalClass", "3", Q_NULLPTR)
         << QApplication::translate("ProjetoFinalClass", "4", Q_NULLPTR)
        );
        menuOp_es->setTitle(QApplication::translate("ProjetoFinalClass", "Configura\303\247\303\265es", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProjetoFinalClass: public Ui_ProjetoFinalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETOFINAL_H
