/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "slidervelocity.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayoutVelocity;
    QSpinBox *spinBoxVelocity;
    QFrame *line_4;
    SliderVelocity *horizontalSliderVelocity;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelT2FromCV;
    QLabel *labelR1FromCV;
    QLabel *labelT3FromCV;
    QLabel *labelR2FromCV;
    QLabel *label;
    QLabel *labelT1FromCV;
    QLabel *labelR3FromCV;
    QLabel *label_3;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *labelF3FromSP;
    QLabel *labelF1FromSP;
    QLabel *labelF2FromSP;
    QLabel *label_4;
    QLabel *labelR2FromSP;
    QLabel *labelR1FromSP;
    QLabel *labelR3FromSP;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonKey_S;
    QCheckBox *checkBoxKey_2;
    QPushButton *pushButtonKey_W;
    QCheckBox *checkBoxKey_1;
    QCheckBox *checkBoxKey_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxKey_4;
    QCheckBox *checkBoxKey_5;
    QLabel *labelImage;
    QFrame *line_3;
    QFrame *line_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *labelWFromSP;
    QLabel *labelLFromSP;
    QLabel *labelHFromSP;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditCameraID;
    QPushButton *pushButtonOpenCamera;
    QPushButton *pushButtonOpenFile;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit;
    QPushButton *pushButtonSend;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditFileName;
    QPushButton *pushButtonRecord;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QPushButton *pushButtonOpenPort;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(573, 583);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(350, 270, 211, 41));
        horizontalLayoutVelocity = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayoutVelocity->setSpacing(6);
        horizontalLayoutVelocity->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutVelocity->setObjectName(QStringLiteral("horizontalLayoutVelocity"));
        horizontalLayoutVelocity->setContentsMargins(0, 0, 0, 0);
        spinBoxVelocity = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxVelocity->setObjectName(QStringLiteral("spinBoxVelocity"));

        horizontalLayoutVelocity->addWidget(spinBoxVelocity);

        line_4 = new QFrame(horizontalLayoutWidget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayoutVelocity->addWidget(line_4);

        horizontalSliderVelocity = new SliderVelocity(horizontalLayoutWidget_2);
        horizontalSliderVelocity->setObjectName(QStringLiteral("horizontalSliderVelocity"));
        horizontalSliderVelocity->setOrientation(Qt::Horizontal);

        horizontalLayoutVelocity->addWidget(horizontalSliderVelocity);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(350, 60, 211, 61));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalLayoutWidget->sizePolicy().hasHeightForWidth());
        verticalLayoutWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(4);
        labelT2FromCV = new QLabel(verticalLayoutWidget);
        labelT2FromCV->setObjectName(QStringLiteral("labelT2FromCV"));
        sizePolicy.setHeightForWidth(labelT2FromCV->sizePolicy().hasHeightForWidth());
        labelT2FromCV->setSizePolicy(sizePolicy);
        labelT2FromCV->setFrameShape(QFrame::WinPanel);
        labelT2FromCV->setFrameShadow(QFrame::Sunken);
        labelT2FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelT2FromCV, 3, 2, 1, 1);

        labelR1FromCV = new QLabel(verticalLayoutWidget);
        labelR1FromCV->setObjectName(QStringLiteral("labelR1FromCV"));
        sizePolicy.setHeightForWidth(labelR1FromCV->sizePolicy().hasHeightForWidth());
        labelR1FromCV->setSizePolicy(sizePolicy);
        labelR1FromCV->setFrameShape(QFrame::WinPanel);
        labelR1FromCV->setFrameShadow(QFrame::Sunken);
        labelR1FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelR1FromCV, 2, 1, 1, 1);

        labelT3FromCV = new QLabel(verticalLayoutWidget);
        labelT3FromCV->setObjectName(QStringLiteral("labelT3FromCV"));
        sizePolicy.setHeightForWidth(labelT3FromCV->sizePolicy().hasHeightForWidth());
        labelT3FromCV->setSizePolicy(sizePolicy);
        labelT3FromCV->setFrameShape(QFrame::WinPanel);
        labelT3FromCV->setFrameShadow(QFrame::Sunken);
        labelT3FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelT3FromCV, 3, 3, 1, 1);

        labelR2FromCV = new QLabel(verticalLayoutWidget);
        labelR2FromCV->setObjectName(QStringLiteral("labelR2FromCV"));
        sizePolicy.setHeightForWidth(labelR2FromCV->sizePolicy().hasHeightForWidth());
        labelR2FromCV->setSizePolicy(sizePolicy);
        labelR2FromCV->setFrameShape(QFrame::WinPanel);
        labelR2FromCV->setFrameShadow(QFrame::Sunken);
        labelR2FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelR2FromCV, 2, 2, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        labelT1FromCV = new QLabel(verticalLayoutWidget);
        labelT1FromCV->setObjectName(QStringLiteral("labelT1FromCV"));
        sizePolicy.setHeightForWidth(labelT1FromCV->sizePolicy().hasHeightForWidth());
        labelT1FromCV->setSizePolicy(sizePolicy);
        labelT1FromCV->setFrameShape(QFrame::WinPanel);
        labelT1FromCV->setFrameShadow(QFrame::Sunken);
        labelT1FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelT1FromCV, 3, 1, 1, 1);

        labelR3FromCV = new QLabel(verticalLayoutWidget);
        labelR3FromCV->setObjectName(QStringLiteral("labelR3FromCV"));
        sizePolicy.setHeightForWidth(labelR3FromCV->sizePolicy().hasHeightForWidth());
        labelR3FromCV->setSizePolicy(sizePolicy);
        labelR3FromCV->setFrameShape(QFrame::WinPanel);
        labelR3FromCV->setFrameShadow(QFrame::Sunken);
        labelR3FromCV->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelR3FromCV, 2, 3, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayoutWidget_6 = new QWidget(centralWidget);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(350, 190, 211, 61));
        sizePolicy.setHeightForWidth(gridLayoutWidget_6->sizePolicy().hasHeightForWidth());
        gridLayoutWidget_6->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        labelF3FromSP = new QLabel(gridLayoutWidget_6);
        labelF3FromSP->setObjectName(QStringLiteral("labelF3FromSP"));
        sizePolicy.setHeightForWidth(labelF3FromSP->sizePolicy().hasHeightForWidth());
        labelF3FromSP->setSizePolicy(sizePolicy);
        labelF3FromSP->setFrameShape(QFrame::WinPanel);
        labelF3FromSP->setFrameShadow(QFrame::Sunken);
        labelF3FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelF3FromSP, 2, 3, 1, 1);

        labelF1FromSP = new QLabel(gridLayoutWidget_6);
        labelF1FromSP->setObjectName(QStringLiteral("labelF1FromSP"));
        sizePolicy.setHeightForWidth(labelF1FromSP->sizePolicy().hasHeightForWidth());
        labelF1FromSP->setSizePolicy(sizePolicy);
        labelF1FromSP->setFrameShape(QFrame::WinPanel);
        labelF1FromSP->setFrameShadow(QFrame::Sunken);
        labelF1FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelF1FromSP, 2, 1, 1, 1);

        labelF2FromSP = new QLabel(gridLayoutWidget_6);
        labelF2FromSP->setObjectName(QStringLiteral("labelF2FromSP"));
        sizePolicy.setHeightForWidth(labelF2FromSP->sizePolicy().hasHeightForWidth());
        labelF2FromSP->setSizePolicy(sizePolicy);
        labelF2FromSP->setFrameShape(QFrame::WinPanel);
        labelF2FromSP->setFrameShadow(QFrame::Sunken);
        labelF2FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelF2FromSP, 2, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_4, 2, 0, 1, 1);

        labelR2FromSP = new QLabel(gridLayoutWidget_6);
        labelR2FromSP->setObjectName(QStringLiteral("labelR2FromSP"));
        sizePolicy.setHeightForWidth(labelR2FromSP->sizePolicy().hasHeightForWidth());
        labelR2FromSP->setSizePolicy(sizePolicy);
        labelR2FromSP->setFrameShape(QFrame::WinPanel);
        labelR2FromSP->setFrameShadow(QFrame::Sunken);
        labelR2FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelR2FromSP, 3, 2, 1, 1);

        labelR1FromSP = new QLabel(gridLayoutWidget_6);
        labelR1FromSP->setObjectName(QStringLiteral("labelR1FromSP"));
        sizePolicy.setHeightForWidth(labelR1FromSP->sizePolicy().hasHeightForWidth());
        labelR1FromSP->setSizePolicy(sizePolicy);
        labelR1FromSP->setFrameShape(QFrame::WinPanel);
        labelR1FromSP->setFrameShadow(QFrame::Sunken);
        labelR1FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelR1FromSP, 3, 1, 1, 1);

        labelR3FromSP = new QLabel(gridLayoutWidget_6);
        labelR3FromSP->setObjectName(QStringLiteral("labelR3FromSP"));
        sizePolicy.setHeightForWidth(labelR3FromSP->sizePolicy().hasHeightForWidth());
        labelR3FromSP->setSizePolicy(sizePolicy);
        labelR3FromSP->setFrameShape(QFrame::WinPanel);
        labelR3FromSP->setFrameShadow(QFrame::Sunken);
        labelR3FromSP->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelR3FromSP, 3, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 3, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 260, 239, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonKey_S = new QPushButton(gridLayoutWidget_2);
        pushButtonKey_S->setObjectName(QStringLiteral("pushButtonKey_S"));
        pushButtonKey_S->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(pushButtonKey_S, 3, 1, 1, 1);

        checkBoxKey_2 = new QCheckBox(gridLayoutWidget_2);
        checkBoxKey_2->setObjectName(QStringLiteral("checkBoxKey_2"));
        checkBoxKey_2->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(checkBoxKey_2, 2, 1, 1, 1);

        pushButtonKey_W = new QPushButton(gridLayoutWidget_2);
        pushButtonKey_W->setObjectName(QStringLiteral("pushButtonKey_W"));
        pushButtonKey_W->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(pushButtonKey_W, 0, 1, 1, 1);

        checkBoxKey_1 = new QCheckBox(gridLayoutWidget_2);
        checkBoxKey_1->setObjectName(QStringLiteral("checkBoxKey_1"));
        checkBoxKey_1->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(checkBoxKey_1, 2, 0, 1, 1);

        checkBoxKey_3 = new QCheckBox(gridLayoutWidget_2);
        checkBoxKey_3->setObjectName(QStringLiteral("checkBoxKey_3"));
        checkBoxKey_3->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(checkBoxKey_3, 2, 2, 1, 1);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(260, 260, 61, 141));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBoxKey_4 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxKey_4->setObjectName(QStringLiteral("checkBoxKey_4"));
        checkBoxKey_4->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_2->addWidget(checkBoxKey_4);

        checkBoxKey_5 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxKey_5->setObjectName(QStringLiteral("checkBoxKey_5"));
        checkBoxKey_5->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_2->addWidget(checkBoxKey_5);

        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(10, 10, 320, 240));
        labelImage->setStyleSheet(QStringLiteral("border-color: rgb(85, 0, 255);"));
        labelImage->setFrameShape(QFrame::WinPanel);
        labelImage->setFrameShadow(QFrame::Raised);
        labelImage->setLineWidth(1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(240, 260, 20, 141));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setWindowModality(Qt::NonModal);
        line_5->setGeometry(QRect(10, 250, 551, 16));
        line_5->setFrameShadow(QFrame::Sunken);
        line_5->setLineWidth(2);
        line_5->setMidLineWidth(0);
        line_5->setFrameShape(QFrame::HLine);
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(350, 140, 211, 31));
        sizePolicy.setHeightForWidth(verticalLayoutWidget_3->sizePolicy().hasHeightForWidth());
        verticalLayoutWidget_3->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(4);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        labelWFromSP = new QLabel(verticalLayoutWidget_3);
        labelWFromSP->setObjectName(QStringLiteral("labelWFromSP"));
        sizePolicy.setHeightForWidth(labelWFromSP->sizePolicy().hasHeightForWidth());
        labelWFromSP->setSizePolicy(sizePolicy);
        labelWFromSP->setFrameShape(QFrame::WinPanel);
        labelWFromSP->setFrameShadow(QFrame::Sunken);
        labelWFromSP->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelWFromSP, 2, 2, 1, 1);

        labelLFromSP = new QLabel(verticalLayoutWidget_3);
        labelLFromSP->setObjectName(QStringLiteral("labelLFromSP"));
        sizePolicy.setHeightForWidth(labelLFromSP->sizePolicy().hasHeightForWidth());
        labelLFromSP->setSizePolicy(sizePolicy);
        labelLFromSP->setFrameShape(QFrame::WinPanel);
        labelLFromSP->setFrameShadow(QFrame::Sunken);
        labelLFromSP->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelLFromSP, 2, 1, 1, 1);

        labelHFromSP = new QLabel(verticalLayoutWidget_3);
        labelHFromSP->setObjectName(QStringLiteral("labelHFromSP"));
        sizePolicy.setHeightForWidth(labelHFromSP->sizePolicy().hasHeightForWidth());
        labelHFromSP->setSizePolicy(sizePolicy);
        labelHFromSP->setFrameShape(QFrame::WinPanel);
        labelHFromSP->setFrameShadow(QFrame::Sunken);
        labelHFromSP->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelHFromSP, 2, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(350, 20, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditCameraID = new QLineEdit(horizontalLayoutWidget);
        lineEditCameraID->setObjectName(QStringLiteral("lineEditCameraID"));
        lineEditCameraID->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(lineEditCameraID);

        pushButtonOpenCamera = new QPushButton(horizontalLayoutWidget);
        pushButtonOpenCamera->setObjectName(QStringLiteral("pushButtonOpenCamera"));
        pushButtonOpenCamera->setEnabled(true);
        pushButtonOpenCamera->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(pushButtonOpenCamera);

        pushButtonOpenFile = new QPushButton(horizontalLayoutWidget);
        pushButtonOpenFile->setObjectName(QStringLiteral("pushButtonOpenFile"));
        pushButtonOpenFile->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(pushButtonOpenFile);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 410, 541, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(textEdit);

        pushButtonSend = new QPushButton(horizontalLayoutWidget_3);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        pushButtonSend->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(pushButtonSend);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(350, 330, 211, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEditFileName = new QLineEdit(horizontalLayoutWidget_4);
        lineEditFileName->setObjectName(QStringLiteral("lineEditFileName"));
        lineEditFileName->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_4->addWidget(lineEditFileName);

        pushButtonRecord = new QPushButton(horizontalLayoutWidget_4);
        pushButtonRecord->setObjectName(QStringLiteral("pushButtonRecord"));
        pushButtonRecord->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_4->addWidget(pushButtonRecord);

        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(350, 370, 211, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(horizontalLayoutWidget_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        pushButtonOpenPort = new QPushButton(horizontalLayoutWidget_5);
        pushButtonOpenPort->setObjectName(QStringLiteral("pushButtonOpenPort"));
        pushButtonOpenPort->setFocusPolicy(Qt::ClickFocus);
        pushButtonOpenPort->setStyleSheet(QStringLiteral("border-color: rgb(85, 170, 255);"));

        horizontalLayout_5->addWidget(pushButtonOpenPort);

        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        gridLayoutWidget_6->raise();
        gridLayoutWidget_2->raise();
        verticalLayoutWidget_2->raise();
        labelImage->raise();
        line_3->raise();
        line_5->raise();
        verticalLayoutWidget_3->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_3->raise();
        horizontalLayoutWidget_4->raise();
        horizontalLayoutWidget_5->raise();
        horizontalLayoutWidget_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 573, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TreeBot", 0));
        labelT2FromCV->setText(QString());
        labelR1FromCV->setText(QString());
        labelT3FromCV->setText(QString());
        labelR2FromCV->setText(QString());
        label->setText(QApplication::translate("MainWindow", "R", 0));
        labelT1FromCV->setText(QString());
        labelR3FromCV->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "T", 0));
        labelF3FromSP->setText(QString());
        labelF1FromSP->setText(QString());
        labelF2FromSP->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "F", 0));
        labelR2FromSP->setText(QString());
        labelR1FromSP->setText(QString());
        labelR3FromSP->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "R", 0));
        pushButtonKey_S->setText(QApplication::translate("MainWindow", "S", 0));
        checkBoxKey_2->setText(QApplication::translate("MainWindow", "Middle", 0));
        pushButtonKey_W->setText(QApplication::translate("MainWindow", "W", 0));
        checkBoxKey_1->setText(QApplication::translate("MainWindow", "Left", 0));
        checkBoxKey_3->setText(QApplication::translate("MainWindow", "Right", 0));
        checkBoxKey_4->setText(QApplication::translate("MainWindow", "Top", 0));
        checkBoxKey_5->setText(QApplication::translate("MainWindow", "Trail", 0));
        labelImage->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "L", 0));
        labelWFromSP->setText(QString());
        labelLFromSP->setText(QString());
        labelHFromSP->setText(QString());
        lineEditCameraID->setText(QApplication::translate("MainWindow", "0", 0));
        pushButtonOpenCamera->setText(QApplication::translate("MainWindow", "Camera", 0));
        pushButtonOpenFile->setText(QApplication::translate("MainWindow", "File", 0));
        pushButtonSend->setText(QApplication::translate("MainWindow", "Send", 0));
        lineEditFileName->setText(QApplication::translate("MainWindow", "a", 0));
        pushButtonRecord->setText(QApplication::translate("MainWindow", "Start Recording", 0));
        pushButtonOpenPort->setText(QApplication::translate("MainWindow", "Open Port", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
