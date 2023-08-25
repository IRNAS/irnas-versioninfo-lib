# Print out build type
zephyr_library()
message(STATUS "Build type: ${CONFIG_VERSION_INFO_APP_BUILD_TYPE} 🚀")

set(PRE_CONFIGURE_FILE "generated_version_info.h.in")
set(POST_CONFIGURE_FILE "generated/generated_version_info.h")
include(git_watcher.cmake)

add_dependencies(app check_git)

zephyr_include_directories(.)
zephyr_library_sources(version_info.c)
