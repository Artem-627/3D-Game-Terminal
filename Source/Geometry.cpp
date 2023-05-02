#include "Geometry.h"
#include <cmath>

Vector3 operator+(const Vector3 &vec3_1, const Vector3 &vec3_2) {
  return Vector3(vec3_1.x + vec3_2.x, vec3_1.y + vec3_2.y, vec3_1.z + vec3_2.z);
}

Vector3 operator/(const Vector3 &vec3_1, const double &divider) {
  return Vector3(vec3_1.x / divider, vec3_1.y / divider, vec3_1.z / divider);
}

double Vector3::GetLenght() {
  return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
