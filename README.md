# Version info module

Module `version_info` provides data structures and functions that contain
information about application version, git hash, build type and other.

Data that is provided by this module is always up to date, as cmake during each
`west build` command run checks whether new version information should be
generated.

These checks are possible due to the usefull `git_watcher.cmake` file found on:
https://github.com/andrew-hardin/cmake-git-version-tracking.

## How to use this module

1. Module creates a generated file in `version_info/generated`.
Make sure that `generated` folder is kept out of version control.

2. Enable module in your `prj.conf`:
```
CONFIG_VERSION_INFO=y
```

You can now include header file in the source file of your choice and start
using its functions.

## Expanding the module

If you want to add more git related strings to this module you will have to do
this on several places:
1. Register new variable in `git_watcher.cmake` file to `_state_variable_names`
   variable.
2. Fill new variable at the end of `GetGitState` function, look above to see
   how previous variables are assinged.
3. Add a new variable in `generated_version_info.h.in` file as a define
   statement, make sure that is placed betwen `@` signs like others are.
4. Use the new define in `version_info.c` file.

