////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/VqLogging.hpp>
#include <yq/core/StreamOps.hpp>

namespace yq {
}

log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream& stream, const VkExtent2D& x)
{
    stream << '[' << x.width << 'x' << x.height << ']';
    return stream;
}

log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&stream, const VkExtent3D&x)
{
    stream << '[' << x.width << 'x' << x.height << 'x' << x.depth << ']';
    return stream;
}

yq::Stream& operator<<(yq::Stream&stream, const VkExtent2D&x)
{
    stream << '[' << x.width << 'x' << x.height << ']';
    return stream;
}

yq::Stream& operator<<(yq::Stream&stream, const VkExtent3D&x)
{
    stream << '[' << x.width << 'x' << x.height << 'x' << x.depth << ']';
    return stream;
}

