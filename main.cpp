#include "Source/Display.h"
#include "Source/Geometry.h"
#include <chrono>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <thread>

int main() {
  Canvas *cnv = new Canvas();

  // cnv->Start();

  // float edge = 0;
  // while (true) {
  // cnv->Rect(0, 0, floor(edge * cnv->GetWidth()),
  // floor(edge * cnv->GetHeight()), 0, 0, 255 * edge);
  // if (edge < 0.999999)
  // edge += 0.00001;
  // }

  Vector3 vec(1, 2, 3);

  std::cout << vec.GetLenght();

  return 0;
}
