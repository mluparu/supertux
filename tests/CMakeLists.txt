find_package(sqlite3 CONFIG REQUIRED)

# build SuperTux tests
  file(GLOB TEST_SUPERTUX_SOURCES *.cpp)
  add_executable(test_supertux2 ${TEST_SUPERTUX_SOURCES})

  target_compile_options(test_supertux2 PRIVATE ${WARNINGS_CXX_FLAGS})

  target_link_libraries(test_supertux2
    gtest gtest_main
    supertux2_lib
    sqlite3
    ${CMAKE_THREAD_LIBS_INIT})

  add_test(NAME test_supertux2
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND test_supertux2)
