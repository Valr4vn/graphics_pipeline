#ifndef OBJPARSER_H
#define OBJPARSER_H

#include <optional>

#include "graphics_pipeline/core/model/IModelParser.h"
#include "graphics_pipeline/model_parser/obj/ObjModel.h"

class ObjParser : public IModelParser {
 public:
  ObjParser() = default;

  std::optional<std::unique_ptr<IModel>> Parse(
      const std::string& obj_file_path);

 private:
  bool ParseObjLine(std::istringstream& iss, std::string_view type);

  template <typename T>
  bool ParseAxisValues(std::istringstream& iss, int min_val_count);

  bool ParseFace(std::istringstream& iss, int min_val_count);

  static constexpr std::string_view kVertexCoordinates{"v"};
  static constexpr std::string_view kTextureCoordinates{"vt"};
  static constexpr std::string_view kVertexNormal{"vn"};
  static constexpr std::string_view kFace{"f"};
  static constexpr char kFaceValueDelimiter{'/'};

  static constexpr int kVertexCoordinatesMinValCount{3};
  static constexpr int kTextureCoordinatesMinValCount{1};
  static constexpr int kVertexNormalMinValCount{3};
  static constexpr int kFaceMinValCount{3};

  ObjModelData obj_model_data;
};

#endif  // OBJPARSER_H