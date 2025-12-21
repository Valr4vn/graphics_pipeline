#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "graphics_pipeline/core/pipeline/FrameBuffer.h"

template <typename FrameBufferType>
class Renderer {
 public:
  Renderer() {}

  void SetFrameBuffer(std::unique_ptr<FrameBufferType> frame_buffer) {
    frame_buffer_ = std::move(frame_buffer);
  }

  void TestFrameBuffer() {
    int w = frame_buffer_->width();
    int h = frame_buffer_->height();

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (((i % 10) <= 5) && ((j % 10) <= 5)) {
          frame_buffer_->at(j, i) = {255, 255, 255};
        } else {
          frame_buffer_->at(j, i) = {0, 0, 0};
        }
      }
    }

    frame_buffer_->Display();
  }

 private:
  std::unique_ptr<FrameBuffer<FrameBufferType>> frame_buffer_;
};

#endif  // RENDERER_H