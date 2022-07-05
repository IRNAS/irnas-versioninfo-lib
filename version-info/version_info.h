#ifndef VERSION_INFO_H
#define VERSION_INFO_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Module version_info provides data structures and functions that
 * contain information about application version, git hash, build type and
 * other.
 *
 * Data that is provided by this module is always up to date, as cmake during
 * each west build command run checks whether new version information should be
 * generated.
 */

struct version_info {
	uint8_t major;
	uint8_t minor;
	uint8_t patch;
	/* Wether the build contains uncommitted changes */
	bool dirty;
	/* Output of git describe --always */
	char hash[9];
	/* Provided by Kconfig option, it should be set in .conf file */
	char build_type[20];
	/* Output of git describe --tags --always --long --dirty=+ */
	char git_describe[30];
};

/**
 * @brief Get version information struct
 *
 * @return struct version_info
 */
const struct version_info *version_info_get(void);

/**
 * @brief Log version information
 *
 * This will print the application version, full git describe output, git hash,
 * whether the build was dirty, build type, NCS version and the board name.
 */
void version_info_print(void);

#ifdef __cplusplus
}
#endif

#endif // VERSION_INFO_H
