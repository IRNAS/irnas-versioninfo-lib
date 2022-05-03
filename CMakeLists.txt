# Print out build type, this does not work properly
message(STATUS "Build type: ${CONFIG_VERSION_INFO_APP_BUILD_TYPE} 🚀")

set(PRE_CONFIGURE_FILE "generated_version_info.h.in")
set(POST_CONFIGURE_FILE "generated/generated_version_info.h")
include(git_watcher.cmake)

zephyr_include_directories(.)
add_dependencies(app check_git)

target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/version_info.c)

# target_link_libraries(app PUBLIC git) target_sources(app PRIVATE
# ${CMAKE_CURRENT_SOURCE_DIR}/version_info.c)

# if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/gen_cache_version.txt) message(STATUS
# "File gen_cache_version.txt was found") else() message(STATUS "File
# gen_cache_version.txt was not found") endif()
