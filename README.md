# Version info module

Module `version_info` provides data structures and functions that contain
information about application version, git hash, build type and other.

Data that is provided by this module is always up-to-date, as Cmake during each
`west build` command run checks whether new version information should be
generated.

These checks are possible due to the useful `git_watcher.cmake` file found on:
https://github.com/andrew-hardin/cmake-git-version-tracking.

## Setup

1. To your `west.yml` add the `irnas` remote to the `remotes` section:

   ```yaml
   - name: ba-rd-ais
     url-base: https://code.bbraun.io/ba-rd-ais
   ```

2. Then in the `projects` section add below snippet at the bottom. You need to
   manually select `revision`.

   ```yaml
   - name: versioninfo-lib
     repo-path: versioninfo-lib
     path: ba-rd-ais/versioninfo-lib
     remote: ba-rd-ais
     revision: <revision>
   ```

## How to use this module

1. Module creates a generated file in `version_info/generated`. Make sure that
   `generated` folder is kept out of version control.

2. Enable module in your `prj.conf`:

```Kconfig
CONFIG_VERSION_INFO=y
```

You can now include header file in the source file of your choice and start
using its functions.

### Build type

User can specify what kind of build type is used for the project being built.
Build type is available as a `.build_type`, a member of the `version_info`
struct.

Build type can be either set manually in a KConfig file or automatically with
[East].

> [!Note] Both examples are show in this repository, inside the `app` folder.

[east]: https://github.com/IRNAS/irnas-east-software

#### Setting it manually

Place below two lines in a `prj.conf` file. `.build_type` is now set to
`"basic"`.

```Kconfig
CONFIG_VERSION_INFO_APP_BUILD_TYPE_USER=y
CONFIG_VERSION_INFO_APP_BUILD_TYPE="basic"
```

#### Setting it automatically

Place your project into `east.yml` file. Refer to the East's documentation on
how to do that. East will provide build type via `EAST_BUILD_TYPE` define.
Version info library picks up this define and places it into the code.

## Expanding the module

If you want to add more git related strings to this module you will have to do
this in several places:

1. Register new variable in `git_watcher.cmake` file to `_state_variable_names`
   variable.
2. Fill new variable at the end of `GetGitState` function, look above to see how
   previous variables are assigned.
3. Add a new variable in `generated_version_info.h.in` file as a define
   statement, make sure that is placed between `@` signs like others are.
4. Use the new define in `version_info.c` file.
