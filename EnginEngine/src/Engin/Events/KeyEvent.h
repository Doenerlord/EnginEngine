#pragma once

#include "Event.h"

namespace Engin {

	//KeyEvent inherit from base class Event and is the base class for other key events because they all have a keycode
	//assigns category and returns keycode
	class ENGIN_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		//sets categories for key events (because they are the same for each individual key event)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	//the other keyevents inherit from KeyEvent class
	// 
	//KeyPressedEvent is triggered when a key is pressed. It also returns if the key is held down.
	class ENGIN_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		//m_RepeatCount equals 1 if the key is held down and 0 if it was a single press
		inline int GetRepeatCount() const { return m_RepeatCount;  }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		//sets event type for this key event
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	//Is triggered when a previously pressed key is released.
	class ENGIN_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		
		//sets event type for this key event
		EVENT_CLASS_TYPE(KeyReleased)
	};
}