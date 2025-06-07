////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition2.hpp>
#include <tachyon/command/position/AddPosition2Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition2Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/SetPosition2Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition²>();
        w.property(UNSAFE, "position", &APosition²::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition²::on_set_position2);
        w.slot(UNSAFE, &APosition²::on_set_positionX);
        w.slot(UNSAFE, &APosition²::on_set_positionY);

        w.slot(UNSAFE, &APosition²::on_add_position2);
        w.slot(UNSAFE, &APosition²::on_add_positionX);
        w.slot(UNSAFE, &APosition²::on_add_positionY);
        
        w.slot(UNSAFE, &APosition²::on_multiply_position);
        w.slot(UNSAFE, &APosition²::on_multiply_position2);
        w.slot(UNSAFE, &APosition²::on_multiply_positionX);
        w.slot(UNSAFE, &APosition²::on_multiply_positionY);
    }
}
