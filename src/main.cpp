#include <iostream>

#include "graphics_pipeline/model/obj/ObjParser.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: .\\graphics_pipeline.exe <obj_file_path>\n";
    return 0;
  }

  std::string obj_file_path{argv[1]};

  std::optional<ObjModel> obj_model = ObjParser().Parse(obj_file_path);

  return 0;
}