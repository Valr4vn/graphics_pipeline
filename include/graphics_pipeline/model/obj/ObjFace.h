#ifndef OBJFACE_H
#define OBJFACE_H

#include <string>
#include <vector>

struct ObjFace {
  using FaceIndices = std::array<int, 3>;

  std::string material_;

  // {vertex_index, texture_index, normal_index}
  std::vector<FaceIndices> indices_;
};

#endif  // OBJFACE_H