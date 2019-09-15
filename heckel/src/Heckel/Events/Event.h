#pragma once


namespace Heckel
{
	// Events are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with rigth then and there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage


	// To be able to easily identify the event
	enum class EventType
	{
		None = 0,
		// window events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		// app events
		AppTick, AppUpdate, AppRender,
		// key events
		KeyPressed, KeyRelease,
		// mouse events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// to be able to filter the type of events we care about
	// flags
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0), // 1
		EventCategoryInput       = BIT(1), // 2
		EventCategoryKeyboard    = BIT(2), // 4
		EventCategoryMouse       = BIT(3), // 8
		EventCategoryMouseButton = BIT(4)  // 16
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual EventType GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	
	// abstract class that will be used to define our events
	class HECKEL_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0; // for debugging
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); } // for debugging

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		// to tell if the event was handled or if it needs to be dispatched
		bool m_Handled = false;
	};

	// If we receive an event, and our onEvent function gets called
	// we will receive the event as an event reference
	// we will be able to create an EventDispatcher object, with the event we received
	// and then we can call the Dispatch function that will execute a given callback
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

} // end of namespace
