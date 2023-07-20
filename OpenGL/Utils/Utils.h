#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Utils {

public:

	static double MapRange(double current_min, double current_max, double new_min, double new_max, double value) {
		double currentRange = current_max - current_min;
		double newRange = new_max - new_min;
		return new_min + ((value - current_min) / currentRange) * newRange;
	}

	static glm::vec3 x_rotation(const glm::vec3& vec, float theta) {
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(theta), glm::vec3(1, 0, 0));
		glm::vec4 rotated_vec = rotation * glm::vec4(vec, 1.0f);
		return glm::vec3(rotated_vec);
	}

	static glm::vec3 y_rotation(const glm::vec3& vec, float theta) {
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(theta), glm::vec3(0, 1, 0));
		glm::vec4 rotated_vec = rotation * glm::vec4(vec, 1.0f);
		return glm::vec3(rotated_vec);
	}

	static glm::vec3 z_rotation(const glm::vec3& vec, float theta) {
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(theta), glm::vec3(0, 0, 1));
		glm::vec4 rotated_vec = rotation * glm::vec4(vec, 1.0f);
		return glm::vec3(rotated_vec);
	}
};