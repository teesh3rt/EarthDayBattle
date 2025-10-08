set(PUT_ASSETS_IN ${CMAKE_BINARY_DIR}/$<CONFIG>)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${PUT_ASSETS_IN}/assets
    COMMENT "Copying assets to build directory"
)