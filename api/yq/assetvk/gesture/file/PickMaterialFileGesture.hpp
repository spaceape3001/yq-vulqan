////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickMaterialFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickMaterialFileGesture, OpenFileGesture)
    public:
        PickMaterialFileGesture(TypedID, const std::string& path={});
        ~PickMaterialFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
