////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class OpenTSXFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(OpenTSXFileGesture, OpenFileGesture)
    public:
        OpenTSXFileGesture(TypedID, const std::string& path={});
        ~OpenTSXFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
