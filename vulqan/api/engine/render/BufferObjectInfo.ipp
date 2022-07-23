////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

// #pragma once

#include "BufferObjectInfo.hpp"
#include "IndexBufferObjectInfo.hpp"
#include "UniformBufferObjectInfo.hpp"
#include "VertexBufferObjectInfo.hpp"
#include "Pipeline.hpp"

namespace yq {
    namespace engine {

        BufferObjectInfo::BufferObjectInfo(std::string_view n, Pipeline*p, const std::source_location&sl) : Meta(n, p, sl)
        {
        }

            
        void    BufferObjectInfo::set_data_activity(DataActivity v)
        {
            m_activity  = v;
        }
        
        //void    BufferObjectInfo::set_data_format(DataFormat fmt)
        //{
            //m_format        = fmt;
        //}
        
        //void    BufferObjectInfo::set_data_type(const TypeInfo* ti)
        //{
            //m_type          = ti;
        //}
        
        void    BufferObjectInfo::set_location(uint32_t l)
        {
            m_location  = l;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        IndexBufferObjectInfo::IndexBufferObjectInfo(std::string_view n, Pipeline* p, const std::source_location& sl) : BufferObjectInfo(n, p, sl)
        {
            if(p){
                p->m_ibos.push_back(this);
            }
        }

        void    IndexBufferObjectInfo::set_index_type(IndexType it)
        {
            m_type = it;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        UniformBufferObjectInfo::UniformBufferObjectInfo(std::string_view n, Pipeline* p, const std::source_location& sl) : BufferObjectInfo(n, p, sl)
        {
            if(p){
                p->m_ubos.push_back(this);
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        VertexBufferObjectInfo::VertexBufferObjectInfo(std::string_view n, Pipeline* p, const std::source_location& sl) : BufferObjectInfo(n, p, sl), m_binding(0)
        {
            if(p){
                m_binding       = p->m_vbos.size();
                p->m_vbos.push_back(this);
            }
        }

        
    }
}
