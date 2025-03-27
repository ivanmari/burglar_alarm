cmake_minimum_required(VERSION 3.15...3.31)

project(
	BurglarAlarm
	VERSION 1.0
	LANGUAGES CXX)

add_executable(burglar_alarm main.cpp ui.cpp X86Platform.cpp)
target_compile_definitions(burglar_alarm PUBLIC X86_PLAT)
target_link_libraries(burglar_alarm PRIVATE ${CMAKE_SOURCE_DIR}/libburglaralarm.a ncurses)

