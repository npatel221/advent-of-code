target_include_directories(common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(aoc2025_day01 main.cpp Command.cpp Safe.cpp)

target_link_libraries(aoc2025_day01
    PRIVATE common
)