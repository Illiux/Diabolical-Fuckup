cmake_minimum_required(VERSION 2.4)
project(diabolical)

set (
	SOURCES
	test_image.cpp
	mouse.h
	)

Find_Package( SDL REQUIRED )
Find_Package( SDL_image REQUIRED )

include_directories( ${SDL_INCLUDE_DIR} )

link_libraries(${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})

add_executable(diabolical ${SOURCES})
