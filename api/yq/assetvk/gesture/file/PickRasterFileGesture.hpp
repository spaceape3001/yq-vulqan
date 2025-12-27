////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickRasterFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickRasterFileGesture, OpenFileGesture)
    public:
        PickRasterFileGesture(TypedID, const std::string& path={});
        ~PickRasterFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
