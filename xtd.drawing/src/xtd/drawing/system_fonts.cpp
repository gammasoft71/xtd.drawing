#include "../../../include/xtd/drawing/system_fonts.hpp"
#include <xtd/drawing/native/system_fonts.hpp>

using namespace xtd;
using namespace xtd::drawing;

const font system_fonts::caption_font =  font::from_hfont(native::system_fonts::caption_font());
const font system_fonts::default_font =  font::from_hfont(native::system_fonts::default_font());
const font system_fonts::dialog_font =  font::from_hfont(native::system_fonts::dialog_font());
const font system_fonts::icon_title_font =  font::from_hfont(native::system_fonts::icon_title_font());
const font system_fonts::menu_font =  font::from_hfont(native::system_fonts::menu_font());
const font system_fonts::message_box_font =  font::from_hfont(native::system_fonts::message_box_font());
const font system_fonts::small_caption_font =  font::from_hfont(native::system_fonts::small_caption_font());
const font system_fonts::status_font =  font::from_hfont(native::system_fonts::status_font());