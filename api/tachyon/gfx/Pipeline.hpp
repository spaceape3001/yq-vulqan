////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Ref.hpp>
#include <basic/UniqueID.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>

namespace yq {
    namespace tachyon {
        /*! \brief Pipeline configuration
        
            This is a pipeline configuration.  Once created, can be submitted to the 
            visualizer for a proper VkPipeline.
        */
        class Pipeline : public UniqueID, public RefCount {
        public:
        
            const PipelineConfig&   config() const { return m_config; }
            
            Pipeline(const PipelineConfig&);
            Pipeline(PipelineConfig&&);
            
            std::string_view    name() const { return m_name; }
            void                set_name(std::string_view);
            
            bool                is_object() const { return m_object != nullptr; }
            const ObjectInfo*   object() const { return m_object; }
            
        protected:
            Pipeline();
            virtual ~Pipeline();
        
        private:
            PipelineConfig      m_config;
            std::string         m_name;
            const ObjectInfo*   m_object        = nullptr;
        };
    }
}
