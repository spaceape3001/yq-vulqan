////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/file/OpenFileGesture.hpp>
#include <yq/tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class LuaExecuteFileGesture : public OpenFileGesture {
        YQ_OBJECT_DECLARE(LuaExecuteFileGesture, OpenFileGesture)
    public:
        LuaExecuteFileGesture(TypedID, const std::string& path={});
        ~LuaExecuteFileGesture();
        virtual void open(const std::string&) override;
        
    private:
        TypedID     m_target;
    };
}
