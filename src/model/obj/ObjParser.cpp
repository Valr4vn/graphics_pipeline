#include "graphics_pipeline/model/obj/ObjParser.h"

#include <cerrno>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

template <typename T>
bool ObjParser::ParseAxisValues(std::istringstream& iss, int min_val_count) {
  T vertex_coordinates{};

  int i = 0;
  double value{};

  while (iss >> value) {
    if (i >= vertex_coordinates.size()) {
      break;
    }

    vertex_coordinates[i++] = value;
  }

  if ((i < min_val_count) || (i >= vertex_coordinates.size())) {
    std::cerr << "Invalid number of arguments. (Given = " << (i + 1)
              << ", Range = [" << min_val_count << ", "
              << vertex_coordinates.size() << "]\n";
    return false;
  } else {
    obj_model_data.vertex_coordinates.push_back(std::move(vertex_coordinates));
    return true;
  }
}

bool ObjParser::ParseFace(std::istringstream& iss, int min_val_count) {
  ObjFace obj_face{};
  std::string indices_str{};

  int i = 0;

  while (iss >> indices_str) {
    std::istringstream indices_iss(indices_str);
    std::string index_str{};

    ObjFace::FaceIndices indices{};
    int j = 0;

    while (std::getline(indices_iss, index_str, kFaceValueDelimiter)) {
      int index = (index_str.empty()) ? 0 : std::stoi(index_str);
      indices[j++] = index;
    }

    // Face indices format is v/vt/vn. v is mandatory. Either vt or vn must be
    // specified.
    if ((indices[0] == 0) || ((indices[1] == 0) && (indices[2] == 0))) {
      std::cerr << "Invalid face definition.\n";
      return false;
    }

    obj_face.indices.emplace_back(std::move(indices));

    ++i;
  }

  if (i < kFaceMinValCount) {
    std::cerr << "Not enough information to define a face.\n";
    return false;
  }

  obj_model_data.faces.emplace_back(obj_face);
  return true;
}

bool ObjParser::ParseObjLine(std::istringstream& iss, std::string_view type) {
  if (type == kVertexCoordinates) {
    return ParseAxisValues<ObjModelData::VertexCoordinates>(
        iss, kVertexCoordinatesMinValCount);
  } else if (type == kTextureCoordinates) {
    return ParseAxisValues<ObjModelData::VertexCoordinates>(
        iss, kTextureCoordinatesMinValCount);
  } else if (type == kVertexNormal) {
    return ParseAxisValues<ObjModelData::VertexCoordinates>(
        iss, kVertexNormalMinValCount);
  } else if (type == kFace) {
    return ParseFace(iss, kFaceMinValCount);
  } else {
    return true;
  }
}

std::optional<ObjModel> ObjParser::Parse(const std::string& obj_file_path) {
  std::ifstream obj_file;

  try {
    obj_file.exceptions(std::ifstream::badbit);

    obj_file.open(obj_file_path);

    if (!obj_file.is_open()) {
      throw std::system_error(errno, std::generic_category(),
                              "Failed to open file '" + obj_file_path + "'");
    }

    std::string line{};
    int line_count{1};

    while (std::getline(obj_file, line)) {
      std::istringstream iss(line);
      std::string type{};
      std::string material{};

      if (iss >> type) {
        bool parse_line_result = ParseObjLine(iss, type);

        if (!parse_line_result) {
          std::cerr << "Invalid line format .obj file. (Line: " << line_count
                    << ", File: " << obj_file_path << ").\n";
          return {};
        }
      }

      ++line_count;
    }
  } catch (const std::system_error& e) {
    std::cerr << e.what() << "\n";
    return {};
  }

  return ObjModel{std::move(obj_model_data)};
}