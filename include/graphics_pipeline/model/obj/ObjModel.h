#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <array>
#include <vector>

#include "graphics_pipeline/model/obj/ObjModelData.h"

class ObjModel {
 public:
  explicit ObjModel(ObjModelData data);

 private:
  ObjModelData data_;
};

#endif  // OBJMODEL_H