////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/SaveFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class SaveXGFileGesture : public SaveFileGesture {
        YQ_OBJECT_DECLARE(SaveXGFileGesture, SaveFileGesture)
    public:
        SaveXGFileGesture(TypedID, const std::string& path={});
        ~SaveXGFileGesture();
        virtual void save(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
