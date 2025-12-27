////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "OpenFileGesture.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <ImGuiFileDialog.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenFileGesture);

namespace yq::tachyon {
    OpenFileGesture::OpenFileGesture(const std::string& _key, const Param& p) : FileGesture(_key)
    {
        IGFD::FileDialogConfig cfg;
        
        cfg.flags |= ImGuiFileDialogFlags_Default | ImGuiFileDialogFlags_CaseInsensitiveExtentionFiltering;
        
        cfg.path = p.path;
        if(cfg.path.empty())
            cfg.path    = ".";
        std::string title   = p.title;
        if(title.empty())
            title   = "Choose File to Open/Import";
        m_dialog->OpenDialog(key(), title, p.filters.c_str(), cfg);
    }
    
    OpenFileGesture::~OpenFileGesture()
    {
    }

    void OpenFileGesture::imgui() 
    {
        if(!m_dialog->Display(key(), ImGuiWindowFlags_NoCollapse, min_size()))
            return;
            
        if(m_dialog->IsOk()){
            std::string filePathName    = m_dialog->GetFilePathName();
            if(!filePathName.empty())
                open(filePathName);
        }
        m_done  = true;
        m_dialog->Close();
    }
}
