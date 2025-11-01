////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AColor.hpp"
#include "AColorWriter.hxx"
#include <tachyon/command/color/SetColorCommand.hpp>
#include <tachyon/event/color/ColorChangeEvent.hpp>

namespace yq::tachyon {
    AColor::AColor() = default;
    AColor::~AColor() = default;

    void    AColor::color(emit_k)
    {
        send(new ColorChangeEvent({.source=typed()}, m_color));
    }

    void    AColor::color(set_k, const RGBA4F&v)
    {
        m_color = v;
        mark();
        color(EMIT);
    }

    void    AColor::on_set_color(const SetColorCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        color(SET, cmd.color());
    }
}

