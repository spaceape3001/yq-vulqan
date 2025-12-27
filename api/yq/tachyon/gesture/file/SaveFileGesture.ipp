////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "SaveFileGesture.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <ImGuiFileDialog.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveFileGesture);

namespace yq::tachyon {
    SaveFileGesture::SaveFileGesture(const std::string& _key, const Param& p) : FileGesture(_key)
    {
        IGFD::FileDialogConfig cfg;
        
        cfg.flags |= ImGuiFileDialogFlags_Modal;
        cfg.flags |= ImGuiFileDialogFlags_HideColumnType;
        cfg.flags |= ImGuiFileDialogFlags_CaseInsensitiveExtentionFiltering;
        cfg.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
        
        cfg.path = p.path;
        if(cfg.path.empty())
            cfg.path    = ".";
        std::string title   = p.title;
        if(title.empty())
            title   = "Choose File to Save/Export";
        m_dialog->OpenDialog(key(), title, p.filters.c_str(), cfg);
    }
    
    SaveFileGesture::~SaveFileGesture()
    {
    }

    void SaveFileGesture::imgui() 
    {
        if(!m_dialog->Display(key(), ImGuiWindowFlags_NoCollapse, min_size()))
            return;
            
        if(m_dialog->IsOk()){
            std::string filePathName    = m_dialog->GetFilePathName();
            if(!filePathName.empty())
                save(filePathName);
        }
        m_done  = true;
        m_dialog->Close();
    }
}
