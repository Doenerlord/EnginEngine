#pragma once

#include "enginpch.h"
#include "Engin/Core.h"

namespace Engin {

	//assignable types of events
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//usable to filter events
	//bits are used so that an event can have more than one category
	//EventCategory is no enum class because we need it to be the assigned Bit and not an object so that we can use an bitwise AND operation to check the categories. 
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	//macro to define a few methods which return the right type for child classes of events without the need to write every method in every event child class
	//useful to get the event type of some event
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
								virtual EventType GetEventType() const override {return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	//macro to define a method which returns the right category for child classes without the need to write it in every one of them
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }

	//an abstract class Event from which all other events can inherit functions and variables
	class ENGIN_API Event {
		friend class EventDispatcher;
	public:
		//pure virtual functions
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		//used to check if a certain event is in a certain category to filter events
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		//set handled to true after event has been handled by the EventDispatcher, so that an event isn't looked at twice
		bool m_Handled = false;
	};

	//used to dispatch any type of event
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {

		}

		//used to dispatch all types of events. 
		//exists for every type of event once since it's a template
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			//check which type the event is and run the binded function if the types match
			if (m_Event.GetEventType() == T::GetStaticType()) {
				//sets m_handled to true if the AND operation with the return value of the binded function and the event is anything other than 0
				m_Event.m_Handled = func(*(T*) & m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//log events by being able to simply call ToString() by using the << operator
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}