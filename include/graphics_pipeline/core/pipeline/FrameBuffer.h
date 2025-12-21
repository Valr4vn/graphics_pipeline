#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <array>
#include <cstdint>

struct Pixel {
  uint8_t r, g, b;
};

template <typename Derived>
class FrameBuffer {
 public:
  virtual ~FrameBuffer() = default;

  constexpr Derived& derived() { return static_cast<Derived&>(*this); }
  constexpr const Derived& derived() const {
    return static_cast<const Derived&>(*this);
  }

  Pixel& at(int x, int y) { return derived().at(x, y); }

  decltype(auto) width() { return derived().width(); }

  decltype(auto) height() { return derived().height(); }

  void Display() { derived().Display(); }
};

#endif  // FRAMEBUFFER_H