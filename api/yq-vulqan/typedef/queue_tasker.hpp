////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <functional>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    using queue_tasker_fn     = std::function<void(VkCommandBuffer)>;
    
    class ViQueueTasker;
    using ViQueueTaskerPtr   = Ref<ViQueueTasker>;
}
