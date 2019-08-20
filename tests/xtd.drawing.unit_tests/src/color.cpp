#include <xtd/xtd.drawing>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_color) {
  public:
    void test_method_(create_empty_color) {
      color c;
      
      assert::are_equal(color(), c);
      assert::are_equal(color::empty, c);
      
      assert::are_equal(0, c.a());
      assert::are_equal(0, c.r());
      assert::are_equal(0, c.g());
      assert::are_equal(0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("0", c.name());

      assert::is_true(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());

      assert::are_equal(0, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0) {
      color c = color::from_argb(0);
      
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0, c.a());
      assert::are_equal(0, c.r());
      assert::are_equal(0, c.g());
      assert::are_equal(0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("0", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12_0x34_0x56_0x78) {
      color c = color::from_argb(0x12, 0x34, 0x56, 0x78);
      
      assert::are_equal(color::from_argb(0x12345678), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x12, c.a());
      assert::are_equal(0x34, c.r());
      assert::are_equal(0x56, c.g());
      assert::are_equal(0x78, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("12345678", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x12345678, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12_0x34_0x56) {
      color c = color::from_argb(0x12, 0x34, 0x56);
      
      assert::are_equal(color::from_argb(0xFF123456), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x12, c.r());
      assert::are_equal(0x34, c.g());
      assert::are_equal(0x56, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("FF123456", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0xFF123456, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x20_color_blue) {
      color c = color::from_argb(0x20, color::blue);
      
      assert::are_equal(color::from_argb(0x20, color::blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x20, c.a());
      assert::are_equal(0x0, c.r());
      assert::are_equal(0x0, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("200000FF", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x200000FF, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12345678) {
      color c = color::from_argb(0x12345678);
      
      assert::are_equal(color::from_argb(0x12345678), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x12, c.a());
      assert::are_equal(0x34, c.r());
      assert::are_equal(0x56, c.g());
      assert::are_equal(0x78, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("12345678", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x12345678, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_invalid) {
      assert::throws<std::invalid_argument>([] {color::from_known_color((known_color)7654);});
    }

    void test_method_(create_from_know_color_transparent) {
      color c = color::from_known_color(known_color::transparent);
      
      assert::are_equal(color::from_known_color(known_color::transparent), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x00, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("transparent", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0x00FFFFFF, c.to_argb());
      assert::are_equal(known_color::transparent, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_alice_blue) {
      color c = color::from_known_color(known_color::alice_blue);
      
      assert::are_equal(color::from_known_color(known_color::alice_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("alice_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0F8FF, c.to_argb());
      assert::are_equal(known_color::alice_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_antique_white) {
      color c = color::from_known_color(known_color::antique_white);
      
      assert::are_equal(color::from_known_color(known_color::antique_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xEB, c.g());
      assert::are_equal(0xD7, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("antique_white", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAEBD7, c.to_argb());
      assert::are_equal(known_color::antique_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_aqua) {
      color c = color::from_known_color(known_color::aqua);
      
      assert::are_equal(color::from_known_color(known_color::aqua), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("aqua", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FFFF, c.to_argb());
      assert::are_equal(known_color::aqua, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_aquamarine) {
      color c = color::from_known_color(known_color::aquamarine);
      
      assert::are_equal(color::from_known_color(known_color::aquamarine), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7F, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xD4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("aquamarine", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7FFFD4, c.to_argb());
      assert::are_equal(known_color::aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_azure) {
      color c = color::from_known_color(known_color::azure);
      
      assert::are_equal(color::from_known_color(known_color::azure), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("azure", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0FFFF, c.to_argb());
      assert::are_equal(known_color::azure, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_beige) {
      color c = color::from_known_color(known_color::beige);
      
      assert::are_equal(color::from_known_color(known_color::beige), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("beige", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5F5DC, c.to_argb());
      assert::are_equal(known_color::beige, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_bisque) {
      color c = color::from_known_color(known_color::bisque);
      
      assert::are_equal(color::from_known_color(known_color::bisque), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xC4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("bisque", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4C4, c.to_argb());
      assert::are_equal(known_color::bisque, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_black) {
      color c = color::from_known_color(known_color::black);
      
      assert::are_equal(color::from_known_color(known_color::black), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("black", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000000, c.to_argb());
      assert::are_equal(known_color::black, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blanched_almond) {
      color c = color::from_known_color(known_color::blanched_almond);
      
      assert::are_equal(color::from_known_color(known_color::blanched_almond), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xEB, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blanched_almond", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFEBCD, c.to_argb());
      assert::are_equal(known_color::blanched_almond, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blue) {
      color c = color::from_known_color(known_color::blue);
      
      assert::are_equal(color::from_known_color(known_color::blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000FF, c.to_argb());
      assert::are_equal(known_color::blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blue_violet) {
      color c = color::from_known_color(known_color::blue_violet);
      
      assert::are_equal(color::from_known_color(known_color::blue_violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8A, c.r());
      assert::are_equal(0x2B, c.g());
      assert::are_equal(0xE2, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blue_violet", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8A2BE2, c.to_argb());
      assert::are_equal(known_color::blue_violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_brown) {
      color c = color::from_known_color(known_color::brown);
      
      assert::are_equal(color::from_known_color(known_color::brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA5, c.r());
      assert::are_equal(0x2A, c.g());
      assert::are_equal(0x2A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("brown", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA52A2A, c.to_argb());
      assert::are_equal(known_color::brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_burly_wood) {
      color c = color::from_known_color(known_color::burly_wood);
      
      assert::are_equal(color::from_known_color(known_color::burly_wood), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDE, c.r());
      assert::are_equal(0xB8, c.g());
      assert::are_equal(0x87, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("burly_wood", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDEB887, c.to_argb());
      assert::are_equal(known_color::burly_wood, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cadet_blue) {
      color c = color::from_known_color(known_color::cadet_blue);
      
      assert::are_equal(color::from_known_color(known_color::cadet_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x5F, c.r());
      assert::are_equal(0x9E, c.g());
      assert::are_equal(0xA0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cadet_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF5F9EA0, c.to_argb());
      assert::are_equal(known_color::cadet_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_chartreuse) {
      color c = color::from_known_color(known_color::chartreuse);
      
      assert::are_equal(color::from_known_color(known_color::chartreuse), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7F, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("chartreuse", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7FFF00, c.to_argb());
      assert::are_equal(known_color::chartreuse, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_chocolate) {
      color c = color::from_known_color(known_color::chocolate);
      
      assert::are_equal(color::from_known_color(known_color::chocolate), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD2, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0x1E, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("chocolate", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD2691E, c.to_argb());
      assert::are_equal(known_color::chocolate, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_coral) {
      color c = color::from_known_color(known_color::coral);
      
      assert::are_equal(color::from_known_color(known_color::coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x7F, c.g());
      assert::are_equal(0x50, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("coral", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF7F50, c.to_argb());
      assert::are_equal(known_color::coral, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cornflower_blue) {
      color c = color::from_known_color(known_color::cornflower_blue);
      
      assert::are_equal(color::from_known_color(known_color::cornflower_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x64, c.r());
      assert::are_equal(0x95, c.g());
      assert::are_equal(0xED, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cornflower_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6495ED, c.to_argb());
      assert::are_equal(known_color::cornflower_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cornsilk) {
      color c = color::from_known_color(known_color::cornsilk);
      
      assert::are_equal(color::from_known_color(known_color::cornsilk), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cornsilk", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF8DC, c.to_argb());
      assert::are_equal(known_color::cornsilk, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_crimson) {
      color c = color::from_known_color(known_color::crimson);
      
      assert::are_equal(color::from_known_color(known_color::crimson), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x3C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crimson", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDC143C, c.to_argb());
      assert::are_equal(known_color::crimson, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cyan) {
      color c = color::from_known_color(known_color::cyan);
      
      assert::are_equal(color::from_known_color(known_color::cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cyan", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FFFF, c.to_argb());
      assert::are_equal(known_color::cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_blue) {
      color c = color::from_known_color(known_color::dark_blue);
      
      assert::are_equal(color::from_known_color(known_color::dark_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00008B, c.to_argb());
      assert::are_equal(known_color::dark_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_cyan) {
      color c = color::from_known_color(known_color::dark_cyan);
      
      assert::are_equal(color::from_known_color(known_color::dark_cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_cyan", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008B8B, c.to_argb());
      assert::are_equal(known_color::dark_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_goldenrod) {
      color c = color::from_known_color(known_color::dark_goldenrod);
      
      assert::are_equal(color::from_known_color(known_color::dark_goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB8, c.r());
      assert::are_equal(0x86, c.g());
      assert::are_equal(0x0B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_goldenrod", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB8860B, c.to_argb());
      assert::are_equal(known_color::dark_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_gray) {
      color c = color::from_known_color(known_color::dark_gray);
      
      assert::are_equal(color::from_known_color(known_color::dark_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA9, c.r());
      assert::are_equal(0xA9, c.g());
      assert::are_equal(0xA9, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA9A9A9, c.to_argb());
      assert::are_equal(known_color::dark_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_green) {
      color c = color::from_known_color(known_color::dark_green);
      
      assert::are_equal(color::from_known_color(known_color::dark_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x64, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF006400, c.to_argb());
      assert::are_equal(known_color::dark_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_khaki) {
      color c = color::from_known_color(known_color::dark_khaki);
      
      assert::are_equal(color::from_known_color(known_color::dark_khaki), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBD, c.r());
      assert::are_equal(0xB7, c.g());
      assert::are_equal(0x6B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_khaki", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBDB76B, c.to_argb());
      assert::are_equal(known_color::dark_khaki, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_magenta) {
      color c = color::from_known_color(known_color::dark_magenta);
      
      assert::are_equal(color::from_known_color(known_color::dark_magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_magenta", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B008B, c.to_argb());
      assert::are_equal(known_color::dark_magenta, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_olive_green) {
      color c = color::from_known_color(known_color::dark_olive_green);
      
      assert::are_equal(color::from_known_color(known_color::dark_olive_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x55, c.r());
      assert::are_equal(0x6B, c.g());
      assert::are_equal(0x2F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_olive_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF556B2F, c.to_argb());
      assert::are_equal(known_color::dark_olive_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_orange) {
      color c = color::from_known_color(known_color::dark_orange);
      
      assert::are_equal(color::from_known_color(known_color::dark_orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x8C, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orange", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF8C00, c.to_argb());
      assert::are_equal(known_color::dark_orange, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_orchid) {
      color c = color::from_known_color(known_color::dark_orchid);
      
      assert::are_equal(color::from_known_color(known_color::dark_orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x99, c.r());
      assert::are_equal(0x32, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orchid", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9932CC, c.to_argb());
      assert::are_equal(known_color::dark_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_red) {
      color c = color::from_known_color(known_color::dark_red);
      
      assert::are_equal(color::from_known_color(known_color::dark_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B0000, c.to_argb());
      assert::are_equal(known_color::dark_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_salmon) {
      color c = color::from_known_color(known_color::dark_salmon);
      
      assert::are_equal(color::from_known_color(known_color::dark_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE9, c.r());
      assert::are_equal(0x96, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_salmon", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE9967A, c.to_argb());
      assert::are_equal(known_color::dark_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_sea_green) {
      color c = color::from_known_color(known_color::dark_sea_green);
      
      assert::are_equal(color::from_known_color(known_color::dark_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8F, c.r());
      assert::are_equal(0xBC, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_sea_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8FBC8B, c.to_argb());
      assert::are_equal(known_color::dark_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_slate_blue) {
      color c = color::from_known_color(known_color::dark_slate_blue);
      
      assert::are_equal(color::from_known_color(known_color::dark_slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x48, c.r());
      assert::are_equal(0x3D, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_slate_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF483D8B, c.to_argb());
      assert::are_equal(known_color::dark_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_slate_gray) {
      color c = color::from_known_color(known_color::dark_slate_gray);
      
      assert::are_equal(color::from_known_color(known_color::dark_slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x2F, c.r());
      assert::are_equal(0x4F, c.g());
      assert::are_equal(0x4F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_slate_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF2F4F4F, c.to_argb());
      assert::are_equal(known_color::dark_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_turquoise) {
      color c = color::from_known_color(known_color::dark_turquoise);
      
      assert::are_equal(color::from_known_color(known_color::dark_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xD1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_turquoise", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00CED1, c.to_argb());
      assert::are_equal(known_color::dark_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_violet) {
      color c = color::from_known_color(known_color::dark_violet);
      
      assert::are_equal(color::from_known_color(known_color::dark_violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x94, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_violet", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9400D3, c.to_argb());
      assert::are_equal(known_color::dark_violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_deep_pink) {
      color c = color::from_known_color(known_color::deep_pink);
      
      assert::are_equal(color::from_known_color(known_color::deep_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_pink", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF1493, c.to_argb());
      assert::are_equal(known_color::deep_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_deep_sky_blue) {
      color c = color::from_known_color(known_color::deep_sky_blue);
      
      assert::are_equal(color::from_known_color(known_color::deep_sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xBF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_sky_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00BFFF, c.to_argb());
      assert::are_equal(known_color::deep_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dim_gray) {
      color c = color::from_known_color(known_color::dim_gray);
      
      assert::are_equal(color::from_known_color(known_color::dim_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x69, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0x69, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dim_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF696969, c.to_argb());
      assert::are_equal(known_color::dim_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dodger_blue) {
      color c = color::from_known_color(known_color::dodger_blue);
      
      assert::are_equal(color::from_known_color(known_color::dodger_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x1E, c.r());
      assert::are_equal(0x90, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dodger_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF1E90FF, c.to_argb());
      assert::are_equal(known_color::dodger_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_firebrick) {
      color c = color::from_known_color(known_color::firebrick);
      
      assert::are_equal(color::from_known_color(known_color::firebrick), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB2, c.r());
      assert::are_equal(0x22, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("firebrick", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB22222, c.to_argb());
      assert::are_equal(known_color::firebrick, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_floral_white) {
      color c = color::from_known_color(known_color::floral_white);
      
      assert::are_equal(color::from_known_color(known_color::floral_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("floral_white", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFAF0, c.to_argb());
      assert::are_equal(known_color::floral_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_forest_green) {
      color c = color::from_known_color(known_color::forest_green);
      
      assert::are_equal(color::from_known_color(known_color::forest_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x22, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("forest_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF228B22, c.to_argb());
      assert::are_equal(known_color::forest_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_fuchsia) {
      color c = color::from_known_color(known_color::fuchsia);
      
      assert::are_equal(color::from_known_color(known_color::fuchsia), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("fuchsia", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF00FF, c.to_argb());
      assert::are_equal(known_color::fuchsia, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gainsboro) {
      color c = color::from_known_color(known_color::gainsboro);
      
      assert::are_equal(color::from_known_color(known_color::gainsboro), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0xDC, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gainsboro", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDCDCDC, c.to_argb());
      assert::are_equal(known_color::gainsboro, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_ghost_white) {
      color c = color::from_known_color(known_color::ghost_white);
      
      assert::are_equal(color::from_known_color(known_color::ghost_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF8, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("ghost_white", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF8F8FF, c.to_argb());
      assert::are_equal(known_color::ghost_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gold) {
      color c = color::from_known_color(known_color::gold);
      
      assert::are_equal(color::from_known_color(known_color::gold), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xD7, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gold", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFD700, c.to_argb());
      assert::are_equal(known_color::gold, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_goldenrod) {
      color c = color::from_known_color(known_color::goldenrod);
      
      assert::are_equal(color::from_known_color(known_color::goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDA, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x20, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("goldenrod", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDAA520, c.to_argb());
      assert::are_equal(known_color::goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gray) {
      color c = color::from_known_color(known_color::gray);
      
      assert::are_equal(color::from_known_color(known_color::gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808080, c.to_argb());
      assert::are_equal(known_color::gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_green) {
      color c = color::from_known_color(known_color::green);
      
      assert::are_equal(color::from_known_color(known_color::green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008000, c.to_argb());
      assert::are_equal(known_color::green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_green_yellow) {
      color c = color::from_known_color(known_color::green_yellow);
      
      assert::are_equal(color::from_known_color(known_color::green_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAD, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x2F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("green_yellow", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFADFF2F, c.to_argb());
      assert::are_equal(known_color::green_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_honeydew) {
      color c = color::from_known_color(known_color::honeydew);
      
      assert::are_equal(color::from_known_color(known_color::honeydew), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("honeydew", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0FFF0, c.to_argb());
      assert::are_equal(known_color::honeydew, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_hot_pink) {
      color c = color::from_known_color(known_color::hot_pink);
      
      assert::are_equal(color::from_known_color(known_color::hot_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("hot_pink", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF69B4, c.to_argb());
      assert::are_equal(known_color::hot_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_indian_red) {
      color c = color::from_known_color(known_color::indian_red);
      
      assert::are_equal(color::from_known_color(known_color::indian_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x5C, c.g());
      assert::are_equal(0x5C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indian_red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD5C5C, c.to_argb());
      assert::are_equal(known_color::indian_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_indigo) {
      color c = color::from_known_color(known_color::indigo);
      
      assert::are_equal(color::from_known_color(known_color::indigo), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x4B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x82, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indigo", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4B0082, c.to_argb());
      assert::are_equal(known_color::indigo, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_ivory) {
      color c = color::from_known_color(known_color::ivory);
      
      assert::are_equal(color::from_known_color(known_color::ivory), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("ivory", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFF0, c.to_argb());
      assert::are_equal(known_color::ivory, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_khaki) {
      color c = color::from_known_color(known_color::khaki);
      
      assert::are_equal(color::from_known_color(known_color::khaki), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xE6, c.g());
      assert::are_equal(0x8C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("khaki", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0E68C, c.to_argb());
      assert::are_equal(known_color::khaki, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lavender) {
      color c = color::from_known_color(known_color::lavender);
      
      assert::are_equal(color::from_known_color(known_color::lavender), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE6, c.r());
      assert::are_equal(0xE6, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lavender", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE6E6FA, c.to_argb());
      assert::are_equal(known_color::lavender, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lavender_blush) {
      color c = color::from_known_color(known_color::lavender_blush);
      
      assert::are_equal(color::from_known_color(known_color::lavender_blush), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF0, c.g());
      assert::are_equal(0xF5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lavender_blush", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF0F5, c.to_argb());
      assert::are_equal(known_color::lavender_blush, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lawn_green) {
      color c = color::from_known_color(known_color::lawn_green);
      
      assert::are_equal(color::from_known_color(known_color::lawn_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7C, c.r());
      assert::are_equal(0xFC, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lawn_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7CFC00, c.to_argb());
      assert::are_equal(known_color::lawn_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lemon_chiffon) {
      color c = color::from_known_color(known_color::lemon_chiffon);
      
      assert::are_equal(color::from_known_color(known_color::lemon_chiffon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lemon_chiffon", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFACD, c.to_argb());
      assert::are_equal(known_color::lemon_chiffon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_blue) {
      color c = color::from_known_color(known_color::light_blue);
      
      assert::are_equal(color::from_known_color(known_color::light_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAD, c.r());
      assert::are_equal(0xD8, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFADD8E6, c.to_argb());
      assert::are_equal(known_color::light_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_coral) {
      color c = color::from_known_color(known_color::light_coral);
      
      assert::are_equal(color::from_known_color(known_color::light_coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_coral", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF08080, c.to_argb());
      assert::are_equal(known_color::light_coral, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_cyan) {
      color c = color::from_known_color(known_color::light_cyan);
      
      assert::are_equal(color::from_known_color(known_color::light_cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_cyan", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE0FFFF, c.to_argb());
      assert::are_equal(known_color::light_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_goldenrod_yellow) {
      color c = color::from_known_color(known_color::light_goldenrod_yellow);
      
      assert::are_equal(color::from_known_color(known_color::light_goldenrod_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xD2, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_goldenrod_yellow", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAFAD2, c.to_argb());
      assert::are_equal(known_color::light_goldenrod_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_gray) {
      color c = color::from_known_color(known_color::light_gray);
      
      assert::are_equal(color::from_known_color(known_color::light_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD3, c.r());
      assert::are_equal(0xD3, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD3D3D3, c.to_argb());
      assert::are_equal(known_color::light_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_green) {
      color c = color::from_known_color(known_color::light_green);
      
      assert::are_equal(color::from_known_color(known_color::light_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x90, c.r());
      assert::are_equal(0xEE, c.g());
      assert::are_equal(0x90, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF90EE90, c.to_argb());
      assert::are_equal(known_color::light_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_pink) {
      color c = color::from_known_color(known_color::light_pink);
      
      assert::are_equal(color::from_known_color(known_color::light_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xB6, c.g());
      assert::are_equal(0xC1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_pink", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFB6C1, c.to_argb());
      assert::are_equal(known_color::light_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_salmon) {
      color c = color::from_known_color(known_color::light_salmon);
      
      assert::are_equal(color::from_known_color(known_color::light_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_salmon", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA07A, c.to_argb());
      assert::are_equal(known_color::light_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_sea_green) {
      color c = color::from_known_color(known_color::light_sea_green);
      
      assert::are_equal(color::from_known_color(known_color::light_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x20, c.r());
      assert::are_equal(0xB2, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_sea_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF20B2AA, c.to_argb());
      assert::are_equal(known_color::light_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_sky_blue) {
      color c = color::from_known_color(known_color::light_sky_blue);
      
      assert::are_equal(color::from_known_color(known_color::light_sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x87, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_sky_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF87CEFA, c.to_argb());
      assert::are_equal(known_color::light_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_slate_gray) {
      color c = color::from_known_color(known_color::light_slate_gray);
      
      assert::are_equal(color::from_known_color(known_color::light_slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x77, c.r());
      assert::are_equal(0x88, c.g());
      assert::are_equal(0x99, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_slate_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF778899, c.to_argb());
      assert::are_equal(known_color::light_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_steel_blue) {
      color c = color::from_known_color(known_color::light_steel_blue);
      
      assert::are_equal(color::from_known_color(known_color::light_steel_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB0, c.r());
      assert::are_equal(0xC4, c.g());
      assert::are_equal(0xDE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_steel_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB0C4DE, c.to_argb());
      assert::are_equal(known_color::light_steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_yellow) {
      color c = color::from_known_color(known_color::light_yellow);
      
      assert::are_equal(color::from_known_color(known_color::light_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xE0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_yellow", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFE0, c.to_argb());
      assert::are_equal(known_color::light_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lime) {
      color c = color::from_known_color(known_color::lime);
      
      assert::are_equal(color::from_known_color(known_color::lime), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lime", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FF00, c.to_argb());
      assert::are_equal(known_color::lime, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lime_green) {
      color c = color::from_known_color(known_color::lime_green);
      
      assert::are_equal(color::from_known_color(known_color::lime_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x32, c.r());
      assert::are_equal(0xCD, c.g());
      assert::are_equal(0x32, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lime_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF32CD32, c.to_argb());
      assert::are_equal(known_color::lime_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_linen) {
      color c = color::from_known_color(known_color::linen);
      
      assert::are_equal(color::from_known_color(known_color::linen), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xF0, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("linen", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAF0E6, c.to_argb());
      assert::are_equal(known_color::linen, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_magenta) {
      color c = color::from_known_color(known_color::magenta);
      
      assert::are_equal(color::from_known_color(known_color::magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("magenta", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF00FF, c.to_argb());
      assert::are_equal(known_color::magenta, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_maroon) {
      color c = color::from_known_color(known_color::maroon);
      
      assert::are_equal(color::from_known_color(known_color::maroon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("maroon", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800000, c.to_argb());
      assert::are_equal(known_color::maroon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_aquamarine) {
      color c = color::from_known_color(known_color::medium_aquamarine);
      
      assert::are_equal(color::from_known_color(known_color::medium_aquamarine), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xCD, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_aquamarine", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66CDAA, c.to_argb());
      assert::are_equal(known_color::medium_aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_blue) {
      color c = color::from_known_color(known_color::medium_blue);
      
      assert::are_equal(color::from_known_color(known_color::medium_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000CD, c.to_argb());
      assert::are_equal(known_color::medium_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_orchid) {
      color c = color::from_known_color(known_color::medium_orchid);
      
      assert::are_equal(color::from_known_color(known_color::medium_orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBA, c.r());
      assert::are_equal(0x55, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_orchid", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBA55D3, c.to_argb());
      assert::are_equal(known_color::medium_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_purple) {
      color c = color::from_known_color(known_color::medium_purple);
      
      assert::are_equal(color::from_known_color(known_color::medium_purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x93, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0xDB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_purple", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9370DB, c.to_argb());
      assert::are_equal(known_color::medium_purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_sea_green) {
      color c = color::from_known_color(known_color::medium_sea_green);
      
      assert::are_equal(color::from_known_color(known_color::medium_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x3C, c.r());
      assert::are_equal(0xB3, c.g());
      assert::are_equal(0x71, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_sea_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF3CB371, c.to_argb());
      assert::are_equal(known_color::medium_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_slate_blue) {
      color c = color::from_known_color(known_color::medium_slate_blue);
      
      assert::are_equal(color::from_known_color(known_color::medium_slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7B, c.r());
      assert::are_equal(0x68, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_slate_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7B68EE, c.to_argb());
      assert::are_equal(known_color::medium_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_spring_green) {
      color c = color::from_known_color(known_color::medium_spring_green);
      
      assert::are_equal(color::from_known_color(known_color::medium_spring_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0x9A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_spring_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FA9A, c.to_argb());
      assert::are_equal(known_color::medium_spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_turquoise) {
      color c = color::from_known_color(known_color::medium_turquoise);
      
      assert::are_equal(color::from_known_color(known_color::medium_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x48, c.r());
      assert::are_equal(0xD1, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_turquoise", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF48D1CC, c.to_argb());
      assert::are_equal(known_color::medium_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_violet_red) {
      color c = color::from_known_color(known_color::medium_violet_red);
      
      assert::are_equal(color::from_known_color(known_color::medium_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC7, c.r());
      assert::are_equal(0x15, c.g());
      assert::are_equal(0x85, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_violet_red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC71585, c.to_argb());
      assert::are_equal(known_color::medium_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_midnight_blue) {
      color c = color::from_known_color(known_color::midnight_blue);
      
      assert::are_equal(color::from_known_color(known_color::midnight_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x19, c.r());
      assert::are_equal(0x19, c.g());
      assert::are_equal(0x70, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("midnight_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF191970, c.to_argb());
      assert::are_equal(known_color::midnight_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_mint_cream) {
      color c = color::from_known_color(known_color::mint_cream);
      
      assert::are_equal(color::from_known_color(known_color::mint_cream), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("mint_cream", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5FFFA, c.to_argb());
      assert::are_equal(known_color::mint_cream, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_misty_rose) {
      color c = color::from_known_color(known_color::misty_rose);
      
      assert::are_equal(color::from_known_color(known_color::misty_rose), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xE1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("misty_rose", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4E1, c.to_argb());
      assert::are_equal(known_color::misty_rose, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_moccasin) {
      color c = color::from_known_color(known_color::moccasin);
      
      assert::are_equal(color::from_known_color(known_color::moccasin), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xB5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("moccasin", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4B5, c.to_argb());
      assert::are_equal(known_color::moccasin, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_navajo_white) {
      color c = color::from_known_color(known_color::navajo_white);
      
      assert::are_equal(color::from_known_color(known_color::navajo_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xDE, c.g());
      assert::are_equal(0xAD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("navajo_white", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFDEAD, c.to_argb());
      assert::are_equal(known_color::navajo_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_navy) {
      color c = color::from_known_color(known_color::navy);
      
      assert::are_equal(color::from_known_color(known_color::navy), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("navy", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000080, c.to_argb());
      assert::are_equal(known_color::navy, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_old_lace) {
      color c = color::from_known_color(known_color::old_lace);
      
      assert::are_equal(color::from_known_color(known_color::old_lace), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFD, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("old_lace", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFDF5E6, c.to_argb());
      assert::are_equal(known_color::old_lace, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_olive) {
      color c = color::from_known_color(known_color::olive);
      
      assert::are_equal(color::from_known_color(known_color::olive), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("olive", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808000, c.to_argb());
      assert::are_equal(known_color::olive, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_olive_drab) {
      color c = color::from_known_color(known_color::olive_drab);
      
      assert::are_equal(color::from_known_color(known_color::olive_drab), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x6B, c.r());
      assert::are_equal(0x8E, c.g());
      assert::are_equal(0x23, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("olive_drab", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6B8E23, c.to_argb());
      assert::are_equal(known_color::olive_drab, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orange) {
      color c = color::from_known_color(known_color::orange);
      
      assert::are_equal(color::from_known_color(known_color::orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA500, c.to_argb());
      assert::are_equal(known_color::orange, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orange_red) {
      color c = color::from_known_color(known_color::orange_red);
      
      assert::are_equal(color::from_known_color(known_color::orange_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange_red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF4500, c.to_argb());
      assert::are_equal(known_color::orange_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orchid) {
      color c = color::from_known_color(known_color::orchid);
      
      assert::are_equal(color::from_known_color(known_color::orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDA, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0xD6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orchid", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDA70D6, c.to_argb());
      assert::are_equal(known_color::orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_goldenrod) {
      color c = color::from_known_color(known_color::pale_goldenrod);
      
      assert::are_equal(color::from_known_color(known_color::pale_goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xEE, c.r());
      assert::are_equal(0xE8, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_goldenrod", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFEEE8AA, c.to_argb());
      assert::are_equal(known_color::pale_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_green) {
      color c = color::from_known_color(known_color::pale_green);
      
      assert::are_equal(color::from_known_color(known_color::pale_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x98, c.r());
      assert::are_equal(0xFB, c.g());
      assert::are_equal(0x98, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF98FB98, c.to_argb());
      assert::are_equal(known_color::pale_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_turquoise) {
      color c = color::from_known_color(known_color::pale_turquoise);
      
      assert::are_equal(color::from_known_color(known_color::pale_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAF, c.r());
      assert::are_equal(0xEE, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_turquoise", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFAFEEEE, c.to_argb());
      assert::are_equal(known_color::pale_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_violet_red) {
      color c = color::from_known_color(known_color::pale_violet_red);
      
      assert::are_equal(color::from_known_color(known_color::pale_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDB, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_violet_red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDB7093, c.to_argb());
      assert::are_equal(known_color::pale_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_papaya_whip) {
      color c = color::from_known_color(known_color::papaya_whip);
      
      assert::are_equal(color::from_known_color(known_color::papaya_whip), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xEF, c.g());
      assert::are_equal(0xD5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("papaya_whip", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFEFD5, c.to_argb());
      assert::are_equal(known_color::papaya_whip, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_peach_puff) {
      color c = color::from_known_color(known_color::peach_puff);
      
      assert::are_equal(color::from_known_color(known_color::peach_puff), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xDA, c.g());
      assert::are_equal(0xB9, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("peach_puff", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFDAB9, c.to_argb());
      assert::are_equal(known_color::peach_puff, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_peru) {
      color c = color::from_known_color(known_color::peru);
      
      assert::are_equal(color::from_known_color(known_color::peru), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x85, c.g());
      assert::are_equal(0x3F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("peru", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD853F, c.to_argb());
      assert::are_equal(known_color::peru, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pink) {
      color c = color::from_known_color(known_color::pink);
      
      assert::are_equal(color::from_known_color(known_color::pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xCB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pink", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFC0CB, c.to_argb());
      assert::are_equal(known_color::pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_plum) {
      color c = color::from_known_color(known_color::plum);
      
      assert::are_equal(color::from_known_color(known_color::plum), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDD, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0xDD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("plum", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDDA0DD, c.to_argb());
      assert::are_equal(known_color::plum, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_powder_blue) {
      color c = color::from_known_color(known_color::powder_blue);
      
      assert::are_equal(color::from_known_color(known_color::powder_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB0, c.r());
      assert::are_equal(0xE0, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("powder_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB0E0E6, c.to_argb());
      assert::are_equal(known_color::powder_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_purple) {
      color c = color::from_known_color(known_color::purple);
      
      assert::are_equal(color::from_known_color(known_color::purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("purple", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800080, c.to_argb());
      assert::are_equal(known_color::purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_rebecca_purple) {
      color c = color::from_known_color(known_color::rebecca_purple);
      
      assert::are_equal(color::from_known_color(known_color::rebecca_purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0x33, c.g());
      assert::are_equal(0x99, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("rebecca_purple", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF663399, c.to_argb());
      assert::are_equal(known_color::rebecca_purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_red) {
      color c = color::from_known_color(known_color::red);
      
      assert::are_equal(color::from_known_color(known_color::red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("red", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF0000, c.to_argb());
      assert::are_equal(known_color::red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_rosy_brown) {
      color c = color::from_known_color(known_color::rosy_brown);
      
      assert::are_equal(color::from_known_color(known_color::rosy_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBC, c.r());
      assert::are_equal(0x8F, c.g());
      assert::are_equal(0x8F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("rosy_brown", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBC8F8F, c.to_argb());
      assert::are_equal(known_color::rosy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_royal_blue) {
      color c = color::from_known_color(known_color::royal_blue);
      
      assert::are_equal(color::from_known_color(known_color::royal_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x41, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xE1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("royal_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4169E1, c.to_argb());
      assert::are_equal(known_color::royal_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_saddle_brown) {
      color c = color::from_known_color(known_color::saddle_brown);
      
      assert::are_equal(color::from_known_color(known_color::saddle_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x13, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("saddle_brown", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B4513, c.to_argb());
      assert::are_equal(known_color::saddle_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_salmon) {
      color c = color::from_known_color(known_color::salmon);
      
      assert::are_equal(color::from_known_color(known_color::salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x72, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("salmon", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFA8072, c.to_argb());
      assert::are_equal(known_color::salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sandy_brown) {
      color c = color::from_known_color(known_color::sandy_brown);
      
      assert::are_equal(color::from_known_color(known_color::sandy_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF4, c.r());
      assert::are_equal(0xA4, c.g());
      assert::are_equal(0x60, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sandy_brown", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF4A460, c.to_argb());
      assert::are_equal(known_color::sandy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sea_green) {
      color c = color::from_known_color(known_color::sea_green);
      
      assert::are_equal(color::from_known_color(known_color::sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x2E, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x57, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sea_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF2E8B57, c.to_argb());
      assert::are_equal(known_color::sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sea_shell) {
      color c = color::from_known_color(known_color::sea_shell);
      
      assert::are_equal(color::from_known_color(known_color::sea_shell), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sea_shell", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF5EE, c.to_argb());
      assert::are_equal(known_color::sea_shell, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sienna) {
      color c = color::from_known_color(known_color::sienna);
      
      assert::are_equal(color::from_known_color(known_color::sienna), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA0, c.r());
      assert::are_equal(0x52, c.g());
      assert::are_equal(0x2D, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sienna", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA0522D, c.to_argb());
      assert::are_equal(known_color::sienna, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_silver) {
      color c = color::from_known_color(known_color::silver);
      
      assert::are_equal(color::from_known_color(known_color::silver), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC0, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xC0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("silver", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC0C0C0, c.to_argb());
      assert::are_equal(known_color::silver, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sky_blue) {
      color c = color::from_known_color(known_color::sky_blue);
      
      assert::are_equal(color::from_known_color(known_color::sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x87, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xEB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sky_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF87CEEB, c.to_argb());
      assert::are_equal(known_color::sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_slate_blue) {
      color c = color::from_known_color(known_color::slate_blue);
      
      assert::are_equal(color::from_known_color(known_color::slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x6A, c.r());
      assert::are_equal(0x5A, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("slate_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6A5ACD, c.to_argb());
      assert::are_equal(known_color::slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_slate_gray) {
      color c = color::from_known_color(known_color::slate_gray);
      
      assert::are_equal(color::from_known_color(known_color::slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x70, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x90, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("slate_gray", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF708090, c.to_argb());
      assert::are_equal(known_color::slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_snow) {
      color c = color::from_known_color(known_color::snow);
      
      assert::are_equal(color::from_known_color(known_color::snow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("snow", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFAFA, c.to_argb());
      assert::are_equal(known_color::snow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_spring_green) {
      color c = color::from_known_color(known_color::spring_green);
      
      assert::are_equal(color::from_known_color(known_color::spring_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x7F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("spring_green", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FF7F, c.to_argb());
      assert::are_equal(known_color::spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_steel_blue) {
      color c = color::from_known_color(known_color::steel_blue);
      
      assert::are_equal(color::from_known_color(known_color::steel_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x46, c.r());
      assert::are_equal(0x82, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("steel_blue", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4682B4, c.to_argb());
      assert::are_equal(known_color::steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_tan) {
      color c = color::from_known_color(known_color::tan);
      
      assert::are_equal(color::from_known_color(known_color::tan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD2, c.r());
      assert::are_equal(0xB4, c.g());
      assert::are_equal(0x8C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tan", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD2B48C, c.to_argb());
      assert::are_equal(known_color::tan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_teal) {
      color c = color::from_known_color(known_color::teal);
      
      assert::are_equal(color::from_known_color(known_color::teal), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("teal", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008080, c.to_argb());
      assert::are_equal(known_color::teal, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_thistle) {
      color c = color::from_known_color(known_color::thistle);
      
      assert::are_equal(color::from_known_color(known_color::thistle), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD8, c.r());
      assert::are_equal(0xBF, c.g());
      assert::are_equal(0xD8, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("thistle", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD8BFD8, c.to_argb());
      assert::are_equal(known_color::thistle, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_tomato) {
      color c = color::from_known_color(known_color::tomato);
      
      assert::are_equal(color::from_known_color(known_color::tomato), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x63, c.g());
      assert::are_equal(0x47, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tomato", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF6347, c.to_argb());
      assert::are_equal(known_color::tomato, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_turquoise) {
      color c = color::from_known_color(known_color::turquoise);
      
      assert::are_equal(color::from_known_color(known_color::turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x40, c.r());
      assert::are_equal(0xE0, c.g());
      assert::are_equal(0xD0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("turquoise", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF40E0D0, c.to_argb());
      assert::are_equal(known_color::turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_violet) {
      color c = color::from_known_color(known_color::violet);
      
      assert::are_equal(color::from_known_color(known_color::violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xEE, c.r());
      assert::are_equal(0x82, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("violet", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFEE82EE, c.to_argb());
      assert::are_equal(known_color::violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_wheat) {
      color c = color::from_known_color(known_color::wheat);
      
      assert::are_equal(color::from_known_color(known_color::wheat), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xDE, c.g());
      assert::are_equal(0xB3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("wheat", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5DEB3, c.to_argb());
      assert::are_equal(known_color::wheat, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_white) {
      color c = color::from_known_color(known_color::white);
      
      assert::are_equal(color::from_known_color(known_color::white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("white", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFFF, c.to_argb());
      assert::are_equal(known_color::white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_white_smoke) {
      color c = color::from_known_color(known_color::white_smoke);
      
      assert::are_equal(color::from_known_color(known_color::white_smoke), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xF5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("white_smoke", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5F5F5, c.to_argb());
      assert::are_equal(known_color::white_smoke, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_yellow) {
      color c = color::from_known_color(known_color::yellow);
      
      assert::are_equal(color::from_known_color(known_color::yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("yellow", c.name());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFF00, c.to_argb());
      assert::are_equal(known_color::yellow, c.to_known_color());
    }
  };
}