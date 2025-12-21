#include <iostream>
#include <memory>

#include "graphics_pipeline/core/pipeline/Renderer.h"
#include "graphics_pipeline/frame_buffer/PNG.h"
#include "graphics_pipeline/model_parser/obj/ObjParser.h"

int main(int argc, char* argv[]) {
  // if (argc != 2) {
  //   std::cerr << "Usage: .\\graphics_pipeline.exe <obj_file_path>\n";
  //   return 0;
  // }

  // std::string obj_file_path{argv[1]};

  // std::optional<std::unique_ptr<IModel>> obj_model =
  //     ObjParser().Parse(obj_file_path);

  std::unique_ptr<PNG<600, 800>> frame_buffer =
      std::make_unique<PNG<600, 800>>("./output/test.png");

  Renderer<PNG<600, 800>> renderer{};

  renderer.SetFrameBuffer(std::move(frame_buffer));
  renderer.TestFrameBuffer();

  return 0;
}