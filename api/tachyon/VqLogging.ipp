////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqLogging.hpp"
#include <basic/Logging.hpp>

namespace yq {
}

log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream& stream, const VkExtent2D& x)
{
    stream << '[' << x.width << 'x' << x.height << ']';
    return stream;
}
