#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

#include "graphics_pipeline/core/model/IModel.h"
#include "graphics_pipeline/core/scene/Camera.h"

class Scene {
 public:
  std::optional<Camera&> camera() { return *camera_; }
  std::optional<IModel&> model(const std::string& model_name) {
    if (models_.find(model_name) != models_.end()) {
      return *(models_[model_name]);
    } else {
      return std::nullopt;
    }
  }

 private:
  std::unique_ptr<Camera> camera_;
  std::unordered_map<std::string, std::unique_ptr<IModel>> models_;
};

#endif  // SCENE_H