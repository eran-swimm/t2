#include <iostream>
#include <string>

struct Shape {
  virtual ~Shape() = default;

  virtual std::string GetName() const = 0;
};

struct Circle : Shape {
  void Resize(float factor) { radius *= factor; }

  std::string GetName() const override {
    return std::string("A circle of radius ") + std::to_string(radius);
  }

  float radius = 10.0f;
};

struct Rect : Shape {
  void Resize(float factor) { width *= factor; height *= factor;}

  std::string GetName() const override {
    return std::string("A rect of ") + std::to_string(width) + "*" + std::to_string(height);
  }

  float width = 10.0f;
  float height = 10.0f;
};

struct ColoredShape : Shape {
  ColoredShape(const std::string& color, Shape* shape)
      : color(color), shape(shape) {}

  std::string GetName() const override {
    return shape->GetName() + " which is colored " + color;
  }

  std::string color;
  Shape* shape;
};

int main() {
  Circle circle;
  Rect rect;
  ColoredShape colored_shape1("red", &circle);
  ColoredShape colored_shape2("blue", &rect);
  std::cout << colored_shape1.GetName() << std::endl;
  std::cout << colored_shape2.GetName() << std::endl;

}