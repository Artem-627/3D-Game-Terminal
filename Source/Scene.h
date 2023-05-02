#pragma once

#include "Geometry.h"
#include <cstdint>

// Цвет
struct Color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

// Базовый класс для игровых объектов
class GameObject {
public:
  Point3 position; // Позиция объекта
  Color color;     // Цвет объекта

  GameObject(Point3 position, Color color) : position(position), color(color){};

  // Поиск пересечения луча и объекта (для рендера)
  virtual Color Collision(Point3 camera_position, Vector3 direction);
};

// Сфера
class Sphere : private GameObject {
private:
  double size; // Радиус сферы

public:
  using GameObject::Collision;

  Sphere(const Point3 &position, double size, const Color &color)
      : GameObject(position, color), size(size){};

  // Поиск пересечения луча и сферы (для рендера)
  Color Collision(Point3 camera_position, Vector3 direction);
};
