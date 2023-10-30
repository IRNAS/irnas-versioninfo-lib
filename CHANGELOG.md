# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)

## [Unreleased]

## [1.2.0] - 2023-10-30

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

[Unreleased]: https://github.com/IRNAS/irnas-versioninfo-lib/compare/v1.2.0...HEAD

[1.2.0]: https://github.com/IRNAS/irnas-versioninfo-lib/compare/66a0a2bcbc21f67f312538d29041a0319c90612c...v1.2.0
