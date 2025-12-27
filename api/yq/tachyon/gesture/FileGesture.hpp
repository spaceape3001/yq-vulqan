////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Gesture.hpp>
#include <yq/typedef/vector2.hpp>

namespace IGFD { class FileDialog; }

namespace yq::tachyon {
    class FileGesture : public Gesture {
        YQ_OBJECT_DECLARE(FileGesture, Gesture)
    public:
    
        struct Param {
            std::string     filters;
            std::string     path;
            std::string     title;
        };
        
        const std::string& key() const { return m_key; }
    
        virtual bool is_imgui() const { return true; }
        virtual bool is_modal() const override { return true; }
        
        static void init_meta();
    
    protected:    
        FileGesture(const std::string& key);
        ~FileGesture();
        
        static Vector2F       min_size();
    
        std::string         m_key;
        IGFD::FileDialog*   m_dialog    = nullptr;
    };
}
