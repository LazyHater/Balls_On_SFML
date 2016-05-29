#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <QThread>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "ui_mainwindow.h"
#include "simulation.hpp"

using namespace std;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);

signals:
	void savePath(QString s);
	void loadPath(QString s);
private slots:
	void beginSimulation(bool);
	void simulationFinished();
	void errorString(QString); 
	void chooseResolution(QAction* qa); // messy but works as expected 
	void saveAs() {
		simulation->pause(true);
		QString path = QFileDialog::getSaveFileName(this,
			tr("Save State"), "saves\\", tr("Save Files (*.sav)"));
		emit savePath(path);

		//simulation->save(path.toStdString());
		simulation->pause(false);
	}
	void load() {
		//simulation->pause(true);
		QString path = QFileDialog::getOpenFileName(this,
			tr("Load State"), "saves\\", tr("Save Files (*.sav)"));
		//simulation->load(path.toStdString());
		emit loadPath(path);
		//simulation->pause(false);

	}
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


