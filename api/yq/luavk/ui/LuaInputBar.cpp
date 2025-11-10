////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaInputBar.hpp"
#include "LuaInputBarWriter.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaInputBar)

namespace yq::lua {
    void LuaInputBar::init_meta()
    {
        auto w = writer<LuaInputBar>();
        w.description("Lua Input Bar");
    }

    LuaInputBar::LuaInputBar(std::string_view k, tachyon::UIFlags flags) : tachyon::UIInputBar(k, flags)
    {
    }
    
    LuaInputBar::LuaInputBar(const LuaInputBar&cp) : tachyon::UIInputBar(cp)
    {
    }
    
    LuaInputBar::~LuaInputBar()
    {
    }
    
    
    LuaInputBar*    LuaInputBar::clone() const
    {
        return new LuaInputBar(*this);
    }

    ////////////////////////////
    
    LuaInputBarWriter::LuaInputBarWriter() = default;
    LuaInputBarWriter::LuaInputBarWriter(const LuaInputBarWriter&) = default;
    LuaInputBarWriter::~LuaInputBarWriter() = default;
    
    LuaInputBar* LuaInputBarWriter::element()
    {
        return static_cast<LuaInputBar*>(m_ui);
    }
    
    LuaInputBarWriter::LuaInputBarWriter(LuaInputBar* ui) : tachyon::UIInputBarWriter(ui)
    {
    }

}

