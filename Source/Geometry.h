#pragma once

// Точка в трехмерном пространстве
struct Point3 {
  double x;
  double y;
  double z;
};

struct Vector3 {
  double x;
  double y;
  double z;

  Vector3(double x, double y, double z) : x(x), y(y), z(z){};

  double GetLenght(); // Получение длины вектора

  Vector3 Normalizate(); // Получение нормализованного вектора
};
