#pragma once

#include "enginpch.h"

#include "Engin/Core.h"
#include "Engin/Events/Event.h"

namespace Engin {
	//properties of the window
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		//constructor of WindowProps struct with default values
		WindowProps(const std::string& title = "Engin Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	//Represents desktop system based window
	//interface for platform specific windows implementations
	class ENGIN_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() { }

		virtual void OnUpdate() = 0;
	
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}