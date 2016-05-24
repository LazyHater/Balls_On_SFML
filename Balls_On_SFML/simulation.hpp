﻿#pragma once
#include <QObject>
#include <QCoreApplication>
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "Environment.h"
#include "tools.h"

class Time { // what a mess
	sf::Time delta_t = sf::seconds(0);
	sf::Time max_fps = sf::seconds(60.f); // max on 60 fps
	sf::Time max_frame_time = sf::seconds(1.f/60.f); // max on 60 fps
	float currentFPS;
	float time_factor = 1.f;
	sf::Clock clock;
	bool holdFPS = true;
public:
	Time() {
		max_frame_time = sf::seconds(1 / max_fps.asSeconds());
	}
	void update() {
		delta_t = clock.getElapsedTime();
		if (delta_t<max_frame_time)
			sf::sleep(max_frame_time - delta_t);
		delta_t = clock.restart();
		currentFPS = 1 / delta_t.asSeconds();
		delta_t *= time_factor;
	}

	float get_delta_t() { return delta_t.asSeconds(); }
	float get_current_FPS() { return currentFPS; }

	void set_time_factor(double val) { time_factor = val; }
};

class Simulation : public QObject {
	Q_OBJECT

public:
	Simulation(sf::VideoMode vm, bool full_screen);
	~Simulation();

	BallTool *ball_tool;
	RectangleTool *rectangle_tool;
	LineTool *line_tool;

public slots:
	void process();

	void setTool(int ID) {
		switch (ID) {
		case BALL_TOOL:
			current_tool = ball_tool;
			break;
		case RECTANGLE_TOOL:
			current_tool = rectangle_tool;
			break;
		case LINE_TOOL:
			current_tool = line_tool;
			break;
		}
	}

	void setTimeFactor(double val) {
		time.set_time_factor(val);
	}
	void setVerySlowTimeFactor() {
		time.set_time_factor(0.01);
	}
	void setSlowTimeFactor() {
		time.set_time_factor(0.1);
	}
	void setNormalTimeFactor() {
		time.set_time_factor(1);
	}
	void setFastTimeFactor() {
		time.set_time_factor(10);
	}

	void setShowFPS(bool b) { showFPS = b; }

	void setBallToBallCollisions(bool b) {
		environment->settings.ball_to_ball_collisions = b;
	}

	void setGravityForces(bool b) {
		environment->settings.gravity_forces = b;
	}
signals:
	void finished();
	void error(QString err);
	void ballsNChanged(int);
	void fpsUpdate(int);

private:
	sf::Texture ball_texture;
	sf::View view;
	sf::VideoMode video_mode;
	bool full_screen;

	sf::Font font;
	bool quit = false;
	bool showFPS = true;
	Time time;
	Environment *environment;
	Tool *current_tool;

	float scale = 1.f;

	sf::Vector2i def_window_position;
	void drawBalls(sf::RenderWindow &renderer, std::vector<Ball> &balls);
	void drawRectangles(sf::RenderWindow &renderer, std::vector<Rectangle> &Rectangles);
	void drawLines(sf::RenderWindow &renderer, std::vector<Line> &Lines);

	void drawFPS(sf::RenderWindow &renderer, float fps);
	// add your variables here
	

};


