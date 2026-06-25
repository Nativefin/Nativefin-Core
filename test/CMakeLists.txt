add_executable(Nativefin-Core-Test
        main.cpp
)

target_link_libraries(Nativefin-Core-Test PRIVATE
        Nativefin-Core
)

add_test(
        NAME Nativefin-Core-Tests
        COMMAND Nativefin-Core-Test
)