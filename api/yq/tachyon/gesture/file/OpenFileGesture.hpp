////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/FileGesture.hpp>


namespace yq::tachyon {
    class OpenFileGesture : public FileGesture {
        YQ_OBJECT_DECLARE(OpenFileGesture, FileGesture)
    public:
    
        OpenFileGesture(const std::string& key, const Param& params={});
        ~OpenFileGesture();
    
        virtual void imgui() override;
        virtual void open(const std::string&) = 0;
    };
}
