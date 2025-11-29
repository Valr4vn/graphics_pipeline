#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <array>
#include <vector>

#include "graphics_pipeline/core/model/IModel.h"
#include "graphics_pipeline/model_parser/obj/ObjModelData.h"

class ObjModel : public IModel {
 public:
  explicit ObjModel(ObjModelData data);

 private:
  ObjModelData data_;
};

#endif  // OBJMODEL_H