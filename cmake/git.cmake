find_package(Git)
if(Git_FOUND)
    # Run git to get the current commit hash
    execute_process(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    message(STATUS "GIT_HASH = ${GIT_HASH}")
endif()