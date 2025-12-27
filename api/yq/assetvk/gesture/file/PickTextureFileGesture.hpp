////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickTextureFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickTextureFileGesture, OpenFileGesture)
    public:
        PickTextureFileGesture(TypedID, const std::string& path={});
        ~PickTextureFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
