////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaExecuteFileGesture.hpp"
#include <yq/luavk/command/LuaExecuteFileCommand.hpp>
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/io/Save.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaExecuteFileGesture)

namespace yq::tachyon {
    LuaExecuteFileGesture::LuaExecuteFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("ExecuteLuaFile", {
            .filters = ".lua",
            .path    = path,
            .title   = "Pick Lua File to execute"
        }), m_target(tgt)
    {
    }
    
    LuaExecuteFileGesture::~LuaExecuteFileGesture()
    {
    }
    
    void LuaExecuteFileGesture::open(const std::string& s) 
    {
        send(new LuaExecuteFileCommand({.target=m_target}, s));
    }
}

