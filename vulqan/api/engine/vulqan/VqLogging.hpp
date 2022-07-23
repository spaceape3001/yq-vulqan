////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <basic/Logging.hpp>

#define vqAlert           yAlert("vq")
#define vqCritical        yCritical("vq")
#define vqDebug           yDebug("vq")
#define vqError           yError("vq")
#define vqEmergency       yEmergency("vq")
#define vqFatal           yFatal("vq")
#define vqInfo            yInfo("vq")
#define vqNotice          yNotice("vq")
#define vqWarning         yWarning("vq")

namespace log4cpp {
    class CategoryStream;
}

log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const VkExtent2D&);
