#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QTimer>

#include "ui_mainwindow.h"
#include "simulation.hpp"
#include <iostream>
#include <QThread>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);

private slots:
	void beginSimulation();
	void simulationFinished();
	void errorString(QString); 
	void chooseResolution(QAction* qa); // messy but works as expected 
signals:

private:
	void writeDefaultValues() {
		//simulation
		simulation->setTimeFactor(1);
		simulation->setShowFPS(ui.actionShow_FPS->isChecked());
		simulation->setBallToBallCollisions(ui.actionCollisions->isChecked());
		simulation->setGravityForces(ui.actionGravity_Force->isChecked());
		simulation->setTool(ui.toolsSettingsTabWidget->currentIndex());
		//ball tool
		simulation->ball_tool->setBallsRadius(ui.ballRadiusDoubleSpinBox->value());
		simulation->ball_tool->setBallsMass(ui.ballMassDoubleSpinBox->value());
		simulation->ball_tool->setBallsBounceFactor(ui.ballBounceFactorDoubleSpinBox->value());
		simulation->ball_tool->setBallsPerDeploy(ui.ballPerClickSpinBox->value());
		simulation->ball_tool->setBallsRandomVelocity(ui.ballRandomVelocityButton->isChecked());
		simulation->ball_tool->setBallsRandomRadius(ui.ballRandomRadiusButton->isChecked());
	};
	QThread* thread;
	Simulation* simulation;
	sf::VideoMode video_mode;
	QMenu *resolutions_menu;

	Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H


