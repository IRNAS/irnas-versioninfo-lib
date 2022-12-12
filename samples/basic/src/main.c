
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <version_info.h>

LOG_MODULE_REGISTER(main);

void main(void)
{
	LOG_INF("Basic version info sample started");

	/* Print to logger */
	version_info_print();

	/* fetch version info struct manually */
	const struct version_info *vi = version_info_get();

	/* The version is extracted from the latest git tag. If there is no
	 * applicable tag, this is all set to 0
	 */
	LOG_INF("major: %d", vi->major);
	LOG_INF("minor: %d", vi->minor);
	LOG_INF("patch: %d", vi->patch);

	/* Whether there are uncommitted changes in the projects files */
	LOG_INF("dirty: %d", vi->dirty);

	/* The hash of the current git commit */
	LOG_INF("hash: %s", vi->hash);

	/* CONFIG_VERSION_INFO_APP_BUILD_TYPE, or "unknown" if not set */
	LOG_INF("build_type: %s", vi->build_type);

	/* The full result of the git describe command */
	LOG_INF("git_describe: %s", vi->git_describe);
}
