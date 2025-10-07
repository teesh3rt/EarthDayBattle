include(FetchContent)

FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG        master
)

FetchContent_MakeAvailable(fmtlib)