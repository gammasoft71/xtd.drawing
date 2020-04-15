#include <xtd/drawing/native/system_colors.h>
#include <wx/settings.h>

#include <cstdint>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

#if defined(__WXMSW__)
#include <Windows.h>
#endif

bool __xtd_enable_dark_mode__ = false;
bool __xtd_enable_light_mode__ = false;

using namespace xtd::drawing::native;

namespace {
  bool dark_mode() {
#if defined(__WXMSW__)
    DWORD value = 0, value_size = sizeof(value);
    if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) == ERROR_SUCCESS)
      return value == 0 || __xtd_enable_dark_mode__;
#endif
    return __xtd_enable_dark_mode__;
  }

  bool light_mode() {
    return __xtd_enable_light_mode__;
  }

  uint32_t to_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }

  uint32_t to_argb(const wxColour color) {
    return ::to_argb(color.Alpha(), color.Red(), color.Green(), color.Blue());
  }
}

bool system_colors::force_set_system_color() {
  return ::dark_mode() || ::light_mode();
}

uint32_t system_colors::to_argb(intptr_t color) {
#if defined(__WXOSX__)
   if (force_set_system_color()) return static_cast<uint32_t>(color);
  return ::to_argb(wxColour(reinterpret_cast<WX_NSColor>(color)));
#else
  return static_cast<uint32_t>(color);
#endif
}

intptr_t system_colors::active_border() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
#endif
}

intptr_t system_colors::active_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
#endif
}

intptr_t system_colors::active_caption_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT));
#endif
}

intptr_t system_colors::app_workspace() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  if (::light_mode()) return ::to_argb(255, 231, 231, 231);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
#endif
}

intptr_t system_colors::button_face() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  if (::light_mode()) return ::to_argb(255, 231, 231, 231);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::button_highlight() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  if (::light_mode()) return ::to_argb(255, 255, 255, 255);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::button_shadow() {
  if (::dark_mode()) return ::to_argb(255, 35, 35, 35);
  if (::light_mode()) return ::to_argb(255, 173, 173, 173);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  if (::light_mode()) return ::to_argb(255, 231, 231, 231);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#  else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#  endif
#else
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxButton* button = new wxButton(frame, wxID_ANY, "");
  wxColour colour = button->GetBackgroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete button;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::control_dark() {
  if (::dark_mode()) return ::to_argb(255, 35, 35, 35);
  if (::light_mode()) return ::to_argb(255, 173, 173, 173);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control_dark_dark() {
  if (::dark_mode()) return ::to_argb(255, 35, 35, 35);
  if (::light_mode()) return ::to_argb(255, 173, 173, 173);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
#endif
}

intptr_t system_colors::control_light() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  if (::light_mode()) return ::to_argb(255, 255, 255, 255);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
#endif
}

intptr_t system_colors::control_light_light() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  if (::light_mode()) return ::to_argb(255, 255, 255, 255);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::control_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT).OSXGetNSColor());
#  else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
#  endif
#else
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxButton* button = new wxButton(frame, wxID_ANY, "");
  wxColour colour = button->GetForegroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete button;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::desktop() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
#endif
}

intptr_t system_colors::gradient_active_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
#endif
}

intptr_t system_colors::gradient_inactive_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
#endif
}

intptr_t system_colors::gray_text() {
  if (::dark_mode()) return ::to_argb(255, 107, 107, 107);
  if (::light_mode()) return ::to_argb(255, 178, 178, 178);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
#endif
}

intptr_t system_colors::highlight() {
  if (::dark_mode()) return ::to_argb(255, 49, 79, 120);
  if (::light_mode()) return ::to_argb(255, 165, 205, 255);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
#endif
}

intptr_t system_colors::highlight_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  if (::light_mode()) return ::to_argb(255, 0, 0, 0);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
#endif
}

intptr_t system_colors::hot_track() {
  if (::dark_mode()) return ::to_argb(255, 223, 223, 223);
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
#endif
}

intptr_t system_colors::inactive_border() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
#endif
}

intptr_t system_colors::inactive_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
#endif
}

intptr_t system_colors::inactive_caption_text() {
  if (::dark_mode()) return ::to_argb(255, 107, 107, 107);
  if (::light_mode()) return ::to_argb(255, 178, 178, 178);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
#endif
}

intptr_t system_colors::info() {
  if (::light_mode()) return ::to_argb(255, 231, 231, 231);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
#endif
}

intptr_t system_colors::info_text() {
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
#endif
}

intptr_t system_colors::menu() {
  if (::dark_mode()) return ::to_argb(255, 0, 0, 0);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
#endif
}

intptr_t system_colors::menu_bar() {
  if (::dark_mode()) return ::to_argb(255, 0, 0, 0);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
#endif
}

intptr_t system_colors::menu_highlight() {
  if (::light_mode()) return ::to_argb(255, 52, 93, 241);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
#endif
}

intptr_t system_colors::menu_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
#endif
}

intptr_t system_colors::scroll_bar() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
#endif
}

intptr_t system_colors::window() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  if (::light_mode()) return ::to_argb(255, 255, 255, 255);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW).OSXGetNSColor());
#  else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
#  endif
#else
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxTextCtrl* text = new wxTextCtrl(frame, wxID_ANY, "");
  wxColour colour = text->GetBackgroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete text;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::window_frame() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  if (::light_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
#endif
}

intptr_t system_colors::window_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  if (::light_mode()) return ::to_argb(255, 36, 36, 36);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT).OSXGetNSColor());
#  else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
#  endif
#else
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxTextCtrl* text = new wxTextCtrl(frame, wxID_ANY, "");
  wxColour colour = text->GetForegroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete text;
  delete frame;
  return default_color;
#endif
}
