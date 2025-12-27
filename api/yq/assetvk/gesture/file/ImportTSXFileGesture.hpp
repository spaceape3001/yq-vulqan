////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class ImportTSXFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(ImportTSXFileGesture, OpenFileGesture)
    public:
        ImportTSXFileGesture(TypedID, const std::string& path={});
        ~ImportTSXFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
