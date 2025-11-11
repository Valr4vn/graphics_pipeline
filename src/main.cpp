#include <iostream>

#include "graphics_pipeline/model/obj/ObjParser.h"

int main() {
  std::optional<ObjModel> obj_model = ObjParser().Parse("test.obj");

  return 0;
}