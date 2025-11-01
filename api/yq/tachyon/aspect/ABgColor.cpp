////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ABgColor.hpp"
#include "ABgColorWriter.hxx"
#include <yq/tachyon/command/color/SetBgColorCommand.hpp>
#include <yq/tachyon/event/color/BgColorChangeEvent.hpp>

namespace yq::tachyon {
    ABgColor::ABgColor() = default;
    ABgColor::~ABgColor() = default;

    void    ABgColor::bgcolor(emit_k)
    {
        send(new BgColorChangeEvent({.source=typed()}, m_bgcolor));
    }

    void    ABgColor::bgcolor(set_k, const RGBA4F&v)
    {
        m_bgcolor = v;
        mark();
        bgcolor(EMIT);
    }

    void    ABgColor::on_set_bgcolor(const SetBgColorCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        bgcolor(SET, cmd.bgcolor());
    }
}

