cmake_minimum_required(VERSION 2.4)
project(diabolical)

set (
	SOURCES
	dfgame.cpp
	dfgame.h
	globals.h
	main.cpp
	platform.h
	platform.cpp
	player.h
	player.cpp
	object.h
	level.h
	level.cpp
	texture.h
	texture.cpp
	ui.h
	ui.cpp
	items/item.h
	items/item.cpp
	items/door.h
	items/door.cpp
	)

Find_Package( SDL REQUIRED )
Find_Package( SDL_image REQUIRED )
Find_Package( OpenGL REQUIRED )

include_directories( ${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} )

link_libraries(${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY})

add_executable(diabolical ${SOURCES})
