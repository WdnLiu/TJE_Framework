#include "player.h"
#include "enemy.h"
#include "game/StageManager.h"
#include "framework/audio.h"
#include "game/GameStage.h"

#include <string>
#include <algorithm>

// cubemap

void Player::sphere_bullet_collision(Vector3 position, float radius) {
	Stage* stage = StageManager::instance->currStage;
	bool isHit = targetable;
	std::string audiofile;
	if (targetable) {
		for (Bullet* bullet : stage->enemy->bullets) {
			sCollisionData data;

			if (bullet->isInstanced) {
				for (Matrix44& instanced_model : bullet->models) {
					if (targetable && bullet->mesh->testSphereCollision(instanced_model, position, radius, data.colPoint, data.colNormal)) {
						colliding = true;
						bullet->to_delete = true;
						stage->anxiety_dt -= bullet->damage;
						targetable = false;
						startHit = Game::instance->time;
						audiofile = std::to_string((int)floor(random(2.99))) + ".mp3";
						Audio::Play("data/audio/h1_" + audiofile);
						std::cout << "data/audio/h3_" + audiofile;
						return;
					}
				}
			}
			else {
				if (targetable && bullet->mesh->testSphereCollision(bullet->model, position, radius, data.colPoint, data.colNormal)) {
					colliding = true;
					bullet->to_delete = true;
					stage->anxiety_dt -= bullet->damage;
					targetable = false;
					startHit = Game::instance->time;
					audiofile = std::to_string((int)floor(random(2.99))) + ".mp3";
					Audio::Play("data/audio/h1_" + audiofile);
					std::cout << "data/audio/h3_" + audiofile;
					return;
				}
			}
		}
		BulletNormal& bns = stage->enemy->bullets_normal;
		for (int i = 0; i < bns.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_normal.models[i];
			sCollisionData data;
			if (targetable && bns.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				bns.despawnBullet(i);
				stage->anxiety_dt -= bns.damage;
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(2.99))) + ".mp3";
				Audio::Play("data/audio/h1_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletNormal& bbs = stage->enemy->bullets_ball;
		for (int i = 0; i < bbs.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_ball.models[i];
			sCollisionData data;
			if (targetable && bbs.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				bbs.despawnBullet(i);
				stage->anxiety_dt -= bbs.damage;
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(1.99))) + ".mp3";
				Audio::Play("data/audio/h2_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletNormal& bsbs = stage->enemy->bullets_smallball;
		for (int i = 0; i < bsbs.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_smallball.models[i];
			sCollisionData data;
			if (targetable && bsbs.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				bsbs.despawnBullet(i);
				stage->anxiety_dt -= bsbs.damage;
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(2.99))) + ".mp3";
				Audio::Play("data/audio/h1_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletResize& bgb = stage->enemy->bullets_giantball;
		for (int i = 0; i < bgb.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_giantball.models[i];
			sCollisionData data;
			if (targetable && bgb.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				stage->anxiety_dt -= bgb.damage * bgb.sizes[i];
				bgb.despawnBullet(i);
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(1.99))) + ".mp3";
				Audio::Play("data/audio/h3_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletNormal& bno = stage->enemy->bullets_normal_orange;
		for (int i = 0; i < bno.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_normal_orange.models[i];
			sCollisionData data;
			if (targetable && bno.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				stage->anxiety_dt -= bno.damage;
				bno.despawnBullet(i);
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(1.99))) + ".mp3";
				Audio::Play("data/audio/h3_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletNormal& bny = stage->enemy->bullets_normal_yellow;
		for (int i = 0; i < bny.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_normal_yellow.models[i];
			sCollisionData data;
			if (targetable && bny.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				stage->anxiety_dt -= bny.damage;
				bny.despawnBullet(i);
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(1.99))) + ".mp3";
				Audio::Play("data/audio/h3_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
		BulletNormal& bnp = stage->enemy->bullets_normal_purple;
		for (int i = 0; i < bnp.models.size(); i++) {
			Matrix44& m = stage->enemy->bullets_normal_purple.models[i];
			sCollisionData data;
			if (targetable && bnp.mesh->testSphereCollision(m, position, radius, data.colPoint, data.colNormal)) {
				stage->anxiety_dt -= bnp.damage;
				bnp.despawnBullet(i);
				targetable = false;
				startHit = Game::instance->time;
				audiofile = std::to_string((int)floor(random(1.99))) + ".mp3";
				Audio::Play("data/audio/h3_" + audiofile);
				std::cout << "data/audio/h3_" + audiofile;
				return;
			}
		}
	}
	//if (isHit != targetable) Audio::Play("data/audio/whip.wav");
}

void Player::dash(float delta_time, float dash_duration = 1, float invul_duration = 0.25) {
	if (!dashing) {
		if (stamina > 30) {
			staminadec -= 30;
			m_spd = 3 * DEFAULT_SPD;
			timer_dash = Game::instance->time;
			dashInvulnerabilityTimer = Game::instance->time;
			dashing = true;
			targetable = false;
			can_be_hit = false;
			Audio::Play("data/audio/dash_0.wav");
		}
	}
	else if (m_spd > DEFAULT_SPD) {
		m_spd -= 3 * DEFAULT_SPD * delta_time / dash_duration;
	}
	else {
		m_spd = DEFAULT_SPD;
		dashing = false;
	}
	if (!targetable && Game::instance->time - timer_dash > invul_duration) {
		targetable = true;
		can_be_hit = true;
	}
}

void Player::jump(float delta_time) {
	if (grounded) {
		if (stamina > 60) {
			staminadec -= 60;
			v_spd = JUMP_SPD;
			timer_jump = Game::instance->time;
			grounded = false;
			jumping = true;
			Audio::Play("data/audio/jump.wav");
		}
	}
	else v_spd = JUMP_SPD * (1 - (2 * (Game::instance->time - timer_jump)));
}

void Player::shoot(bullet_type bullet_type = auto_aim) {
	Matrix44 _m = model;
	_m.setFrontAndOrthonormalize(_m.frontVector() * Vector3(1, 0, 1));
	if (bullet_type == shotgun) {
		if (free_bullets && mana > shoot_cost[bullet_type] && Game::instance->time - timer_bullet[bullet_type] > shoot_cooldown[bullet_type]) {
			Audio::Play("data/audio/shotgun.wav");
			timer_bullet[bullet_type] = Game::instance->time;
			mana -= shoot_cost[bullet_type];
			free_bullets -= amount[bullet_type];
			std::cout << "Aqui llega \n";
			Patterns::shotgun2(_m, bullets_normal, 20);
			std::cout << mana << " " << bullet_idx_first << " " << free_bullets << " " << bullet_type << std::endl;
		}
		return;
	}
	else if (bullet_type == auto_aim) {
		if (free_bullets && mana > shoot_cost[bullet_type] && Game::instance->time - timer_bullet[bullet_type] > shoot_cooldown[bullet_type]) {
			Audio::Play("data/audio/shoot_player.wav", 0.1);
			timer_bullet[bullet_type] = Game::instance->time;
			mana -= shoot_cost[bullet_type];
			free_bullets -= amount[bullet_type];
			Patterns::autoAim2(_m, bullets_auto);
			std::cout << mana << " " << bullet_idx_first << " " << free_bullets << " " << bullet_type << std::endl;
		}
		return;
	}
	else if (bullet_type == circle) {
		if (free_bullets && mana > shoot_cost[bullet_type] && Game::instance->time - timer_bullet[bullet_type] > shoot_cooldown[bullet_type]) {
			Audio::Play("data/audio/shoot_player.wav", 0.5);
			timer_bullet[bullet_type] = Game::instance->time;
			mana -= shoot_cost[bullet_type];
			free_bullets -= amount[bullet_type];
			Patterns::horizontal3(_m, bullets_normal, 5, 20, 0.3);
			std::cout << mana << " " << bullet_idx_first << " " << free_bullets << " " << bullet_type << std::endl;
		}
		return;
	}
	else if (free_bullets && mana > shoot_cost[bullet_type] && Game::instance->time - timer_bullet[bullet_type] > shoot_cooldown[bullet_type]) {
		Stage* stage = StageManager::instance->currStage;
		if (bullet_type == sniper) {
			if (stage->anxiety > 10) stage->anxiety_dt -= 4;
		}
		Audio::Play("data/audio/lazer.mp3");
		timer_bullet[bullet_type] = Game::instance->time;
		mana -= shoot_cost[bullet_type];
		free_bullets -= amount[bullet_type];
		patterns[bullet_type](StageManager::instance->currStage->enemy->getPosition() + Vector3(0, player_height, 0), forward, _m, bullets, amount[bullet_type], bullet_shaders[bullet_type], bullet_textures[bullet_type], bullet_meshes[bullet_type]);
		std::cout << mana << " " << bullet_idx_first << " " << free_bullets << " " << bullet_type << std::endl;
	}
}

void Player::shootCharge(bullet_type bullet_type) {
	//std::cout << "charging (telo imaginas)" << std::endl;
	bool time = (Game::instance->time - timer_charge[bullet_type]) > charge_cooldown[bullet_type];

	if (time && !charging && Game::instance->time - timer_bullet[bullet_type] > shoot_cooldown[bullet_type]) {
		timer_charge[bullet_type] = Game::instance->time;
		charge_channel = Audio::Play("data/audio/lazer_charge.mp3");
		charging = true;
	}
	else if (charging) {
		if (!time) {
			
		}
		else {
			charging = false;
			shoot(bullet_type);
		}
	}
}


void Player::showHitbox(Camera* camera) {
	Matrix44 m = model;

	flat_shader->enable();

	float sphere_radius = HITBOX_RAD;
	m.translate(0.0f, (player_height / 1.5), 0.0f);
	m.scale(sphere_radius, sphere_radius, sphere_radius);

	flat_shader->setUniform("u_color", Vector4(touching_ground, 0.0f, colliding, 1.0f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", m);

	hitbox_mesh->render(GL_LINES);

	flat_shader->disable();

	m = model;

	flat_shader->enable();

	m.translate(0.0f, (player_height / 1.5) + 2* sphere_radius, 0.0f);
	m.scale(sphere_radius, sphere_radius, sphere_radius);

	flat_shader->setUniform("u_color", Vector4(touching_ground, 0.0f, colliding, 1.0f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", m);

	hitbox_mesh->render(GL_LINES);

	flat_shader->disable();

	m = model;

	flat_shader->enable();

	m.translate(0.0f, (player_height/ 1.5) + 4 * sphere_radius, 0.0f);
	m.scale(sphere_radius, sphere_radius, sphere_radius);

	flat_shader->setUniform("u_color", Vector4(touching_ground, 0.0f, colliding, 1.0f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", m);

	hitbox_mesh->render(GL_LINES);

	flat_shader->disable();

	m = model;

	flat_shader->enable();

	m.translate(0.0f, (player_height / 1.5) + 6 * sphere_radius, 0.0f);
	m.scale(sphere_radius, sphere_radius, sphere_radius);

	flat_shader->setUniform("u_color", Vector4(touching_ground, 0.0f, colliding, 1.0f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", m);

	hitbox_mesh->render(GL_LINES);

	flat_shader->disable();

	m = model;

	flat_shader->enable();

	m.translate(0.0f, (player_height / 1.5) + 8 * sphere_radius, 0.0f);
	m.scale(sphere_radius, sphere_radius, sphere_radius);

	flat_shader->setUniform("u_color", Vector4(touching_ground, 0.0f, colliding, 1.0f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", m);

	hitbox_mesh->render(GL_LINES);

	flat_shader->disable();
}

void Player::chargingShot(Camera* camera) {
	float size = (1 - (Game::instance->time - timer_charge[bt])) / charge_cooldown[bt];
	charge_model = model;
	charge_model.translate(Vector3(0, 1, 0));
	charge_model.scale(size, size, size);

	if (!charge_mat.shader) {
		charge_mat.shader = Shader::Get(isInstanced ? "data/shaders/instanced.vs" : "data/shaders/basic.vs");
	}

	charge_mat.shader->enable();

	charge_mat.shader->setUniform("u_color", charge_mat.color);
	charge_mat.shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	charge_mat.shader->setTexture("u_texture", charge_mat.diffuse, 0 /*Slot que ocupa en la CPU, cuando tengamos mas texturas ya nos organizamos*/);
	charge_mat.shader->setUniform("u_model", charge_model);
	charge_mat.shader->setUniform("u_time", Game::instance->time);

	charge_mesh->render(GL_TRIANGLES);

	// Disable shader after finishing rendering
	charge_mat.shader->disable();
}

void Player::renderWithLights(Camera* camera) {

	//int width = Game::instance->window_width;
	//int height = Game::instance->window_height;
	Stage* stage = StageManager::instance->currStage;
	//bool visible = true;
	//Vector3 pos3d = getPositionGround();
	//Vector2 position;
	//Vector3 pos = camera->project(pos3d, width, height);
	//std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
	//if (pos.z < 0.0f || pos.z > 1.0f) {
	//	visible = true;
	//	pos.y = height - pos.y;
	//	position = Vector2(pos.x, pos.y);
	//}
	//else {
	//	pos.y = height - pos.y;
	//	position = Vector2(pos.x, pos.y);
	//}

	//Vector2 _size = Vector2(100, 100);
	////float max_dist = 5.0f;
	////float dist = clamp(stage->camera->eye.distance(pos3d), 0.01f, max_dist);
	////_size *= 1.f - (dist / max_dist);

	//if (!staminashader) {
	//	staminashader = Shader::Get("data/shaders/hud2.vs", "data/shaders/hud2.fs");
	//}

	//staminashader->enable();

	//staminashader->setUniform("u_viewprojection", stage->camera2D->viewprojection_matrix);
	//staminashader->setUniform("u_color", Vector3(0, 1, 0));
	//staminashader->setUniform("u_percentage", stamina / 300);
	//staminashader->setUniform("u_decrease", staminadec / 300);

	//Mesh quad;
	//quad.createQuad(position.x, height - position.y - 30, 100, 10, false);
	////quad.createQuad(500, 500, 1000, 100, true);
	//quad.render(GL_TRIANGLES);

	//staminashader->disable();





	bool time = (Game::instance->time - timer_charge[bt]) > charge_cooldown[bt];



	// Render the charging
	if (charging) 
		chargingShot(camera);

	// Render the Shadow
	Matrix44 squash = model;
	squash.setTranslation(Vector3(model.getTranslation().x, ground_y, model.getTranslation().z));
	squash.scale(1 / (1 + ground_below_y), 0.01, 1 / (1 + ground_below_y));

	//glDepthFunc(GL_GREATER);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);
	//glDepthMask(false);
	flat_shader->enable();

	flat_shader->setUniform("u_color", Vector4(0.0f, 0.0f, 0.0f, 0.5f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", squash);

	shadow_mesh->render(GL_TRIANGLES);

	flat_shader->disable();



	//Matrix44 stam = model;
	//stam.setTranslation(Vector3(model.getTranslation().x, ground_y + 0.1, model.getTranslation().z));

	//staminashader->enable();

	//staminashader->setUniform("u_color", Vector4(0.0f, 0.0f, 0.0f, 0.5f));
	//staminashader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	//staminashader->setUniform("u_model", squash);

	//staminabar->render(GL_TRIANGLES);

	//staminashader->disable();










	anim = animation_pool[current_animation];
	Skeleton blended_skeleton = anim->skeleton;
	if (Game::instance->time - timer_anim < ANIM_TRANSLATIONTIME) {
		blendSkeleton(&animation_pool[last_animation]->skeleton,
			&animation_pool[current_animation]->skeleton,
			(Game::instance->time - timer_anim) / ANIM_TRANSLATIONTIME, &blended_skeleton);
	}

	if (!shader_lights) {
		shader_lights = Shader::Get("data/shaders/skinning.vs", "data/shaders/textureLight.fs");
	}

	Shader* shader = shader_lights;

	if (grounded) {
		anim->assignTime(Game::instance->time);
	}
	else {
		anim->assignTime((Game::instance->time - timer_jump)/3);
	}
	



	shader_lights->enable();
	shader_lights->setUniform("u_color", targetable ? material.color : Vector4(1, 1, 1, 0.1 + 0.9 * (can_be_hit) * ((int)(Game::instance->time * 10) % 2)));
	shader_lights->setUniform("u_viewprojection", camera->viewprojection_matrix);

	float value = 0.0;
	shader_lights->setUniform("u_normal_option", value);

	shader_lights->setUniform("eye", camera->eye);
	shader_lights->setUniform("u_alpha", 30.0f);
	shader_lights->setUniform("u_specular", 0.2f);
	shader_lights->setUniform("u_ambient_light", StageManager::instance->ambient_night);

	GameStage::lightToShader(GameStage::instance->mainLight, shader_lights);
	//for (Light* light : GameStage::instance->lights) GameStage::lightToShader(light, shader_lights);

	if (material.diffuse) {
		shader_lights->setTexture("u_texture", material.diffuse, 0);
	}
	shader_lights->setUniform("u_model", model);
	shader_lights->setUniform("u_time", Game::instance->time);

	mesh->renderAnimated(GL_TRIANGLES, &blended_skeleton);
	// std::cout << isAnimated << std::endl;

	// Disable shader_lights after finishing rendering
	shader_lights->disable();

	if (!stage->transitioningPhase) {

		Matrix44 stam = model;
		stam.translate(Vector3(0, (ground_y - model.getTranslation().y) + 0.05, 0));
		Matrix44 stam2 = stam;
		stam2.rotate(stam2.getYawRotationToAimTo(stage->enemy->getPosition()), Vector3::UP);
		Matrix44 stam3 = stam2;

		float dot = stam.frontVector().normalize().dot(stam2.frontVector());
		bool enough_mana = (mana > shoot_cost[(int)bt]);

		veccircleshader->enable();

		veccircleshader->setUniform("u_viewprojection", camera->viewprojection_matrix);
		veccircleshader->setUniform("u_model", stam);
		if (dot > 0.98) veccircleshader->setUniform("u_color", Vector4(0, enough_mana + 0.7 * !enough_mana, !enough_mana, 1));
		else veccircleshader->setUniform("u_color", Vector4(enough_mana, enough_mana + 0.7 * !enough_mana, 1, 1));
		circlemesh->render(GL_TRIANGLES);

		float dist = clamp((getPositionGround().distance(stage->enemy->getPositionGround()) / 10) - 0.2f, 0.2, 2);
		stam2.scale(Vector3(1, 1, dist));

		veccircleshader->setUniform("u_viewprojection", camera->viewprojection_matrix);
		veccircleshader->setUniform("u_model", stam2);
		veccircleshader->setUniform("u_color", Vector4(1, 1, 1, clamp((dist - 0.4)/2, 0, 0.4)));
		vector->render(GL_TRIANGLES);

		veccircleshader->disable();


		stam3.rotate(PI, Vector3::UP);


		staminashader->enable();

		staminashader->setUniform("u_viewprojection", camera->viewprojection_matrix);
		staminashader->setUniform("u_model", stam3);
		staminashader->setUniform("u_color", Vector4(0, 1, 0, 1));
		staminashader->setUniform("u_percentage", stamina / 200);
		staminashader->setUniform("u_decrease", staminadec / 200);
		//flat_shader->setTexture("u_texture", staminatext, 0);
		staminabar->render(GL_TRIANGLES);

		staminashader->disable();



		//dir->render(camera);
		//vec->render(camera);
	}




	glDisable(GL_BLEND);
	glFrontFace(GL_CCW);
	glDisable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glDepthMask(true);

	// Render hijos
	for (size_t i = 0; i < children.size(); i++)
	{
		children[i]->renderWithLights(camera);
	}
	bullets_normal.render(camera);
	bullets_auto.render(camera);


	// Render Bullets
	for (int i = bullets.size() - 1; i >= 0; i--)
		bullets[i]->render(camera);




	//showHitbox(camera);
};

void Player::render(Camera* camera) {

	bool time = (Game::instance->time - timer_charge[bt]) > charge_cooldown[bt];
	// Render Bullets
	for (int i = bullets.size() - 1; i >= 0; i--)
		bullets[i]->render(camera);


	// Render the charging
	if (charging)
		chargingShot(camera);

	// Render the Shadow
	Matrix44 squash = model;
	squash.setTranslation(Vector3(model.getTranslation().x, ground_y, model.getTranslation().z));
	squash.scale(1 / (1 + ground_below_y), 0.01, 1 / (1 + ground_below_y));

	//glDepthFunc(GL_GREATER);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);
	//glDepthMask(false);
	flat_shader->enable();

	flat_shader->setUniform("u_color", Vector4(0.0f, 0.0f, 0.0f, 0.5f));
	flat_shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
	flat_shader->setUniform("u_model", squash);

	shadow_mesh->render(GL_TRIANGLES);

	flat_shader->disable();
	glDisable(GL_BLEND);
	glFrontFace(GL_CCW);
	glDisable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glDepthMask(true);


	anim = animation_pool[current_animation];
	Skeleton blended_skeleton = anim->skeleton;
	if (Game::instance->time - timer_anim < 0.4) {
		blendSkeleton(&animation_pool[last_animation]->skeleton,
			&animation_pool[current_animation]->skeleton,
			(Game::instance->time - timer_anim) / 0.4, &blended_skeleton);
	}

	if (!material.shader) {
		material.shader = Shader::Get("data/shaders/skinning.vs", "data/shaders/texture.fs");
	}
	anim->assignTime(Game::instance->time);
	material.shader->enable();
	material.shader->setUniform("u_color", material.color);
	material.shader->setUniform("u_viewprojection", camera->viewprojection_matrix);

	if (material.diffuse) {
		material.shader->setTexture("u_texture", material.diffuse, 0 /*Slot que ocupa en la CPU, cuando tengamos mas texturas ya nos organizamos*/);
	}
	material.shader->setUniform("u_model", model);
	material.shader->setUniform("u_time", Game::instance->time);

	mesh->renderAnimated(GL_TRIANGLES, &blended_skeleton);
	// std::cout << isAnimated << std::endl;

	// Disable shader after finishing rendering
	material.shader->disable();

	// Render hijos
	for (size_t i = 0; i < children.size(); i++)
	{
		children[i]->render(camera);
	}
	bullets_normal.render(camera);
	bullets_auto.render(camera);


	dir->render(camera);
	vec->render(camera);

	//showHitbox(camera);
};

void Player::move(const Vector3& vec) {
	//model.translate(vec);
	model.translateGlobal(vec);
}


float Player::updateSubframe(float delta_time) {
	Stage* stage = StageManager::instance->currStage;
	float time = Game::instance->time;
	direction = model.frontVector();
	if ((Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_walk)) /* && stage->mouse_locked*/)) {
		if (!dashing) m_spd = DEFAULT_SPD;
		direction +=  5*model.frontVector();
	}

	Matrix44 m = model;
	m.rotate(m.getYawRotationToAimTo(stage->enemy->getPosition()), Vector3::UP);
	if (Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_right))  ) {
		if (!dashing) m_spd = DEFAULT_SPD;
		direction += -5*m.rightVector();
	}
	if (Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_back))) {
		if (!dashing) m_spd = DEFAULT_SPD;
		direction += -5*m.frontVector();
	}
	if (Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_left))) {
		if (!dashing) m_spd = DEFAULT_SPD;
		direction += 5*m.rightVector();
	}
	direction.normalize();
	//direction = Vector3(0.0f);

	//if (Input::isKeyPressed(StageManager::instance->k_walk)) direction += getFront();
	//if (Input::isKeyPressed(SDL_SCANCODE_S)) direction -= getFront();
	//if (Input::isKeyPressed(SDL_SCANCODE_A)) direction += getRight();
	//if (Input::isKeyPressed(SDL_SCANCODE_D)) direction -= getRight();
	if (!targetable) targetable = (time - startHit >= 0.66f && time - dashInvulnerabilityTimer >= 1.f);

	if (!dashing && m_spd > 0) {
		m_spd -= DEFAULT_SPD * delta_time / stop_duration;
		if (m_spd < 0) m_spd = 0;
	}
	direction *= m_spd;
	bool is_knowckback = timer_bullet_general < knockback_time[bt];
	float knockback_speed = DEFAULT_SPD * knockback[bt] * (knockback_time[bt] - timer_bullet_general) * (is_knowckback); //the speed is defined by the seconds_elapsed so it goes constant

	//std::cout << speed << std::endl;


	

	direction -= knockback_speed * model.frontVector();
	direction.normalize();
	float total_spd = abs(m_spd - knockback_speed);

	for (int i = 0; i < bullets.size(); i++) {
		Bullet* b = bullets[i];
		if (b->to_delete) {
			bullets.erase((bullets.begin() + i));
			delete b;
			bullet_idx_last++;
			free_bullets++;
		}
		else if (Game::instance->time - b->timer_spawn > 2.5) {
			b->active = false;
			b->update(delta_time);
		}
		else b->update(delta_time);
	}


	mana += (DEFAULT_COST + 2) * delta_time / (DEFAULT_FIRERATE);
	mana = clamp(mana, 0, 300);

	//stamina += ((stamina) + 1) * delta_time;
	stamina += 40 * delta_time;
	stamina += staminadec * delta_time * 10;
	staminadec -= staminadec * delta_time * 10;
	stamina = clamp(stamina, 0, 200);

	std::vector<sCollisionData> collisions;
	std::vector<sCollisionData> ground;

	Vector3 player_center = getPosition() + Vector3(0, player_height, 0);
	if (!mesh) std::cout << "NOMESH ";

	colliding = stage->sphere_collided(stage->root, collisions, player_center, HITBOX_RAD);

	stage->ray_collided(stage->root, ground, player_center, -Vector3::UP, 100, false , FLOOR);


	for (sCollisionData& g : collisions) {
		direction += g.colNormal * 10000;
		direction.y = 0;
	}
	direction.normalize();
	ground_below_y = 10000;
	ground_y = -10000;

	touching_ground = false;

	for (sCollisionData& g : ground) {
		if (ground_y < g.colPoint.y) {
			ground_y = g.colPoint.y;
			ground_below_y = player_center.y - g.colPoint.y;
			ground_normal = g.colNormal;
		}
		if (player_center.y - g.colPoint.y < player_height + 0.01 && player_center.y - g.colPoint.y > player_height - 0.3) {
			touching_ground = true;
			v_spd = g.colNormal.y * ground_below_y * ground_below_y;
		}
	}
	grounded = touching_ground;
	if (Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_jump)) && (grounded || ((time - timer_jump) < .3))) {
		jump(delta_time);
	}
	else
		jumping = false;

	if (!grounded && !jumping) {
		v_spd -= GRAVITY * delta_time;
	}

	Vector3 movement = (direction * total_spd + Vector3::UP * (grounded ? (ground_y - getPosition().y) * 40 : v_spd)) * delta_time;
	move(movement);
	return total_spd;
}

void Player::update(float delta_time) {
	//std::cout << stamina << "\n";
	Stage* stage = StageManager::instance->currStage;
	if (stage->mouse_locked) model.rotate(StageManager::instance->sensitivity*Input::mouse_delta.x * (0.005f - (timer_bullet_general < knockback_time[bt]) * (0.0045f)), Vector3(0.0f, -1.0f, 0.0f));
	float total_spd;
	int subframes = 1;
	if (1 / delta_time < 60) subframes = 120 * delta_time;
	for (int i = 0; i < subframes; i++) {
		total_spd = updateSubframe(delta_time / subframes);
	}

	float time = Game::instance->time;
	float box_dist = getPositionGround().distance(box_cam);
	if (box_dist > 1) {
		box_cam += (box_dist - 1) * (getPositionGround() - box_cam) * delta_time;
	}
	timer_bullet_general = Game::instance->time - timer_bullet[bt];
	if (Input::wasKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_dash)) || dashing) {
		dash(delta_time);
	}
	if (Input::wasKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_shoot))) {
		if (mana + 10 < shoot_cost[bt]) {
			Audio::Play("data/audio/incorrect.mp3");
			return;
		}
	}
	if (Input::isKeyPressed(SDL_GetScancodeFromKey(StageManager::instance->k_shoot))) {
		//std::cout << std::endl << "\ncharge:\n" << charge_cooldown[bt] << std::endl;
		if (charge_cooldown[bt] && (mana - shoot_cost[bt]) > 0) shootCharge(bt);
		else shoot(bt);
	}
	else {
		charging = false;
		timer_charge[bt] = 0;
		Audio::Stop(charge_channel);
	}

	if (autoshoot) {
		shoot();
	}

	float dot = direction.dot(model.frontVector());
	Matrix44 m = model;
	//m.rotate(m.getYawRotationToAimTo(stage->enemy->getPosition()), Vector3::UP);

	float dotfront = direction.dot(m.frontVector());
	float dotside = direction.dot(m.rightVector());

	if (dot > 0.9) {
		if (dashing) {
			if (current_animation != DASH) {
				last_animation = current_animation;
				current_animation = DASH;
				timer_anim = Game::instance->time;
			}
		}
		else if (total_spd > 0.3) {
			if (current_animation != WALKING) {
				last_animation = current_animation;
				current_animation = WALKING;
				timer_anim = Game::instance->time;
			}
		}
		else {
			if (current_animation != IDLE) {
				last_animation = current_animation;
				current_animation = IDLE;
				timer_anim = Game::instance->time;
			}
		}
	}
	else if (dotside < -0.6) {
		if (dashing) {
			if (current_animation != RUNNING_RIGHT) {
				last_animation = current_animation;
				current_animation = RUNNING_RIGHT;
				timer_anim = Game::instance->time;
			}
		}
		else if (total_spd > 0.3) {
			if (current_animation != WALKING_RIGHT) {
				last_animation = current_animation;
				current_animation = WALKING_RIGHT;
				timer_anim = Game::instance->time;
			}
		}
		else {
			if (current_animation != IDLE) {
				last_animation = current_animation;
				current_animation = IDLE;
				timer_anim = Game::instance->time;
			}
		}
	}
	else if (dotside > 0.6) {
		if (dashing) {
			if (current_animation != RUNNING_LEFT) {
				last_animation = current_animation;
				current_animation = RUNNING_LEFT;
				timer_anim = Game::instance->time;
			}
		}
		else if (total_spd > 0.3) {
			if (current_animation != WALKING_LEFT) {
				last_animation = current_animation;
				current_animation = WALKING_LEFT;
				timer_anim = Game::instance->time;
			}
		}
		else {
			if (current_animation != IDLE) {
				last_animation = current_animation;
				current_animation = IDLE;
				timer_anim = Game::instance->time;
			}
		}
	}
	else {
		if (dashing) {
			if (current_animation != RUNNING_BACK) {
				last_animation = current_animation;
				current_animation = RUNNING_BACK;
				timer_anim = Game::instance->time;
			}
		}
		else if (total_spd > 0.3) {
			if (current_animation != WALKING_BACK) {
				last_animation = current_animation;
				current_animation = WALKING_BACK;
				timer_anim = Game::instance->time;
			}
		}
		else {
			if (current_animation != IDLE) {
				last_animation = current_animation;
				current_animation = IDLE;
				timer_anim = Game::instance->time;
			}
		}
	}

//	move(direction * speed * delta_time);
//	if (!grounded)
//		move(Vector3::UP * v_spd * delta_time);
//	else
//		move(Vector3::UP * (ground_y - getPosition().y) * delta_time * 20);

	bullets_auto.objective = stage->enemy->getHitboxPosition();
	bullets_normal.update(delta_time);
	bullets_auto.update(delta_time);
	Entity::update(delta_time);


	Vector3 player_center = getPosition() + Vector3(0, player_height, 0);

	this->sphere_bullet_collision(player_center, HITBOX_RAD);
	Vector3 minusPlayerHeight = Vector3(0, -player_height / 3, 0);
	this->sphere_bullet_collision(player_center + Vector3::UP * 2*HITBOX_RAD + minusPlayerHeight, HITBOX_RAD);
	this->sphere_bullet_collision(player_center + Vector3::UP * 4*HITBOX_RAD + minusPlayerHeight, HITBOX_RAD);
	this->sphere_bullet_collision(player_center + Vector3::UP * 6 * HITBOX_RAD + minusPlayerHeight, HITBOX_RAD);
	this->sphere_bullet_collision(player_center + Vector3::UP * 8 * HITBOX_RAD + minusPlayerHeight, HITBOX_RAD);

	//Matrix44 _m = this->model;
	//dir->model = _m;
	//dir->model.translate(Vector3(0, 0.01 - (_m.getTranslation().y - ground_y), 0));
	//vec->model = _m;
	//Vector3 enemypos = stage->enemy->getPosition();
	//enemypos.y = 0;
	//Vector3 playerpos = getPosition();
	//playerpos.y = 0;

	//vec->model.rotate(vec->model.getYawRotationToAimTo(enemypos), Vector3::UP);

	//float dist = clamp((playerpos.distance(enemypos) / 10) - 0.2f, 0.2, 2);
	//vec->model.scale(Vector3(1, 1, dist));

	//vec->model.translateGlobal(vec->model.frontVector().normalize() + Vector3(0, 0.2 - (_m.getTranslation().y - ground_y), 0));


	
}



void Player::onMouseWheel(SDL_MouseWheelEvent event)
{
	m_spd *= event.y > 0 ? 1.1f : 0.9f;
}

void Player::onMouseButtonDown(SDL_MouseButtonEvent event)
{

}

void Player::onKeyUp(SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_SPACE)
	{
		std::cout << "hehe" << std::endl;
		jumping = false;
	}
	if (event.keysym.sym == SDLK_q) {
		canshoot = true;
	}
}

void Player::onKeyDown(SDL_KeyboardEvent event)
{
	if (timer_bullet_general > knockback_time[bt]) {
		if (event.keysym.sym == StageManager::instance->k_s1) {
			bt = circle;
		}
		if (event.keysym.sym == StageManager::instance->k_s2) {
			bt = shotgun;
		}
		if (event.keysym.sym == StageManager::instance->k_s3) {
			bt = sniper;
		}
	}
	if (event.keysym.sym == SDLK_SPACE && grounded) {
		timer_jump = Game::instance->time;
	}
	if (event.keysym.sym == StageManager::instance->k_auto) {
		autoshoot = !autoshoot;
	}
}