#pragma once

#include "Event.h"

namespace Engin {
	//Application Events inherit from base Event class
	//This event occurs when the application window is resized. 
	class ENGIN_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		//unsigned int is used because the size of the window can't be lower than zero. Const because the methods shouldn't be able to change the window size
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		//Returns the new width and height of the window
		//overrides the ToString() method in event
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		//Assigns event type and categorizes it.
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	//Is triggered when application window is closed
	class ENGIN_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	

	class ENGIN_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//is triggered when the state of the application has been updated
	class ENGIN_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//is possibly triggered when a frame of the application has been rendered
	class ENGIN_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ENGIN_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent(int focus) : m_Focus(focus) {}

		inline int GetFocus() const { return m_Focus; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowFocusEvent: " << m_Focus;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_Focus;
	};

	class ENGIN_API WindowMovedEvent : public Event {
	public:
		WindowMovedEvent(int xpos, int ypos) : m_XPos(xpos), m_YPos(ypos) {}

		inline int GetXPos() const { return m_XPos; }
		inline int GetYPos() const { return m_YPos; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowMovedEvent: " << m_XPos << ", " << m_YPos;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_XPos, m_YPos;
	};
}
