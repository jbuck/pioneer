#ifndef _GUIREPEATERBUTTON_H
#define _GUIREPEATERBUTTON_H

#include "GuiButton.h"

namespace Gui {
	/* Emits click events like the normal button, except that when
	 * depressed for msDelay milliseconds it will begin emitting events
	 * every msRepeat milliseconds */
	class RepeaterButton: public SolidButton {
	public:
		RepeaterButton(int msDelay, int msRepeat);
		virtual ~RepeaterButton();
	private:
		void OnPress();
		void OnRelease();
		void OnRepeat();
		sigc::connection m_repeatCon;
		int m_delay, m_repeat;
	};
}

#endif /* _GUIREPEATERBUTTON_H */
