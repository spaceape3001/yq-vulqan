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
#include <yq/typedef/filesystem_path.hpp>

namespace yq::tachyon::imgui {
    class KVTable {
    public:
    
        KVTable(const char* zTable="KV");
        ~KVTable();
        
        void        finish();
        KVTable&    operator()(std::string_view);

        bool        operator()(table_k) const { return m_table; }
        bool        operator()(value_k) const { return m_value; }

        KVTable&    operator<<(const char*);
        KVTable&    operator<<(const std::string&);
        KVTable&    operator<<(std::string_view);
        KVTable&    operator<<(const std::filesystem::path&);
        KVTable&    operator<<(bool);
        KVTable&    operator<<(float);
        KVTable&    operator<<(double);
        KVTable&    operator<<(int8_t);
        KVTable&    operator<<(int16_t);
        KVTable&    operator<<(int32_t);
        KVTable&    operator<<(int64_t);
        KVTable&    operator<<(uint8_t);
        KVTable&    operator<<(uint16_t);
        KVTable&    operator<<(uint32_t);
        KVTable&    operator<<(uint64_t);
        
    private:
    
        bool    m_table = false;
        bool    m_value = false;
    };
}
