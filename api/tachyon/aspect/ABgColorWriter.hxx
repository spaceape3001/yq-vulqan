////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ABgColor.hpp>
#include <tachyon/command/color/SetBgColorCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ABgColor::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ABgColor>();
        w.property(UNSAFE, "bgcolor", &ABgColor::m_bgcolor).tag(kTag_Save);
        w.slot(UNSAFE, &ABgColor::on_set_bgcolor);
    }
}
