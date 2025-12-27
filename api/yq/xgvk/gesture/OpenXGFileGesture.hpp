////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class OpenXGFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(OpenXGFileGesture, OpenFileGesture)
    public:
        OpenXGFileGesture(TypedID, const std::string& path={});
        ~OpenXGFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
