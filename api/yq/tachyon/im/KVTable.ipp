////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KVTable.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/im/text.hpp>
#include <filesystem>

namespace yq::tachyon::im {
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
                text(kv);
            m_value = ImGui::TableNextColumn();
        }
        return *this;
    }
}
