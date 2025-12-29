////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <string_view>
#include <cstdint>

#include <yq/keywords.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/im/text.hpp>
#include <yq/typedef/filesystem_path.hpp>

namespace yq::tachyon::im {
    class KVTable {
    public:
    
        KVTable(const char* zTable="KV");
        ~KVTable();
        
        void        finish();
        KVTable&    operator()(std::string_view);

        bool        operator()(table_k) const { return m_table; }
        bool        operator()(value_k) const { return m_value; }
    
        template <typename T>
        KVTable&    operator<<(const T&v)
        {
            text(v);
            return *this;
        }
        
    private:
    
        bool    m_table = false;
        bool    m_value = false;
    };
}
