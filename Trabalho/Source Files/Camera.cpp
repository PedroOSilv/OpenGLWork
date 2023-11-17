#include<glm/gtx/transform.hpp>

#include "../HeaderFiles/Camera.h"

Camera::Camera() :
	_position(glm::vec3(0.f)),
	_viewDir(glm::vec3(0.f, 0.f, -1.f)),
	_left(1.f, 0.f, 0.f),
	_UP(glm::vec3(0.f, 1.f, 0.f)),
	_SPEED_MAG(0.15f),
	_oldMousePos(glm::vec2(0.f)),
	_isMouseActivated(false)
{
}

void Camera::mouseUpdate(const glm::vec2& currentPos)
{
	if (!_isMouseActivated)
	{
		_oldMousePos = currentPos;
		_isMouseActivated = true;
	}

	glm::vec2 delta = currentPos - _oldMousePos;
	
	float threshold = 2.2f;
	if (glm::length(delta) > threshold)
		setMag(delta, threshold);
	
	_oldMousePos = currentPos;

	glm::mat4 RotationMatrixX = glm::rotate(glm::radians(-delta.x), glm::vec3(_UP));
	glm::mat4 RotationMatrixY = glm::rotate(glm::radians(-delta.y), glm::vec3(-_left));

	_viewDir = glm::mat3(RotationMatrixX) * glm::mat3(RotationMatrixY) * _viewDir;
	_viewDir = glm::normalize(_viewDir);

	_left = glm::cross(_UP, _viewDir);
	_left = glm::normalize(_left);

}

void Camera::setMag(glm::vec2& v, float val)
{
	glm::vec2 versor = glm::normalize(v);
	v = val * versor;
}

glm::mat4 Camera::ativar()
{
	return glm::lookAt(_position, _position + _viewDir, _UP);
}

void Camera::moveForward()
{
	_position = _position + _viewDir * _SPEED_MAG;
}

void Camera::moveBack()
{
	_position = _position + _viewDir * (-_SPEED_MAG);
}

void Camera::moveLeft()
{
	_position = _position + _left * _SPEED_MAG;
}

void Camera::moveRight()
{
	_position = _position + _left * (-_SPEED_MAG);
}