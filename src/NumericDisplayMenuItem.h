#ifndef NUMERIC_DISPLAY_MENU_ITEM_H
#define NUMERIC_DISPLAY_MENU_ITEM_H

#include "MenuSystem.h"
#include "MenuComponentRenderer2.h"

class NumericDisplayMenuItem : public MenuItem {
public:
	//! \brief Callback for formatting the numeric value into a String.
	//!
	//! \param value The value to convert.
	//! \returns The String representation of value.
	using FormatValueFnPtr = const String(*)(const float value);

public:
	//! Constructor
	//!
	//! @param name The name of the menu item.
	//! @param select_fn The function to call when this MenuItem is selected.
	//! @param value Default value
	//! @param format_value_fn The custom formatter. If nullptr the String
	//!                        float formatter will be used.
	NumericDisplayMenuItem(const char* basename, SelectFnPtr select_fn,
		float value,FormatValueFnPtr format_value_fn = nullptr)
		: MenuItem(basename, select_fn),
        _value(value),
        _format_value_fn(format_value_fn) {}

	//!
	//! \brief Sets the custom number formatter.
	//!
	//! \param numberFormat the custom formatter. If nullptr the String float
	//!                     formatter will be used (2 decimals)
	//!
	void set_number_formatter(FormatValueFnPtr format_value_fn) { _format_value_fn = format_value_fn; }

	float get_value() const { return _value; }

	void set_value(float value) { _value = value; }

	String get_formatted_value() const {
        String buffer;
        if (_format_value_fn != nullptr)
            buffer += _format_value_fn(_value);
        else
            buffer += _value;
        return buffer;
    }

	virtual void render(MenuComponentRenderer const& renderer) const {
        MenuComponentRenderer2 const& my_renderer = static_cast<MenuComponentRenderer2 const&>(renderer);
        my_renderer.render_numeric_display_menu_item(*this);
    }

protected:
	float _value;
	FormatValueFnPtr _format_value_fn;
};

#endif
