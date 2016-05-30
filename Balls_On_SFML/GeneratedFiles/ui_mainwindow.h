/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionStart_simulation;
    QAction *actionCollisions;
    QAction *actionGravity_Force;
    QAction *actionShow_FPS;
    QAction *actionResolution;
    QAction *actionFull_Screen;
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPause;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *simulationPushButton;
    QLabel *toolLabel;
    QComboBox *toolComboBox;
    QTabWidget *toolsSettingsTabWidget;
    QWidget *ballsTool;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *ballRadiusLabel;
    QPushButton *ballRandomVelocityButton;
    QLabel *ballsLabel;
    QSpinBox *ballPerClickSpinBox;
    QPushButton *ballRandomRadiusButton;
    QLabel *ballPerClickLabel;
    QLabel *ballMassLabel;
    QLabel *ballBounceFactorLabel;
    QDoubleSpinBox *ballRadiusDoubleSpinBox;
    QDoubleSpinBox *ballBounceFactorDoubleSpinBox;
    QDoubleSpinBox *ballMassDoubleSpinBox;
    QWidget *tab_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout;
    QLabel *timeFactorLabel;
    QRadioButton *verySlowRadioButton;
    QRadioButton *slowRadioButton;
    QRadioButton *normalRadioButton;
    QRadioButton *fastRadioButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSimulation;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(324, 326);
        actionStart_simulation = new QAction(MainWindowClass);
        actionStart_simulation->setObjectName(QStringLiteral("actionStart_simulation"));
        actionStart_simulation->setCheckable(true);
        actionCollisions = new QAction(MainWindowClass);
        actionCollisions->setObjectName(QStringLiteral("actionCollisions"));
        actionCollisions->setCheckable(true);
        actionCollisions->setChecked(true);
        actionCollisions->setMenuRole(QAction::TextHeuristicRole);
        actionGravity_Force = new QAction(MainWindowClass);
        actionGravity_Force->setObjectName(QStringLiteral("actionGravity_Force"));
        actionGravity_Force->setCheckable(true);
        actionShow_FPS = new QAction(MainWindowClass);
        actionShow_FPS->setObjectName(QStringLiteral("actionShow_FPS"));
        actionShow_FPS->setCheckable(true);
        actionShow_FPS->setChecked(true);
        actionResolution = new QAction(MainWindowClass);
        actionResolution->setObjectName(QStringLiteral("actionResolution"));
        actionResolution->setMenuRole(QAction::TextHeuristicRole);
        actionFull_Screen = new QAction(MainWindowClass);
        actionFull_Screen->setObjectName(QStringLiteral("actionFull_Screen"));
        actionFull_Screen->setCheckable(true);
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionNew->setVisible(true);
        actionLoad = new QAction(MainWindowClass);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionPause = new QAction(MainWindowClass);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionPause->setCheckable(true);
        actionPause->setEnabled(false);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 301, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        simulationPushButton = new QPushButton(verticalLayoutWidget);
        simulationPushButton->setObjectName(QStringLiteral("simulationPushButton"));
        simulationPushButton->setCheckable(true);

        horizontalLayout_2->addWidget(simulationPushButton);

        toolLabel = new QLabel(verticalLayoutWidget);
        toolLabel->setObjectName(QStringLiteral("toolLabel"));
        toolLabel->setLayoutDirection(Qt::LeftToRight);
        toolLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(toolLabel);

        toolComboBox = new QComboBox(verticalLayoutWidget);
        toolComboBox->setObjectName(QStringLiteral("toolComboBox"));

        horizontalLayout_2->addWidget(toolComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        toolsSettingsTabWidget = new QTabWidget(verticalLayoutWidget);
        toolsSettingsTabWidget->setObjectName(QStringLiteral("toolsSettingsTabWidget"));
        toolsSettingsTabWidget->setTabShape(QTabWidget::Rounded);
        ballsTool = new QWidget();
        ballsTool->setObjectName(QStringLiteral("ballsTool"));
        gridLayoutWidget = new QWidget(ballsTool);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 291, 173));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        ballRadiusLabel = new QLabel(gridLayoutWidget);
        ballRadiusLabel->setObjectName(QStringLiteral("ballRadiusLabel"));

        gridLayout->addWidget(ballRadiusLabel, 0, 0, 1, 1);

        ballRandomVelocityButton = new QPushButton(gridLayoutWidget);
        ballRandomVelocityButton->setObjectName(QStringLiteral("ballRandomVelocityButton"));
        ballRandomVelocityButton->setCheckable(true);
        ballRandomVelocityButton->setChecked(true);

        gridLayout->addWidget(ballRandomVelocityButton, 5, 0, 1, 1);

        ballsLabel = new QLabel(gridLayoutWidget);
        ballsLabel->setObjectName(QStringLiteral("ballsLabel"));

        gridLayout->addWidget(ballsLabel, 4, 1, 1, 1);

        ballPerClickSpinBox = new QSpinBox(gridLayoutWidget);
        ballPerClickSpinBox->setObjectName(QStringLiteral("ballPerClickSpinBox"));
        ballPerClickSpinBox->setMinimum(1);
        ballPerClickSpinBox->setMaximum(10000);
        ballPerClickSpinBox->setValue(100);

        gridLayout->addWidget(ballPerClickSpinBox, 3, 1, 1, 1);

        ballRandomRadiusButton = new QPushButton(gridLayoutWidget);
        ballRandomRadiusButton->setObjectName(QStringLiteral("ballRandomRadiusButton"));
        ballRandomRadiusButton->setCheckable(true);

        gridLayout->addWidget(ballRandomRadiusButton, 5, 1, 1, 1);

        ballPerClickLabel = new QLabel(gridLayoutWidget);
        ballPerClickLabel->setObjectName(QStringLiteral("ballPerClickLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ballPerClickLabel->sizePolicy().hasHeightForWidth());
        ballPerClickLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ballPerClickLabel, 3, 0, 1, 1);

        ballMassLabel = new QLabel(gridLayoutWidget);
        ballMassLabel->setObjectName(QStringLiteral("ballMassLabel"));

        gridLayout->addWidget(ballMassLabel, 1, 0, 1, 1);

        ballBounceFactorLabel = new QLabel(gridLayoutWidget);
        ballBounceFactorLabel->setObjectName(QStringLiteral("ballBounceFactorLabel"));

        gridLayout->addWidget(ballBounceFactorLabel, 2, 0, 1, 1);

        ballRadiusDoubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        ballRadiusDoubleSpinBox->setObjectName(QStringLiteral("ballRadiusDoubleSpinBox"));
        ballRadiusDoubleSpinBox->setMaximum(1e+17);
        ballRadiusDoubleSpinBox->setValue(5);

        gridLayout->addWidget(ballRadiusDoubleSpinBox, 0, 1, 1, 1);

        ballBounceFactorDoubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        ballBounceFactorDoubleSpinBox->setObjectName(QStringLiteral("ballBounceFactorDoubleSpinBox"));
        ballBounceFactorDoubleSpinBox->setMaximum(1);
        ballBounceFactorDoubleSpinBox->setSingleStep(0.01);
        ballBounceFactorDoubleSpinBox->setValue(0.9);

        gridLayout->addWidget(ballBounceFactorDoubleSpinBox, 2, 1, 1, 1);

        ballMassDoubleSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        ballMassDoubleSpinBox->setObjectName(QStringLiteral("ballMassDoubleSpinBox"));
        ballMassDoubleSpinBox->setMinimum(0);
        ballMassDoubleSpinBox->setMaximum(1e+17);
        ballMassDoubleSpinBox->setValue(1000);

        gridLayout->addWidget(ballMassDoubleSpinBox, 1, 1, 1, 1);

        toolsSettingsTabWidget->addTab(ballsTool, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        toolsSettingsTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        toolsSettingsTabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(toolsSettingsTabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timeFactorLabel = new QLabel(verticalLayoutWidget);
        timeFactorLabel->setObjectName(QStringLiteral("timeFactorLabel"));

        horizontalLayout->addWidget(timeFactorLabel);

        verySlowRadioButton = new QRadioButton(verticalLayoutWidget);
        verySlowRadioButton->setObjectName(QStringLiteral("verySlowRadioButton"));

        horizontalLayout->addWidget(verySlowRadioButton);

        slowRadioButton = new QRadioButton(verticalLayoutWidget);
        slowRadioButton->setObjectName(QStringLiteral("slowRadioButton"));

        horizontalLayout->addWidget(slowRadioButton);

        normalRadioButton = new QRadioButton(verticalLayoutWidget);
        normalRadioButton->setObjectName(QStringLiteral("normalRadioButton"));
        normalRadioButton->setCheckable(true);
        normalRadioButton->setChecked(true);

        horizontalLayout->addWidget(normalRadioButton);

        fastRadioButton = new QRadioButton(verticalLayoutWidget);
        fastRadioButton->setObjectName(QStringLiteral("fastRadioButton"));

        horizontalLayout->addWidget(fastRadioButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 324, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setEnabled(false);
        menuSimulation = new QMenu(menuBar);
        menuSimulation->setObjectName(QStringLiteral("menuSimulation"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSimulation->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuSimulation->addAction(actionStart_simulation);
        menuSimulation->addAction(actionPause);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionCollisions);
        menuSimulation->addAction(actionGravity_Force);
        menuSettings->addAction(actionShow_FPS);
        menuSettings->addAction(actionFull_Screen);
        menuSettings->addAction(actionResolution);

        retranslateUi(MainWindowClass);
        QObject::connect(toolComboBox, SIGNAL(currentIndexChanged(int)), toolsSettingsTabWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(toolsSettingsTabWidget, SIGNAL(currentChanged(int)), toolComboBox, SLOT(setCurrentIndex(int)));

        toolsSettingsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Balls On SFML", 0));
        actionStart_simulation->setText(QApplication::translate("MainWindowClass", "Start simulation", 0));
        actionCollisions->setText(QApplication::translate("MainWindowClass", "Collisions", 0));
        actionGravity_Force->setText(QApplication::translate("MainWindowClass", "Gravity Force", 0));
        actionShow_FPS->setText(QApplication::translate("MainWindowClass", "Show FPS", 0));
        actionResolution->setText(QApplication::translate("MainWindowClass", "Resolution", 0));
        actionFull_Screen->setText(QApplication::translate("MainWindowClass", "Full Screen", 0));
        actionNew->setText(QApplication::translate("MainWindowClass", "New", 0));
        actionLoad->setText(QApplication::translate("MainWindowClass", "Load", 0));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0));
        actionSave_As->setText(QApplication::translate("MainWindowClass", "Save As...", 0));
        actionPause->setText(QApplication::translate("MainWindowClass", "Pause", 0));
        simulationPushButton->setText(QApplication::translate("MainWindowClass", "Start Simulation", 0));
        toolLabel->setText(QApplication::translate("MainWindowClass", "Tool:", 0));
        toolComboBox->clear();
        toolComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Ball Spawner", 0)
         << QApplication::translate("MainWindowClass", "Rectangle Spawner", 0)
         << QApplication::translate("MainWindowClass", "Line Spawner", 0)
        );
        label->setText(QApplication::translate("MainWindowClass", "Number of balls:", 0));
        ballRadiusLabel->setText(QApplication::translate("MainWindowClass", "Ball radius:", 0));
        ballRandomVelocityButton->setText(QApplication::translate("MainWindowClass", "Random velocity", 0));
        ballsLabel->setText(QApplication::translate("MainWindowClass", "0", 0));
        ballRandomRadiusButton->setText(QApplication::translate("MainWindowClass", "Random radius", 0));
        ballPerClickLabel->setText(QApplication::translate("MainWindowClass", "Balls per click:", 0));
        ballMassLabel->setText(QApplication::translate("MainWindowClass", "Ball mass:", 0));
        ballBounceFactorLabel->setText(QApplication::translate("MainWindowClass", "Ball bounce factor:", 0));
        ballRadiusDoubleSpinBox->setSuffix(QApplication::translate("MainWindowClass", "[m]", 0));
        ballBounceFactorDoubleSpinBox->setSuffix(QApplication::translate("MainWindowClass", "[%]", 0));
        ballMassDoubleSpinBox->setSuffix(QApplication::translate("MainWindowClass", "[kg]", 0));
        toolsSettingsTabWidget->setTabText(toolsSettingsTabWidget->indexOf(ballsTool), QApplication::translate("MainWindowClass", "Ball Spawner", 0));
        toolsSettingsTabWidget->setTabText(toolsSettingsTabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Rectangle Spawner", 0));
        toolsSettingsTabWidget->setTabText(toolsSettingsTabWidget->indexOf(tab_3), QApplication::translate("MainWindowClass", "Line Spawner", 0));
        timeFactorLabel->setText(QApplication::translate("MainWindowClass", "Time Factor:", 0));
        verySlowRadioButton->setText(QApplication::translate("MainWindowClass", "0.01x", 0));
        slowRadioButton->setText(QApplication::translate("MainWindowClass", "0.1x", 0));
        normalRadioButton->setText(QApplication::translate("MainWindowClass", "1x", 0));
        fastRadioButton->setText(QApplication::translate("MainWindowClass", "10x", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuSimulation->setTitle(QApplication::translate("MainWindowClass", "Simulation", 0));
        menuSettings->setTitle(QApplication::translate("MainWindowClass", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
