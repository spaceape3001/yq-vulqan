////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickHeightFieldFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickHeightFieldFileGesture, OpenFileGesture)
    public:
        PickHeightFieldFileGesture(TypedID, const std::string& path={});
        ~PickHeightFieldFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
