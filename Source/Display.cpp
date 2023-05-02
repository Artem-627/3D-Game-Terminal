#include "Display.h"

void Canvas::Show() {
  while (true) {
    // printf("\033[1;1H");
    for (int h = 1; h <= this->height; ++h) {
      for (int w = 1; w <= this->width; ++w) {
        int w2 = w * 2;
        printf("\033[%d;%dH", h, w2);
        // printf("\033[%d;%dH", w2, h);
        printf("\033[48;2;%d;%d;%dm \033[m",
               this->Image[this->height - h][w - 1].red,
               this->Image[this->height - h][w - 1].green,
               this->Image[this->height - h][w - 1].blue);
        printf("\033[48;2;%d;%d;%dm \033[m",
               this->Image[this->height - h][w - 1].red,
               this->Image[this->height - h][w - 1].green,
               this->Image[this->height - h][w - 1].blue);
      }
      // printf("\n\r");
    }
  }
}

// Конструктор, который создает холст на весь доступный экран
Canvas::Canvas() {
  struct winsize sz; // структора с информацией об экране
  ioctl(0, TIOCGWINSZ, &sz);

  this->height = sz.ws_row - 1;
  this->width = sz.ws_col / 2;
  this->Image.resize(height, std::vector<Pixel>(width));
}

// Конструктор, который создает холст данных размеров
Canvas::Canvas(int width, int height) {
  this->height = height;
  this->width = width;
  this->Image.resize(height, std::vector<Pixel>(width));
}

// Запуск отрисовки
void Canvas::Start() {
  printf("\033[2J");

  std::thread thread(&Canvas::Show, this);
  // this->Canvas_thread = *thread;
  // Canvas_thread.join();
  thread.detach();
}

// Рисование пикселя
void Canvas::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  this->Image[y][x].red = red;
  this->Image[y][x].green = green;
  this->Image[y][x].blue = blue;
}

// Рисование прямоугольника
void Canvas::Rect(int x1, int y1, int x2, int y2, uint8_t red, uint8_t green,
                  uint8_t blue) {
  for (int x = x1; x < x2; ++x) {
    for (int y = y1; y < y2; ++y) {
      this->Image[y][x].red = red;
      this->Image[y][x].green = green;
      this->Image[y][x].blue = blue;
    }
  }
}
