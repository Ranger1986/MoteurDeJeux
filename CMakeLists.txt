# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
	X11
	Xxf86vm
	Xi
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Moteur
add_executable(Moteur

        Moteur/Moteur.cpp
		
		Moteur/src/Bullet.cpp
		Moteur/src/Bullet.hpp
		Moteur/src/Behaviour.cpp
		Moteur/src/Behaviour.hpp
		Moteur/src/helper.cpp
		Moteur/src/Hitbox.cpp
		Moteur/src/Hitbox.hpp
		Moteur/src/Player.cpp
		Moteur/src/Player.hpp
		Moteur/src/Scene.cpp
		Moteur/src/Scene.hpp
		Moteur/src/Obstacle.cpp
		Moteur/src/Obstacle.hpp
		Moteur/src/Ennemy.cpp
		Moteur/src/Ennemy.hpp
		Moteur/src/Mesh.cpp
		Moteur/src/Mesh.hpp
		Moteur/src/Node.cpp
		Moteur/src/Node.hpp
		Moteur/src/Transform.cpp
		Moteur/src/Transform.hpp
		Moteur/src/Quad.cpp
		Moteur/src/Quad.hpp
		Moteur/src/mapreader.hpp
		Moteur/src/RessourceLoader.hpp

	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp

        Moteur/vertex_shader.glsl
        Moteur/fragment_shader.glsl
)
target_link_libraries(Moteur
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(Moteur PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Moteur/")
create_target_launcher(Moteur WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Moteur/")




SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET Moteur POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Moteur${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/Moteur/"
)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

