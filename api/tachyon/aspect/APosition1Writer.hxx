////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition1.hpp>
#include <tachyon/command/position/AddPosition1Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition1Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/SetPosition1Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹::init_info(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition¹>();
        w.property(UNSAFE, "position", &APosition¹::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹::on_set_position1);
        w.slot(UNSAFE, &APosition¹::on_set_positionX);

        w.slot(UNSAFE, &APosition¹::on_add_position1);
        w.slot(UNSAFE, &APosition¹::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹::on_multiply_position);
        w.slot(UNSAFE, &APosition¹::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹::on_multiply_positionX);
    }
}
