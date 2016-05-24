#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.pushButton->setVisible(false);
	ui.comboBox->setVisible(false);
	ui.label_2->setVisible(false);
	connect(ui.actionStart_simulation, SIGNAL(triggered()), this, SLOT(beginSimulation()));
	resolutions_menu = new QMenu(ui.menuSettings);
	ui.actionResolution->setMenu(resolutions_menu);
	for (sf::VideoMode vm : sf::VideoMode::getFullscreenModes()) {
		QAction* pAction = new QAction("[" + QString::number(vm.height) + "x" + QString::number(vm.width) + "]", this);
		pAction->setCheckable(true);
		resolutions_menu->addAction(pAction);
	}
	connect(resolutions_menu, SIGNAL(triggered(QAction*)), this, SLOT(chooseResolution(QAction*)));
	resolutions_menu->actions()[0]->setChecked(true);
	video_mode = sf::VideoMode::getFullscreenModes()[0];
}

void MainWindow::errorString(QString s) {
	std::cout << s.toStdString()<<std::endl;
}

void MainWindow::simulationFinished() {
	ui.actionStart_simulation->setEnabled(true);
};



void MainWindow::beginSimulation() {


	thread = new QThread;
	simulation = new Simulation(video_mode, ui.actionFull_Screen->isChecked());

	writeDefaultValues();

	connect(simulation, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
	connect(thread, SIGNAL(started()), simulation, SLOT(process()));
	connect(simulation, SIGNAL(finished()), thread, SLOT(quit()));
	connect(simulation, SIGNAL(finished()), simulation, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	connect(simulation, SIGNAL(finished()), this, SLOT(simulationFinished()));

	connect(simulation->ball_tool, SIGNAL(ballsNChanged(int)), ui.ballsLabel, SLOT(setNum(int)));
	connect(ui.ballPerClickSpinBox, SIGNAL(valueChanged(int)), simulation->ball_tool, SLOT(setBallsPerDeploy(int)));
	connect(ui.ballMassDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsMass(double)));
	connect(ui.ballBounceFactorDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsBounceFactor(double)));
	connect(ui.ballRadiusDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsRadius(double)));
	connect(ui.ballRandomVelocityButton, SIGNAL(clicked(bool)), simulation->ball_tool, SLOT(setBallsRandomVelocity(bool)));
	connect(ui.ballRandomRadiusButton, SIGNAL(clicked(bool)), simulation->ball_tool, SLOT(setBallsRandomRadius(bool)));

	connect(ui.verySlowRadioButton, SIGNAL(clicked()), simulation, SLOT(setVerySlowTimeFactor()));
	connect(ui.slowRadioButton, SIGNAL(clicked()), simulation, SLOT(setSlowTimeFactor()));
	connect(ui.normalRadioButton, SIGNAL(clicked()), simulation, SLOT(setNormalTimeFactor()));
	connect(ui.fastRadioButton, SIGNAL(clicked()), simulation, SLOT(setFastTimeFactor()));

	connect(ui.actionShow_FPS, SIGNAL(toggled(bool)), simulation, SLOT(setShowFPS(bool)));
	connect(ui.toolsSettingsTabWidget, SIGNAL(currentChanged(int)), simulation, SLOT(setTool(int)));

	connect(ui.actionCollisions, SIGNAL(toggled(bool)), simulation, SLOT(setBallToBallCollisions(bool)));
	connect(ui.actionGravity_Force, SIGNAL(toggled(bool)), simulation, SLOT(setGravityForces(bool)));
	simulation->moveToThread(thread);

	ui.actionStart_simulation->setEnabled(false);
	thread->start();
};

void MainWindow::chooseResolution(QAction* qa) {// messy but works as expected 
	for (QAction* tmp : resolutions_menu->actions())
		tmp->setChecked(false);

	int idx = 0;
	for (QAction* act : resolutions_menu->actions()) {
		if (act->text() == qa->text()) {
			video_mode = sf::VideoMode::getFullscreenModes()[idx];
			act->setChecked(true);
			return;
		}
		idx++;
	}
}