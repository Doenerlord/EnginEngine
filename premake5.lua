workspace "EnginEngine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EnginEngine"
    location "EnginEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGIN_PLATFORM_WINDOWS",
            "ENGIN_BUILD_DLL"
        }

        postbuildcommands{
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "ENGIN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ENGIN_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "ENGIN_DIST"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "EnginEngine/vendor/spdlog/include",
        "EnginEngine/src"
    }

    links {
        "EnginEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGIN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ENGIN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ENGIN_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "ENGIN_DIST"
        symbols "On"
