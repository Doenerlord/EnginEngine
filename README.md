# EnginEngine

EnginEngine basiert auf den Videos (und dem Code) der Game Engine Series von The Cherno (https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT)

Der Funktionsumfang der EnginEngine ist noch sehr eingeschränkt und sie funktioniert derzeit nur unter Windows.
Die Engine wird als .dll-File ausgeliefert und muss in das Projekt eingebunden werden um auf die Funktionen zugreifen zu können.

Der derzeitige Funktionsumfang besteht aus einer Log Funktion, einem Event System und dem Erstellen eines Application Windows unter Windows.
Für das Event System und das Application Window wird die OpenGL Library GLFW verwendet und die Logs wurden mithilfe der spdlog Library umgesetzt.

Um die Engine zu benutzen muss in der Applikation, wie in der Demoapplikation ersichtlich, ein Engin::Application* mit der Funktion Engin::CreateApplication() erstellt werden
um den Entrypoint der Engine aufzurufen. Daraufhin wird eine Run-Funktion ausgeführt, bei der es sich um den primary loop der Engine handelt.

Mithilfe von GLFW werden folgende Events im Application Window erkannt:

Window Events:
  - WindowClose, WindowResize, WindowFocus, WindowMoved
Application Events:
  - AppTick, AppUpdate, AppRender

Input Events:
  - Key Events:
    - KeyPressed/KeyRepeated, KeyReleased
  - Mouse Events:
    - MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

Wird eines dieser Events getriggert wird dies in den Log geschrieben und die Farbe des Application Windows ändert sich.

Für verkürzte Builddauer wurden precompiled header benutzt (EnginEngine/src/engpch.h)
Für einfachere buildconfiguration inklusive postbuild copy step der EnginEngine.dll in den Ordner der Demo Applicatio wurde premake5 benutzt.

Zusätzliche Dinge, die nicht in den vorgegebenen Videos enthalten waren:
  - WindowFocus und WindowMoved Event implementiert.
  - WindowLostFocus Event entfernt, da WindowFocus beide Fälle abdeckt.
  - Die Farben des ApplicationWindow ändern sich, je nachdem welches Event getriggert wurde.


Dieses Projekt richtig klonen:
  1. git clone https://github.com/Doenerlord/EnginEngine.git / Repo auf gewünschtem Weg klonen
  2. generateProjects.bat ausführen. Hiermit werden die Submodules des Repos heruntergeladen und die Projektfiles für Visual Studio 2022 erstellt. / Falls eine andere      IDE als Visual Studio 2022 benutzt wird muss "vs2022" im batchfile ersetzt werden.
  3. Projekt öffnen
  4. ???
  5. Profit!
