#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    struct brush {
    public:
      //static const brush null;
      
      /// @cond
      brush(const brush&);
      virtual ~brush();
      brush& operator=(const brush&);
      bool operator==(const brush& value) const {return this->brush_ == value.brush_;}
      bool operator!=(const brush& value) const {return !this->operator==(value);}
      /// @endcond
      
      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::brush& brush) noexcept {
        return os << brush.to_string();
      }
      /// @endcond
      
    protected:
      brush();
      
      void set_native_brush(intptr_t brush);

      intptr_t brush_ = 0;
    };
  }
}