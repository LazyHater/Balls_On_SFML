#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
	connect(ui.actionLoad, SIGNAL(triggered()), this, SLOT(load()));


	//connect(ui.actionStart_simulation, SIGNAL(toggled(bool)), this, SLOT(beginSimulation(bool)));
	connect(ui.simulationPushButton, SIGNAL(toggled(bool)), this, SLOT(beginSimulation(bool)));
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
	ui.actionStart_simulation->setChecked(false);
	ui.actionStart_simulation->setText("Start Simulation");
	ui.simulationPushButton->setChecked(false);
	ui.simulationPushButton->setText("Start Simulation");
};



void MainWindow::beginSimulation(bool b) {
	if (b) {
		thread = new QThread;
		simulation = new Simulation(video_mode, ui.actionFull_Screen->isChecked());

		writeDefaultValues();
		//connections what  thread neede to work 
		connect(simulation, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
		connect(thread, SIGNAL(started()), simulation, SLOT(process()));
		connect(simulation, SIGNAL(finished()), thread, SLOT(quit()));
		connect(simulation, SIGNAL(finished()), simulation, SLOT(deleteLater()));
		connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
		connect(simulation, SIGNAL(finished()), this, SLOT(simulationFinished()));
		//tools connections
		connect(simulation->ball_tool, SIGNAL(ballsNChanged(int)), ui.ballsLabel, SLOT(setNum(int)));
		connect(ui.ballPerClickSpinBox, SIGNAL(valueChanged(int)), simulation->ball_tool, SLOT(setBallsPerDeploy(int)));
		connect(ui.ballMassDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsMass(double)));
		connect(ui.ballBounceFactorDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsBounceFactor(double)));
		connect(ui.ballRadiusDoubleSpinBox, SIGNAL(valueChanged(double)), simulation->ball_tool, SLOT(setBallsRadius(double)));
		connect(ui.ballRandomVelocityButton, SIGNAL(clicked(bool)), simulation->ball_tool, SLOT(setBallsRandomVelocity(bool)));
		connect(ui.ballRandomRadiusButton, SIGNAL(clicked(bool)), simulation->ball_tool, SLOT(setBallsRandomRadius(bool)));
		//time connections
		connect(ui.verySlowRadioButton, SIGNAL(clicked()), simulation, SLOT(setVerySlowTimeFactor()));
		connect(ui.slowRadioButton, SIGNAL(clicked()), simulation, SLOT(setSlowTimeFactor()));
		connect(ui.normalRadioButton, SIGNAL(clicked()), simulation, SLOT(setNormalTimeFactor()));
		connect(ui.fastRadioButton, SIGNAL(clicked()), simulation, SLOT(setFastTimeFactor()));
		//fps and tool chose
		connect(ui.actionShow_FPS, SIGNAL(toggled(bool)), simulation, SLOT(setShowFPS(bool)));
		connect(ui.toolsSettingsTabWidget, SIGNAL(currentChanged(int)), simulation, SLOT(setTool(int)));
		connect(ui.toolComboBox, SIGNAL(currentIndexChanged(int)), simulation, SLOT(setTool(int)));
		//functions of simulation
		connect(ui.actionCollisions, SIGNAL(toggled(bool)), simulation, SLOT(setBallToBallCollisions(bool)));
		connect(ui.actionGravity_Force, SIGNAL(toggled(bool)), simulation, SLOT(setGravityForces(bool)));

		simulation->moveToThread(thread);
		//ui.actionStart_simulation->setEnabled(false);
		ui.actionStart_simulation->setChecked(true);
		ui.actionStart_simulation->setText("Stop Simulation");
		ui.simulationPushButton->setChecked(true);
		ui.simulationPushButton->setText("Stop Simulation");

		connect(this, SIGNAL(savePath(QString)), simulation, SLOT(saveSimState(QString)));
		connect(this, SIGNAL(loadPath(QString)), simulation, SLOT(loadSimState(QString)));
		thread->start();
	} else {
		ui.actionStart_simulation->setChecked(false);
		ui.actionStart_simulation->setText("Start Simulation");
		ui.simulationPushButton->setChecked(false);
		ui.simulationPushButton->setText("Start Simulation");
		simulation->quit = true;
	}
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