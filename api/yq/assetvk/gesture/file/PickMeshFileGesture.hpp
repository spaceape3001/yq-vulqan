////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickMeshFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickMeshFileGesture, OpenFileGesture)
    public:
        PickMeshFileGesture(TypedID, const std::string& path={});
        ~PickMeshFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
