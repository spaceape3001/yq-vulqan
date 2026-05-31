////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class PickColorProfileFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(PickColorProfileFileGesture, OpenFileGesture)
    public:
        PickColorProfileFileGesture(TypedID, const std::string& path={});
        ~PickColorProfileFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
