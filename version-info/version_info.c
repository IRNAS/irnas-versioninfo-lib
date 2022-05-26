#include <zephyr.h>

#include <version_info.h>

#include "generated/generated_version_info.h"

#include <ncs_version.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(version_info, CONFIG_VERSION_INFO_LOG_LEVEL);

static const struct version_info prv_version = {
    .major        = VERSION_INFO_MAJOR,
    .minor        = VERSION_INFO_MINOR,
    .patch        = VERSION_INFO_PATCH,
    .dirty        = VERSION_INFO_DIRTY,
    .hash         = VERSION_INFO_HASH,
    .git_describe = VERSION_INFO_GIT_DESCRIBE,
    .build_type   = CONFIG_VERSION_INFO_APP_BUILD_TYPE,
};

const struct version_info *version_info_get(void)
{
    return &prv_version;
}

void version_info_print(void)
{
    LOG_INF("---------------------------------------------");
    LOG_INF("App version:\t %i.%i.%i",
            prv_version.major,
            prv_version.minor,
            prv_version.patch);
    LOG_INF("Git describe:\t %s", prv_version.git_describe);
    LOG_INF("Git hash:\t %s", prv_version.hash);
    LOG_INF("Git dirty:\t %s", prv_version.dirty ? "yes" : "no");
    LOG_INF("Build type:\t %s", prv_version.build_type);
    LOG_INF("NCS:\t\t %s", NCS_VERSION_STRING);
    LOG_INF("Board:\t\t %s", CONFIG_BOARD);
    LOG_INF("---------------------------------------------");
}
