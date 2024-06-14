#pragma once
#ifndef BULLET_NORMAL_H
#define BULLET_NORMAL_H

#include "framework/entities/bullet/bullet.h"

class BulletNormal : public Bullet {

public:
	BulletNormal() {
		//material.shader == nullptr ? std::cout << "NULL SHADER" : std::cout << "GOOD SHADER";
		this->speed = BULLET_SPD;
		this->timer_spawn = Game::instance->time;
	};
	BulletNormal(Mesh* mesh, const Material& material, Vector3 direction, Matrix44 model, float speed = BULLET_SPD, const std::string& name = "", bool fromPlayer = true) : Bullet(fromPlayer) {
		this->mesh = mesh;
		//material.shader == nullptr ? std::cout << "NULL SHADER" : std::cout << "GOOD SHADER";
		this->material = material;
		this->speed = speed;
		this->direction = direction;
		this->model = model;
		this->timer_spawn = Game::instance->time;
	};
	~BulletNormal() {

	}



	void move(Vector3 vec);
	// Methods overwritten from base class
	void render(Camera* camera);
	void update(float elapsed_time);

	void addInstance(Matrix44 model, float speed, float accel = 0, float angular_speed = 0, float angular_accel = 0) {
		this->spawn_time.push_back(Game::instance->time);

		this->models.push_back(model);
		this->speeds.push_back(speed);
		this->accels.push_back(accel);
		this->angular_speeds.push_back(angular_speed);
		this->angular_accels.push_back(angular_accel);

		Audio::Play("data/audio/shoot.wav", BULLET_VOL);
	};


	void clearInstances() {
		this->spawn_time.clear();

		this->models.clear();
		this->speeds.clear();
		this->accels.clear();
		this->angular_speeds.clear();
		this->angular_accels.clear();
	}


	void addRing(Matrix44 model, float speed, float accel = 0, float angular_speed = 0, float angular_accel = 0, float rad = 1, int count = 6) {
		for (int i = 0; i < count; i++) {
			Matrix44 _m = model;
			Matrix44 rotatematrix = Matrix44();
			rotatematrix.rotate(i * 2 * PI / count, Vector3::UP);
			_m.translate(rad * rotatematrix.rotateVector(Vector3(1,0,0)));
			this->spawn_time.push_back(Game::instance->time);

			this->models.push_back(_m);
			this->speeds.push_back(speed);
			this->accels.push_back(accel);
			this->angular_speeds.push_back(angular_speed);
			this->angular_accels.push_back(angular_accel);
		}
		Audio::Play("data/audio/shoot.wav", BULLET_VOL);
	}

	void onMouseWheel(SDL_MouseWheelEvent event);
	void onMouseButtonDown(SDL_MouseButtonEvent event);
	void onKeyUp(SDL_KeyboardEvent event);

	Vector3 getPosition();

};

#endif