#ifndef PNG_H
#define PNG_H

#include <array>

#include "graphics_pipeline/core/pipeline/FrameBuffer.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

template <int Width, int Height>
class PNG : public FrameBuffer<PNG<Width, Height>> {
 public:
  PNG(std::string save_directory)
      : save_directory_(std::move(save_directory)) {}
  ~PNG() override = default;

  Pixel& at(int x, int y) { return data_[y][x]; }

  int width() { return Width; }

  int height() { return Height; }

  void Display() {
    int num_color_channels = 3;
    int stride_in_bytes = Width * num_color_channels;

    int result =
        stbi_write_png(save_directory_.c_str(), Width, Height,
                       num_color_channels, data_.data(), stride_in_bytes);

    if (!result) {
      std::cerr << "Failed to save image \n"
                << "\"" << save_directory_ << " \".";
    }
  }

 private:
  std::array<std::array<Pixel, Width>, Height> data_;
  std::string save_directory_;
};

#endif  // PNG_H