﻿#include "simulation.hpp"

Simulation::Simulation(sf::VideoMode vm, bool full_screen) : video_mode(vm), full_screen(full_screen) {

	environment = new Environment(Rectangle(0, 0, vm.width, vm.height));
	ball_tool = new BallTool(environment);
	rectangle_tool = new RectangleTool(environment);
	line_tool = new LineTool(environment);
	current_tool = ball_tool; 
	font.loadFromFile("fonts\\Roboto\\Roboto-Light.ttf");
	ball_texture.loadFromFile("textures\\ball.png");
	ball_texture.setSmooth(true);
	view.reset(sf::FloatRect(0, 0, vm.width, vm.height));
}

Simulation::~Simulation() {
	delete environment;
	delete ball_tool;
	delete rectangle_tool;
	delete line_tool;
}
void Simulation::process() {
	sf::RenderWindow renderer;
	sf::VideoMode::getFullscreenModes()[0];
	if (full_screen)
		renderer.create(video_mode, "Simulate Window", sf::Style::Fullscreen);
	else
		renderer.create(video_mode, "Simulate Window");

	renderer.setView(view);
	while (renderer.isOpen())
	{
		
		sf::Event event;
		while (renderer.pollEvent(event)) //event loop
		{
			switch (event.type) {
			case sf::Event::Closed:
				renderer.close();
				break;

			case sf::Event::MouseButtonPressed:
				current_tool->update(event, renderer);
				break;
			case sf::Event::MouseButtonReleased:
				current_tool->update(event, renderer);
				break;
			case sf::Event::MouseMoved:
				static sf::Event::MouseMoveEvent prev_mouse_move;
				current_tool->update(event, renderer);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
					view.move((prev_mouse_move.x - event.mouseMove.x)*scale,
							(prev_mouse_move.y - event.mouseMove.y)*scale);
					renderer.setView(view);
				}
				prev_mouse_move = event.mouseMove;
				break;
			case sf::Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					if (event.mouseWheelScroll.delta < 0) {
						view.zoom(2.0f);
						scale *= 2.f;
					}
					else {
						view.zoom(0.5f);
						scale *= 0.5f;
					}
					renderer.setView(view);
				}
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					view.move(0, -20);
					renderer.setView(view);
					break;
				case sf::Keyboard::Down:
					view.move(0, 20);
					renderer.setView(view);
					break;
				case sf::Keyboard::Left:
					view.move(-20, 0);
					renderer.setView(view);
					break;
				case sf::Keyboard::Right:
					view.move(20, 0);
					renderer.setView(view);
					break;				
				case sf::Keyboard::Escape:
					quit = true;
				case sf::Keyboard::F5:
					saveSimState(quick_save_path);
					break;
				case sf::Keyboard::F7:
					loadSimState(quick_save_path);
					break;
				}
				break;
			}
		}

		environment->update(time.get_delta_t()*((paused)?0:1.f));//if paused then make 0 delta t

		renderer.clear();
		drawBalls(renderer, environment->BSpwn.balls);
		drawRectangles(renderer, environment->rectangles);
		drawLines(renderer, environment->lines);
		current_tool->draw(renderer);
		if (showFPS)
			drawFPS(renderer, time.get_current_FPS());
		renderer.display();

		time.update();

		QCoreApplication::processEvents();
		if (quit) {
			renderer.close();
			quit = false;
		}
	}
	emit finished();
}


void Simulation::drawBalls(sf::RenderWindow &renderer, std::vector<Ball> &balls) {
	sf::CircleShape circle;
	circle.setTexture(&ball_texture);
	for (Ball &ball : balls) {
		circle.setRadius(ball.r);
		circle.setOrigin(circle.getRadius(), circle.getRadius());
		circle.setPosition(ball.position.x, ball.position.y);
		circle.setFillColor(ball.color);
		renderer.draw(circle);
	}
}

void Simulation::drawRectangles(sf::RenderWindow &renderer, std::vector<Rectangle> &Rectangles) {
	sf::RectangleShape rect;
	for (Rectangle &rectangle : Rectangles) {
		rect.setSize(sf::Vector2f(rectangle.rect.w, rectangle.rect.h));
		rect.setPosition(rectangle.rect.x, rectangle.rect.y);
		rect.setFillColor(sf::Color(0, 0, 0, 0));
		rect.setOutlineColor(rectangle.color);
		rect.setOutlineThickness(10);
		//rect.getOutlineColor
		renderer.draw(rect);
	}
}

void Simulation::drawLines(sf::RenderWindow &renderer, std::vector<Line> &Lines){
sf::RectangleShape rect;
	for (Line &line : Lines) {
		rect.setSize(sf::Vector2f(line.length, line.width));
		rect.setPosition(line.p1.x, line.p1.y);
		rect.setRotation(line.angle * 180 / M_PI);
		rect.setFillColor(line.color);
		renderer.draw(rect);
	}
}

void Simulation::drawFPS(sf::RenderWindow &renderer, float fps) {
	sf::View prev_state;
	prev_state = renderer.getView();
	renderer.setView(renderer.getDefaultView());

	sf::Text text;
	QString s ="FPS: " + QString::number(fps);
	text.setFont(font);
	text.setString(s.toStdString());
	text.setColor(sf::Color::White);
	text.setCharacterSize(20);
	text.setPosition(renderer.getSize().x - 100, 0);
	renderer.draw(text);

	renderer.setView(prev_state);
}
