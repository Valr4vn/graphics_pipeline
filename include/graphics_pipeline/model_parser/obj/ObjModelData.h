#ifndef OBJMODELDATA_H
#define OBJMODELDATA_H

#include <array>
#include <vector>

#include "graphics_pipeline/model_parser/obj/ObjFace.h"

struct ObjModelData {
  using VertexCoordinates = std::array<double, 4>;
  using TextureCoordinates = std::array<double, 3>;
  using VertexNormal = std::array<double, 3>;

  std::vector<VertexCoordinates> vertex_coordinates;
  std::vector<TextureCoordinates> texture_coordinates;
  std::vector<VertexNormal> vertex_normals;
  std::vector<ObjFace> faces;
};

#endif  // OBJMODELDATA_H