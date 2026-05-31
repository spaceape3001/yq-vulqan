////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/SaveFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class SaveTSXFileGesture : public SaveFileGesture {
        YQ_OBJECT_DECLARE(SaveTSXFileGesture, SaveFileGesture)
    public:
        SaveTSXFileGesture(TypedID, const std::string& path={});
        ~SaveTSXFileGesture();
        virtual void save(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
