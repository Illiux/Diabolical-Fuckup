cmake_minimum_required(VERSION 2.4)
project(diabolical)

set (
	SOURCES
	mouse.h
	dfgame.cpp
	dfgame.h
	globals.h
	main.cpp
	)

Find_Package( SDL REQUIRED )
Find_Package( SDL_image REQUIRED )
Find_Package( OpenGL REQUIRED )

include_directories( ${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} )

link_libraries(${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${OPENGL_gl_LIBRARY})

add_executable(diabolical ${SOURCES})
