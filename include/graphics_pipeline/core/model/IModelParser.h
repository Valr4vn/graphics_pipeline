#ifndef IMODELPARSER_H
#define IMODELPARSER_H

#include <memory>
#include <optional>
#include <string>

#include "graphics_pipeline/core/model/IModel.h"

class IModelParser {
 public:
  virtual std::optional<std::unique_ptr<IModel>> Parse(
      const std::string& obj_file_path) = 0;

 protected:
  IModelParser() {};
};

#endif  // IMODELPARSER_H