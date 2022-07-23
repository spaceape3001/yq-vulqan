////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pipeline.hpp"
#include "Rendered.hpp"

namespace yq {
    namespace engine {

        Pipeline::Pipeline(std::string_view name, const std::source_location& sl) : Pipeline(name, nullptr, sl)
        {
        
        }
        
        Pipeline::Pipeline(std::string_view name, RenderedInfo*parent, const std::source_location& sl) : Meta(name, parent, sl)
        {
            set_option(PIPELINE);
            m_rendered  = parent;
        }

    }
}
