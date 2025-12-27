////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "FileGesture.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <ImGuiFileDialog.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FileGesture);

namespace yq::tachyon {
    void FileGesture::init_meta()
    {
        auto w = writer<FileGesture>();
        w.description("File Gesture");
        w.abstract();
        w.property("key", &FileGesture::key);
    }

    Vector2F       FileGesture::min_size()
    {
        Widget*w    = widget();
        if(!w)
            return {};
        return Vector2F((float) 0.5*w->width(), (float) 0.5*w->height());
    }

    FileGesture::FileGesture(const std::string& _key) : m_key(_key)
    {
        m_dialog    = new IGFD::FileDialog;
    }
    
    FileGesture::~FileGesture()
    {
        delete m_dialog;
    }
}
