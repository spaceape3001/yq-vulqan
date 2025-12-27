////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/FileGesture.hpp>


namespace yq::tachyon {
    class SaveFileGesture : public FileGesture {
        YQ_OBJECT_DECLARE(SaveFileGesture, FileGesture)
    public:
    
        SaveFileGesture(const std::string& key, const Param& params={});
        ~SaveFileGesture();
    
        virtual void imgui() override;
        virtual void save(const std::string&) = 0;
    };
}
