/**
 * \file    TextEditMenuItem.h
 * \brief   TextEditMenuItem
 * \version 3.1.0
 * \date    2020-02-16
 * \copyright  Licensed under the MIT license (see LICENSE)
 */
// from https://github.com/willie68/arduino-menusystem/blob/master/MenuSystem.h
#ifndef TEXT_EDIT_MENU_ITEM_H
#define TEXT_EDIT_MENU_ITEM_H

#include "MenuSystem.h"
#include "MenuComponentRenderer2.h"

enum EDITING_STATE {
	FOCUSED, SELECTION, EDITING
};

//! \brief A MenuItem for editing a short text string
//!
//! TextEditMenuItem is a menu item for automatically
//! edit a short text buffer. It's specialised for use
//! with an rotary encoder. On editing ending the
//! the user-defined Menu::_select_fn callback is called.
class TextEditMenuItem: public MenuItem {
public:
	//! Constructor
	//!
	//! @param name The name of the menu item.
	//! @param select_fn The function to call when this MenuItem is selected.
	//! @param value the buffer with the text to edit.
	//! @param size size of the buffer
	TextEditMenuItem(const char* name, SelectFnPtr select_fn, char* value, uint8_t size) : MenuItem(basename, select_fn), _value(value), _size(size) {}

	EDITING_STATE _editing_state;

	char* get_value() const { return _value; }
	uint8_t get_size() const { return _size; }
	uint8_t get_pos() const { return _pos; }

	void set_value(char* value) { _value = value; }
	void set_size(byte size) { _size = value; }

	virtual void render(MenuComponentRenderer2 const& renderer) const { renderer.render_text_edit_menu_item(*this); }

protected:
	virtual bool next(bool loop = false);
	virtual bool prev(bool loop = false);

	virtual Menu* select();

	char getNextValidChar(char value);
	char getPrevValidChar(char value);

protected:
	char* _value;
	uint8_t _size;
	uint8_t _pos;
};

inline Menu* TextEditMenuItem::select() {
	if (!_has_focus) {
		_editing_state = SELECTION;
		_has_focus = true;
		_pos = 1;
	} else {
		switch (_editing_state) {
		case SELECTION:
			if (_pos == 0) {
				_has_focus = false;
			} else {
				_editing_state = EDITING;
			}
			break;
		case EDITING:
			_editing_state = SELECTION;
			break;
		}
	}
	if (!_has_focus && _select_fn != nullptr)
		_select_fn(this);
	return nullptr;
}

inline char TextEditMenuItem::getNextValidChar(char value) {
	char myValue = value;
	if (myValue < 32) {
		myValue = 32;
	}
	if (myValue >= 126) {
		return 126;
	}
	return myValue + 1;
}

inline char TextEditMenuItem::getPrevValidChar(char value) {
	char myValue = value;
	if (myValue < 32) {
		myValue = 32;
	}
	if (myValue <= 32) {
		return 32;
	}
	return myValue - 1;
}

inline bool TextEditMenuItem::next(bool loop) {
	switch (_editing_state) {
	case SELECTION:
		_pos++;
		if (_pos > _size) {
			_pos = _size;
		}
		break;
	case EDITING:
		if (_pos > 0) {
			_value[_pos - 1] = getNextValidChar(_value[_pos - 1]);
		}
		break;
	}
	return true;
}

inline bool TextEditMenuItem::prev(bool loop) {
	switch (_editing_state) {
	case SELECTION:
		if (_pos == 0) {
		} else {
			_pos--;
		}
		break;
	case EDITING:
		if (_pos > 0) {
			_value[_pos - 1] = getPrevValidChar(_value[_pos - 1]);
		}
		break;
	}
	return true;
}

#endif // TEXT_EDIT_MENU_ITEM_H

