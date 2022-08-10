////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/meta/Meta.hpp>
#include <engine/preamble.hpp>

namespace yq {
    namespace engine {
    
        class Rendered;
        class Pipeline;

        struct BufferData {
            const void*     data        = nullptr;
            size_t          size        = 0;
            uint64_t        revision    = 0;
        };
    
        class BufferObjectInfo : public Meta {
        public:
        
            struct Writer;

            virtual BufferData  get(const Rendered*) const = 0;
            
            //const TypeInfo*     data_type() const { return m_type; }
            //const DataFormat    data_format() const { return m_format; }
            const DataActivity  data_activity() const { return m_activity; }
            
            //! Location or binding that's in the shader
            uint32_t            location() const { return m_location; }
            
            void    set_data_activity(DataActivity);
            //void    set_data_format(DataFormat);
            //void    set_data_type(const TypeInfo*);
            void    set_location(uint32_t);
            
        protected:
            BufferObjectInfo(std::string_view, Pipeline*, const std::source_location&);
            
            //const TypeInfo* m_type          = nullptr;
            //DataFormat      m_format;
            DataActivity    m_activity;
            uint32_t        m_location      = UINT32_MAX;
        };
    }
}

