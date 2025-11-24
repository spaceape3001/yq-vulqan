////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KVTable.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <filesystem>

namespace yq::tachyon::imgui {
    KVTable::KVTable(const char* zTable)
    {
        m_table = ImGui::BeginTable(zTable, 2, ImGuiTableFlags_SizingStretchProp);
        if(m_table){
            ImGui::TableSetupColumn("##Key",   0, 0.20 );
            ImGui::TableSetupColumn("##Value", 0, 0.80 );
        }
    }
    
    KVTable::~KVTable()
    {
        finish();
    }
    
    void KVTable::finish()
    {
        if(m_table){
            ImGui::EndTable();
            m_table = false;
            m_value = false;
        }
    }

    KVTable&    KVTable::operator()(std::string_view kv)
    {
        if(m_table){
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn())
                ImGui::TextUnformatted(kv);
            m_value = ImGui::TableNextColumn();
        }
        return *this;
    }

    KVTable&    KVTable::operator<<(const char* v)
    {
        if(m_value && v)
            ImGui::TextUnformatted(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(const std::string&v)
    {
        if(m_value)
            ImGui::TextUnformatted(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(std::string_view v)
    {
        if(m_value)
            ImGui::TextUnformatted(v);
        return *this;
    }

    KVTable&    KVTable::operator<<(const std::filesystem::path& v)
    {
        if(m_value)
            ImGui::TextUnformatted(v.c_str());
        return *this;
    }
    
    KVTable&    KVTable::operator<<(bool v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(float v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(double v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(int8_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(int16_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(int32_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(int64_t v)
    {
        if(m_value)
            ImGui::Text("%ld", v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(uint8_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(uint16_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(uint32_t v)
    {
        if(m_value)
            ImGui::Text("%u", v);
        return *this;
    }
    
    KVTable&    KVTable::operator<<(uint64_t v)
    {
        if(m_value)
            ImGui::Text(v);
        return *this;
    }
}
