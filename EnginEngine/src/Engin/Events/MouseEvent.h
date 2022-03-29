#pragma once

#include "Event.h"

namespace Engin {

	//MouseEvents inherit from Event as base class

	//Is triggered when the mouse is moved around on the application window
	class ENGIN_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		//assigns event type
		EVENT_CLASS_TYPE(MouseMoved)
		//assigns event categories
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		//the coordinates of the mouse pointer relative to (0|0)(top left corner) of the application window. 
		float m_MouseX, m_MouseY;
	};

	//is triggered when the the mouse wheel is used. values < 0 for down, values > 0 for up, values < 0 for left, values > for right
	class ENGIN_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	//serves as base class for MouseButtonPressed and MouseButtonReleased as they share the button keycode
	class ENGIN_API MouseButtonEvent : public Event {
	public:
		inline int GetMousButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	//is triggered when a mouse button is pressed
	class ENGIN_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	//is triggered when a previously pressed mouse button is released.
	class ENGIN_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}