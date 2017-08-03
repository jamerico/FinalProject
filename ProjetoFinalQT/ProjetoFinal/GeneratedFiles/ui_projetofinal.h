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
#include <QtWidgets/QHeaderView>
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
    QPushButton *pauseButton;
    QPlainTextEdit *XYText;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkShowimageBox;
    QCheckBox *checkShowTraj;
    QCheckBox *checkShowDrawBox;
    QCheckBox *checkShowBlob;
    QMenuBar *menuBar;
    QMenu *menuOp_es;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetoFinalClass)
    {
        if (ProjetoFinalClass->objectName().isEmpty())
            ProjetoFinalClass->setObjectName(QStringLiteral("ProjetoFinalClass"));
        ProjetoFinalClass->resize(677, 208);
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
        startButton->setGeometry(QRect(30, 130, 75, 23));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);
        pauseButton->setGeometry(QRect(110, 130, 75, 23));
        pauseButton->setFlat(false);
        XYText = new QPlainTextEdit(centralWidget);
        XYText->setObjectName(QStringLiteral("XYText"));
        XYText->setGeometry(QRect(220, 20, 441, 131));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 20, 165, 88));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkShowimageBox = new QCheckBox(widget);
        checkShowimageBox->setObjectName(QStringLiteral("checkShowimageBox"));

        verticalLayout->addWidget(checkShowimageBox);

        checkShowTraj = new QCheckBox(widget);
        checkShowTraj->setObjectName(QStringLiteral("checkShowTraj"));
        checkShowTraj->setEnabled(false);

        verticalLayout->addWidget(checkShowTraj);

        checkShowDrawBox = new QCheckBox(widget);
        checkShowDrawBox->setObjectName(QStringLiteral("checkShowDrawBox"));
        checkShowDrawBox->setEnabled(false);

        verticalLayout->addWidget(checkShowDrawBox);

        checkShowBlob = new QCheckBox(widget);
        checkShowBlob->setObjectName(QStringLiteral("checkShowBlob"));
        checkShowBlob->setEnabled(false);

        verticalLayout->addWidget(checkShowBlob);

        ProjetoFinalClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjetoFinalClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 21));
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
        checkShowTraj->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Trajet\303\263ria", Q_NULLPTR));
        checkShowDrawBox->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Desenho Rob\303\264", Q_NULLPTR));
        checkShowBlob->setText(QApplication::translate("ProjetoFinalClass", "Mostrar Blobs Imagem", Q_NULLPTR));
        menuOp_es->setTitle(QApplication::translate("ProjetoFinalClass", "Configura\303\247\303\265es", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProjetoFinalClass: public Ui_ProjetoFinalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETOFINAL_H
