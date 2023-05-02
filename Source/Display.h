// Обработка и вывод дисплея

#pragma once
#define _CRT_DISABLE_PERFCRIT_LOCKS

#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <thread>
#include <vector>

// Пиксель (единица дисплея, хранящая свой цвет)
struct Pixel {
  uint8_t red = 0;
  uint8_t green = 0;
  uint8_t blue = 0;
};

// Дисплей (обработка и вывод пикселей)
class Canvas {
private:
  int height;                            // Высота холста
  int width;                             // Ширина холста
  std::vector<std::vector<Pixel>> Image; // Вектор пикселей
  std::thread *Canvas_thread; // Указатель на поток, в котором выполняется
                              // рисование холста

  void Show();

public:
  // Конструктор, который создает холст на весь доступный экран
  Canvas();

  // Конструктор, который создает холст данных размеров
  Canvas(int width, int height);

  // Запуск отрисовки
  void Start();

  // Рисование пикселя
  void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

  // Рисование прямоугольника
  void Rect(int x1, int y1, int x2, int y2, uint8_t red, uint8_t green,
            uint8_t blue);

  int GetWidth() { return this->width; }
  int GetHeight() { return this->height; }
};
