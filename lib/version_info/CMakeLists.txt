if(CONFIG_VERSION_INFO)
  zephyr_library()

  if(CONFIG_VERSION_INFO_APP_BUILD_TYPE_USER)
    zephyr_library_compile_definitions(
      VERSION_INFO_BUILD_TYPE="${CONFIG_VERSION_INFO_APP_BUILD_TYPE}")
    set(BUILD_TYPE "${CONFIG_VERSION_INFO_APP_BUILD_TYPE}")

  elseif(CONFIG_VERSION_INFO_APP_BUILD_TYPE_EAST)
    zephyr_library_compile_definitions(
      VERSION_INFO_BUILD_TYPE="${EAST_BUILD_TYPE}")
    set(BUILD_TYPE "${EAST_BUILD_TYPE}")

  else(CONFIG_VERSION_INFO_APP_BUILD_TYPE_EAST)
    set(BUILD_TYPE "unknown")

  endif()

  message(STATUS "Build type: ${BUILD_TYPE} 🚀")

  set(PRE_CONFIGURE_FILE "generated_version_info.h.in")
  set(POST_CONFIGURE_FILE "generated/generated_version_info.h")
  include(git_watcher.cmake)

  add_dependencies(app check_git)

  zephyr_include_directories(.)
  zephyr_library_sources(version_info.c)
endif()
