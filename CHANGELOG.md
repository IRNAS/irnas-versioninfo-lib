# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)

## [Unreleased]

This is the first release done with the CI release process.

### Added

-   Support for `EAST_BUILD_TYPE` define flag. This library now uses our East 
    tool to determine at compile time what build type is being used. Related 
    `CONFIG_VERSION_INFO_APP_BUILD_TYPE_USER` can be used to manually specify 
    the build type.
-   CI infrastructure was updated.


### Changed

-   Project structure. This library now uses the most recent project structure 
    from our irnas-zephyr-template.
