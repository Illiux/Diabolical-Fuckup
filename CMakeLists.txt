cmake_minimum_required(VERSION 2.4)
project(diabolical)

set (
	SOURCES
	glheader.h
	glmain.cpp
	)

Find_Package( SDL REQUIRED )
Find_Package( SDL_image REQUIRED )

link_libraries(${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})

add_executable(diabolical ${SOURCES})
