#pragma once
#include "brush.hpp"
#include "color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    struct solid_brush : public brush {
    public:
      solid_brush() = default;
      solid_brush(const drawing::color& color) {this->color(color);}

      /// @cond
      solid_brush(const solid_brush&);
      solid_brush& operator=(const solid_brush&);
      bool operator==(const solid_brush& value) const {return this->color_ == value.color_;}
      bool operator!=(const solid_brush& value) const {return !this->operator==(value);}
      /// @endcond
      
      const drawing::color& color() const {return this->color_;}
      solid_brush& color(const drawing::color& color);
      
    private:
      drawing::color color_ = drawing::color::black;
    };
  }
}