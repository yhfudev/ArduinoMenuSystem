#ifndef _TOGGLEMENUITEM_H
#define _TOGGLEMENUITEM_H

#include "MenuSystem.h"
#include "MenuComponentRenderer2.h"

class ToggleMenuItem : public MenuItem
{
public:
	/**
	 * @param width the width of the edit mode 'ASCII graphics', must be > 1
	 * @param name The name of the menu item.
	 * @param value Default value.
	 * @param valueFormatter The custom formatter. If nullptr the String float
	 *                       formatter will be used.
	 */
	ToggleMenuItem(const char* name, SelectFnPtr select_fn,const char* onString, const char* offString, bool state = false)
        : MenuItem(name, select_fn), _state(state), _onString(onString), _offString(offString) {}

	void set_state(bool state) { _state = state; }
	void set_state_on() { _state = true; }
	void set_state_off() { _state = false; }
	void toggle_state() { _state = !_state; }
	bool get_state() const { return _state; }
	const char* get_state_str() const {
        if (get_state())
            return _onString;
        else
            return _offString;
    }
	virtual void render(MenuComponentRenderer const& renderer) const {
	MenuComponentRenderer2 const& my_renderer = static_cast<MenuComponentRenderer2 const&>(renderer);
	my_renderer.render_toggle_menu_item(*this);
}

protected:
	virtual Menu* select() {
        toggle_state();
        if (_select_fn != nullptr)
            _select_fn(this);
        return nullptr;
    }

private:
	bool _state;
	const char* _onString;
	const char* _offString;
};

#endif // _TOGGLEMENUITEM_H
