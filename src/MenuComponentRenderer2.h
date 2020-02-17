/**
 * \file    MenuComponentRenderer2.h
 * \brief   new interface
 * \author  Yunhui Fu (yhfudev@gmail.com)
 * \version 1.0
 * \date    2020-01-05
 * \copyright GPL/BSD
 */

#ifndef _MenuComponentRenderer2_H
#define _MenuComponentRenderer2_H 1

#include "MenuSystem.h"

class ToggleMenuItem;
class NumericDisplayMenuItem;
class TextEditMenuItem;

class MenuComponentRenderer2 : public MenuComponentRenderer
{
public:
  virtual void render(Menu const& menu) const = 0;
  virtual void render_menu_item(MenuItem const& menu_item) const = 0;
  virtual void render_back_menu_item(BackMenuItem const& menu_item) const = 0;
  virtual void render_numeric_menu_item(NumericMenuItem const& menu_item) const = 0;
  virtual void render_toggle_menu_item(ToggleMenuItem const& menu_item) const = 0;
  virtual void render_numeric_display_menu_item(NumericDisplayMenuItem const& menu_item) const = 0;
  virtual void render_menu(Menu const& menu) const = 0;
  virtual void render_text_edit_menu_item(TextEditMenuItem const& menu_item) const = 0;
};


#ifdef __cplusplus
extern "C" {
#endif

void somefunc333();

#ifdef __cplusplus
}
#endif


#endif // _MenuComponentRenderer2_H

