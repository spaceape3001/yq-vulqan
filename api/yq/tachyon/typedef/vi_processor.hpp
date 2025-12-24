////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <memory>
#include <vector>
#include <functional>

namespace yq::tachyon {
    class ViProcessor;
    class ViWorker;
    
    using ViProcessorUPtr = std::unique_ptr<ViProcessor>;
    using ViProcessorUPtrVector    = std::vector<ViProcessorUPtr>;
    using FNProcessorTask   = std::function<void(ViWorker&)>;
}
